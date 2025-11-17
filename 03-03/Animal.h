#pragma once
#include <iostream>
#include <string>

class Animal {
public:
	//コンストラクタ
	Animal();
	//デストラクタ
	virtual ~Animal();
	//移動する
	virtual void move();

protected:
	//動物の名前
	std::string name_;
};

