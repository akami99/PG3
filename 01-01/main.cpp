
#include <iostream>
#include <list>
using namespace std;

int main() {
	// 1970,2019,2022年の山手線の駅名をそれぞれlistに格納

	int count = 0; // カウンタを初期化

	// 初めは1970年の駅名
	list<const char*> JY = {
		 "Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		 "Uguisudani","Nippori","Tabata","Komagome",
		 "Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba",
		 "Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
		 "Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
		 "Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
	};

	printf_s("1970年の山手線の駅\n");
	for (auto itr = JY.begin(); itr != JY.end(); ++itr) {
		// 番号を表示(JY1:)
		cout << " JY" << ++count << ":";

		// 要素を表示
		cout << *itr << "\n";
	}

	// 2019年の駅名に更新(NipporiとTabataの間に追加)
	for (auto itr = JY.begin(); itr != JY.end(); ++itr) {
		if (*itr == "Tabata") {
			JY.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}

	count = 0; // カウンタをリセット

	printf_s("\n2019年の山手線の駅\n");
	for (auto itr = JY.begin(); itr != JY.end(); ++itr) {
		// 番号を表示(JY1:)
		cout << " JY" << ++count << ":";

		// 要素を表示
		cout << *itr << "\n";
	}

	// 2022年の駅名に更新(ShinagawaとTamachiの間に追加)
	for (auto itr = JY.begin(); itr != JY.end(); ++itr) {
		if (*itr == "Tamachi") {
			JY.insert(itr, "Takanawa Gateway");
			++itr;
		}
	}

	count = 0; // カウンタをリセット

	printf_s("\n2022年の山手線の駅\n");
	for (auto itr = JY.begin(); itr != JY.end(); ++itr) {
		// 番号を表示(JY1:)
		cout << " JY" << ++count << ":";

		// 要素を表示
		cout << *itr << "\n";
	}

	return 0;
}