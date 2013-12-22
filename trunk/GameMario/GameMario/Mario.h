#ifndef MARIO_H_
#define MARIO_H_
#define VELOCNORMAL  30.0f
#define GROUNDY  95

#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"LoadMap.h"
#include"Bullet.h"
#include"AABBCollisionDetected.h"
#include"Score.h"
#define TIMEAMINATION  1.6f
#define TIMESHOWPROTECTED  0.5f
#define TIMEPROTECTED  25.0f
enum ActionMario
{
	normal,
	Jump,
	run,
	down
};
enum StatusMario
{
	mariosmall,
	mariobig,
	mariogun
};
class CMario :public CGameObject{
private:
	CSprite *m_spriteBig;
	CSprite *m_sriteSmall;
	CSprite *m_spriteGun;
	ActionMario m_action;
	StatusMario m_status;
	StatusMario m_start_status;
	DirectCollision  m_directCollion;//xem dang va cham theo huong nao
	D3DXVECTOR2 m_MaxVeloc;//luu tru maxveloc ban dau,khi va cham cho maxvecloc ve 0
	//

	vector<CBullet*> m_bullet;
	// bo sung ngay 17/11/2013

	//22/11/2013
	CAABBCollision* m_collision;
	D3DXVECTOR2 m_lastPos;
	bool m_isProtected;
	float m_timeProtected;
	float m_timeShowProtected;
	//Item
	bool m_eatStar;
	
public:
	static CScore *sc;
	int keydown;
	int CountCoin;//an tien
	bool EatLife;//an nam mang
	static int Score;//diem cong them vao
	static bool WinState;// va cham voi house bao hieu het man
	static vector<CGameObject*> ListItem;
	static int g_widthMap,g_heightMap;
	CMario();
	CMario(int,D3DXVECTOR2);
	~CMario();
	void Init();
	//void Update(CInput*,float,CCamera*);
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	bool CanCollision() {return true;}
	void UpdateCollison(CGameObject* , CInput* , float);
	void ChangeStatus();
	void ExecuteCollision(CGameObject*,DirectCollision,float,float);//tiem game chay, va time va cham
};

#endif

