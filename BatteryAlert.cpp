// BatteryAlert.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <conio.h>

#pragma comment(lib, "winmm.lib" )

#define ESC 27


SYSTEM_POWER_STATUS sps;

void firstcheck(void) {
	GetSystemPowerStatus(&sps);															//システムの電源状態を取得
	if (sps.BatteryFlag == 128)															//バッテリーが存在しないとき
	{
		printf("バッテリーが検出されませんでした．自動で終了します．\n Error Code 1.");
		Sleep(5000);																	//5秒待機する
		exit(1);																		//コード1を返し、終了
	}
	else if (sps.BatteryFlag == 256)													//バッテリーが不明な状態のとき
	{
		printf("バッテリーが不明な状態です．自動で終了します．\nError Code 2.");
		Sleep(5000);																	//5秒待機する
		exit(2);																		//コード2を返し、終了
	}
	else
	{
		printf("監視を開始しました．\n監視を終了するにはESCキーを押してください．\n\n");
	}
}

void docheck(int b)
{
	PlaySound(_TEXT("Sounds\\Battery.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);
	if (b == 10)
		PlaySound(_TEXT("Sounds\\10.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 20)
		PlaySound(_TEXT("Sounds\\20.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 30)
		PlaySound(_TEXT("Sounds\\30.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 40)
		PlaySound(_TEXT("Sounds\\40.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 50)
		PlaySound(_TEXT("Sounds\\50.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 60)
		PlaySound(_TEXT("Sounds\\60.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 70)
		PlaySound(_TEXT("Sounds\\70.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 80)
		PlaySound(_TEXT("Sounds\\80.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 90)
		PlaySound(_TEXT("Sounds\\90.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (b == 100)
		PlaySound(_TEXT("Sounds\\100.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);

	if (sps.ACLineStatus == AC_LINE_ONLINE)
		PlaySound(_TEXT("Sounds\\on.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);
	if (sps.ACLineStatus == AC_LINE_OFFLINE)
		PlaySound(_TEXT("Sounds\\off.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);
}


int main(void)
{
	int b, c = 0;

	printf("バッテリー残量監視ツールv1.0.0 (c) Daichi Shigechika 2020.\n\n");
	firstcheck();
	while (1) {
		GetSystemPowerStatus(&sps);									//バッテリー状態を取得
		b = sps.BatteryLifePercent;									//バッテリー残量状態をbに代入
		if (b % 10 == 0)											//バッテリー残量が10の倍数%のとき
		{
			if (c == 0)												//再生停止フラグが解除されているとき
			{
				docheck(b);											//docheck関数の呼び出し
				c++;												//再生停止フラグを立てる
			}
		}
		else c = 0;													//再生停止フラグを解除する

		if (_kbhit() && _getch() == ESC) break;						//ESCキーを押すことによりループを脱出
		Sleep(1000);												//1秒待機する
	}
	printf("\n監視を終了しました．\n自動で終了します．\n");
	Sleep(5000);													//5秒待機する
	return 0;														//コード0を返し、終了
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
