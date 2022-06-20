#pragma once
#include "File.h"

class PBM_File : protected File
{
	std::vector <int> file;

public:

	void grayscale();
	void monochrome();
	void negative();
	void rotate(std::string direction);

};

