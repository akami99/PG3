#pragma once
#include "Novice.h"

class InputManager {
private:
  // シングルトンパターンのインスタンス
  static InputManager *instance_;

  // キー入力結果を受け取る箱
  char keys[256] = {0};
  char preKeys[256] = {0};

public:
  // シングルトンパターンのインスタンスを取得する関数
  static InputManager *GetInstance();

  // 初期化関数
  void Initialize();
  // 終了関数
  void Finalize();
  // キー入力を更新する関数
  void Update();
  // キーが押されたかを判定する関数
  bool IsKeyPressed(int keyCode);
  // キーが離されたかを判定する関数
  bool IsKeyReleased(int keyCode);
  // キーが押されているかを判定する関数
  bool IsKeyHeld(int keyCode);

private:
  InputManager() = default;
  ~InputManager() = default;
  InputManager(InputManager &) = delete;
  InputManager &operator=(InputManager &) = delete;
};
