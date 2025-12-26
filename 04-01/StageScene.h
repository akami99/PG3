#pragma once
#include "IScene.h"

class StageScene : public IScene {
private:
  // 簡易的なシューティングゲーム用の変数(敵を倒すのみ)

  // プレイヤー
  float playerPosX_ = 640.0f;
  float playerPosY_ = 600.0f;
  const float playerSpeed_ = 5.0f;
  const float playerRadius_ = 20.0f;
  // 敵
  float enemyPosX_ = 540.0f;
  float enemyPosY_ = 100.0f;
  const float enemySpeed_ = 2.0f;
  const float enemyRadius_ = 20.0f;
  //戻るの用の符号
  float angle_ = 1.0f;
  // 弾
  float shotPosX_ = 0.0f;
  float shotPosY_ = 0.0f;
  const float shotSpeed_ = 10.0f;
  const float shotRadius_ = 5.0f;
  // 状態管理
  bool isCleared_ = false;
  bool isEnemyAlive_ = true;
  bool isShot_ = false;

public:
  // 初期化処理
  void Init() override;
  // 更新処理
  void Update() override;
  // 描画処理
  void Draw() override;
};
