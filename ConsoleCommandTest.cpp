// ConsoleCommandTest.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <windows.h>

using namespace std;

void getConsoleSize(int&, int&);


int main()
{
	int columns, rows;
	char test;
	TCHAR  szBuf[256];
	DWORD  dwWriteByte;

	//コンソールハンドルを作る
	HANDLE consoleHandle1 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	HANDLE consoleHandle2 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);



	char str1[1024] = "++++++++++++++++++++++++++++++++++\n+++++++++++++++++++++++++";
	char str2[1024] = "-";

	DWORD cell;
	COORD defoPos = { 0,0 };

	for (;;)
	{
		SetConsoleCursorPosition(consoleHandle1, defoPos);

		// スクリーンバッファを指定して文字を書き込む
		WriteConsole(consoleHandle1, str1, strlen(str1), &cell, NULL);
		SetConsoleActiveScreenBuffer(consoleHandle1);

		//SetConsoleCursorPosition(consoleHandle2, defoPos);

		WriteConsole(consoleHandle2, str2, strlen(str2), &cell, NULL);
		SetConsoleActiveScreenBuffer(consoleHandle2);
	}
	// スクリーンバッファを解放
	CloseHandle(consoleHandle1);
	consoleHandle1 = NULL;

	CloseHandle(consoleHandle2);
	consoleHandle2 = NULL;

	//for (;;)
	//{
	//	cin >> test;
	//	getConsoleSize(columns, rows);

	//	DrawPunctuation(columns, rows);

	//	/*printf("columns: %d\n", columns);
	//	printf("rows: %d\n", rows);*/

	//}
	return 0;
}

void DrawPunctuation(int columns, int rows)
{
	system("cls");								//	画面をクリア

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "+";
		}
		cout << endl;

	}
}

void getConsoleSize(int &columns, int &rows)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
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
