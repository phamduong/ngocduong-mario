#include"GameApp.h"

CGameApp::CGameApp(){
}
int CGameApp::GameInit(HINSTANCE _hInstance){
	m_windown = new CWindown(_hInstance);
	if(!m_windown->InitWindows()){
		MessageBox(m_windown->Get_Handle(), "Can't Create Windows", "Error", MB_OK );
		return 1;
	}
	m_graphic = new CGraphic();
	if(!m_graphic->InitDevice(m_windown->Get_Handle())){
		MessageBox(m_windown->Get_Handle(), "Can't Create device", "Error", MB_OK );
		return 1;
	}

	CResourceManager::GetInstance()->Init(m_graphic->Get_pd3device(), m_windown->Get_Handle());
	D3DXCreateSprite(m_graphic->Get_pd3device(), &m_spriteHandler);

	if (m_spriteHandler == NULL)
	{
		return 0;
	}
	m_input = new CInput();
	if (!m_input->InitKeyboard(m_windown->Get_hInstance(),m_windown->Get_Handle()))
	{
		MessageBox(m_windown->Get_Handle(), "Can't Create input", "Error", MB_OK );
		return 0;
	}
	m_time = new CTimer();
	m_time->SetMaxFps(60.0f);
	m_mario = new CMario();
	m_camera = new CCamera();
	/**********************************************************************/
	m_map = new CMap();

	object = m_map->GetObjectFromFile("Resource//map//Map6.txt");
	m_mario->g_widthMap = m_map->m_widthmap;
	m_mario->g_heightMap = m_map->m_heightmap;
	// quad tree
	m_Tobject = new CTreeObject();
	m_nodeRoot = m_Tobject->LoadTree("Resource//map//Map6Tree.txt"); 

}
int CGameApp::GameRun(){
	m_time->StartCount();
	/*DWORD frame_start = GetTickCount();

	DWORD tick_per_frame = 100 / 60;*/
	MSG msg;
	ZeroMemory(&msg,sizeof(msg));
	int done=0;
	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT)
			{
				done = 1;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (m_time->GetTime () < 1.0f)
			{
				m_time->EndCount();
				m_input->ProcessKeyBoard();
				UpdateWorld(m_time->GetDeltaTime());
				DrawWorld();

			}	
		}
		//


	}
	return (int) msg.wParam;
}
int CGameApp::GameEnd(){
	if (m_windown != NULL)
	{
		delete m_windown;
	}
	if (m_graphic != NULL)
	{
		delete m_graphic;
	}
	if (m_input!=NULL)
	{
		m_input->Kill_Keyboard();
		delete m_input;
	}
	if (m_mario!=NULL)
	{

		delete m_mario;
	}
	for (int i = 0; i < object.size(); i++)
	{
		delete object[i];
	}
	return 1;
}
void CGameApp::UpdateWorld(float time){
	// update the gioi cac doi tuong
	m_mario->Update(m_input,time,m_camera,m_ListObjectInViewport);
	m_ListObjectInViewport.clear();
//	m_ListIdObjectInViewport.clear();
	m_ListIdObjectInViewport = m_Tobject->GetIDObjectInViewPort(m_nodeRoot,m_camera->GetBoundCamera());
	for (int i = 0; i < object.size(); i++)
	{
		for (int j = 0; j < m_ListIdObjectInViewport.size(); j++)
		{
			if(object[i]->GetId() == m_ListIdObjectInViewport[j])
			{
				m_ListObjectInViewport.push_back(object[i]);
			}

		}
	}
	//if (m_ListObjectInViewport.size() >= 100)
	//{
	//	char ha[10];
	//itoa(m_ListObjectInViewport.size(),ha,10);
	//MessageBox(NULL,ha,"",MB_OK);
	//}
	

	m_Tobject->Update(m_ListObjectInViewport,m_input,m_camera,time);
	

}
void CGameApp::DrawWorld(){
	m_graphic->BeginRender();
	m_spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	m_Tobject->Draw(m_ListObjectInViewport,m_spriteHandler,m_camera);
	m_mario->Draw(m_spriteHandler,m_camera);
	//ve cac doi tuong can ve o day
	m_spriteHandler->End();
	m_graphic->EndRender();
}