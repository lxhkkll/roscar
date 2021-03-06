#!/usr/bin/env python

import rospy
#import math
from std_msgs.msg import Float32
from std_msgs.msg import Int32
from std_msgs.msg import Float64MultiArray
from geometry_msgs.msg import Twist

import numpy as np
np.random.seed(1337)  # for reproducibility
import matplotlib.pyplot as plt
from keras.models import Sequential,load_model
from keras.layers import LSTM, TimeDistributed, Dense
#from keras.applications import imagenet_utils
from keras.optimizers import Adam
#import keras
#from importlib import reload
# reload(keras.models)

TIME_STEPS = 20
BATCH_SIZE = 20
INPUT_SIZE = 2
OUTPUT_SIZE = 2
CELL_SIZE = 500
LR = 0.006
ON_TRAIN=True
# ON_TRAIN=False



class lstm_class(object):
  def __init__(self):
    self.pointer=0
    self.pointer_b=0
    self.batch_index=0
    self.index=0
    self.memory_x = np.zeros((BATCH_SIZE,TIME_STEPS, INPUT_SIZE), dtype=np.float32)
    self.memory_y = np.zeros((BATCH_SIZE,TIME_STEPS, OUTPUT_SIZE), dtype=np.float32)
    self.x_temp=np.zeros((TIME_STEPS, INPUT_SIZE), dtype=np.float32)
    self.y_temp=np.zeros((TIME_STEPS, OUTPUT_SIZE), dtype=np.float32)
    ##ros init
    rospy.Subscriber("/Asv_traindata", Twist, self.get_data)
    rospy.init_node('lstm_train', anonymous=True)
    self.rate = rospy.Rate(5) # 10hz
    

  def build_model(self):
     self.model = Sequential()
        # build a LSTM RNN
     self.model.add(LSTM(
       batch_input_shape=(BATCH_SIZE, TIME_STEPS, INPUT_SIZE),       # Or: input_dim=INPUT_SIZE, input_length=TIME_STEPS,
       output_dim=CELL_SIZE,
       return_sequences=True,      # True: output at all steps. False: output as last step.
       stateful=False,          
     ))
        # add output layer
     self.model.add(TimeDistributed(Dense(INPUT_SIZE)))
     self.model.add(LSTM(
       batch_input_shape=(BATCH_SIZE, TIME_STEPS, INPUT_SIZE),       # Or: input_dim=INPUT_SIZE, input_length=TIME_STEPS,
       output_dim=CELL_SIZE,
       return_sequences=True,      # True: output at all steps. False: output as last step.
       stateful=True,              # True: the final state of batch1 is feed into the initial state of batch2
     ))
        # add output layer
    #  self.model.add(Dense(CELL_SIZE))
     self.model.add(TimeDistributed(Dense(OUTPUT_SIZE)))
     self.adam = Adam(LR)
     self.model.compile(optimizer=self.adam,loss='mse',)
     print(self.model.summary())
  def save(self):
        self.model.save_weights('my_model_weights.h5')

  def restore(self):
     self.model.load_weights('my_model_weights.h5')
  def train(self):
     cost = self.model.train_on_batch(self.memory_x, self.memory_y)
     return cost
  def pre_y(self):
     pred = self.model.predict(self.memory_x, BATCH_SIZE)

     return pred[self.batch_index][self.index][0] ,self.memory_y[self.batch_index][self.index][0]



  def get_data(self,data):
     self.index = self.pointer % TIME_STEPS  # replace the old memory with new memory
     if(self.index==0):
         self.pointer_b += 1
         self.batch_index = self.pointer_b % BATCH_SIZE
         
     self.pointer += 1

     x_data=np.array([data.linear.x,data.linear.y],dtype=np.float32) #road x input data
     y_data=np.array([data.angular.x,data.angular.y],dtype=np.float32)*100
    #  y_data=np.array([data.linear.y,data.linear.x],dtype=np.float32)*10
    #  y_data=np.array([data.angular.x],dtype=np.float32)*10
    #  self.x_temp[self.index,:]=x_data
    #  self.y_temp[self.index,:]=y_data
    #  print(y_data)
     self.memory_x[self.batch_index,self.index, :] = x_data
     self.memory_y[self.batch_index,self.index, :] = y_data
    #  print(self.memory_x)

  def get_batch(self):
    return self.memory_x,self.memory_y




# model.load_weights('my_model_weights.h5')

# for step in range(301):
#     # data shape = (batch_num, steps, inputs/outputs)
# X_batch, Y_batch, xs = get_batch()
#     cost = model.train_on_batch(X_batch, Y_batch)
#     pred = model.predict(X_batch, BATCH_SIZE)

#     if step % 10 == 0:
#         print('train cost: ', cost)
# 	plt.plot(xs[0, :], Y_batch[0].flatten(), 'r', xs[0, :], pred.flatten()[:TIME_STEPS], 'b--')
#    	plt.ylim((-1.2, 1.2))
#    	plt.draw()
#     	plt.pause(0.1)


ls=lstm_class()
ls.build_model()
ls.restore()
x1=[]
x2=[]

while not rospy.is_shutdown():
    if ON_TRAIN:
        ls.rate.sleep()
        X_batch,Y_batch= ls.get_batch()
        cost=ls.train()
        print(cost)
    else:
            prx,pry=ls.pre_y()
            x1.append(pry)
            x2.append(prx)
            plt.plot(np.arange(15,15+len(x1)), x1, 'r', np.arange(len(x2)), x2, 'b--')
            # plt.plot(np.arange(len(x2)), x2, 'r')
            if(ls.pointer%1000==0):
                print(ls.pointer)
            if(ls.pointer>2000):
                break
# plt.plot(np.arange(len(x1)), x1, 'r',np.arange(len(x2)), x2, 'b--')
# plt.plot(np.arange(len(x2)), x2, 'r')
plt.draw()
plt.show()
plt.pause(0.1)
if ON_TRAIN:
    ls.save()


    