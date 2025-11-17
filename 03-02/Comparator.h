#pragma once
#include <iostream>

// クラステンプレートの定義
template <typename Type1, typename Type2>
class Comparator {
public:
	// 比較対象の2つの値
	Type1 value1_;
	Type2 value2_;

	// コンストラクタ
	Comparator(Type1 v1, Type2 v2) : value1_(v1), value2_(v2) {}
	// 二つの値の小さい方を返すメンバ関数
	auto Min() const -> decltype(value1_ < value2_ ? value1_ : value2_) {
		if (value1_ < value2_) {
			return value1_;
		} else {
			return value2_;
		}
	}
};

template <typename Type>
class Comparator<Type, Type> {
public:
	// 比較対象の2つの値
	Type value1_;
	Type value2_;

	// コンストラクタ
	Comparator(Type v1, Type v2) : value1_(v1), value2_(v2) {}
	// 二つの値の小さい方を返すメンバ関数
	Type Min() const {
		if (value1_ < value2_) {
			return value1_;
		} else {
			return value2_;
		}
	}
};

