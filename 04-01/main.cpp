#include <Novice.h>

#include "GameManager.h"

const char kWindowTitle[] = "LE2B_01_アカミネ_レン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	GameManager gameManager;

	gameManager.Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
