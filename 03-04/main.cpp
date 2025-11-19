#include "Circle.h"
#include "Rectangle.h"

int main() {
	IShape* shapes[2];
	// 生成フェーズ
	shapes[0] = new Circle(5.0f);        // 半径5.0の円
	shapes[1] = new Rectangle(4.0f, 6.0f); // 幅4.0、高さ6.0の長方形
	// 面積計算フェーズ
	for (int i = 0; i < 2; ++i) {
		shapes[i]->Size();
	}
	// 描画フェーズ
	for (int i = 0; i < 2; ++i) {
		shapes[i]->Draw();
	}
	// 破棄フェーズ
	for (int i = 0; i < 2; ++i) {
		delete shapes[i];
	}

	return 0;
}