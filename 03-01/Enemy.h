#pragma once
#include <iostream>

enum class State {
	Approach,
	Attack,
	Retreat,
	Count
};

class Enemy {
private:
	State currentState = State::Approach; // 現在の状態

public:
	void Update();

private:
	// 接近関数
	void Approach();

	// 攻撃関数
	void Attack();

	// 離脱関数
	void Retreat();

	// メンバ関数のポインタのテーブル
	static void (Enemy::* actionTable[static_cast<size_t>(State::Count)])();
};

