#pragma once
#include <vector>
#include "RGB.h"
#include "File.h"

class PPM_File : public File {

	std::vector <RGB> file;

public:

	PPM_File(int width, int height, std::vector <RGB> file);
	void grayscale();
	void monochrome();
	void negative();
	void rotate(std::string direction);

};

