#include "Animal.h"

Animal::Animal() {
	name_ = "動物";
}

Animal::~Animal() {
	std::cout << name_ << "が倒れました。" << std::endl;
}

void Animal::move() {
}
