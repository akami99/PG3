#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>

using namespace std;

// ソート用の構造体
struct SortableString {
	int num1;
	int num2;
	string text;
};

// 比較関数
bool compareSortableStrings(const SortableString& a, const SortableString& b) {
	if (a.num1 != b.num1) {
		return a.num1 < b.num1; // num1で昇順にソート
	}
	return a.num2 < b.num2; // num1が同じ場合はnum2で昇順にソート
}

int main() {
	// ファイルを開く
	ifstream idFile("PG3_2025_01_02.txt");

	// ファイルが開けなかった場合
	if (!idFile.is_open()) {
		cerr << "error: not open file" << endl;
		return 1;
	}

	// IDを格納
	vector<SortableString> ids;
	string line;

	// 正規表現パターンを定義
	const regex pattern("^k(\\d+)g(\\d+)@g\\.neec\\.ac\\.jp$");
	smatch matchs;


	// ファイルの終端まで読み込む
	if (getline(idFile, line)) {
		// カンマで分割してIDを取得
		stringstream ss(line);
		string idToken;

		while (getline(ss, idToken, ',')) {

			// 個別のIDに対して正規表現にマッチするか確認
			if (regex_match(idToken, matchs, pattern)) {
				// matchs[0]は全体マッチ、
				// matchs[1]は最初の数字、
				// matchs[2]は2番目の数字

				// 文字列を整数に変換して格納
				int num1 = stoi(matchs[1].str());
				int num2 = stoi(matchs[2].str());

				ids.push_back({ num1, num2, idToken });
			} else {
				cerr << "error: not match pattern in line: " << idToken << endl;
			}
		}
	} else {
		cerr << "error: not read from file or file is empty" << endl;
	}

	idFile.close();

	// ソート
	sort(ids.begin(), ids.end(), compareSortableStrings);

	// ソートされたIDを格納
	vector<string> sortIds;
	for (const auto& id : ids) {
		sortIds.push_back(id.text);
	}

	// IDを表示
	cout << "\n--- Sorted IDs ---" << endl;
	int lineNumber = 1;
	for (const auto& id : sortIds) {
		cout << lineNumber++ << ": " << id << endl;
	}
	return 0;
}