#include "car_line.hpp"
void chatterCallback(const vision::image_cv::ConstPtr& msg)
{
    
	img_w=msg->weight;
	img_h=msg->hight;
    frame.release();
	frame=cv::Mat::zeros(img_h,img_w,CV_8UC3);
	if(img_w>100){
	 for(int i=0;i<frame.rows;i++)
		 		for(int j=0;j<frame.cols;j++)
				 		for(int k=0;k<3;k++){
		frame.data[(i*frame.cols*3)+(j*3)+k]=msg->data[(i*frame.cols*3)+(j*3)+k];
				 }
	}
    
}






void settingmap(float j,float i,float *x_cor,float *y_cor){
//    int x_cor; 
  
   if(j<=479&&j>465){
        if(i<=355){//118
        *x_cor=(17*(479-j)/(479-465))+238;*y_cor=150*(355-i)/(355-(113-(113-96)*(j-465)/(479-465)));
        }
        if(i>355){//511
        *x_cor=(17*(479-j)/(479-465))+238;*y_cor=-150*(i-355)/((585+(597-585)*(j-465)/(479-465))-355);
        }
    }

    if(j<=465&&j>450){
        if(i<=355){//&&i>=129
        *x_cor=(20*(465-j)/(465-450))+255;*y_cor=150*(355-i)/(355-(128-(128-113)*(j-450)/(465-450)));
        }
        if(i>355){//i<=500&&
        *x_cor=(20*(465-j)/(465-450))+255;*y_cor=-150*(i-355)/((570+(585-570)*(j-450)/(465-450))-355);
        }
    }
  
    if(j<=450&&j>438){
        if(i<=355){//&&i>=140
        *x_cor=(20*(450-j)/(450-438))+275;*y_cor=150*(355-i)/(355-(140-(140-128)*(j-438)/(450-438)));
        }
        if(i>355){//i<=490&&
        *x_cor=(20*(450-j)/(450-438))+275;*y_cor=-150*(i-355)/((560+(570-560)*(j-438)/(450-438))-355);
        }
    }
    
    if(j<=438&&j>425){
        if(i<=355){//&&i>=150
        *x_cor=(20*(438-j)/(438-425))+295;*y_cor=150*(355-i)/(355-(152-(152-140)*(j-425)/(438-425)));
        }
        if(i>355){//i<=481&&
        *x_cor=(20*(438-j)/(438-425))+295;*y_cor=-150*(i-355)/((547+(560-547)*(j-425)/(438-425))-355);
        }
    }

    if(j<=425&&j>415){
        if(i<=355){//&&i>=159
        *x_cor=(20*(425-j)/(425-415))+315;*y_cor=150*(355-i)/(355-(162-(162-152)*(j-415)/(425-415)));
        }
        if(i>355){//i<=471&&
        *x_cor=(20*(425-j)/(425-415))+315;*y_cor=-150*(i-355)/((538+(547-538)*(j-415)/(425-415))-355);
        }
    }
    if(j<=415&&j>405){
        if(i<=355){//&&i>=168
        *x_cor=(20*(415-j)/(415-405))+335;*y_cor=150*(355-i)/(355-(173-(173-162)*(j-405)/(415-405)));
        }
        if(i>355){//i<=464&&
        *x_cor=(20*(415-j)/(415-405))+335;*y_cor=-150*(i-355)/((530+(538-530)*(j-405)/(415-405))-355);
        }
    }
    if(j<=405&&j>396){
        if(i<=355){//&&i>=174
        *x_cor=(20*(405-j)/(405-396))+355;*y_cor=150*(355-i)/(355-(182-(182-173)*(j-396)/(405-396)));
        }
        if(i>355){//i<=457&&
        *x_cor=(20*(405-j)/(405-396))+355;*y_cor=-150*(i-355)/((522+(530-522)*(j-396)/(405-396))-355);
        }
    }
    if(j<=396&&j>388){
        if(i<=355){//&&i>=182
        *x_cor=(20*(396-j)/(396-388))+375;*y_cor=150*(355-i)/(355-(188-(188-182)*(j-388)/(396-388)));
        }
        if(i>355){//i<=450&&
        *x_cor=(20*(396-j)/(396-388))+375;*y_cor=-150*(i-355)/((516+(522-516)*(j-388)/(396-388))-355);
        }
    }
    if(j<=388&&j>381){
        if(i<=355){//&&i>=188
        *x_cor=(20*(388-j)/(388-381))+395;*y_cor=150*(355-i)/(355-(196-(196-188)*(j-381)/(388-381)));
        }
        if(i>355){//i<=443&&
        *x_cor=(20*(388-j)/(388-381))+395;*y_cor=-150*(i-355)/((510+(516-510)*(j-381)/(388-381))-355);
        }
    }
    if(j<=381&&j>374){
        if(i<=355){//&&i>=192
        *x_cor=(20*(381-j)/(381-374))+415;*y_cor=150*(355-i)/(355-(203-(203-196)*(j-374)/(381-374)));
        }
        if(i>355){//i<=438&&
        *x_cor=(20*(381-j)/(381-374))+415;*y_cor=-150*(i-355)/((504+(510-504)*(j-374)/(381-374))-355);
        }
    }
    if(j<=374){//&&j>=368
        if(i<=355){//&&i>=197
        *x_cor=(20*(374-j)/(374-368))+435;*y_cor=150*(355-i)/(355-(208-(208-203)*(j-368)/(374-368)));
        }
        if(i>355){//i<=434&&
        *x_cor=(20*(374-j)/(374-368))+435;*y_cor=-150*(i-355)/((499+(504-499)*(j-368)/(374-368))-355);
        }
    }
    
    // Point cor(x_cor,y_cor);
    //return cor;
    
}








