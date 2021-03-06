#include "RGB.h"

RGB::RGB() {

	red = 255;
	green = 255;
	blue = 255;

}

RGB::RGB(unsigned red_, unsigned green_, unsigned blue_, unsigned max_value_) {

	red = red_*255/max_value_;
	green = green_ * 255 / max_value_;
	blue = blue_ * 255 / max_value_;

}

void RGB::to_monochrome() {

	to_greyscale();
	red = (red > 0) ? 1 : 0;
	green = red;
	blue = red;
	return;

}

void RGB::to_greyscale() {

	int c = 0.299*red + 0.587*green + 0.114*blue;
	red = c;
	green = c;
	blue = c;

	return;
}

void RGB::to_negative() {

	red = 255 - red;
	green = 255 - green;
	blue = 255 - blue;

	return;

}