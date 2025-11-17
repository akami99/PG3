#include "Comparator.h"

int main() {
	int intNum1 = 123;
	int intNum2 = 321;
	float floatNum1 = 65.4f;
	float floatNum2 = 45.6f;
	double doubleNum1 = 7.89;
	double doubleNum2 = 9.87;

	// Comparatorクラスのインスタンスを生成
	Comparator<int, int> comp0(intNum1, intNum2);            // int型同士を比較
	Comparator<float, float> comp1(floatNum1, floatNum2);    // float型同士を比較
	Comparator<double, double> comp2(doubleNum1, doubleNum2);// double型同士を比較
	Comparator<int, float> comp3(intNum1, floatNum1);        // int型とfloat型を比較
	Comparator<int, double> comp4(intNum1, doubleNum1);      // int型とdouble型を比較
	Comparator<float, double> comp5(floatNum1, doubleNum1);  // float型とdouble型を比較

	// 各比較結果を表示
	std::cout << "int Min(" << intNum1 << ", " << intNum2 << "): " << comp0.Min() << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "float Min(" << floatNum1 << ", " << floatNum2 << "): " << comp1.Min() << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "double Min(" << doubleNum1 << ", " << doubleNum2 << "): " << comp2.Min() << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "int and float Min(" << intNum1 << ", " << floatNum1 << "): " << comp3.Min() << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "int and double Min(" << intNum1 << ", " << doubleNum1 << "): " << comp4.Min() << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "float and double Min(" << floatNum1 << ", " << doubleNum1 << "): " << comp5.Min() << std::endl;

	return 0;
}