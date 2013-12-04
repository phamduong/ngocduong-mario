#include "GameStateManager.h"
#include "GameState.h"

CGameStateManager::CGameStateManager(void)
{
	/*m_gameState.push_back(new CLoadingState());
	m_gameState.back()->Init();*/
}

void CGameStateManager::InitFirstState(CGameState* _state)
{
	m_gameState.push_back(_state);
	m_gameState.back()->Init();
}
void CGameStateManager::Init(HINSTANCE _hInstance, HWND _wndHandle,CGraphic* _graphic, CInput* _input)
{
	this->m_hInstance = _hInstance;
	this->m_wndHandle = _wndHandle;
	//m_resource = CResourceManager::GetInstance();
	this->m_input = _input;
	this->m_graphic =_graphic;
	D3DXCreateSprite(m_graphic->Get_pd3device() , &m_spriteHandle);
}
void CGameStateManager::CleanUp()
{

}
void CGameStateManager::ChangeState(CGameState* _nextState)
{
	this->m_nextState = _nextState;
	//khac rong clean va xoa khoi mang
	if (!m_gameState.empty())
	{
		m_gameState.back()->CleanUp();
		m_gameState.pop_back();
	}
	//khoi tao cai moi'
	m_gameState.push_back(m_nextState);
	m_gameState.back()->Init();
}
//them vao  xu dung khi pause
void CGameStateManager::AddState(CGameState* _nextState)
{
	this->m_nextState = _nextState;
	if (!m_gameState.empty())
	{
		m_gameState.back()->Pause();
	}
	m_gameState.push_back(m_nextState);
	m_gameState.back()->Init();
}
//xoa di
void CGameStateManager::DeleteState()
{
	if (!m_gameState.empty())
	{
		m_gameState.back()->CleanUp();
		m_gameState.pop_back();
	}
}

void CGameStateManager::Update(float _time,CCamera * _camera)
{
	m_gameState.back()->Update(m_input, _time,_camera);
}

void CGameStateManager::Draw(LPD3DXSPRITE _spriteHandler,CCamera * _camera)
{
	m_gameState.back()->Draw(_spriteHandler,_camera);
}

//int CGameStateManager::GetScreenWidth()
//{
//	return m_graphic->GetScreenWidth();
//}
//int CGameStateManager::GetScreenHeight()
//{
//	return m_graphic->GetScreenHeight();
//}
CGameStateManager::~CGameStateManager(void)
{
}
