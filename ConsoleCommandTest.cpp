#include <iostream>
#include <windows.h>

using namespace std;

void getConsoleSize(int&, int&, HANDLE&);
void DrawPunctuation(HANDLE&, char);

int main()
{
	
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

	DWORD cell;
	COORD defoPos = { 0,0 };
	for (;;)
	{
		// スクリーンバッファを指定して文字を書き込む
		DrawPunctuation(consoleHandle1, ' ');

		DrawPunctuation(consoleHandle2, ' ');

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

void DrawPunctuation(HANDLE& consoleHandle, char c)
{
	int columns, rows;

	getConsoleSize(columns, rows, consoleHandle);

	char *data = (char*)malloc(sizeof(char) *(columns * rows) + 1);
	int count = 0;
	COORD defoPos = { 0,0 };
	DWORD cell;

	

	//	カーソル位置を一番上にもっていく
	SetConsoleCursorPosition(consoleHandle, defoPos);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (j == 100) data[count] = '|';
			else data[count] = c;
			count++;
		}

		data[(i + 1)*columns] = '\n';
	}
	//	文字列を描画
	WriteConsole(consoleHandle, data, strlen(data), &cell, NULL);

	//	バッファをコンソールに適応
	SetConsoleActiveScreenBuffer(consoleHandle);

	//	データメモリを解放
	free(data);
}

void getConsoleSize(int &columns, int &rows, HANDLE& consoleHandle)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(consoleHandle, &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}