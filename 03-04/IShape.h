#pragma once

// 形状インターフェース
class IShape {
public:
	// 仮想デストラクタ
	virtual ~IShape() = default;
	// 面積を計算する純粋仮想関数
	virtual void Size() = 0;
	// 面積を表示する純粋仮想関数
	virtual void Draw() = 0;
};

