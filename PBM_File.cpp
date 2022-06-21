#include "PBM_File.h"

void PBM_File::grayscale() {

	return;

}

void PBM_File::monochrome() {

	return;

}

void PBM_File::negative() {

	for (int i = 0; i < width * height; i++) {

		file[i] = (file[i == 0]) ? 1 : 0;

	}

	return;

}

void PBM_File::rotate(std::string direction) {

	//         right      left
	//1 2 3     3 6        4 1
	//4 5 6 ->  2 5    ||  5 2
	//		    1 4        3 6
	//1 2 3 4 5 6 -> 3 6 2 5 1 4 || 4 1 5 2 3 6

	//std::swap(width, height);



}

std::string PBM_File::get_file_extension() { return ".pbm"; }