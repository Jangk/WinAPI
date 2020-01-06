#include "pch.h"
#include "Player.h"

void Player::Initialize()
{
	m_fSpeed		= 200;
	m_tInfo.fWidth  = PLAYER_X;
	m_tInfo.fHeight = PLAYER_Y;

	m_bIsJump		= false;
	m_fJumpForce	= 1.0f;
	m_fJumpAcc		= 0.0f;
	m_fAccIncrease  = 0.3f;
}

void Player::Update()
{
	Input();

	m_tInfo.fX += GameManager::GetInstance()->GetScreenMove();

	if (m_bIsJump)
	{
		// y = 힘 * 가속도 * sin(90) - 중력(9.8) * 가속도 ^ 2 * 0.5
		float leftVal  = m_fJumpForce * m_fJumpAcc * 1;
		float rightVal = 9.8f * pow(m_fJumpAcc, 2) * 0.5;
		m_tInfo.fY -= leftVal - rightVal;
		m_fJumpAcc += m_fAccIncrease * g_fDeltaTime;

		if (m_fJumpAcc >= m_fAccIncrease)			// 조건 착지했을때로 바꿀것.(현재 1초에 가속도 증가값만큼)
		{
			m_bIsJump = false;
			m_fJumpAcc = 0;
		}
	}
	else   // 점프중이 아니면 중력 영향받음.
		m_tInfo.fY += 500 * g_fDeltaTime;
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