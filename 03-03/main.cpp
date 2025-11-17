#include "Human.h"
#include "Dog.h"

int main() {
	Animal* animals[3];

	// 生成フェーズ
	for (int i = 0; i < 3; ++i) {
		std::string name;
		if (i == 0) {
			name = "守衛";
			animals[i] = new Human(name);
		} else {
			name = "番犬その" + std::to_string(i);
			animals[i] = new Dog(name);
		}
	}

	// 移動フェーズ
	for (int i = 0; i < 3; ++i) {
		animals[i]->move();
	}

	// 破棄フェーズ
	for (int i = 0; i < 3; ++i) {
		delete animals[i];
	}

	return 0;
}