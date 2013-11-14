#ifndef DXGRAPHIC_H_
#define DXGRAPHIC_H_

#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

class CGraphic
{
private:
	LPDIRECT3D9 m_pd3d;
	LPDIRECT3DDEVICE9 m_pd3device;
	D3DPRESENT_PARAMETERS m_d3dpp;
public:
	CGraphic();
	~CGraphic();
	int InitDevice(HWND);
	LPDIRECT3D9 Get_pd3d();
	LPDIRECT3DDEVICE9 Get_pd3device();
	D3DPRESENT_PARAMETERS Get_d3dpp();

	void ReleaseDevice();
	void BeginRender();
	void EndRender();


};

#endif