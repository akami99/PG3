#include "Enemy.h"

void Enemy::Update() {
	// 現在の状態に対応するインデックスを取得
	int index = static_cast<size_t>(currentState);
	
	// メンバ関数ポインタを取得して関数を呼び出す
	(this->*actionTable[index])();
}

void Enemy::Approach() {
	std::cout << "敵が接近\n" << std::endl;
	currentState = State::Attack;
}

void Enemy::Attack() {
	std::cout << "敵が攻撃\n" << std::endl;
	currentState = State::Retreat;
}

void Enemy::Retreat() {
	std::cout << "敵が離脱\n" << std::endl;
	currentState = State::Approach;
}

void (Enemy::* Enemy::actionTable[])() = {
	&Enemy::Approach,
	&Enemy::Attack,
	&Enemy::Retreat
};
