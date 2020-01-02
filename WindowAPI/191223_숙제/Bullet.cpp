#include "pch.h"
#include "Bullet.h"

void Bullet::SetShoot(float angle)
{
	m_bIsShoot	= true;
	m_fAngle	= angle;
}

void Bullet::SetLockOn(GameObject* target)
{
	m_bIsShoot  = true;
	m_bIsLockOn = true;
	m_Target	= target;
}

void Bullet::Initialize()
{
	// m_tInfo
	m_tInfo.fX		= 0;
	m_tInfo.fY		= 0;
	m_tInfo.fWidth  = 30;
	m_tInfo.fHeight = 30;

	// 기타
	m_fSpeed		= 400;
	m_fAngle		= 0;
	m_bIsShoot		= false;
	m_bIsLockOn		= false;
}

void Bullet::Update()
{
	if (m_bIsShoot)
	{
		if (m_bIsLockOn)
		{
			float x = m_Target->GetInfo().fX - m_tInfo.fX;
			float y = m_Target->GetInfo().fY - m_tInfo.fY;

			if (m_Target->GetInfo().fY < m_tInfo.fY)
				m_fAngle = acosf(x / sqrtf((x * x) + (y * y)));
			else
				m_fAngle = -acosf(x / sqrtf((x * x) + (y * y)));


			// 유도미사일떄매 잠시 잠금
			m_tInfo.fX += cos(m_fAngle) * m_fSpeed * g_fDeltaTime;
			m_tInfo.fY -= sin(m_fAngle) * m_fSpeed * g_fDeltaTime;
		}
		else
		{
			m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180) * g_fDeltaTime;
			m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180) * g_fDeltaTime;
		}
	}
}

void Bullet::Render(HDC hdc)
{
	GameObject::UpdateRect();
	if (m_bIsShoot)
		Ellipse(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void Bullet::Release()
{
}
