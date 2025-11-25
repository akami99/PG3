#include "TitleScene.h"
#include <iostream>

// 初期化処理
void TitleScene::Init() {
	// シーン番号をタイトルに設定
	sceneNo = SCENE::TITLE;
}

// 更新処理
void TitleScene::Update() {
	// ユーザー入力をシミュレート（ここではEnterキーが押されたと仮定）
	bool isEnterPressed = false;

	// Consoleからの入力をチェック
	std::cout << "タイトルシーン: Enterキーを押してステージへ進む...\n";
	char inputChar;
	std::cin.get(inputChar);
	if (inputChar == '\n') {
		isEnterPressed = true;
	}

	if (isEnterPressed) {
		// シーン番号をステージシーンに変更
		sceneNo = SCENE::GAME_STAGE;
	}
}

// 描画処理
void TitleScene::Draw() {
	// タイトルシーンの描画処理をここに記述
	std::cout << "タイトルシーンを描画...\n";
}