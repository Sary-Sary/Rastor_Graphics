#pragma once
struct Greyscale
{
	int value; //to 255

	Greyscale();
	Greyscale(int value_, int max_value_);
	void to_monochrome();
	void to_negative();

};

