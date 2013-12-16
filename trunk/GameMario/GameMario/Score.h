#ifndef SCORE_H_
#define SCORE_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"

enum SCoreType
{
	 MOTTRAM,
	 BATRAM,
	 NAMTRAM
};
class CScore:public CGameObject
{
private:
	CSprite *m_score;
	SCoreType m_scoretype;
public:
	CScore();
	CScore(D3DXVECTOR2,SCoreType);
	~CScore();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

