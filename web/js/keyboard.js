    var key = [];

    function keysPressed(e) {
        var vec3;
	console.log(e.keyCode);
        key[e.keyCode] = true;
        if (key[80]) {
            topicROSGameState(0);
        }
        if (key[79]) {
            topicROSGameState(1);
        }
    switch(e.keyCode){
	case 87:
		pubMessage(1);
	break
	case 65:
		pubMessage(3);
	break
	case 68:
		pubMessage(4);
	break
	case 83:
		pubMessage(2);
	break
	case 81:
		pubMessage(5);
	break
	case 70:
		pubwheel(0);
	break
	case 71:
		pubwheel(1);
	break
	case 72:
		pubwheel(2);
	break
	case 74:
		pubwheel(3);
	break
	case 75:
		pubwheel(4);
	break
	case 89:
		pubspeed(1);
	break
	case 78:
		pubspeed(0);
	break

   }


    }
    function keyuped(e) {
console.log(e.keyCode);
        key[e.keyCode] = false;
    }

function keyboardcontrol(start) {
        if (start == true) {
            window.addEventListener("keydown", keysPressed, false);
            window.addEventListener("keyup", keyuped, false);
            
        } else {
            document.onkeydown = 0;
            document.onkeyup = 0;
	    window.removeEventListener("keydown", keysPressed, false);
            window.removeEventListener("keyup", keyuped, false);
        }
    }
