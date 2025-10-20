#include <iostream>

enum WageType {
	GENERAL = 0,
	RECURSIVE = 1
};

// 賃金計算関数
int CalculateWage(int hoursWage, int hoursWorked, WageType wageType) {
	switch (wageType) {
	case GENERAL:
		return hoursWorked * hoursWage;

		break;
	case RECURSIVE:

		// 再帰の停止条件
		if (hoursWorked <= 0) {
			// 最後に再帰で呼ばれた際には時給が無いので0を返す
			return 0;
		}
		// 現在の賃金
		int currentWage = hoursWage;

		// 次の時間の時給を計算
		int nextHoursWage = hoursWage * 2 - 50;
		if (nextHoursWage < 0) {
			nextHoursWage = 0; // 時給がマイナスにならないようにする
		}

		// 次の時間の賃金を再帰的に計算
		return currentWage + CalculateWage(nextHoursWage, hoursWorked - 1, wageType);

		break;
	}

	if (false) {
		return 0; // コンパイラの警告を防ぐためのダミーコード
	}
}

int main() {

	// 賃金形態
	int generalWage = 1226; // 一般的な賃金（円/時間）
	int recursiveWage = 100; // 再帰的な賃金（初めの1時間）

	// 賃金取得変数
	int getGeneralWage = 0;
	int getRecursiveWage = 0;

	int hoursWorked = 0; // 労働時間（時間）

	while (true) {
		hoursWorked += 1;
		std::cout << "労働時間: " << hoursWorked << " 時間" << std::endl;

		getGeneralWage = CalculateWage(generalWage, hoursWorked, GENERAL);
		getRecursiveWage = CalculateWage(recursiveWage, hoursWorked, RECURSIVE);

		std::cout << "  一般的な賃金: " << getGeneralWage << " 円" << std::endl;
		std::cout << "  再帰的な賃金: " << getRecursiveWage << " 円\n" << std::endl;

		if (getGeneralWage < getRecursiveWage) {
			std::cout << "  => 再帰的な賃金の方が高い！" << std::endl;
			break;
		}
	}
	return 0;
}