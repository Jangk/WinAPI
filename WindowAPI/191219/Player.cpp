#include "pch.h"
#include "Player.h"
#include "Bullet.h"

void Player::Initialize()
{
	m_fSpeed = 10;
	m_tInfo.fX = 0; 
	m_tInfo.fY = 0;
	m_tInfo.fWidthHalf  = 30;
	m_tInfo.fHeightHalf = 30;
}

EventType Player::Update()
{
	GameObject::UpdateRect();
	Input();
	DontEscapeMap();
	return NO_EVENT;
}

void Player::Render(HDC hdc)
{
	HBRUSH nowBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(hdc, nowBrush));
	Rectangle(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	SelectObject(hdc, oldBrush);
	DeleteObject(nowBrush);
}

void Player::Release()
{
}

void Player::SetBulletList(OBJECT_LIST* objList)
{
	m_BulletList = objList;
}

void Player::Input()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_tInfo.fY -= m_fSpeed;
		m_eDir = UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_tInfo.fY += m_fSpeed;
		m_eDir = DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_tInfo.fX -= m_fSpeed;
		m_eDir = LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_tInfo.fX += m_fSpeed;
		m_eDir = RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		GameObject* temp = GameObjectCreator<Bullet>::CreateGameObject(m_tInfo.fX, m_tInfo.fY);
		dynamic_cast<Bullet*>(temp)->SetDirection(m_eDir);
		m_BulletList->push_back(temp);

	}
}

Player::~Player()
{
}
