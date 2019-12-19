#include "pch.h"
#include "Bullet.h"

void Bullet::Initialize()
{
	m_fSpeed = 20;
	m_tInfo.fX = 0;
	m_tInfo.fY = 0;
	m_tInfo.fWidthHalf = 10;
	m_tInfo.fHeightHalf = 10;
}

EventType Bullet::Update()
{
	GameObject::UpdateRect();
	if (m_tInfo.fX < 0 || SCREEN_X < m_tInfo.fX ||
		m_tInfo.fY < 0 || SCREEN_Y < m_tInfo.fY ||
		m_bIsDead)
		return DEAD;

	switch (m_eDir)
	{
	case UP:
		m_tInfo.fY -= m_fSpeed;
		break;
	case DOWN:
		m_tInfo.fY += m_fSpeed;
		break;
	case LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;
	case RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;
	}
	return NO_EVENT;
}

void Bullet::Render(HDC hdc)
{
	HBRUSH nowBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(hdc, nowBrush));

	Rectangle(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	SelectObject(hdc, oldBrush);
	DeleteObject(nowBrush);
}

void Bullet::Release()
{
}

void Bullet::SetDirection(Direction dir)
{
	m_eDir = dir;
}
