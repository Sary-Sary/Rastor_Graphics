#pragma once
struct RGB
{
	unsigned red; //to 255
	unsigned green; //to 255
	unsigned blue; //to 255

	RGB();
	RGB(unsigned red_, unsigned green_, unsigned blue_, unsigned max_value_);
	void to_monochrome();
	void to_greyscale();
	void to_negative();

};