int main(int argc, char *argv[])
{
   ros::init(argc, argv, "car_line");
	ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("bag_picture", 10, chatterCallback);
    // Parameter_getting(1);
    // ros::Subscriber sub_parm = n.subscribe("/ParmIsChange", 10, ParmIsChangeCallback);
    pub1 = n.advertise<vision_pro::line_inform>("line_info", 1000);
    pub2 = n.advertise<vision::image_cv>("pic_source", 1000);
	
    VideoCapture capture("/home/allen/linux/car_line/model/20150210-130451CO.AVI");

    Status status = NewSession(SessionOptions(), &session);
    std::string graph_filename="/home/allen/linux/catkin_ws/model_0415.pb";
    LoadGraph(graph_filename, &session);

//    std::string timepath="/home/nvidia/testSD/tensorflow_model/time.txt";
//    fd.open(timepath,std::ios::out | ios::app);
 
    CvMat lowerBound;
    CvMat upperBound;
    float minRange[] = { -1.5, -1.5, -800, 172, 112 };
    float maxRange[] = { 1.5, 1.5, 800, 340, 124 };

    cvInitMatHeader(&lowerBound, 5, 1, CV_32FC1, minRange);
    cvInitMatHeader(&upperBound, 5, 1, CV_32FC1, maxRange);

    float A[stateNum][stateNum] = {
        1,0,0,0,0,
        0,1,0,0,0,
        0,0,1,0,0,
        0,0,0,1,0,
        0,0,0,0,1
    };
    memcpy(condens->DynamMatr, A, sizeof(A));

    cvConDensInitSampleSet(condens, &lowerBound, &upperBound);

    // VideoCapture capture(0);
    // rosbag play -l 2019-05-07-17-18-56.bag --topic /usb_cam/image_raw 

	ros::Rate loop_rate(30);
    while(ros::ok()){

        clockid_t start_time, end_time;
        float total_time=0;
        start_time=clock();

        capture>>frame;
        ///////////////////////////
        //         ros::spinOnce();
        // while(frame.empty()){
        //     ros::spinOnce();}
////////////////////////////////////

        if(frame.empty()){
//            fd.close();
            break;
        }
        // float k=479;float h=100;
        // float aa;float cc;
        // settingmap(k,h,aa,cc);printf("map_x=%f,map_y=%f",aa,cc);
        
        resize(frame,frame_resize,cv::Size(512,288),CV_INTER_LINEAR);
        Mat newing(288,1024, CV_8UC3, Scalar(0,0,0));
        frame_new=newing;
        for(int i=0;i<frame_resize.rows;i++)
        {
            for(int j=0;j<frame_resize.cols;j++)
            {
                //newing.create(288,1024, CV_8UC3);
                int x=i;
                int y=j+frame_resize.cols/2;
                    newing.at<Vec3b>(x,y)[0]=frame_resize.at<Vec3b>(i,j)[0];
                    newing.at<Vec3b>(x,y)[1]=frame_resize.at<Vec3b>(i,j)[1];
                    newing.at<Vec3b>(x,y)[2]=frame_resize.at<Vec3b>(i,j)[2];
            }
        }
        count1++;

        if (predict_hy) {

            learning_model();

            anglecompute();

            //gradient_compute();

            Condensationtracking();
        }
        else{

            cvInitMatHeader(&lowerBound, 5, 1, CV_32FC1, minRange);
            cvInitMatHeader(&upperBound, 5, 1, CV_32FC1, maxRange);

            float A[stateNum][stateNum] = {
                1,0,0,0,0,
                0,1,0,0,0,
                0,0,1,0,0,
                0,0,0,1,0,
                0,0,0,0,1
            };
            memcpy(condens->DynamMatr, A, sizeof(A));

            cvConDensInitSampleSet(condens, &lowerBound, &upperBound);

            learning_model();
            gradient();
            ROI_I_feature();
            if (!line_l.empty() && !line_r.empty())
                 ROI_II_feature();
            /*else
                line_l.clear(); line_r.clear();*/

            if (!img_r.empty() && !img_l.empty())
                houghtransfer();

            if (Vvp != 0 && !isnan(Vvp)){
                estimateroadparameter();
                Condensationtracking();
            }
            else{
                vision_pro::line_inform line_msg;
                line_msg.state=3;
                // vector<float> lane_lx;
                // line_msg.line1_x=lane_lx;
                pub1.publish(line_msg);
                Mat Roi=frame_resize(cv::Rect(0,160,512,128)).clone();
                Mat Roi_size = frame_resize(cv::Rect(0,160,512,128));

                if (!line_r.empty())
                        drawline(line_r, &Roi, Scalar(0, 100, 255));

                if (!line_l.empty())
                        drawline(line_l, &Roi, Scalar(0, 100, 255));
                Roi.copyTo(Roi_size);

                line_l.clear();
                line_r.clear();
                // imshow("Roi_size",Roi_size);
            }
        }

        ////////////////////////////sssssssssssss
        cv::Mat show_data;
        show_data= newing(Range(0,287), Range(256,767));
        resize(show_data,show_data,cv::Size(128,72),CV_INTER_LINEAR);
        vision::image_cv pic_source;
		pic_source.weight=show_data.cols;//x
		pic_source.hight=show_data.rows;//y
		std_msgs::Int32MultiArray array;
		array.data.clear();
		pic_source.data.clear();
		 for(int i=0;i<show_data.rows;i++)
		 		for(int j=0;j<show_data.cols;j++)
				 		for(int k=0;k<3;k++){
		array.data.push_back(show_data.data[(i*show_data.cols*3)+(j*3)+k]);
				 }
		pic_source.data=array.data;
		pub2.publish(pic_source);
        /////////////////////////////////////ssssssssss
        //Mat app;
        // resize(frame_resize,frame_resize,cv::Size(img_w,img_h),CV_INTER_LINEAR);
        // app=worldcoordinate(frame_resize);
        // imshow("frame",frame);
        // imshow("capture",frame_resize);
        imshow("capture1",newing);
        // frame_resize.release();
        //imwrite("capture.png",frame_resize);
        //imwrite("capture2.png",img_1);

        waitKey(1);


        //end_time=clock();
        total_time=(float)(end_time-start_time)/CLOCKS_PER_SEC;
        printf("Time : %f sec \n", total_time);


        //fd<<fixed<<total_time<<"\r\n";
loop_rate.sleep();

    }
    return 0;

}

void learning_model(){

    GpuMat img_gray, img_canny, Gimg_resize;//, img_thread, img_dil

    GpuMat Gframe(frame_resize);

    //gpu::cvtColor(Gframe,img_gray,CV_BGR2GRAY);

    gpu::resize(Gframe,Gimg_resize,cv::Size(width,144),CV_INTER_CUBIC);

    GpuMat img_segment=Gimg_resize(cv::Rect(0, 60, 256, 84));

   // gpu::Canny(img_segment,img_canny,50,150);
    //gpu::threshold(img_canny,img_thread,0,255,THRESH_BINARY);
    //gpu::dilate(img_thread,img_dil,Mat(),cv::Point(-1,-1),2);
    //gpu::resize(img_dil,Gimg_resize,cv::Size(width,height),CV_INTER_CUBIC);

    Mat img_resize;

    //img_gray.download(test1);
    img_segment.download(img_resize);
    //imshow("cn1",test1);
    //imshow("canny",img_resize);

    //創建Tensor
    Tensor input_tensor(DT_FLOAT,TensorShape({1,height,width,3}));
    auto input_tensor_mapped=input_tensor.tensor<float, 4>();

    //正規化圖像
    Mat img_resize2;
    img_resize.convertTo(img_resize2,CV_32FC1);
    img_resize2=img_resize2/255;

    //Mat複製到Tensor
    for(int i=0;i<height;i++){
        float* img_resize_data=img_resize2.ptr<float>(i);
        for(int j=0;j<width;j++){
            input_tensor_mapped(0, i, j, 0)= img_resize_data[j*3+2];
            input_tensor_mapped(0, i, j, 1)= img_resize_data[j*3+1];
            input_tensor_mapped(0, i, j, 2)= img_resize_data[j*3+0];
        }
    }
   /* int depth=img_resize.channels();
    const float * source_data = (float*) img_resize.data;
    for (int y = 0; y < height; ++y) {
       const float* source_row = source_data + (y * width * depth);
       for (int x = 0; x < width; ++x) {
         const float* source_pixel = source_row + (x * depth);
         for (int c = 0; c < depth; ++c) {
              const float* source_value = source_pixel + c;
              input_tensor_mapped(0, y, x, c) = *source_value;
         }
       }
     }*/


    //帶入模型訓練
    vector<Tensor> output;
    Status run_status = session->Run({{"input_img",input_tensor}},{"output_node0"},{},&output);
    if (!run_status.ok()) {
        std::cout << run_status.ToString() << "\n";
    }

    //結果輸出
    //std::cerr << "final output size =" << output.size() << std::endl;
    //Tensor output_tensor = std::move(output.at(0));//移動複製
    Tensor* output_tensor = &output[0];
    const Eigen::TensorMap<Eigen::Tensor<float, 1, Eigen::RowMajor>, Eigen::Aligned>& prediction = output_tensor->flat<float>();
    Mat img_output(height,width,CV_8UC1,Scalar(0));

    for(int i=0;i<height;i++){
        uchar* img_data=img_output.ptr<uchar>(i);
        for(int j=0;j<width;j++){
            img_data[j]= prediction(i*width + j)*255;
        }
    }
    // imshow("train",img_output);

    GpuMat Goutput(img_output);

    GpuMat Gimg_return, Gimg_thread, img_erode;//

    //GpuMat Gresult(cv::Size(512,288),CV_8UC1,Scalar(0));

    //gpu::GaussianBlur(Goutput,Goutput,cv::Size(5,5),0,0);
    //gpu::erode(Gimg_return,img_erode,Mat(),cv::Point(-1,-1),1);
    gpu::resize(Goutput,Gimg_return,cv::Size(512,168),CV_INTER_CUBIC);
    gpu::threshold(Gimg_return,Gimg_thread,50,255,THRESH_BINARY);

    Gimg_thread.download(learning_img);

    binary_img = Mat::zeros(frame_resize.rows, frame_resize.cols, CV_8UC1);
    Mat Roi_size = binary_img(cv::Rect(0, 120, 512, 168));
    learning_img.copyTo(Roi_size);

    // Mat temp;
    // cvtColor(binary_img,temp,CV_GRAY2BGR);
    // bitwise_or(temp,frame_resize,temp);
    // imshow("learning_img",temp);
}

