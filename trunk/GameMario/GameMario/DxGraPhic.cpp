#include "DxGraphic.h"


CGraphic::CGraphic(void)
{
	m_pd3d=NULL;
	m_pd3device=NULL;
}

int CGraphic::InitDevice(HWND _wndHandle)
{
	if (NULL==(m_pd3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return 0;
	}
	ZeroMemory( &m_d3dpp, sizeof(m_d3dpp) );
	m_d3dpp.Windowed = TRUE;
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	m_d3dpp.BackBufferCount  = 1;
	m_d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	m_d3dpp.BackBufferWidth  = SCREEN_WIDTH;
	m_d3dpp.hDeviceWindow    = _wndHandle;
	if( FAILED( m_pd3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _wndHandle,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&m_d3dpp, &m_pd3device ) ) )
	{
		if( FAILED( m_pd3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, _wndHandle,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&m_d3dpp, &m_pd3device ) ) )
		{
			if( FAILED( m_pd3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_SW, _wndHandle,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&m_d3dpp, &m_pd3device ) ) )
			{
				return 0;
			}
		}
	}
	return 1;
}
LPDIRECT3D9 CGraphic::Get_pd3d()
{
	return m_pd3d;
}
LPDIRECT3DDEVICE9 CGraphic::Get_pd3device()
{
	return m_pd3device; 
}
D3DPRESENT_PARAMETERS CGraphic::Get_d3dpp()
{
	return m_d3dpp;
}
void CGraphic::BeginRender()
{

	if (m_pd3device!=NULL)
	{
		m_pd3device->BeginScene();
		m_pd3device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(51,102,255), 1.0f, 0);
	}
}
void CGraphic::EndRender()
{
	m_pd3device->EndScene();
	m_pd3device->Present(NULL, NULL, NULL, NULL);
}
void CGraphic::ReleaseDevice()
{
	if (m_pd3d != NULL)
	{
		m_pd3d->Release();
		m_pd3d = NULL;
	}
	if (m_pd3device != NULL)
	{
		m_pd3device->Release();
		m_pd3device = NULL;
	}
}
CGraphic::~CGraphic(){}