#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2/opencv.hpp>

cv::Mat lei_img(const char* FILE) {
	std::ifstream ifs;

	ifs.open(FILE, std::ios::in | std::ios::binary);

	if (!ifs) {
	}

	uint32_t WIDTH, HEIGHT;
	ifs.read((char*)&WIDTH, 4);
	ifs.read((char*)&HEIGHT, 4);
	HEIGHT = HEIGHT / 2 * 3;

	std::cout << "WIDTH " << WIDTH << std::endl;
	std::cout << "HEIGHT " << HEIGHT << std::endl;

	cv::Mat img(cv::Size(WIDTH, HEIGHT), CV_8UC3);

	int i = 0;
	while (!ifs.eof()) {
		uint16_t word;
		ifs.read((char*)&word, 2);
		uint8_t r = (word & 0b1111100000000000) >> 11 << 3;
		uint8_t g = (word & 0b0000011111100000) >> 5 << 2;
		uint8_t b = (word & 0b0000000000011111) >> 0 << 3;
		// https://minus9d.hatenablog.com/entry/20130126/1359194404
		img.data[(i / WIDTH) * img.step + (i % WIDTH) * img.elemSize() + 0] = b;
		img.data[(i / WIDTH) * img.step + (i % WIDTH) * img.elemSize() + 1] = g;
		img.data[(i / WIDTH) * img.step + (i % WIDTH) * img.elemSize() + 2] = r;
		i++;
	}
	ifs.close();

	return  img;
}
