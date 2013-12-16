#ifndef TEXT_H_
#define TEXT_H_
#include <d3dx9.h>
class CText
{
public:

	CText(LPDIRECT3DDEVICE9);
	CText(LPDIRECT3DDEVICE9,int _fontSize,CHAR _m_fontFace);
	CText(LPDIRECT3DDEVICE9 _device,int _fontSize);
	virtual ~CText(void);
	void Draw(LPCSTR,RECT,UINT,D3DCOLOR);
	void Init();
	LPDIRECT3DDEVICE9 m_device;
	LPD3DXFONT m_font;
	int m_fontSize;
	CHAR m_fontFace;
	void SetFontSize(int _fontsize){m_fontSize = _fontsize;}
	void SetFontFace(CHAR _fontFace){m_fontFace = _fontFace;}
};
#endif
