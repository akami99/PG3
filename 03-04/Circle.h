#pragma once
#include "IShape.h"

class Circle : public IShape {
private:
	float radius_; // 半径
	float area_;   // 面積

public:
	// コンストラクタ
	Circle(float radius) : radius_(radius), area_(0.0) {}
	// 面積を計算する
	void Size() override;
	// 面積を表示する
	void Draw() override;
};

