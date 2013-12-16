#include"Score.h"
CScore::CScore(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CScore::CScore(D3DXVECTOR2 pos,SCoreType _scoretype){
	m_pos = pos;
	m_scoretype = _scoretype;
	Init();
}
void CScore::Init(){
	CGameObject::Init();
	m_score = CResourceManager::GetInstance()->GetResouce(SCORE_ID);
	m_sprite = m_score;
	m_maxVelocity = D3DXVECTOR2(0.0f, 20.0f);
	m_IsShow = true;
}
void CScore::Update(CInput *_input,float _time,CCamera* _camera){
	if (m_IsShow)
	{
		m_veloc.y = m_maxVelocity.y;
		m_TimeShow+=_time;
		if (m_TimeShow>5.0f)
		{
			m_TimeShow = 0;
			m_IsShow = false;
		}
		UpdateAnimation(_input,_time);
		CGameObject::Update(_input,_time,_camera);
	}
}
void CScore::UpdateAnimation(CInput *_input,float _time){
	switch (m_scoretype)
	{
	case MOTTRAM:
		{
			m_sprite->SetCurrentSprite(0);
			m_sprite->UpdateSprite();
			break;
		}

	case BATRAM:
		{
			m_sprite->SetCurrentSprite(1);
			m_sprite->UpdateSprite();
			break;
		}
	case NAMTRAM:
		{
			m_sprite->SetCurrentSprite(2);
			m_sprite->UpdateSprite();
			break;
		}
	default:
		break;
	}

}
void CScore::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if (m_IsShow)
	{
		CGameObject::Draw(_spritehandle,_camera);
	}	
}
CScore::~CScore(){}

