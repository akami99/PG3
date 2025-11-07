#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <functional>

// 遅延実行関数
void DelayReveal(std::function<void()> fn, unsigned int delayMs);

int main() {
	// サイコロの出目とユーザーの予想を格納する変数
	int roll = 0;
	int userGuess = 0;

	// 乱数の種を初期化
	srand((unsigned int)time(NULL));

	// ユーザーに偶数か奇数かを予想させる
	printf("偶数なら0、奇数なら1を入力してください: ");
	scanf_s("%d", &userGuess);

	// サイコロを振る
	roll = rand() % 6 + 1; // 1～6のランダムな数値を生成

	// サイコロの出目を表示する関数(ラムダ式)
	auto showResult = [&]() {
		printf("出目は %d でした。\n", roll);

		int oddOrEven = -1;
		oddOrEven = roll % 2;
		if (oddOrEven == userGuess) {
			printf("正解\n");
		} else {
			printf("不正解\n");
		}
		};


	DelayReveal(showResult, 3000);

	return 0;
}

void DelayReveal(std::function<void()> fn, unsigned int delayMs) {
	Sleep(delayMs);

	fn();
}