#ifndef INPUT_H_
#define INPUT_H_
#include <dinput.h>
#include "CWindown.h"
#define KEY_DOWN(code) ( IsKeyDown(code) )

#define KEYBOARD_BUFFER_SIZE	1024
class CInput {
private:
	LPDIRECTINPUT8       m_di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 m_Keyboard;	// The keyboard device 
	BYTE  m_KeyStates[256];			// DirectInput keyboard state buffer 
	// Buffered keyboard data
	DIDEVICEOBJECTDATA _KeyEvents[ KEYBOARD_BUFFER_SIZE ];
	int  m_keydown,m_keyup ;//onkeydow or onkeyup
public:
	CInput();
	~CInput();
	int InitKeyboard(HINSTANCE ,HWND);
	void ProcessKeyBoard();
	int KeyDown(int KeyCode);
	int GetKeyDown();
	int GetKeyUp();
	void Kill_Keyboard();
};

#endif


