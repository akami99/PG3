#pragma once
#include "Animal.h"

class Human : public Animal {
	public:
	// コンストラクタ
	Human(std::string name);
	// デストラクタ
	virtual ~Human();
	// 移動する
	virtual void move() override;
};

