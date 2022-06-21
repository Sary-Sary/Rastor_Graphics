#pragma once
#include "Greyscale.h"
#include "File.h"

class PGM_File : public File {

	std::vector <Greyscale> file;
	int max_value;

public:

	PGM_File(int width, int height, std::vector <Greyscale> file, int max_value);
	void grayscale();
	void monochrome();
	void negative();
	void rotate(std::string direction);
	std::string get_file_extension();
};

