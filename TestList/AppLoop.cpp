#include "stdafx.h"
#include "AppLoop.h"

#include "time.h"

/*Initializes the app loop with default 30fps*/
AppLoop::AppLoop()
	: DeltaTime(0), TargetFrames(30), fps(0), CurrFrame(0), 
	elapsed_secs(0), begin(0), end(0) {
	deltaStep = 1 / TargetFrames;
}

/*Initializes the app loop with custom fps*/
AppLoop::AppLoop(int targetFrames)
	: DeltaTime(0), TargetFrames(targetFrames), fps(0), 
	CurrFrame(0), elapsed_secs(0), begin(0), end(0) {
	deltaStep = 1 / targetFrames;
}

AppLoop::~AppLoop()
{ }

void AppLoop::Update()
{
	printf("%d", fps);
}

void AppLoop::TickBegin() {
	begin = clock();
}

void AppLoop::TickEnd() {
	end = clock();
	elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
	CurrFrame++;
	if(elapsed_secs >= 1) {
		fps = CurrFrame;
		CurrFrame = 0;
		elapsed_secs = 0;
	}
}

void AppLoop::ClearBuffer() const {
	//system("cls");
	ClearScreen();
}

void AppLoop::InternalUpdateApp() {
	while (true) {
		TickBegin();
		Update();
		ClearBuffer();
		TickEnd();
	}
}

void AppLoop::ClearScreen() const
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter( hStdOut, static_cast<TCHAR>(' '), cellCount, homeCoords,
		&count )) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count))
		return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
