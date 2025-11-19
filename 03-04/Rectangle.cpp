#include "Rectangle.h"

#include <iostream>

void Rectangle::Size() {
	area_ = width_ * height_;
}

void Rectangle::Draw() {
	std::cout << "\nRectangle: width = " << width_ << ", height = " << height_ << ", area = " << area_ << std::endl;
}