void gradient() {

    /*Mat img_hsv, hsv_white, hsv_yellow;

    cvtColor(frame_resize, img_hsv, CV_BGR2HSV);

    img_segment_hsv = img_hsv(cv::Rect(0, 120, 512, 168)).clone();//(380 1280 340)1280,720 ;(250 720 230) 720,480


    inRange(img_segment_hsv, Scalar(0, 0, 221), Scalar(180, 40, 255), hsv_white);
    inRange(img_segment_hsv, Scalar(90, 70, 160), Scalar(180, 245, 255), hsv_yellow);


    for (uint16_t i = 0; i < img_segment_hsv.rows; i++) {
        uchar* whitedata = hsv_white.ptr<uchar>(i);
        uchar* yellowdata = hsv_yellow.ptr<uchar>(i);
        for (uint16_t j = 0; j < img_segment_hsv.cols; j++) {
            whitedata[j] = (whitedata[j] > 50 || yellowdata[j] > 50) ? 255 : 0;
        }
    }*/

    edge_img = Mat::zeros(learning_img.rows, learning_img.cols, CV_8UC1);
    img_angle = Mat::zeros(learning_img.rows, learning_img.cols, CV_32FC1);

    int img_H = learning_img.rows - 1;
    int img_W = learning_img.cols - 1;
    int edgeX = 0;
    int edgeY = 0;
    double graMag = 0;
    double graAng = 0;
    double Iang_angle[181] = { 0 };

    for (uint16_t a = 1; a < img_H - 1; a++) {
        uchar* edge_data = edge_img.ptr<uchar>(a);
        float* img_angle_data = img_angle.ptr<float>(a);
        for (uint16_t b = 1; b < img_W - 1; b++) {
            edgeX = learning_img.at<uchar>(a, b + 1) - learning_img.at<uchar>(a, b - 1);
            edgeY = learning_img.at<uchar>(a + 1, b) - learning_img.at<uchar>(a - 1, b);
            graAng = 0;
            graMag = (double)abs(edgeX) + (double)abs(edgeY);
            if (edgeX > 0)
                graAng = (double)atan2(edgeY, edgeX) * 180 / M_PI;

            if (graAng < 0)
                graAng += 180;

            Iang_angle[(int)graAng] = +graMag;
            edge_data[b] = ((graMag > 50) ? 255 : 0);
            img_angle_data[b] = graAng;
        }
    }

    // imshow("edge_img", edge_img);
    //imwrite("edge_img.png",edge_img);
    int g, k = 0;
    for (uint16_t f = 0; f < 90; f++) {
        if (Iang_angle[f]>g) {
            g = Iang_angle[f];
            haarlike_angle[0] = f;
        }
    }
    for (uint16_t h = 91; h < 180; h++) {
        if (Iang_angle[h]>k) {
            k = Iang_angle[h];
            haarlike_angle[1] = h;
        }
    }
}

void gradient_compute() {

    /*Mat img_hsv, hsv_white, hsv_yellow;

    cvtColor(frame_resize, img_hsv, CV_BGR2HSV);

    img_segment_hsv = img_hsv(cv::Rect(0, 120, 512, 168)).clone();//(380 1280 340)1280,720 ;(250 720 230) 720,480
    inRange(img_segment_hsv, Scalar(0, 0, 221), Scalar(180, 40, 255), hsv_white);
    inRange(img_segment_hsv, Scalar(90, 70, 160), Scalar(180, 245, 255), hsv_yellow);


    for (uint16_t i = 0; i < img_segment_hsv.rows; i++) {
        uchar* whitedata = hsv_white.ptr<uchar>(i);
        uchar* yellowdata = hsv_yellow.ptr<uchar>(i);
        for (uint16_t j = 0; j < img_segment_hsv.cols; j++) {
            whitedata[j] = (whitedata[j] > 50 || yellowdata[j] > 50) ? 255 : 0;
        }
    }*/

    edge_img = Mat::zeros(learning_img.rows, learning_img.cols, CV_8UC1);
    img_angle = Mat::zeros(learning_img.rows, learning_img.cols, CV_32FC1);

    int img_H = learning_img.rows - 1;
    int img_W = learning_img.cols - 1;
    int edgeX = 0;
    int edgeY = 0;
    double graMag = 0;
    double graAng = 0;
    double Iang_angle[181] = { 0 };

    for (uint16_t a = 1; a < img_H - 1; a++) {
        uchar* edge_data = edge_img.ptr<uchar>(a);
        float* img_angle_data = img_angle.ptr<float>(a);
        for (uint16_t b = 1; b < img_W - 1; b++) {
            edgeX = learning_img.at<uchar>(a, b + 1) - learning_img.at<uchar>(a, b - 1);
            edgeY = learning_img.at<uchar>(a + 1, b) - learning_img.at<uchar>(a - 1, b);
            graAng = 0;
            graMag = (double)abs(edgeX) + (double)abs(edgeY);

            if (edgeX > 0)
                graAng = (double)atan2(edgeY, edgeX) * 180 / M_PI;

            if (graAng < 0)
                graAng += 180;

            Iang_angle[(int)graAng] = +graMag;
            edge_data[b] = ((graMag > 50) ? 255 : 0);
            img_angle_data[b] = graAng;
        }
    }

    int g, k = 0;

    for (uint16_t f = 0; f < 90; f++) {
        if (Iang_angle[f]>g) {
            g = Iang_angle[f];
            haarlike_angle[0] = f;
        }
    }

    for (uint16_t h = 91; h < 180; h++) {
        if (Iang_angle[h]>k) {
            k = Iang_angle[h];
            haarlike_angle[1] = h;
        }
    }

    binary_img = Mat::zeros(frame_resize.rows, frame_resize.cols, haar_img.type());

    int angle_low_1 = haarlike_angle[0] - 5;
    int angle_high_1 = haarlike_angle[0] + 5;
    int angle_low_2 = haarlike_angle[1] - 5;
    int angle_high_2 = haarlike_angle[1] + 5;

    for (uint16_t i = 0; i < img_H - 24; i++) {
        float* img_angle_data = img_angle.ptr<float>(i);
        uchar* edge_data = edge_img.ptr<uchar>(i);
        uchar* binary_img_data = binary_img.ptr<uchar>(i + 120);
        for (uint16_t j = 0; j < img_W; j++) {
            if (edge_data[j]>200) {
                if ((img_angle_data[j] > angle_low_1 && img_angle_data[j] < angle_high_1) || (img_angle_data[j] > angle_low_2 && img_angle_data[j] < angle_high_2))
                    binary_img_data[j] = 255;
                else
                    binary_img_data[j] = 0;
            }
        }
    }

    // imshow("binary_img",binary_img);
}

void anglecompute(){

    /*Mat xsobel,ysobel,Imag,Iang;
    Sobel(learning_img,xsobel,CV_32F,1,0);
    Sobel(learning_img,ysobel,CV_32F,0,1);

    cartToPolar(xsobel,ysobel,Imag,img_angle,false);*/
    //multiply(Iang,180/M_PI,img_angle);

    int img_H = learning_img.rows - 1;
    int img_W = learning_img.cols - 1;
    int edgeX = 0;
    int edgeY = 0;
    double graAng = 0;

    for (uint16_t a = 1; a < img_H - 1; a++) {
        float* img_angle_data = img_angle.ptr<float>(a);
        for (uint16_t b = 1; b < img_W - 1; b++) {
            edgeX = learning_img.at<uchar>(a, b + 1) - learning_img.at<uchar>(a, b - 1);
            edgeY = learning_img.at<uchar>(a + 1, b) - learning_img.at<uchar>(a - 1, b);
            graAng = 0;

            if (edgeX > 0)
                graAng = (double)atan2(edgeY, edgeX)* 180 / M_PI;

            if (graAng < 0)
                graAng += 180;

            img_angle_data[b] = graAng;
        }
    }
}

