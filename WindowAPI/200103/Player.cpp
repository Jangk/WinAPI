#include "pch.h"
#include "Player.h"

void Player::Initialize()
{
	m_fSpeed		= 200;
	m_tInfo.fWidth  = PLAYER_X;
	m_tInfo.fHeight = PLAYER_Y;

	m_bIsJump = false;
}

void Player::Update()
{
	Input();

	// 중력?
	m_tInfo.fY += 500 * g_fDeltaTime;
	m_tInfo.fX += GameManager::GetInstance()->GetScreenMove();

	if (m_bIsJump)
	{
		//if(m_fCount <= 10)
			m_bIsJump = false;
		//y = v * sinf(90 * PI/180) * t * 9.8 * t ^ 2 * 0.5			// 포물선 공식
		//++m_fCount;
		m_tInfo.fY = 10 * 1 * 1 * 9.8 * 1 * 0.5 * g_fDeltaTime;
	}
	else
		m_fCount = 0;
}

void Player::Render(HDC hdc)
{
	GameObject::UpdateRect();
	Rectangle(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void Player::Release()
{
}


void Player::Input()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000 && !m_bIsJump)
		m_bIsJump = true;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		GameManager::GetInstance()->SetScreenMove(-m_fSpeed * g_fDeltaTime);
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		GameManager::GetInstance()->SetScreenMove(m_fSpeed * g_fDeltaTime);
}