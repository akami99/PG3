#include "GameManager.h"
#include "Novice.h"
#include "InputManager.h"

// コンストラクタ
GameManager::GameManager() {
    InputManager::GetInstance()->Initialize();

  // シーンのインスタンスを生成して配列に格納
  sceneArr_[TITLE] = std::make_unique<TitleScene>();
  sceneArr_[GAME_STAGE] = std::make_unique<StageScene>();
  sceneArr_[CLEAR] = std::make_unique<ClearScene>();

  // 初期シーンの設定
  prevSceneNo_ = TITLE;
  currentSceneNo_ = TITLE;
}

// デストラクタ
GameManager::~GameManager() {}

// ゲームループを回す関数
int GameManager::Run() {
  while (Novice::ProcessMessage() == 0) {
    Novice::BeginFrame();
    // 入力の更新
    InputManager::GetInstance()->Update();

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
    sceneArr_[currentSceneNo_]->Draw(); // シーンごとの描画処理

    Novice::EndFrame();

    // 終了条件
    if (InputManager::GetInstance()->IsKeyPressed(DIK_ESCAPE)) {
      break; // ループを抜けて終了
    }
  }
  return 0;
}
