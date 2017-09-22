#include "CImg.h"
#include<iostream>

void exampleImage() {
	cimg_library::CImg<unsigned char> *image;
	cimg_library::CImgDisplay *imageDisplay;

	int width = 720;
	int height = 720;

	image = new cimg_library::CImg<unsigned char>(width, height, 1, 3, 0);
	imageDisplay = new cimg_library::CImgDisplay(*image, "Cam_001");
	imageDisplay->show();

	int y = 360;
	for (int x = 0; x < width; x++) {
		(*image)(x, y, 0, 0) = 250;
		(*image)(x, y, 0, 1) = 250;
		(*image)(x, y, 0, 2) = 250;
	}
	image->display(*imageDisplay);
	while (!imageDisplay->is_closed()) {
		if (imageDisplay->is_keyT()) {
			std::cout << "T key pressed;"<<std::endl;
		}
		if (imageDisplay->button()) {
			std::cout << "y mouse coord is " << imageDisplay->mouse_y() << std::endl;
		}
		imageDisplay->wait();
	}
}

int main() {
	exampleImage();
}

