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
	m_camera = new CCamera();
	/**********************************************************************/
	m_engine = new CGameStateManager();
	m_engine->Init(_hInstance, m_windown->Get_Handle() , m_graphic, m_input);
	m_engine ->InitFirstState(new CLoadingState(m_engine));
}
int CGameApp::GameRun(){
	m_time->StartCount();
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
	if (m_engine!=NULL)
	{
		delete m_engine;
	}
	return 1;
}
void CGameApp::UpdateWorld(float time){
	// update the gioi cac doi tuong
	m_engine->Update(m_time->GetDeltaTime(),m_camera);
}
void CGameApp::DrawWorld(){
	m_graphic->BeginRender();
	m_spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	m_engine->Draw(m_spriteHandler,m_camera);
	m_spriteHandler->End();
	m_graphic->EndRender();
}