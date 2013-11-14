#ifndef TURTLE_H_
#define TURTLE_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"

enum statusTurtle{Normal,Shield};
class CTurtle:public CGameObject
{
private:
	CSprite *m_spriteTurtle;
	CSprite *m_spriteTurtleShield;
	statusTurtle m_status;
	int m_direct;
	 
public:
	CTurtle();
	CTurtle(int _id,D3DXVECTOR2);
	~CTurtle();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

