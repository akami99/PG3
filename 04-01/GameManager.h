#pragma once
#include <memory> // std::unique_ptrを使うためのヘッダファイル
#include "IScene.h" // ISceneクラスの定義をインクルード
#include "TitleScene.h" // 各シーンを読み込む
#include "StageScene.h"
#include "ClearScene.h"

class GameManager {
private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	// どのステージを呼び出すかを管理する変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_;    // 前のシーン

public:
	GameManager(); // コンストラクタ
	~GameManager();// デストラクタ
	
	int Run(); // この関数でゲームループを呼び出す
};

