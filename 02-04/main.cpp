#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <functional>

// 実行関数
void Reveal(std::function<void()> fn);

int main() {
	// サイコロの出目とユーザーの予想を格納する変数
	int roll = 0;
	int guess = 0;

	// 乱数の種を初期化
	srand((unsigned int)time(NULL));

	printf("偶数なら正解\n");
	guess = 0;

	// サイコロを振る
	roll = rand() % 6 + 1; // 1～6のランダムな数値を生成

	// サイコロの出目を表示する関数(ラムダ式)
	auto showResult = [&]() {
		printf("出目は %d でした。\n", roll);

		int oddOrEven = -1;
		oddOrEven = roll % 2;
		if (oddOrEven == guess) {
			printf("正解\n");
		} else {
			printf("不正解\n");
		}
		};


	Reveal(showResult);

	return 0;
}

void Reveal(std::function<void()> fn) {
	//Sleep(delayMs);

	fn();
}