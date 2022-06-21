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

void PGM_File::rotate(std::string direction) {



}

std::string PGM_File::get_file_extension() { return ".pgm"; }