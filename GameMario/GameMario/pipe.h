#ifndef PIPE_H_
#define PIPE_H_

#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CPipe:public CGameObject
{
private:
	CSprite *m_pipesmall;
	CSprite *m_pipemedium;
	CSprite *m_pipebig;

	int m_status;

public:
	CPipe();
	CPipe(int _id,D3DXVECTOR2,int);
	~CPipe();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

