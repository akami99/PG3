#include "ClearScene.h"
#include <iostream>

// 初期化処理
void ClearScene::Init() {
	// シーン番号をクリアシーンに設定
	sceneNo = SCENE::CLEAR;
}

// 更新処理
void ClearScene::Update() {
	// クリアシーンの更新処理をここに記述
}

// 描画処理
void ClearScene::Draw() {
	// クリアシーンの描画処理をここに記述
	std::cout << "クリアシーンを描画...\n";
}
