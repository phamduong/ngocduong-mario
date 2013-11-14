#ifndef CWINDOWN_H_
#define CWINDOWN_H_
#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
#define NameClass "Game Mario"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
class CWindown
{
private:
	HINSTANCE m_hInstance;
	HWND m_wndHandle;
public:
	CWindown(void);
	CWindown(HINSTANCE);
	bool InitWindows();
	HINSTANCE Get_hInstance();
	HWND Get_Handle();
	static LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
	~CWindown(void);
};
#endif


