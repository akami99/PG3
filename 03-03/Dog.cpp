#include "Dog.h"

Dog::Dog(std::string name) {
	name_ = name;
	std::cout << name_ << "が現れました。" << std::endl;
}

Dog::~Dog() {
}

void Dog::move() {
	std::cout << name_ << "が移動しました。" << std::endl;
}
