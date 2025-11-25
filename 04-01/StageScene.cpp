#include "StageScene.h"
#include <iostream>

// 初期化処理
void StageScene::Init() {
	// シーン番号をステージシーンに設定
	sceneNo = SCENE::GAME_STAGE;
}

// 更新処理
void StageScene::Update() {
	// ゲームのステージ更新処理をここに記述
	// ステージクリアの条件をシミュレート（ここでは常にクリアと仮定）
	bool isStageCleared = false;

	// Consoleからの入力をチェック
	std::cout << "ステージシーン: Enterキーを押してクリアシーンへ進む...\n";
	char inputChar;
	std::cin.get(inputChar);
	if (inputChar == '\n') {
		isStageCleared = true;
	}
	if (isStageCleared) {
		// シーン番号をクリアシーンに変更
		sceneNo = SCENE::CLEAR;
	}
}

// 描画処理
void StageScene::Draw() {
	// ステージシーンの描画処理をここに記述
	std::cout << "ステージシーンを描画...\n";
}
