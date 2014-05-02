#ifdef MOVIERECORDER_UNIT_TEST
#include "MovieRecorder.h"
#include <iostream>
#include <opencv2/opencv.hpp>

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
	cv::Size frame_size = cv::Size(
			capture.get(CV_CAP_PROP_FRAME_WIDTH),
			capture.get(CV_CAP_PROP_FRAME_HEIGHT));

	cv::VideoWriter writer("capture.avi", CV_FOURCC('M','J','P','G'), 
			30.0, frame_size);
	cv::Mat frame;
	cv::namedWindow("from camera",1);
	while(true){
		capture >> frame;
		writer << frame;
		cv::imshow("from camera", frame);
		if(cv::waitKey(1) == 27/*ascii ESC keycode*/){
			break;
		}
	}

    return 0;
}

#endif
