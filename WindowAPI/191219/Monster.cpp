#include "pch.h"
#include "Monster.h"

void Monster::Initialize()
{
	m_iDir = 1;
	m_iMoveCount = 0;
	m_fPlayerX = 0;
	m_fPlayerY = 0;
	m_MonsterType = MONSTER2;

	// default
	m_fSpeed = 3;
	m_tInfo.fX = 0;
	m_tInfo.fY = 0;
	m_tInfo.fWidthHalf = 30;
	m_tInfo.fHeightHalf = 30;
}

EventType Monster::Update()
{
	GameObject::UpdateRect();
	switch (m_MonsterType)
	{
	case MONSTER1:
		Move(DOWN);
		break;
	case MONSTER2:
		Move(SetMovePatten(50));
		break;
	case MONSTER3:
		Move(DOWN);			// 현재 일단 대충 넣음
		break;
	}
	
	
	// 이벤트 처리
	if (m_bIsDead)
		return DEAD;
	if (IsEscapeMap())
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

void Monster::SetPlayerPosition(float x, float y)
{
}

Direction Monster::SetMovePatten(int iMoveLenght)
{
	if (m_iMoveCount < 0 || m_iMoveCount > iMoveLenght)
		m_iDir *= -1;
	m_iMoveCount += m_iDir;
	
	if (m_iDir < 0)
		return LEFT;
	else
		return RIGHT;
}

void Monster::Move(Direction dir = DOWN)
{
	m_tInfo.fY += m_fSpeed;
	m_eDir = DOWN;
	switch (dir)
	{
	case UP:
		m_tInfo.fY -= m_fSpeed;
		m_eDir = UP;
		break;
	case LEFT:
		m_tInfo.fX -= m_fSpeed;
		m_eDir = LEFT;
		break;
	case RIGHT:
		m_tInfo.fX += m_fSpeed;
		m_eDir = RIGHT;
		break;
	}
}
