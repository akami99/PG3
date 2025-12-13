
#include <cstring> // strcmp用
#include <iostream>
#include <list>

int main() {
  // 1970,2019,2022年の山手線の駅名をそれぞれlistに格納

  int count = 0; // カウンタを初期化

  // 初めは1970年の駅名
  std::list<const char *> JY = {
      "Tokyo",        "Kanda",     "Akihabara", "Okachimachi",  "Ueno",
      "Uguisudani",   "Nippori",   "Tabata",    "Komagome",     "Sugamo",
      "Otsuka",       "Ikebukuro", "Mejiro",    "Takadanobaba", "Shin-Okubo",
      "Shinjuku",     "Yoyogi",    "Harajuku",  "Shibuya",      "Ebisu",
      "Meguro",       "Gotanda",   "Osaki",     "Shinagawa",    "Tamachi",
      "Hamamatsucho", "Shimbashi", "Yurakucho"};

  std::cout << "1970年の山手線の駅\n";
  for (const auto &station : JY) {
    // 番号を表示(JY1:)
    std::cout << " JY" << ++count << ":";

    // 要素を表示
    std::cout << station << "\n";
  }

  // 2019年の駅名に更新(NipporiとTabataの間に追加)
  for (auto itr = JY.begin(); itr != JY.end(); ++itr) {
    if (std::strcmp(*itr, "Tabata") == 0) {
      // 戻り値を使用しないことを明示的に示す
      [[maybe_unused]] auto new_itr = JY.insert(itr, "Nishi-Nippori");
      break;
    }
  }

  count = 0; // カウンタをリセット

  std::cout << "\n2019年の山手線の駅\n";
  for (const auto &station : JY) {
    // 番号を表示(JY1:)
    std::cout << " JY" << ++count << ":";

    // 要素を表示
    std::cout << station << "\n";
  }

  // 2022年の駅名に更新(ShinagawaとTamachiの間に追加)
  for (auto itr = JY.begin(); itr != JY.end(); ++itr) {
    if (std::strcmp(*itr, "Tamachi") == 0) {
      // 戻り値を使用しないことを明示的に示す
      [[maybe_unused]] auto new_itr = JY.insert(itr, "Takanawa Gateway");
      break;
    }
  }

  count = 0; // カウンタをリセット

  std::cout << "\n2022年の山手線の駅\n";
  for (const auto &station : JY) {
    // 番号を表示(JY1:)
    std::cout << " JY" << ++count << ":";

    // 要素を表示
    std::cout << station << "\n";
  }

  return 0;
}