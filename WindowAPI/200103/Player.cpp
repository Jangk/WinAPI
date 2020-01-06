#include "pch.h"
#include "Player.h"

void Player::Initialize()
{
	m_fSpeed		= 200;
	m_tInfo.fWidth  = PLAYER_X;
	m_tInfo.fHeight = PLAYER_Y;

	m_bIsJump		= false;
	m_fGravityForce = 500.0f;
	m_fJumpForce	= 1.0f;
	m_fJumpAcc		= 0.0f;
	m_fAccIncrease  = 0.3f;
}

void Player::Update()
{
	// y = �� * ���ӵ� * sin(90) - �߷�(9.8) * ���ӵ� ^ 2 * 0.5
	
	
	Input();
	m_tInfo.fX += GameManager::GetInstance()->GetScreenMove();


	if (m_bIsJump)
	{
		float leftVal  = m_fJumpForce * m_fJumpAcc * 1;
		float rightVal = 9.8f * pow(m_fJumpAcc, 2) * 0.5;
		m_tInfo.fY -= leftVal - rightVal;
		m_fJumpAcc += m_fAccIncrease * g_fDeltaTime;

		if (m_fJumpAcc >= m_fAccIncrease)			// ���� ������������ �ٲܰ�.(���� 1�ʿ� ���ӵ� ��������ŭ)
		{
			m_fGravityForce = 500;
			m_fJumpAcc		= 0;
			m_bIsJump		= false;
		}
	}
	else   // �������� �ƴϸ� �߷� �������.
		m_tInfo.fY += m_fGravityForce * g_fDeltaTime;
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