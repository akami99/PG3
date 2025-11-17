#include "Human.h"

Human::Human(std::string name) {
	name_ = name;
	std::cout << name_ << "が現れました。" << std::endl;
}

Human::~Human() {
}

void Human::move() {
	std::cout << name_ << "が移動しました。" << std::endl;
}
