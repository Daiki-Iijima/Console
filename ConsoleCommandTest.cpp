#include <iostream>
#include <windows.h>

using namespace std;

void getConsoleSize(int&, int&);
void DrawPunctuation(int, int, HANDLE*);

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

	getConsoleSize(columns, rows);


	char data[10000];
	const char* kaigyo = "\n";
	int count = 0;
	//SetConsoleCursorPosition(consoleHandle2, { 0,0 });



	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[count] = '+';
			count++;
		}

		data[(i + 1)*columns] = '\n';
	}

	for (int i = 0; i < sizeof(data); i++)
	{
		if (data[i] == '+')
			cout << data[i];
	}

	//for (;;)
	//{
	//	SetConsoleCursorPosition(consoleHandle1, defoPos);

	//	// スクリーンバッファを指定して文字を書き込む
	//	DrawPunctuation(columns, rows, &consoleHandle1);
	//	Sleep(1000);
	//	//SetConsoleCursorPosition(consoleHandle2, defoPos);

	//	char data[10000];
	//	const char* kaigyo = "\n";

	//	SetConsoleCursorPosition(consoleHandle2, { 0,0 });

	//	for (int i = 1; i < rows + 1; i++)
	//	{
	//		for (int j = 0; j < columns; j++)
	//		{
	//			data[i*j] = '+';
	//		}
	//		data[i*columns+1] = '\n';
	//	}

	//	WriteConsole(consoleHandle2, data, strlen(data), NULL, NULL);

	//	SetConsoleActiveScreenBuffer(consoleHandle2);
	//	Sleep(1000);

	//}
	//// スクリーンバッファを解放
	//CloseHandle(consoleHandle1);
	//consoleHandle1 = NULL;

	//CloseHandle(consoleHandle2);
	//consoleHandle2 = NULL;

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

void DrawPunctuation(int columns, int rows, HANDLE* consoleHandle)
{

}

void getConsoleSize(int &columns, int &rows)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}