#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include"Sprite.h"
#include<d3d9.h>
#include<d3dx9.h>
#include"Texture.h"
#include"Input.h"
#include"Camera.h"
#include<vector>
#include<algorithm>
#include"AABBCollisionDetected.h"
#include"CAudio.h"
// la doi tuong gi de xet va cham 24/11/2013
enum ObjectType
{
	OBJECTTYPE,
	MARIOTYPE,
	LANDTYPE,
	BRICKTYPE,
	PIPETYPE,
	COINTYPE,
	FLOWERTYPE,
	MUSHROOMBIGTYPE,
	MUSHROOMLIFETYPE,
	MUSHROOMTYPE,
	TURTLETYPE,
	STARTYPE,
	COINQUESTIONTYPE,
	HOUSETYPE,
	BOSSTYPE,
	FLAGTYPE
};

class CGameObject{
protected :
	D3DXVECTOR2 m_pos;
	D3DXVECTOR2 m_veloc;
	D3DXVECTOR2 m_accel;
	CSprite *m_sprite;
	RECT m_bound;

	//max
	D3DXVECTOR2 m_maxVelocity;
	D3DXVECTOR2 m_maxAccelemeter;
	//
	D3DXVECTOR2 StartPostion;

	//Bo sung them Id cho cac doi tuong game 14/11 /2013
	int m_Id;
	//bo sung loai doi tuong  24/11/2013
	ObjectType m_type;
	CAABBCollision * m_collision;
	//am thanh
	CAudio *m_sound;
public:
	int m_direct;
	int life;// so mang de quan ly status
	bool m_Islife;//con song hay chet
	bool m_EatBulet;// bi ban dan vao hay chua
	float m_TimeShow;//thoi gian hien thj
	bool m_IsShow;// co hien thi hay ko
	bool m_GrowUp;//moc item
	float m_TimeCollision;//de xem cai nao va cham truoc, cai nao sau
	float m_intetsect;//phan x giao nhau, giao x nheiu thi xu ly truoc
	CGameObject(void);
	CGameObject(int,D3DXVECTOR2);
	~CGameObject(void);
	virtual void Init();
	virtual void Update(CInput*,float,CCamera*);//update vi tri cua object va sprite tuong ung
	virtual	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	virtual void UpdatePosition(CInput*,float);
	virtual void UpdateAnimation(CInput*,float);
	virtual void Draw(LPD3DXSPRITE,CCamera*);
	virtual void UpdateCollison(CGameObject* , CInput* , float);//22/11/2013

	//get
	D3DXVECTOR2 GetVelocity() {return m_veloc;}
	D3DXVECTOR2 GetAccleration() {return m_accel;}
	D3DXVECTOR2 GetPosition() {return m_pos;}
	RECT GetBound() {return m_bound; }
	int GetId(){return m_Id;}
	CSprite* GetSprite(){return m_sprite;}
	D3DXVECTOR2 GetMaxVelocity() {return m_maxVelocity;}
	D3DXVECTOR2 GetMaxAccelemeter(){ return m_maxAccelemeter;}
	ObjectType GetType();//24/11/2013
	//set

	void SetBound();
	void SetBound(RECT *);
	void SetPosition(D3DXVECTOR2 _pos) { m_pos = _pos;}
	void SetVelocity(D3DXVECTOR2 _velocity) { m_veloc = _velocity;}
	void SetAcceleration(D3DXVECTOR2 _accleration) { m_accel = _accleration;}
	void SetPositionX(float _x) {m_pos.x = _x;}
	void SetPositionY(float _y) {m_pos.y = _y;}
	void SetVelocityX(float _vX) {m_veloc.x = _vX;}
	void SetVelocityY(float _vY) {m_veloc.y = _vY;}
	void SetAccelerationX(float _aX) {m_accel.x = _aX;}
	void SetAccelerationY(float _aY) {m_accel.y = _aY;}
	void SetIsShow(bool _isshow) {m_IsShow = _isshow;}
	// set max
	void SetMaxVelocity(D3DXVECTOR2 _velocity) { m_maxVelocity = _velocity;}
	void SetMaxVelocityX(float _vX) {m_maxVelocity.x = _vX;}
	void SetMaxVelocityY(float _vY) {m_maxVelocity.y = _vY;}
	void SetMaxAcceleration(D3DXVECTOR2 _accleration) { m_maxAccelemeter = _accleration;}
	void SetId(int _id){m_Id = _id;}
	void Stop();

};

#endif