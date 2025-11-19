#include "Circle.h"

#include <iostream>
#include <cmath>
#include <numbers>

void Circle::Size() {
	area_ = std::numbers::pi_v<float> * radius_ * radius_;
}

void Circle::Draw() {
	std::cout << "\nCircle: radius = " << radius_ << ", area = " << area_ << std::endl;
}
