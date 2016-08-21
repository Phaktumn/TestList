#pragma once
#include <ctime>

class AppLoop {
public:
	AppLoop();
	explicit AppLoop(int targetFrames);
	virtual ~AppLoop();
	void Update();
	void InternalUpdateApp();
	void ClearScreen() const;
private:
	float DeltaTime;
	int TargetFrames;
	
	int fps;

	int CurrFrame;

	float deltaStep;
	double elapsed_secs;


	clock_t begin;
	clock_t end;

	void TickBegin();
	void TickEnd();
	void ClearBuffer() const;

protected:
};

