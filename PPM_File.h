#pragma once
#include <vector>
#include "RGB.h"
#include "File.h"

class PPM_File : public File {

	std::vector <RGB> file;
	int max_value;

public:

	PPM_File(int width, int height, std::vector <RGB> file, int max_value);
	void grayscale();
	void monochrome();
	void negative();
	void rotate(std::string direction);
	std::string get_file_extension();

};

