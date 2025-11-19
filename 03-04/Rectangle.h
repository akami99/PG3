#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
	float width_;  // 幅
	float height_; // 高さ
	float area_;   // 面積

public:
	// コンストラクタ
	Rectangle(float width, float height) : width_(width), height_(height), area_(0.0) {}
	// 面積を計算する
	void Size() override;
	// 面積を表示する
	void Draw() override;
};

