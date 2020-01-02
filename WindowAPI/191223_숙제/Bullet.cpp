#include "pch.h"
#include "Bullet.h"

void Bullet::SetShoot(float angle)
{
	m_bIsShoot = true;
	m_fAngle = angle;
}

void Bullet::Initialize()
{
	// m_tInfo
	m_tInfo.fX		= 0;
	m_tInfo.fY		= 0;
	m_tInfo.fWidth  = 30;
	m_tInfo.fHeight = 30;

	// ±‚≈∏
	m_fSpeed		= 400;
	m_fAngle		= 0;
	m_bIsShoot		= false;
}

void Bullet::Update()
{
	if (m_bIsShoot)
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180) * g_fDeltaTime;
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180) * g_fDeltaTime;
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