void ROI_I_feature() {

    int img_H = learning_img.rows;
    int img_W = learning_img.cols;

    haar_img = Mat::zeros(img_H, img_W, CV_8UC1);

    vector<cv::Point2f> lanefeacture_r;
    vector<cv::Point2f> lanefeacture_l;

    int angle_low_1 = haarlike_angle[0] - 5;
    int angle_high_1 = haarlike_angle[0] + 5;
    int angle_low_2 = haarlike_angle[1] - 5;
    int angle_high_2 = haarlike_angle[1] + 5;

    int t = 0;

    for (uint16_t i = 0; i < img_H - 24; i++) {
        float* img_angle_data = img_angle.ptr<float>(i);
        uchar* edge_data = edge_img.ptr<uchar>(i);
        uchar* haar_img_data = haar_img.ptr<uchar>(i);
        for (uint16_t j = 0; j < img_W; j++) {
            if (edge_data[j]>200) {
                if ((img_angle_data[j] > angle_low_1 && img_angle_data[j] < angle_high_1) || (img_angle_data[j] > angle_low_2 && img_angle_data[j] < angle_high_2)) {
                    haar_img_data[j] = 255;
                    if (i > 40 && i<80) {
                        if (j > img_W / 2 && j < img_W * 3 / 4)
                            lanefeacture_r.push_back(cv::Point(j, i - 40));
                        else if (j < img_W / 2 && j>img_W / 4)
                            lanefeacture_l.push_back(cv::Point(j, i - 40));
                    }
                    else if (i >= 80) {
                        if (j > img_W / 2)
                            lanefeacture_r.push_back(cv::Point(j, i - 40));
                        else
                            lanefeacture_l.push_back(cv::Point(j, i - 40)); haar_img_data[j] = 255;
                    }
                }
                else
                    haar_img_data[j] = 0;
            }
        }
    }
    // imshow("haar_img", haar_img);

    //----------------RANSAC--------------------
    vector<cv::Point2f> samplepoint_r;
    vector<cv::Point2f> samplepoint_l;

    int number = 0;
    double dis, maxvalue = 0;
    t = 0;

    //----------------right---------------------
    while (t < 30) {
        samplepoint_r.clear();
        number = 0;
        samplepoint_r = getSample(lanefeacture_r.size() / 2, lanefeacture_r);
        fittingCurve(samplepoint_r, 2, p_r);

        //if (p_r[1] > 0.5) {
            double Denominator_r = sqrtf(1 + pow(p_r[1], 2));
            for (uint16_t r = 0; r < lanefeacture_r.size(); r++) {
                dis = abs(lanefeacture_r[r].x* p_r[1] + p_r[0] - lanefeacture_r[r].y) / Denominator_r;
                if (dis<5)
                    number++;
            }

            if (number > maxvalue) {
                maxvalue = number;
                parameter_r[0] = p_r[0];
                parameter_r[1] = p_r[1];
            }
        //}
        t++;
    }

    for (uint16_t s = 0; s < img_H - 40; s++) {
        double equation_x = (s - parameter_r[0]) / parameter_r[1];
        if (equation_x >= 0 && equation_x<img_W)
            line_r.push_back(cv::Point2f(equation_x, s));
    }

    maxvalue = 0;
    t = 0;
    //----------------left---------------------
    while (t < 30) {
        number = 0;
        samplepoint_l.clear();
        samplepoint_l = getSample(lanefeacture_l.size() / 2, lanefeacture_l);
        fittingCurve(samplepoint_l, 2, p_l);

        //if (p_l[1] < -0.5) {
            double Denominator_l = sqrtf(1 + pow(p_l[1], 2));
            for (uint16_t v = 0; v < lanefeacture_l.size(); v++) {
                dis = abs(lanefeacture_l[v].x* p_l[1] + p_l[0] - lanefeacture_l[v].y) / Denominator_l;
                if (dis<5)
                    number++;
            }

            if (number > maxvalue) {
                maxvalue = number;
                parameter_l[0] = p_l[0];
                parameter_l[1] = p_l[1];
            }
        //}
        t++;
    }
    for (uint16_t w = 0; w < img_H - 40; w++){
        double equation_x = (w - parameter_l[0]) / parameter_l[1];
        if (equation_x >= 0 && equation_x<img_W)
            line_l.push_back(cv::Point2f(equation_x, w));

    }


    direction_angle[0] = atan(parameter_r[1]) * 180 / M_PI;
    direction_angle[1] = atan(parameter_l[1]) * 180 / M_PI;

    if (direction_angle[0] < 0)
        direction_angle[0] += 180;

    if (direction_angle[1] < 0)
        direction_angle[1] += 180;

    // Mat haar_img_rgb;

    // Mat Roi_size = haar_img(cv::Rect(0,40,512,128));
    // cvtColor(Roi_size, haar_img_rgb, CV_GRAY2RGB);

    // if (!line_r.empty())
    //         drawline(line_r, &haar_img_rgb, Scalar(0, 255, 255));

    // if (!line_l.empty())
    //         drawline(line_l, &haar_img_rgb, Scalar(255, 0, 0));

    //  imshow("haar_img_rgb", haar_img_rgb);
    //imwrite("haar_img_rgb.png",haar_img_rgb);
    lanefeacture_r.clear();
    lanefeacture_l.clear();

        //line_l.clear();
        //line_r.clear();
}

void ROI_II_feature() {

    Mat ROI, uproi;

    vertex = find_intersection(line_r, line_l);

    int ROI_W = line_r[0].x - line_l[0].x;
    int ROI_H = -vertex.y;

    binary_img = Mat::zeros(frame_resize.rows, frame_resize.cols, haar_img.type());
    Mat Roi_size = binary_img(cv::Rect(0, 120, 512, 168));
    haar_img.copyTo(Roi_size);

    // imshow("binary_img", binary_img);

    if (ROI_W > 0 && ROI_H > 0 && line_l[0].x>0 && vertex.y + 160>0 && ROI_W<288 && ROI_H<512 ) {
        // if (ROI_W > 0 && ROI_H > 0) {
        ROI = binary_img(cv::Rect(line_l[0].x, vertex.y + 160, ROI_W, ROI_H)).clone();
        // ROI = binary_img(cv::Rect(0, 0, 288, 512)).clone();

        Mat ROI_II = Mat::zeros(ROI.rows, ROI.cols, ROI.type());

        ROI_II = searchfeaturepoint(ROI, ROI_II, direction_angle[0]);
        ROI_II = searchfeaturepoint(ROI, ROI_II, direction_angle[1]);

        // imshow("ROI_II", ROI_II);
        // imshow("ROI", ROI);
        //imwrite("ROI_II.png",ROI_II);
        //imwrite("ROI.png", ROI);
    }

    vector<cv::Point2f> rightlanepoint;
    vector<cv::Point2f> leftlanepoint;

    if (!rightpoint_roiII.empty()) {
        for (int j = line_r.size() - 1; j >= 0; j--) {
            rightlanepoint.push_back(cv::Point2f(line_r[j].y + 160, line_r[j].x));
        }
        for (uint16_t i = 0; i < rightpoint_roiII.size(); i++) {
            rightlanepoint.push_back(cv::Point2f(rightpoint_roiII[i].y + vertex.y + 160, rightpoint_roiII[i].x + line_l[0].x));
        }

        rightlanepoint = curvefit(rightlanepoint);
    }

    if (!leftpoint_roiII.empty()) {
        for (int j = line_l.size() - 1; j >= 0; j--) {
            leftlanepoint.push_back(cv::Point2f(line_l[j].y + 160, line_l[j].x));
        }

        for (uint16_t i = 0; i < leftpoint_roiII.size(); i++) {
            leftlanepoint.push_back(cv::Point2f(leftpoint_roiII[i].y + vertex.y + 160, leftpoint_roiII[i].x + line_l[0].x));
        }

            leftlanepoint = curvefit(leftlanepoint);
    }

    img_r = Mat::zeros(frame_resize.rows, frame_resize.cols, frame_resize.type());
    img_l = Mat::zeros(frame_resize.rows, frame_resize.cols, frame_resize.type());

    //img_ = Mat::zeros(frame_resize.rows, frame_resize.cols, frame_resize.type());
    if (!leftlanepoint.empty()) {
        //drawline(leftlanepoint, &img_, Scalar(255, 255, 255));
        drawline(leftlanepoint, &img_l, Scalar(255, 255, 255));
        //imwrite("img_.png",img_);
    }

    if (!rightlanepoint.empty()) {
       //drawline(rightlanepoint, &img_, Scalar(255, 255, 255));
        drawline(rightlanepoint, &img_r, Scalar(255, 255, 255));
        //imwrite("img_.png",img_);
    }


    rightpoint_roiII.clear();
    leftpoint_roiII.clear();
    rightlanepoint.clear();
    leftlanepoint.clear();

}

void houghtransfer() {

    Mat img_chl, img_chr, img_segmentl, img_segmentr;
    int n_segments = 9;

    cvtColor(img_l, img_chl, CV_BGR2GRAY);
    cvtColor(img_r, img_chr, CV_BGR2GRAY);

    vector<Vec4i> linesl[9];
    vector<Vec4i> linesr[9];
    vector<cv::Point2f> xi_l[9];
    vector<cv::Point2f> xi_r[9];
    int hough_threshold[9] = { 6, 8, 8, 8, 8, 12, 12, 16, 20 };
    int hough_minLineLength[9] = { 2, 4, 6, 8, 8, 12, 16, 20, 24 };
    int segments[9] = { 4, 6, 8, 10, 12, 18, 22, 28, 48 };

    multiplevp.clear();

    for (uint16_t i = 0; i<n_segments; i++)
    {
        img_segmentl = img_chl(cv::Rect(0, model_vi[i], 512, segments[i])).clone();
        img_segmentr = img_chr(cv::Rect(0, model_vi[i], 512, segments[i])).clone();

        //------------hough transfer--------------
        HoughLinesP(img_segmentl, linesl[i], 1, CV_PI / 180, hough_threshold[i], hough_minLineLength[i], 1);
        HoughLinesP(img_segmentr, linesr[i], 1, CV_PI / 180, hough_threshold[i], hough_minLineLength[i], 1);

        xi_l[i] = transformpoint(linesl[i], model_vi[i]);
        xi_r[i] = transformpoint(linesr[i], model_vi[i]);

        if (!xi_l[i].empty() && !xi_r[i].empty()) {
            VP uv = find_intersection(xi_l[i], xi_r[i]);
            multiplevp.push_back(cv::Point2f(uv.x, uv.y));
            bounary_l.push_back(xi_l[i][0]);
            bounary_r.push_back(xi_r[i][0]);
            //circle(img_, cv::Point(uv.x, uv.y), 2, Scalar(0, 255, 0), -1);
        }
    }
    //imwrite("vs.png",img_);
    float VHt = 0;
    float VH = 0;
    float Denominator, molecular;
    float ri, sigma = 0;

    //------------M-estimater---------------
    for (uint16_t j = 0; j < multiplevp.size(); j++) {
        ri = pow(VH - multiplevp[j].y, 2);
        sigma = pow(sqrtf(ri)*1.4826, 2);
        molecular += 2 * sigma*multiplevp[j].y / pow(sigma + ri, 2);
        Denominator += 2 * sigma / pow(sigma + ri, 2);
        VHt = molecular / Denominator;
        VH = VHt;
    }

    Vvp = VH;
    //line(img_, cv::Point(0, VH), cv::Point(frame.cols, VH), CV_RGB(255, 0, 0), 2, CV_AA);
    //imwrite("vsline.png",img_);
    // imshow("img_r", img_r);
    // imshow("img_l", img_l);
}

