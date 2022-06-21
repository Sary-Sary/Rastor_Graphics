#include "PGM_File.h"

PGM_File::PGM_File(int width, int height, std::vector <Greyscale> file, int max_value) : File(width, height), file(file), max_value(max_value) {}

void PGM_File::grayscale() {

	return;

}

void PGM_File::monochrome() {

	for (int i = 0; i < width * height; i++) file[i].to_monochrome();
	return;

}

void PGM_File::negative() {

	for (int i = 0; i < width * height; i++) file[i].to_negative();
	return;

}

std::vector<Greyscale> PGM_File::rotate_left() {

	std::vector<Greyscale> rotated_matrix = file;

	for (int i = 0; i < width; i++) {

		for (int j = 0; j < height; j++) {

			rotated_matrix[j * width - i - 1 + height] = file[i*width + j];

		}

	}

	return rotated_matrix;

}

void rotate_right() {




}

void PGM_File::rotate(std::string direction) {

	if (direction == "left") {

		file = rotate_left();
		std::swap(height, width);
		return;
	}

	if (direction == "right") {

		file = rotate_right();
		std::swap(height, width);
		return;

	}

	std::cout << "Invalid direction\n";
	return;

}

std::string PGM_File::get_file_extension() { return ".pgm"; }