#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib,"opencv_world453d.lib")
#else
#pragma comment(lib,"opencv_world453.lib")
#endif

cv::Mat lei_img(const char*);

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		std::cout << argv[0] << " " << "[FILE]" << std::endl;
		return 1;
	}

	const char* infile = argv[1];

	const cv::Mat img = lei_img(infile);

	cv::imshow("", img);

	cv::waitKey(0);

	return 0;
}