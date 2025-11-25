#include "GameManager.h"

// コンストラクタ
GameManager::GameManager() {
	// シーンのインスタンスを生成して配列に格納
	sceneArr_[SCENE::TITLE] = std::make_unique<TitleScene>();
	sceneArr_[SCENE::GAME_STAGE] = std::make_unique<StageScene>();
	sceneArr_[SCENE::CLEAR] = std::make_unique<ClearScene>();

	// 初期シーンの設定
	currentSceneNo_ = SCENE::TITLE;
}

// デストラクタ
GameManager::~GameManager() {}

// ゲームループを回す関数
int GameManager::Run() {
	while (true) {
		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			// シーンが変わったら初期化を呼び出す
			sceneArr_[currentSceneNo_]->Init();
		}

		/// 更新処理
		sceneArr_[currentSceneNo_]->Update(); // シーンごとの更新処理

		/// 描画処理
		sceneArr_[currentSceneNo_]->Draw();   // シーンごとの描画処理

		// 終了条件(クリアシーンのとき)
		if (currentSceneNo_ == SCENE::CLEAR) {
			break; // ループを抜けて終了
		}
	}
	return 0;
}
