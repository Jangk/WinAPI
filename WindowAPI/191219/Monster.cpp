#include "pch.h"
#include "Monster.h"

void Monster::Initialize()
{
	m_fSpeed = 10;
	m_tInfo.fX = 0;
	m_tInfo.fY = 0;
	m_tInfo.fWidthHalf = 30;
	m_tInfo.fHeightHalf = 30;
}

EventType Monster::Update()
{
	GameObject::UpdateRect();
	DontEscapeMap();
	if (m_bIsDead)
		return DEAD;
	return NO_EVENT;
}

void Monster::Render(HDC hdc)
{
	HBRUSH nowBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(hdc, nowBrush));
	Rectangle(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	SelectObject(hdc, oldBrush);
	DeleteObject(nowBrush);
}

void Monster::Release()
{
}
