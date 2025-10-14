#include <iostream>

template <typename Type>
Type Min(Type a, Type b) {
	return static_cast<Type>(a < b ? a : b);
}


int main() {
	int a1 = 3;
	int a2 = 7;
	float b1 = 5.6f;
	float b2 = 4.3f;
	double c1 = 7.5;
	double c2 = 6.4;

	int minA = 0;
	float minB = 0;
	double minC = 0;

	std::cout << "a1: " << a1 << std::endl;
	std::cout << "a2: " << a2 << std::endl;
	std::cout << "\nb1: " << b1 << std::endl;
	std::cout << "b2: " << b2 << std::endl;
	std::cout << "\nc1: " << c1 << std::endl;
	std::cout << "c2: " << c2 << std::endl;

	minA = Min<int>(a1, a2);
	minB = Min<float>(b1, b2);
	minC = Min<double>(c1, c2);

	std::cout << "\nMinA: " << minA << std::endl;
	std::cout << "MinB: " << minB << std::endl;
	std::cout << "MinC: " << minC << std::endl;

	return 0;
}