#include "Camera.h"
#include"Mario.h"

CCamera::CCamera(void)
{
	m_pos = D3DXVECTOR2(0,800);
}

void CCamera::Update(D3DXVECTOR2 _pos)
{
	if (_pos.x < CMario::g_widthMap - 400)
	{
		m_pos.x = (float)_pos.x - 400;

	}

	if (m_pos.x < 0)
	{
		m_pos.x =  0;
	}
	// size 1024 x 1024
	//if (m_pos.x > 200)
	//{
	//	m_boudCamera.left = m_pos.x - 100;
	//}
	//else
	//{
	m_boudCamera.left = m_pos.x;
	//}
	m_boudCamera.right = m_boudCamera.left + 900;
	m_boudCamera.top = 1200;
	m_boudCamera.bottom =0;
}

D3DXMATRIX CCamera::Get_ViewPort()
{
	D3DXMatrixIdentity(&m_viewPort);
	D3DXMatrixAffineTransformation(&m_viewPort , 1, &D3DXVECTOR3(0,0,0), &D3DXQUATERNION(0,0,0,0), &D3DXVECTOR3((float)-m_pos.x, (float) m_pos.y, 0)); 
	m_viewPort._22 = -1;
	return m_viewPort;
}
CCamera::~CCamera(void)
{
}

