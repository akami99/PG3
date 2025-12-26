#include "InputManager.h"

InputManager *InputManager::instance_ = nullptr;

// シングルトンパターンのインスタンスを初期化
InputManager *InputManager::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new InputManager();
    }
    return instance_;
}

// 初期化関数
void InputManager::Initialize() {
    // 初期状態では全てのキーが離されているとみなす
    memset(keys, 0, sizeof(keys));
    memset(preKeys, 0, sizeof(preKeys));
}

// 終了関数
void InputManager::Finalize() {
    // シングルトンパターンのインスタンスを削除
    if (instance_ != nullptr) {
        delete instance_;
        instance_ = nullptr;
    }
}

// キー入力を更新する関数
void InputManager::Update() {
    // 前回のキー入力を保存
    memcpy(preKeys, keys, 256);
    // 現在のキー入力を取得
    Novice::GetHitKeyStateAll(keys);
}
// キーが押されたかを判定する関数
bool InputManager::IsKeyPressed(int keyCode) {
    return keys[keyCode] != 0 && preKeys[keyCode] == 0;
}
// キーが離されたかを判定する関数
bool InputManager::IsKeyReleased(int keyCode) {
    return keys[keyCode] == 0 && preKeys[keyCode] != 0;
};
// キーが押されているかを判定する関数
bool InputManager::IsKeyHeld(int keyCode) { return keys[keyCode] != 0; };