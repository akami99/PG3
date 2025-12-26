#include "TitleScene.h"
#include "InputManager.h"
#include "Novice.h"

// 初期化処理
void TitleScene::Init() {
  // シーン番号をタイトルに設定
  sceneNo = SCENE::TITLE;
}

// 更新処理
void TitleScene::Update() {
  // シーン番号をステージシーンに変更
  if (InputManager::GetInstance()->IsKeyPressed(DIK_SPACE)) {
    sceneNo = SCENE::GAME_STAGE;
  }
}

// 描画処理
void TitleScene::Draw() {
  Novice::ScreenPrintf(100, 100, "TiTle Scene");
  Novice::ScreenPrintf(100, 120, "Press Space");
}