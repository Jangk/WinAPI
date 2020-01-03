#include "pch.h"
#include "Monster.h"

void Monster::Initialize()
{
	// �θ� 
	m_fSpeed		= 100.0f;
	m_fAngle		= 0;
	m_tInfo.fWidth	= PLAYER_X;
	m_tInfo.fHeight = PLAYER_Y;
	

	// ����
	m_Target		= g_Player;
	m_GunPos.x		= 0;
	m_GunPos.y		= 0;
	m_fGunLength	= 100;
}

void Monster::Update()
{
	//		  ������ - ����� = ��������� �������� ����
	float x = m_Target->GetInfo().fX - m_tInfo.fX;
	float y = m_Target->GetInfo().fY - m_tInfo.fY;	

	if (m_Target->GetInfo().fY < m_tInfo.fY)
		m_fAngle = acosf(x / sqrtf(pow(x, 2) + pow(y, 2)));
	else
		m_fAngle = -acosf(x / sqrtf(pow(x, 2) + pow(y, 2)));
	

	// �÷��̾�� ȸ��
	m_GunPos.x = m_tInfo.fX + cosf(m_fAngle) * m_fGunLength;
	m_GunPos.y = m_tInfo.fY + -sinf(m_fAngle) * m_fGunLength;

	// �÷��̾����� �̵�
	m_tInfo.fX += cos(m_fAngle) * m_fSpeed * g_fDeltaTime;
	m_tInfo.fY -= sin(m_fAngle) * m_fSpeed * g_fDeltaTime;
}

void Monster::Render(HDC hdc)
{
	GameObject::UpdateRect();
	Ellipse(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);

	// �ѱ� ��
	MoveToEx(hdc, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hdc, m_GunPos.x, m_GunPos.y);
}

void Monster::Release()
{
}

void Monster::IsDead()
{
}
