#pragma once
#include "File.h"

class PBM_File : public File
{
	std::vector <int> file;

public:

	PBM_File();
	PBM_File(int width, int height, std::vector <int> file);

	void grayscale();
	void monochrome();
	void negative();
	void rotate(std::string direction);

};

