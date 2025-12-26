#include "ClearScene.h"
#include "InputManager.h"
#include "Novice.h"

// 初期化処理
void ClearScene::Init() {
  // シーン番号をクリアシーンに設定
  sceneNo = SCENE::CLEAR;
}

// 更新処理
void ClearScene::Update() {
  // クリアシーンの更新処理をここに記述
  if (InputManager::GetInstance()->IsKeyPressed(DIK_SPACE)) {
    sceneNo = SCENE::TITLE;
  }
}

// 描画処理
void ClearScene::Draw() {
  // クリアシーンの描画処理をここに記述
  Novice::ScreenPrintf(100, 100, "Clear Scene");
  Novice::ScreenPrintf(100, 120, "Press Space");
}