void estimateroadparameter() {

    vector<cv::Point2f> hyperbolas_l;
    vector<cv::Point2f> hyperbolas_r;
    vector<cv::Point2f> hyperbolas;
    double hyl = 0;//al
    double hyr = 0;//ar
    double hy[2] = { 0 };//Uh¡Bb
    uint16_t bounarysizel = bounary_l.size();
    uint16_t bounarysizer = bounary_r.size();

    for (uint16_t i = 0; i < bounarysizel; i++) {
        float hyx = bounary_l[i].y - Vvp;
        float hyyl = bounary_l[i].x*(bounary_l[i].y - Vvp);
        float hyyr = bounary_r[i].x*(bounary_r[i].y - Vvp);

        hyperbolas.push_back(cv::Point2f(hyx, hyyl));
        hyperbolas.push_back(cv::Point2f(hyx, hyyr));
        //circle(frame, cv::Point(bounary_l[i].x, bounary_l[i].y), 2, Scalar(0, 255, 0), -1);
        //circle(frame, cv::Point(bounary_r[i].x, bounary_r[i].y), 2, Scalar(255, 0, 0), -1);
    }

    fittingCurve(hyperbolas, 2, hy);

    float Uvp = hy[1];
    float b = hy[0] / 2;

    //circle(frame_resize, cv::Point(Uvp, Vvp), 2, Scalar(0, 0, 255), -1);

    for (uint16_t m = 0; m < bounarysizel; m++) {
        float paray = bounary_l[m].x - Uvp - b / (bounary_l[m].y - Vvp);
        float parax = bounary_l[m].y - Vvp;

        hyperbolas_l.push_back(cv::Point2f(parax, paray));
    }

    hyl = leastsquares(hyperbolas_l);

    for (uint16_t n = 0; n < bounarysizer; n++) {
        float paray = bounary_r[n].x - Uvp - b / (bounary_r[n].y - Vvp);
        float parax = bounary_r[n].y - Vvp;

        hyperbolas_r.push_back(cv::Point2f(parax, paray));
    }

    hyr = leastsquares(hyperbolas_r);

    hyperbolas_r.clear();
    hyperbolas_l.clear();

    x_parameter[0] = hyl;
    x_parameter[1] = hyr;
    x_parameter[2] = b;
    x_parameter[3] = Uvp;
    x_parameter[4] = Vvp;

    /*int img_H = frame_resize.rows - 1;

    for (int k = img_H; k > Vvp; k--) {
        float upi = Uvp + hyl * (k - Vvp) + b / (k - Vvp);
        hyperbolas_l.push_back(cv::Point2f(upi, k));

    }

    if(!hyperbolas_l.empty())
        drawline(hyperbolas_l, &frame_resize, Scalar(0, 100, 200));

    for (int o = img_H; o > Vvp; o--) {
        float upi = Uvp + hyr * (o - Vvp) + b / (o - Vvp);
        hyperbolas_r.push_back(cv::Point2f(upi, o));
    }

    if (!hyperbolas_r.empty())
        drawline(hyperbolas_r, &frame_resize, Scalar(200, 200, 50));*/
    line_l.clear();
    line_r.clear();
    hyperbolas_r.clear();
    hyperbolas_l.clear();
    bounary_l.clear();
    bounary_r.clear();

}

