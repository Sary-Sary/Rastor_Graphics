#include "PGM_File.h"

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