#ifdef EYETRACKER_UNIT_TEST
#include "EyeTracker.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace et;

int main(int argc, char* argv[])
{
	cv::VideoCapture capture(0);
	if(!capture.isOpened()){
		std::cout << 
			"camera open error! "
			"please check if camera is connected correctly." 
		<< std::endl;
		std::exit(0);
	}

	cv::Mat frame;
	cv::namedWindow("from camera",1);
	while(true){
		capture >> frame;
		cv::imshow("from camera", frame);
		if(cv::waitKey(1) == 27/*ascii ESC keycode*/){
			break;
		}
	}

    return 0;
}

#endif
