#ifndef TIMER_H_
#define TIMER_H_

#include <Windows.h>
#include <tchar.h>
class CTimer
{
private:
	__int64 m_coutPerSec;//tan so cua bo dem thoi gian/( thoi gian bat dau - thoi gian ketthuc )/tan so = thoi gian 2 lan chuyen sprite
	float m_timeScale;//ngich dao bien m_counPersec (chu ki)
	int m_countFrame;
	int m_frameRate;
	float m_deltaTime;
	float t_deltaTime;// thoi gian chuyen hinh
	float m_lockFps;
public:
	__int64 m_timeStart;
	__int64 m_timeEnd;
	CTimer(void);
	~CTimer(void);
	void GetSecondPerTick ();
	void StartCount ();
	void EndCount ();
	void SetMaxFps(float);
	float GetDeltaTime ();
	float GetTime();
	unsigned short GetNumDeltaTime(LPSTR lpstrFrameRate = NULL);
	
};

#endif

