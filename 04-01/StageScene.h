#pragma once
#include "IScene.h"

class StageScene : public IScene {
public:
	// 初期化処理
	void Init() override;
	// 更新処理
	void Update() override;
	// 描画処理
	void Draw() override;
};

