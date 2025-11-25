#include "IScene.h"

// タイトルシーンで初期化
int IScene::sceneNo = SCENE::TITLE;

// 仮想デストラクタの定義(純粋仮想関数化していないので定義できる)
IScene::~IScene() {}

// シーン番号のゲッター
int IScene::GetSceneNo() {
	return sceneNo;
}
