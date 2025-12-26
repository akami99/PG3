#include "StageScene.h"
#include "InputManager.h"
#include "Novice.h"

// 初期化処理
void StageScene::Init() {
  // シーン番号をステージシーンに設定
  sceneNo = SCENE::GAME_STAGE;

  // プレイヤー
  playerPosX_ = 640.0f;
  playerPosY_ = 600.0f;
  // 敵
  enemyPosX_ = 540.0f;
  enemyPosY_ = 100.0f;
  // 戻るの用の符号
  angle_ = 1.0f;
  // 弾
  shotPosX_ = 0.0f;
  shotPosY_ = 0.0f;
  // 状態管理
  isCleared_ = false;
  isEnemyAlive_ = true;
  isShot_ = false;
}

// 更新処理
void StageScene::Update() {
  // playerの移動
  if (InputManager::GetInstance()->IsKeyHeld(DIK_A)) {
    playerPosX_ -= 5.0f;
  }
  if (InputManager::GetInstance()->IsKeyHeld(DIK_D)) {
    playerPosX_ += 5.0f;
  }
  // 弾を発射
  if (!isShot_ && InputManager::GetInstance()->IsKeyPressed(DIK_SPACE)) {
    isShot_ = true;
    shotPosX_ = playerPosX_;
    shotPosY_ = playerPosY_;
  }
  // 弾の移動
  if (isShot_) {
    shotPosY_ -= 10.0f;
    // 弾が画面外に出たらリセット
    if (shotPosY_ < 0.0f) {
      isShot_ = false;
    }
  }

  // 敵の移動
  if (isEnemyAlive_) {
    enemyPosX_ += enemySpeed_ * angle_;
    // 画面端で跳ね返る
    if (enemyPosX_ < enemyRadius_ || enemyPosX_ > 1280.0f - enemyRadius_) {
      angle_ = angle_ * -1.0f;
    }
  }

  // 弾と敵の当たり判定
  if (isEnemyAlive_ && shotPosX_ > enemyPosX_ - 20.0f &&
      shotPosX_ < enemyPosX_ + 20.0f && shotPosY_ > enemyPosY_ - 20.0f &&
      shotPosY_ < enemyPosY_ + 20.0f) {
    isEnemyAlive_ = false;
    isShot_ = false;
    isCleared_ = true; // ステージクリア
  }

  // シーン番号をクリアシーンに変更
  if (isCleared_) {
    sceneNo = SCENE::CLEAR;
  }
}

// 描画処理
void StageScene::Draw() {
  // ステージシーンの描画処理をここに記述
  Novice::ScreenPrintf(100, 100, "Stage Scene");
  Novice::ScreenPrintf(100, 120, "Press Space");

  // 弾の描画
  if (isShot_) {
    Novice::DrawBox(static_cast<int>(shotPosX_ - 5.0f),
                    static_cast<int>(shotPosY_ - 10.0f), 10, 20, 0.0f,
                    0xFFFF00FF, kFillModeSolid);
  }

  // プレイヤーの描画
  Novice::DrawBox(static_cast<int>(playerPosX_ - playerRadius_),
                  static_cast<int>(playerPosY_ - playerRadius_),
                  static_cast<int>(playerRadius_ * 2),
                  static_cast<int>(playerRadius_ * 2), 0.0f, WHITE,
                  kFillModeSolid);

  // 敵の描画
  if (isEnemyAlive_) {
    Novice::DrawBox(static_cast<int>(enemyPosX_ - enemyRadius_),
                    static_cast<int>(enemyPosY_ - enemyRadius_),
                    static_cast<int>(enemyRadius_ * 2),
                    static_cast<int>(enemyRadius_ * 2), 0.0f, RED,
                    kFillModeSolid);
  }
}
