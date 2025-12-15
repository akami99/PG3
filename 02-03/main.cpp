#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

// 遅延実行関数
void DelayReveal(void (*fn)(int, int), int roll, int userGuess);

// 判定関数
void ShowResult(int roll, int userGuess);

int main() {
	// サイコロの出目とユーザーの予想を格納する変数
	int roll = 0;
	int guess = 0;

    // 乱数の種を初期化
	srand((unsigned int)time(NULL)); 

	printf("奇数なら正解\n");
	guess = 1;

	// サイコロを振る
	roll = rand() % 6 + 1; // 1～6のランダムな数値を生成

	DelayReveal(ShowResult, roll, guess);

	return 0;
}

void DelayReveal(void(*fn)(int, int), int roll, int userGuess) {
	//Sleep(delayMs);

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
