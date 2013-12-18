#ifndef FLAG_H_
#define FLAG_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"

class CCoFlag:public CGameObject
{
private:
	CSprite *m_Coflag;
	int m_typeflag;
public:
	CCoFlag();
	CCoFlag(int typeFlag,D3DXVECTOR2);
	~CCoFlag();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};
class CFlag:public CGameObject
{
private:
	CSprite *m_flag;
	CCoFlag *VietNam;
	CCoFlag *Khua;
public:
	CFlag();
	CFlag(int,D3DXVECTOR2);
	~CFlag();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);

};


#endif

