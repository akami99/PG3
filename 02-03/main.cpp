#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

// 遅延実行関数
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess);

// 判定関数
void ShowResult(int roll, int userGuess);

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

	DelayReveal(ShowResult, 3000, roll, userGuess);

	return 0;
}

void DelayReveal(void(*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	Sleep(delayMs);

	fn(roll, userGuess);
}

void ShowResult(int roll, int userGuess) {
	printf("出目は %d でした。\n", roll);

	int oddOrEven = -1;
	oddOrEven = roll % 2;
	if (oddOrEven == userGuess) {
		printf("正解");
	} else {
		printf("不正解");
	}
}
