#pragma once

// シーン名を列挙型(Enum)で定義
enum SCENE {
	TITLE,      // タイトルシーン
	GAME_STAGE,      // ステージシーン
	CLEAR,      // クリアシーン
	SCENE_MAX   // シーン数の最大値
};

// シーン内での処理を行う基底クラス
class IScene {
protected:
	// シーン番号を管理する実数
	static int sceneNo;

public:
	// 継承先で実装される関数(純粋仮想関数)
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// 仮想デストラクタを用意しないと警告される
	virtual ~IScene();

	// シーン番号のゲッター
	int GetSceneNo();
};
