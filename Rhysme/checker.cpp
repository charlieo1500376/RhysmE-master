#include "checker.h"

std::map < std::string, Image* > loaded_image;

Image* Checker_LoadImage(std::string image_source) {
	if (loaded_image[image_source] != NULL) {
		//std::cout << "skipped load image\n";
		return loaded_image[image_source];
	}
	else {
		loaded_image[image_source] = IMG_Load(image_source.c_str());
		//std::cout << "loaded image" << image_source << "\n";
		return loaded_image[image_source];
	}
}

Image* Checker_LoadImage(const char* image_source) {
	if (loaded_image[std::string(image_source)] != NULL) {
		//std::cout << "skipped load image\n";
		return loaded_image[std::string(image_source)];
	}
	else {
		loaded_image[std::string(image_source)] = IMG_Load(image_source);
		//std::cout << "loaded image" << image_source << "\n";
		return loaded_image[std::string(image_source)];
	}
}