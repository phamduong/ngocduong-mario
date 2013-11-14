#include "Time.h"


CTimer::CTimer(void)
{
	GetSecondPerTick();
	m_frameRate =0;
	m_deltaTime=0;
	m_countFrame=0;
	t_deltaTime = 0;
}

void CTimer::GetSecondPerTick()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_coutPerSec);
	m_timeScale = 1.0f/(float)m_coutPerSec;
}

void CTimer::StartCount()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_timeStart);
}

void CTimer::EndCount()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_timeEnd);
	t_deltaTime = (m_timeEnd - m_timeStart) * m_timeScale;
	if (m_lockFps > 0.0f)
	{
		while (t_deltaTime < 1.0f / m_lockFps)
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&m_timeEnd);
			t_deltaTime = (m_timeEnd - m_timeStart) * m_timeScale;
		}
	}
	m_timeStart = m_timeEnd;
	m_deltaTime += t_deltaTime;
	m_countFrame++;
	if (m_deltaTime >= 1.0f)
	{
		m_frameRate = m_countFrame;
		m_countFrame = 0;
		m_deltaTime = 0.0f;
	}
}

void CTimer::SetMaxFps(float _maxFps)
{
	m_lockFps = _maxFps;
}

float CTimer::GetDeltaTime()
{
	return (float)(1.0f/m_lockFps)*10;
}

float CTimer::GetTime()
{
	return m_deltaTime;
}

CTimer::~CTimer(void)
{
}
