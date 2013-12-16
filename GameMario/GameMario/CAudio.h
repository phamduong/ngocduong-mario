#ifndef _CAUDIO_H_
#define _CAUDIO_H_
#include "dsutil.h"


//primary DirectSound object
extern CSoundManager *dsound;

//function prototypes
class CAudio
{
public:
	CAudio(HWND);
	//void Init(HWND);
	CSound *LoadSound(char*);	
	void PlaySound(CSound *);
	void LoopSound(CSound *);
	void StopSound(CSound *);	
	static bool m_isSoundOff;
};

#endif

//#pragma once
//#include "fmod.h"
//#include <Windows.h>
//#include <vector>
//
//class CSample
//{
//private:
//	std::string m_name;
//public:
//	FMOD_SOUND * m_sample;
//	FMOD_CHANNEL *m_channel;
//	CSample();
//	~CSample();
//	std::string getName() {return this->m_name;}
//	void setName(std::string value) {this->m_name = value;}
//};
//
//class CAudio
//{
//private:
//	FMOD_SYSTEM *m_system;
//	typedef std::vector<CSample *> CSamples;
//	typedef std::vector<CSample *>::iterator CIterator;
//	CSamples m_samples;
//
//public:
//	CAudio();
//	~CAudio();
//	FMOD_SYSTEM * getSystem() {return this->m_system;}
//	bool Init();
//	void Update();
//	bool LoadAudio(std::string fileName, std::string name);
//	CSample *LoadAudio(std::string fileName);
//	bool Play(std::string fileName);
//	bool Play(CSample *sample);
//	void Stop(std::string fileName);
//	void StopAll();
//	void StopAllExcept(std::string name);
//	bool IsPlaying(std::string name);
//	bool SampleExists(std::string name);
//	CSample *FindSample(std::string name);
//};