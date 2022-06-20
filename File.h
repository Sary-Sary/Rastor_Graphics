#pragma once
#include <string>
#include <vector>

class File
{

protected:
	int width;
	int height;

public:

	File(int width, int height) : width (width), height(height) {}
	virtual void grayscale() = 0;
	virtual void monochrome() = 0;
	virtual void negative() = 0;
	virtual void rotate(std::string direction) = 0;

};

