#include "Text.h"


CText::CText(LPDIRECT3DDEVICE9 _device)
{
	m_device = _device;
	m_fontFace = (CHAR)"Arial";
	m_fontSize = 30;
	Init();

}
CText::CText(LPDIRECT3DDEVICE9 _device,int _fontSize,CHAR _fontFace)
{
	m_device = _device;
	m_fontFace = _fontFace;
	m_fontSize = _fontSize;
	Init();
}
CText::CText(LPDIRECT3DDEVICE9 _device,int _fontSize)
{
	m_device = _device;
	m_fontSize = _fontSize;
	Init();
}
void CText::Init()
{

	D3DXFONT_DESC FontDesc = {m_fontSize,
		0,
		400,
		0,
		false,
		DEFAULT_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_PITCH,
		m_fontFace};

	D3DXCreateFontIndirect(m_device,&FontDesc,&m_font);
}
void CText::Draw(LPCSTR _text,RECT _position,UINT _alignment,D3DCOLOR _color)
{
	m_font->DrawText(NULL,
		_text,
		-1,
		&_position,
		_alignment,
		_color);
}

CText::~CText(void)
{
	if(m_font != NULL)
	{
		m_font->Release(); //release font
		m_font = NULL;
	}
}
