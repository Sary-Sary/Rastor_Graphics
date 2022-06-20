#include "PPM_File.h"

PPM_File::PPM_File(int width, int height, std::vector <RGB> file) : File(width, height), file(file) {}

void PPM_File::grayscale() {

	for (int i = 0; i < width * height; i++) {

		file[i].to_greyscale();

	}

}

void PPM_File::monochrome() {

	for (int i = 0; i < width * height; i++) {

		file[i].to_monochrome();

	}

}

void PPM_File::negative() {

	for (int i = 0; i < width * height; i++) {

		file[i].to_negative();

	}

}

void PPM_File::rotate(std::string direction) {



}