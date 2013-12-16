#include"Input.h"
CInput::CInput()
{
}

int CInput::InitKeyboard(HINSTANCE _hInstance,HWND _wndhandle){

	HRESULT hr = DirectInput8Create(_hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_di, NULL);
	if (hr!=DI_OK) return 0;
	hr = m_di->CreateDevice(GUID_SysKeyboard, &m_Keyboard, NULL); 
	if (hr!=DI_OK) return 0;
	hr = m_Keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (hr!=DI_OK) return 0;
	hr = m_Keyboard->SetCooperativeLevel(_wndhandle, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE); 
	if (hr!=DI_OK) return 0;
	DIPROPDWORD dipdw;
	dipdw.diph.dwSize       = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj        = 0;
	dipdw.diph.dwHow        = DIPH_DEVICE;
	dipdw.dwData            = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

	hr = m_Keyboard->SetProperty( DIPROP_BUFFERSIZE, &dipdw.diph );
	if (hr!=DI_OK) return 0;

	hr = m_Keyboard->Acquire(); 
	if (hr!=DI_OK) return 0;
	return 1;
}
void CInput::ProcessKeyBoard(){
	m_Keyboard->Poll();
	if (!SUCCEEDED(m_Keyboard->GetDeviceState( sizeof(m_KeyStates), m_KeyStates)));
	{
		//keyboard device lost, try to re-acquire
		m_Keyboard->Acquire();
	}
	
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hr = m_Keyboard->GetDeviceData( sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0 );
	// Scan through all data, check if the key is pressed or released
	for( DWORD i = 0; i < dwElements; i++ ) 
	{
		int KeyCode = _KeyEvents[i].dwOfs;
		int KeyState = _KeyEvents[i].dwData;
		if ( (KeyState & 0x80) > 0)
			//OnKeyDown(KeyCode);
				m_keydown = KeyCode;
		else 
			//OnKeyUp(KeyCode);
			m_keyup = KeyCode;
	}
}
int CInput::KeyDown(int KeyCode){
	return (m_KeyStates[KeyCode] & 0x80) > 0;
}
int CInput::GetKeyDown()
{ 
	int	tam = m_keydown;
	m_keydown = 0;
	return tam;
}
int CInput::GetKeyUp()
{
	int	tam = m_keyup;
	m_keydown = 0;
	return tam;
}
CInput::~CInput()
{
}
void CInput::Kill_Keyboard(){
	if (m_Keyboard!=NULL)
	{
		m_di->Release();
		m_Keyboard->Unacquire();
		m_Keyboard->Release();
		m_Keyboard = NULL;
	}
}