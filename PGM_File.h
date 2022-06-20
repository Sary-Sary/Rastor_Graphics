#pragma once
#include "Greyscale.h"
#include "File.h"

class PGM_File : protected File {

	std::vector <Greyscale> file;
	int max_value;

public:

	void grayscale();
	void monochrome();
	void negative();
	void rotate(std::string direction);

};

