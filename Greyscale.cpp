#include "Greyscale.h"

Greyscale::Greyscale() {
	


}

Greyscale::Greyscale(int value_, int max_value_) {


}

void Greyscale::to_monochrome() {

	if (value != 0) value = 255;
	return;

}

void Greyscale::to_negative() {

	value = 255 - value;
	return;

}