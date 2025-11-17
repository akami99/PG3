#pragma once
#include "Animal.h"

class Dog : public Animal {
	public:
	// コンストラクタ
	Dog(std::string name);
	// デストラクタ
	virtual ~Dog();
	// 移動する
	virtual void move() override;
};