void Condensationtracking() {

    vector<cv::Point2f> hyperbolas_l;
    vector<cv::Point2f> hyperbolas_r;
    int img_W = frame_resize.cols;
    int img_H = frame_resize.rows;

    float predict_al, predict_ar, predict_b, predict_uh, predict_vh;
    float upiState_l[25][sampleNum] = { 0 };
    float upiState_r[25][sampleNum] = { 0 };
    float sumState_l[25] = { 0 };
    float sumState_r[25] = { 0 };
    float variance_l[25] = { 0 };
    float variance_r[25] = { 0 };

    int numberl[25] = { 0 };
    int numberr[25] = { 0 };

    float al, ar, b, uh, vh;

    if (predict_hy) {
        al = (float)condens->State[0];
        ar = (float)condens->State[1];
        b = (float)condens->State[2];
        uh = (float)condens->State[3];
        vh = (float)condens->State[4];
    }
    else {
        al = x_parameter[0];
        ar = x_parameter[1];
        b = x_parameter[2];
        uh = x_parameter[3];
        vh = x_parameter[4];

    }

    for (uint16_t j = 0; j<condens->SamplesNum; j++) {

        predict_al = (float)condens->flSamples[j][0];
        predict_ar = (float)condens->flSamples[j][1];
        predict_b = (float)condens->flSamples[j][2];
        predict_uh = (float)condens->flSamples[j][3];
        predict_vh = (float)condens->flSamples[j][4];
       //if (/*predict_al > -1.5 && predict_al<1.5 && predict_ar>-1.5 && predict_al<1.5 && predict_b>-800 && predict_b < 800 &&*/ predict_uh> (uh-15) && predict_uh < (uh+15) && predict_vh> (vh-15) && predict_vh < (vh+15)) {
            float upi_l = predict_uh + predict_al * (276 - predict_vh) + predict_b / (276 - predict_vh);
            float upi_r = predict_uh + predict_ar * (276 - predict_vh) + predict_b / (276 - predict_vh);
            if (upi_l < img_W / 2 && upi_r > img_W / 2) {
                for (uint16_t i = 0; i < 25; i++) {

                    upi_l = predict_uh + predict_al * (heighttest[i] - predict_vh) + predict_b / (heighttest[i] - predict_vh);
                    upi_r = predict_uh + predict_ar * (heighttest[i] - predict_vh) + predict_b / (heighttest[i] - predict_vh);
                    if (upi_l > 0 && upi_l < img_W * 3 / 4) {
                        sumState_l[i] += upi_l;
                        upiState_l[i][j] = upi_l;
                        numberl[i]++;
                    }
                    if (upi_r > img_W / 4 && upi_r < img_W) {
                        sumState_r[i] += upi_r;
                        upiState_r[i][j] = upi_r;
                        numberr[i]++;
                    }
                }
            }
      // }
    }

    for (uint16_t j = 0; j < 25; j++) {

        sumState_l[j] /= numberl[j];
        sumState_r[j] /= numberr[j];
        for (uint16_t i = 0; i < condens->SamplesNum; i++)
        {
            if (upiState_l[j][i] != 0)
                variance_l[j] += (upiState_l[j][i] - sumState_l[j])*(upiState_l[j][i] - sumState_l[j]);
            if (upiState_r[j][i] != 0)
                variance_r[j] += (upiState_r[j][i] - sumState_r[j])*(upiState_r[j][i] - sumState_r[j]);
        }
        variance_l[j] /= (numberl[j] - 1);
        variance_r[j] /= (numberr[j] - 1);
    }

    float measure_upi, upi, variance;
    uint16_t upi_start, upi_end;
    float measure_angle, upi_angle;
    float minthread = 1000;
    double weightsum = 0;
    Mat allangle = Mat::zeros(frame_resize.rows, frame_resize.cols, img_angle.type());
    Mat Roi_size = allangle(cv::Rect(0, 120, 512, 168));
    img_angle.copyTo(Roi_size);

    for (uint16_t i = 0; i<condens->SamplesNum; i++) {
        float prob = 0;
        float probr = 0;
        for (uint16_t j = 0; j < 25; j++) {
            uchar* binary_data = binary_img.ptr<uchar>(heighttest[j]);
            float* angle_data = allangle.ptr<float>(heighttest[j]);
            for (uint16_t o = 0; o < 2; o++) {
                if (o == 0) {
                    upi_start = upiState_l[j][i] - range[j];
                    upi_end = upiState_l[j][i] + range[j];
                    upi = upiState_l[j][i];
                    variance = variance_l[j];
                }
                else {
                    upi_start = upiState_r[j][i] - range[j];
                    upi_end = upiState_r[j][i] + range[j];
                    upi = upiState_r[j][i];
                    variance = variance_r[j];
                }
                minthread = 1000;
                for (uint16_t k = upi_start; k < upi_end; k++) {
                    if (k > 0 && k < img_W) {
                        uchar data_value = binary_data[k];
                        if (data_value > 100) {
                            float dis = abs(k - upi);
                            if (dis < minthread) {
                                minthread = dis;
                                measure_upi = k;
                            }
                        }
                    }
                }
                if (minthread != 1000) {
                    if (o == 0) {
                        measure_angle = angle_data[(int)measure_upi]*M_PI/180;
                        upi_angle = angle_data[(int)upi]*M_PI/180;
                        prob += (float)exp(-abs(measure_angle * upi_angle) - sqrt(pow(minthread, 2)) / (2 * variance));//
                    }
                    else {
                        measure_angle = angle_data[(int)measure_upi]*M_PI/180;
                        upi_angle = angle_data[(int)upi]*M_PI/180;
                        probr += (float)exp(-abs(measure_angle * upi_angle) - sqrt(pow(minthread, 2)) / (2 * variance));//
                    }
                }
            }
        }
        condens->flConfidence[i] = prob*prob*probr*probr;
        weightsum += prob*prob*probr*probr;
    }

    for (uint16_t i = 0; i<condens->SamplesNum; i++) {
        condens->flConfidence[i] /= weightsum;
    }

    cvConDensUpdateByTime(condens);

    int drawheight = 0;
    int trainheight = 0;
    int flag=0;

    for(uint16_t i = 0; i < img_H; i++){
        uchar* tarindata=binary_img.ptr<uchar>(i);
        for(uint16_t j = 0; j < img_W; j++){
            if(tarindata[j] > 10){
                trainheight = i;
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }

    if((vh + 10) > trainheight)
        drawheight = vh + 10;
    else
        drawheight = trainheight;

    //cvtColor(binary_img, binary_img, CV_GRAY2BGR);

    //Lineim=Mat::zeros(frame_resize.rows,frame_resize.cols,frame_resize.type());
    //img_1=Mat::zeros(frame_resize.rows,frame_resize.cols,frame_resize.type());
    Mat tracking_black(img_H,img_W*2, CV_8UC3, Scalar(0,0,0));
    Mat img;

    
    if (vh > 0) {
        for (int k = img_H-1; k > drawheight /*vh + 10*/; k--) {
            float upil = uh + al * (k - vh) + b / (k - vh);
            float upir = uh + ar * (k - vh) + b / (k - vh);
            hyperbolas_l.push_back(cv::Point2f(upil+img_W/2, k));
            hyperbolas_r.push_back(cv::Point2f(upir+img_W/2, k));
        }
        if (!hyperbolas_l.empty()) {
            //drawline(hyperbolas_l, &frame_resize, Scalar(0, 100, 255));
            drawline(hyperbolas_l, &frame_new, Scalar(0, 100, 255));
            drawline(hyperbolas_l, &tracking_black, Scalar(0, 0, 255));
            //drawline(hyperbolas_l, &binary_img, Scalar(0, 100, 255));
            //drawline(hyperbolas_l, &Lineim, Scalar(0, 100, 255));
            //drawline(hyperbolas_l, &img_1, Scalar(0, 100, 255));
        }

        if (!hyperbolas_r.empty()) {
            //drawline(hyperbolas_r, &frame_resize, Scalar(101, 0, 255));
            drawline(hyperbolas_r, &frame_new, Scalar(101, 0, 255));
            drawline(hyperbolas_r, &tracking_black, Scalar(0, 255, 0));
            //drawline(hyperbolas_r, &binary_img, Scalar(101, 0, 255));
            //drawline(hyperbolas_r, &Lineim, Scalar(101, 0, 255));
            //drawline(hyperbolas_r, &img_1, Scalar(0, 100, 255));
        }
        //imshow("binary_img", binary_img);
        //imshow("Lineim", Lineim);
        predict_hy = true;
    }else{
        predict_hy = false;
    }
    frame_black_widow = tracking_black;
    cvtColor(frame_black_widow,img,CV_BGR2GRAY);
    int val=0;
    int line1=0;
    int line2=0;
    int mid=0;

    for(int height=0;height<img.rows;height++)
    {
        for(int width=0;width<img.cols;width++)
        {
            val=img.at<uchar>(height,width);
            if(val==76){
                line1=width;
            }
            if(val==150){
                line2=width;
                break;
            }
        }
        for(int width=0;width<img.cols;width++)
        {

            if(width>line1&&width<line2){
                //if(height>car&&height<img.rows){
                //img.at<uchar>(height,width)=80;
                // frame_new.at<Vec3b>(height,width)[0]=255;
                // frame_new.at<Vec3b>(height,width)[1]=226;
                // frame_new.at<Vec3b>(height,width)[2]=198;
                tracking_black.at<Vec3b>(height,width)[0]=255;
                tracking_black.at<Vec3b>(height,width)[1]=226;
                tracking_black.at<Vec3b>(height,width)[2]=198;
                //}
            }
        }
    }

    for(int height=0;height<img.rows;height++)
    {
        for(int width=0;width<img.cols;width++)
        {
            val=img.at<uchar>(height,width);

            if(val==76){
                line1=width;
            }
            if(val==150){
                line2=width;
                break;
            }
        }
        if (line1 != 0 && line2 != 0)
        {
            mid = (line1 + line2) / 2;
            for (int width = 0; width < img.cols; width++)
            {
                if (width > mid-3&&width<mid+1) {
                    img.at<uchar>(height, width) = 200;
                    tracking_black.at<Vec3b>(height, width)[0] = 216;
                    tracking_black.at<Vec3b>(height, width)[1]=191;
                    tracking_black.at<Vec3b>(height, width)[2]=216;
                    frame_new.at<Vec3b>(height,width)[0]=216;
                    frame_new.at<Vec3b>(height,width)[1]=20;
                    frame_new.at<Vec3b>(height,width)[2]=220;
                }
            }
            line1=0;line2=0;mid=0;
            //printf("Line1= %d ,Line2 = %d, Mid = %d (height = %d)  \n", line1, line2,mid, height);
        }
    }
    float mid3=0;
    vision_pro::line_inform line_msg;

    for(int height=287;height<img.rows;height++)
    {
        for(int width=0;width<img.cols;width++)
        {
            val=img.at<uchar>(height,width);
            if(val==200){
                mid3=width;
            }
        }
        // printf("mid=%f\n",mid3);
        //if(mid3!=0){

            float offest1=mid3;
            float offest=((mid3-512)/256)*100;
            // printf("offest1=%f ,offest=%f  \n",offest1,offest);
       // }
       if(offest>1&&offest<100){
          line_msg.state=1;
       }
        if(offest<-1&&offest>-100){
          line_msg.state=2;
       }
       if(offest>-1&&offest<1){
          line_msg.state=0;
       }
    line_msg.offest=offest;
    }
    
    
    line_msg.line1_x.clear();
    line_msg.line1_y.clear();
    line_msg.line2_x.clear();
    line_msg.line2_y.clear();
    line_msg.mid_x.clear();
    line_msg.mid_y.clear();

    for(int height=200;height<img.rows;height=height+4)
    {
        for(int width=0;width<img.cols;width++)
        {
            val=img.at<uchar>(height,width);
            if(val==76){
                line1=width;
            }
            if(val==150){
                line2=width;
                break;
            }
            if(val==200){
                mid3=width;
            }
        }
        float jj=height *480/288;float ii=(line1-256) *640/512;float ii2=(line2-256) *640/512;float mm=(mid3-256) *640/512;
        
         float x1;float y_1; float x2; float y2;float mx;float my;

        // printf("Line1= %d ,Line2 = %d,line1_h = %d,Line1_real=%f,Line2_real=%f, line1_h_real = %f ,mm=%f  \n", line1,line2,height, ii,ii2, jj,mm);
        if( line1 !=0){
        settingmap(jj,ii,&x1,&y_1);
        }
        if( line2 !=0){
        settingmap(jj,ii2,&x2,&y2);
        }
        if( mid3 !=0){
        settingmap(jj,mm,&mx,&my);
        }
        if(x1==0&&y1==0){
            line_msg.state=3;
        }
        if(y_1-y2<80){
            y_1=y2-275;
            my=(y_1+y2)/2;
        }
        // if(y_1-y2>475){
        //     y_1=y2+275;
        //     my=(y_1+y2)/2;
        // }

        lane_lx.push_back(x1);
    
    
    line_msg.line1_x.push_back(x1);
    line_msg.line1_y.push_back(y_1);
    line_msg.line2_x.push_back(x2);
    line_msg.line2_y.push_back(y2);
    line_msg.mid_x.push_back(mx);
    line_msg.mid_y.push_back(my);
    line_msg.dot_num=line_msg.line1_x.size();
    
    
    }

    
    int world_x=120; int world_y=800;
    Mat ipm_img=Mat::zeros(cv::Size(world_x,world_y), CV_8U);
    Mat ipm_img2=Mat::zeros(cv::Size(world_x,world_y), CV_8UC3);
    int angle=2;  int height=15.7; int Kx=640; int Ky=480;
    for (uint16_t i = 0; i < ipm_img.rows; i++)
    {
        uchar* ipm_data = ipm_img.ptr<uchar>(i);
        for (uint16_t j = 10; j < ipm_img.cols; j++)
        {
            float xx = 1024 / 2 + Kx * (j - world_x/2) / ((world_y - i)*cos(angle*M_PI / 180) + height * sin(angle * M_PI / 180));
            float yy = 288 / 2 - Ky * ((world_y - i)*sin(angle * M_PI / 180) - height * cos(angle * M_PI / 180)) / ((world_y - i)*cos(angle * M_PI / 180) - height * sin(angle * M_PI / 180));
            if (xx > 0 && xx < 1024 && yy>0 && yy < 288)
            {
                ipm_data[j] = img.at<uchar>(yy, xx);
            }
         }
     }
     for (uint16_t i = 0; i < ipm_img.rows; i++)
    {
        uchar* ipm_data2 = ipm_img2.ptr<uchar>(i);
        for (uint16_t j = 0; j < ipm_img.cols; j++)
        {
            float xx = 512 / 2 + Kx * (j - ipm_img.cols/2) / ((ipm_img.rows - i)*cos(angle*M_PI / 180) + height * sin(angle * M_PI / 180));
            float yy = 288 / 2 - Ky * ((ipm_img.rows - i)*sin(angle * M_PI / 180) - height * cos(angle * M_PI / 180)) / ((ipm_img.rows - i)*cos(angle * M_PI / 180) - height * sin(angle * M_PI / 180));
            if (xx > 0 && xx < 512 && yy>0 && yy < 288)
            {
                ipm_data2[j * 3 + 0] = frame_resize.at<Vec3b>(yy, xx)[0];
                ipm_data2[j * 3 + 1] = frame_resize.at<Vec3b>(yy, xx)[1];
                ipm_data2[j * 3 + 2] = frame_resize.at<Vec3b>(yy, xx)[2];
            }
         }
     }
    cv::vector<cv::Point2f>mid2;
        
    cv::vector<cv::Point2f>mid_ang;
    double cur[3]={};
    for(int i=0;i<ipm_img.rows;i++){
        for(int j=0;j<ipm_img.cols;j++){
            val=ipm_img.at<uchar>(i,j);
            if(val==200){
                mid2.push_back(cv::Point2f(j,i));
            }
        }
    }
    for(int i=400;i<ipm_img.rows;i++){
        for(int j=0;j<ipm_img.cols;j++){
            val=ipm_img.at<uchar>(i,j);
            if(val==200){
                mid_ang.push_back(cv::Point2f(j,i));
            }
        }
    }
    line_msg.curve.clear();
    fittingCurve(mid2,3,cur);
    for(int j=10;j<70;j++){
    float Rcurve=pow(1+pow(2*cur[2]*j+cur[1],2),3/2)/abs(2*cur[2]);
    // if(__finite(Rcurve)){
    //     if(Rcurve>1000){
    //         printf("曲率=straight,j=%d \n",j);
    //     }
    //     else{
    //         printf("曲率=%f ,j=%d \n",Rcurve,j);
    //     }
    // }
    if(Rcurve>=1000){
    line_msg.curve.push_back(1000);
    }
    if(Rcurve<1000){
    line_msg.curve.push_back(Rcurve);
    }
    }
    

    double ang[2]={};
    fittingCurve(mid_ang,2,ang);
    double car_angle=atan(1/ang[1])*180/M_PI;
    // printf("車頭角=%f \n",car_angle);
    line_msg.head_angle=car_angle;
    if(car_angle=0){
        line_msg.state=4;
    }
    

    float mid_ang1;float mid_ang2;
    
    for(int width=0;width<img.cols;width++)
    {
      val=img.at<uchar>(200,width);
        if(val==200){
            mid_ang1=width;
        }
    }
    for(int width=0;width<img.cols;width++)
    {
      val=img.at<uchar>(287,width);
        if(val==200){
            mid_ang2=width;
        }
    }
    float mid_angx1;float mid_angy1;
    // float jj=height *480/288;float ii=(line1-256) *640/512;
    settingmap(200*480/288,(mid_ang1-256) *640/512,&mid_angx1,&mid_angy1);
    // printf("num1=%f,num=%f\n",mid_angx1,mid_angy1);
    float mid_angx2;float mid_angy2;
    settingmap(287*480/288,(mid_ang2-256) *640/512,&mid_angx2,&mid_angy2);
    // printf("num1=%f,num=%f\n",mid_angx2,mid_angy2);
    float ang_re=atan((mid_angy1-mid_angy2)/abs(mid_angx1-mid_angx2))*180/M_PI;
    // printf("ang_re=%f",ang_re);
    line_msg.angle_re=ang_re;
std::reverse(line_msg.line2_x.begin(),line_msg.line2_x.end());
std::reverse(line_msg.line2_y.begin(),line_msg.line2_y.end());
std::reverse(line_msg.line1_x.begin(),line_msg.line1_x.end());
std::reverse(line_msg.line1_y.begin(),line_msg.line1_y.end());
std::reverse(line_msg.mid_x.begin(),line_msg.mid_x.end());
std::reverse(line_msg.mid_y.begin(),line_msg.mid_y.end());
std::reverse(line_msg.curve.begin(),line_msg.curve.end());
    pub1.publish(line_msg);


    // imshow("black",tracking_black);
    // imshow("world_gray", ipm_img);
    // imshow("gray", img);
    // imshow("frame_world", ipm_img2);

    hyperbolas_r.clear();
    hyperbolas_l.clear();
}


VP find_intersection(std::vector<cv::Point2f> l1, std::vector<cv::Point2f> l2)
{
    double m1, m2, c1, c2;

    if (!l1.empty() && !l2.empty()) {
        m1 = ((double)l1[1].y - l1[0].y) / ((double)l1[1].x - l1[0].x);
        c1 = (double)l1[1].y - m1*l1[1].x;

        m2 = ((double)l2[1].y - l2[0].y) / ((double)l2[1].x - l2[0].x);
        c2 = (double)l2[1].y - m2*l2[1].x;

        VP van;

        double yi, xi;
        if (m1 != 0 || m2 != 0)
        {
            xi = (c1 - c2) / (m2 - m1);
            yi = m2*xi + c2;
        }
        else
        {
            yi = 10000;
        }

        if (int(xi)<-200 || int(xi)>1200)
            yi = 10000;

        van.x = (float)xi;
        van.y = (float)yi;
        return van;
    }
}

cv::Mat searchfeaturepoint(cv::Mat ROI, cv::Mat ROI_II, float ang) {

    int ROI_H = ROI.rows;
    int ROI_W = ROI.cols;
    int flag = 0;
    float min_l = 16;
    float min_s = 6;
    float angle_th = ang;
    float dis, angle, minx, miny;

    if (ang >= 26 && ang < 80) {
        for (int i = ROI_H - 1; i >= 0; i--) {
            uchar* ROI_data = ROI.ptr<uchar>(i);
            uchar* ROI_II_data = ROI_II.ptr<uchar>(i);
            min_l = 16;
            min_s = 6;
            flag = 0;
            for (int j = ROI_W - 1; j >= 0; j--) {
                uchar ROI_value = ROI_data[j];
                if (rightpoint_roiII.empty()) {
                    if (ROI_value > 50 && j >= ROI_W * 2 / 3) {
                        rightpoint_roiII.push_back(cv::Point2f(j, i));
                        ROI_II_data[j] = 255;
                        break;
                    }
                }
                else {
                    if (ROI_value > 50) {
                        if (i > ROI_H / 2) {
                            dis = getdistance(rightpoint_roiII[rightpoint_roiII.size() - 1], cv::Point2f(j, i));
                            if (dis<min_l) {
                                min_l = dis;
                                minx = j;
                                miny = i;
                            }
                        }
                        else {
                            dis = getdistance(rightpoint_roiII[rightpoint_roiII.size() - 1], cv::Point2f(j, i));
                            if (dis<min_s) {
                                min_s = dis;
                                minx = j;
                                miny = i;
                            }
                        }
                    }
                }
                if (j == 0 && (min_l != 16 || min_s != 6)) {
                    rightpoint_roiII.push_back(cv::Point(minx, miny));
                    ROI_II_data[(int)minx] = 255;
                    if (minx < 6 || (miny < ROI_H / 2 && minx > ROI_W - 6)) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
                break;
        }
    }
    else {
        for (int i = ROI_H - 1; i >= 0; i--) {
            uchar* ROI_data = ROI.ptr<uchar>(i);
            uchar* ROI_II_data = ROI_II.ptr<uchar>(i);
            min_l = 16;
            min_s = 6;
            flag = 0;
            for (int j = 0; j < ROI_W; j++) {
                uchar ROI_value = ROI_data[j];
                if (leftpoint_roiII.empty()) {
                    if (ROI_value > 50 && j < ROI_W / 3) {
                        leftpoint_roiII.push_back(cv::Point2f(j, i));
                        ROI_II_data[j] = 255;
                        break;
                    }
                }
                else {
                    if (ROI_value > 50) {
                        if (i > ROI_H / 2) {
                            angle = getangle(leftpoint_roiII[leftpoint_roiII.size() - 1], cv::Point2f(j, i));
                            if (angle<angle_th + 50 && angle>angle_th - 50) {
                                dis = getdistance(leftpoint_roiII[leftpoint_roiII.size() - 1], cv::Point2f(j, i));
                                if (dis < min_l) {
                                    min_l = dis;
                                    minx = j;
                                    miny = i;
                                }
                            }
                        }
                        else {
                            dis = getdistance(leftpoint_roiII[leftpoint_roiII.size() - 1], cv::Point2f(j, i));
                            if (dis < min_s) {
                                min_s = dis;
                                minx = j;
                                miny = i;
                            }
                        }
                    }
                }
                if (j == ROI_W - 1 && (min_l != 16 || min_s != 6)) {
                    angle_th = getangle(leftpoint_roiII[leftpoint_roiII.size() - 1], cv::Point2f(minx, miny));
                    leftpoint_roiII.push_back(cv::Point(minx, miny));
                    ROI_II_data[(int)minx] = 255;
                    if ((miny < ROI_H / 2 && minx < 3) || minx > ROI_W - 6) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
                break;
        }
    }

    return ROI_II;

}

std::vector<cv::Point2f> curvefit(std::vector<cv::Point2f> point) {



    vector<cv::Point2f> test;
    vector<cv::Point2f> hytest;
    vector<cv::Point2f> sam;
    int Img_H = frame_resize.rows;
    int Img_W = frame_resize.cols;
    double parameter[8] = { 0 };

    fittingCurve(point, 8, parameter);

    test.clear();

    for (uint16_t s = 120; s < Img_H; s++) {

        double equation_x = parameter[7] * pow(s, 7) + parameter[6] * pow(s, 6) + parameter[5] * pow(s, 5) + parameter[4] * pow(s, 4) + parameter[3] * pow(s, 3) + parameter[2] * pow(s, 2) + parameter[1] * s + parameter[0];//parameter_r[3] * pow(s, 3) +

        if (equation_x > Img_W - 4 || equation_x < 4)
            break;

        test.push_back(cv::Point2f(equation_x, s));
    }

    /*if (!test.empty())
    drawline(test, &frame, Scalar(0, 255, 255));*/

    return test;

}

std::vector<cv::Point2f> transformpoint(std::vector<cv::Vec4i> vec, int vi) {

    float divx, tansita, dx;
    uint16_t img_W = frame_resize.cols;
    vector<cv::Point2f> xi;

    if (!vec.empty()) {
        for (uint16_t i = 0; i < vec.size(); i++) {
            if (vec[i][3] > vec[i][1]) {
                if (vec[i][1] == 0) {
                    xi.push_back(cv::Point2f(vec[i][0], vi));
                    xi.push_back(cv::Point2f(vec[i][2], vec[i][3] + vi));
                    break;
                }
                else {
                    dx = (float)(vec[i][0] - vec[i][2]);
                    tansita = (float)(vec[i][1] - vec[i][3]) / dx;
                    divx = (-vec[i][1]) / tansita;

                    if ((vec[i][0] + divx) > img_W || (vec[i][0] + divx) < 0)
                        continue;

                    xi.push_back(cv::Point2f(vec[i][0] + divx, vi));
                    xi.push_back(cv::Point2f(vec[i][2], vec[i][3] + vi));

                    break;
                }
            }
            else {
                if (vec[i][3] == 0) {
                    xi.push_back(cv::Point2f(vec[i][2], vi));
                    xi.push_back(cv::Point2f(vec[i][0], vec[i][1] + vi));

                    break;
                }
                else {
                    dx = (float)(vec[i][2] - vec[i][0]);
                    tansita = (float)(vec[i][3] - vec[i][1]) / dx;
                    divx = (-vec[i][3]) / tansita;
                    if ((vec[i][2] + divx) > img_W || (vec[i][2] + divx) < 0)
                        continue;

                    xi.push_back(cv::Point2f(vec[i][2] + divx, vi));
                    xi.push_back(cv::Point2f(vec[i][0], vec[i][1] + vi));

                    break;
                }
            }
        }
    }
    return xi;
}

double leastsquares(vector<Point2f> hya) {

    double y, x, a;

    for (uint16_t i = 0; i < hya.size(); i++) {
        y += 2 * hya[i].x*hya[i].y;
        x += pow(hya[i].x, 2);
    }

    a = y / (2 * x);

    return a;
}

void drawline(vector<cv::Point2f> point, Mat* img, Scalar color) {

    for (uint16_t itt_ = 0; itt_ < point.size() - 1; itt_++){
        line(*img, point[itt_], point[itt_ + 1], color, 2, CV_AA);
    }
}



bool fittingCurve(vector<Point2f> &vec, int times, double *p)
{
    double *py = new double[vec.size()];
    double *px = new double[times*vec.size()];
    int ff = 0;

    for (vector<Point2f>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        py[ff] = (*itr).y;
        int j = 0;
        while (j<times)
        {
            px[times*ff + j] = pow(((*itr).x), double(j));
            j++;
        }
        ff++;
    }

    Mat X = Mat((int)vec.size(), times, CV_64FC1, px);
    Mat X_T;
    transpose(X, X_T);

    Mat Y = Mat((int)vec.size(), 1, CV_64FC1, py);
    Mat para = ((X_T*X).inv())*X_T*Y;

    for (uint16_t s = 0; s<times; s++) {
        p[s] = para.at<double>(s);
    }

    delete[] px;
    delete[] py;

    return true;
}

std::vector<cv::Point2f> getSample(int n, vector<cv::Point2f> ps)
{
    vector<cv::Point2f> ret;
    vector<int> order;

    if (ps.size() != 0)
    {
        count_ransac++;
        srand(count_ransac);

        for (uint16_t i = 0; i < n; i++) {
            float r = rand() % ps.size();
            order.push_back(r);
        }

        sort(order.begin(), order.end());

        for (uint16_t ii = 0; ii < n; ii++){
            ret.push_back(ps[order[ii]]);
        }
    }

    return ret;
}

float getangle(cv::Point pointO, cv::Point pointA)
{
    float angle;
    float y_ = pointO.y - pointA.y;
    float x_ = pointO.x - pointA.x;

    if (x_ != 0) {
        angle = atan2(y_, x_);//y / x
        angle = angle / CV_PI * 180;
        if (angle < 0) {
            angle = angle + 180;
        }
    }
    return angle;
}

float getdistance(cv::Point2f a, cv::Point2f b) {

    float dis = pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
    dis = sqrtf(dis);

    return dis;

}

Status LoadGraph(string graph_file_name, Session** session) {
 GraphDef graph_def;
 TF_RETURN_IF_ERROR(
     ReadBinaryProto(Env::Default(), graph_file_name, &graph_def));
 TF_RETURN_IF_ERROR(NewSession(SessionOptions(), session));
 TF_RETURN_IF_ERROR((*session)->Create(graph_def));
 return Status::OK();
}

