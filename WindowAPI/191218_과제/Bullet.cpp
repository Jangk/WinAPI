#include "pch.h"
#include "Bullet.h"

void Bullet::Initialize()
{
	m_tInfo.fCenterX = static_cast<float>(SCREEN_WIDTH * 0.5f);
	m_tInfo.fCenterY = static_cast<float>(SCREEN_HEIGHT * 0.5f);
	m_tInfo.fWidth = 25.f;
	m_tInfo.fHeight = 25.f;

	m_fSpeed = 10.f;
	m_tDir = Direction::UP;
	m_bIsShoot = false;
}

void Bullet::Update()
{
	if (m_bIsShoot)
	{
		switch (m_tDir)
		{
		case Direction::UP:
			m_tInfo.fCenterY -= m_fSpeed;
			break;
		case Direction::Down:
			m_tInfo.fCenterY += m_fSpeed;
			break;
		case Direction::Left:
			m_tInfo.fCenterX -= m_fSpeed;
			break;
		case Direction::Right:
			m_tInfo.fCenterX += m_fSpeed;
			break;
		}
		if (SCREEN_WIDTH < (m_tInfo.fCenterX + m_tInfo.fWidth * 0.5f) ||
			0  >(m_tInfo.fCenterX + m_tInfo.fWidth * 0.5f) ||
			SCREEN_HEIGHT < (m_tInfo.fCenterY + m_tInfo.fHeight * 0.5f) ||
			0 >(m_tInfo.fCenterY + m_tInfo.fHeight * 0.5f))
			m_bIsShoot = false;
	}
}

void Bullet::Render(HDC hdc)
{
	GameObject::UpdateRect();
	if(m_bIsShoot)
		Ellipse(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Bullet::Release()
{
}

void Bullet::SetShoot(int x, int y, Direction dir)
{
	m_tInfo.fCenterX = x;
	m_tInfo.fCenterY = y;
	m_bIsShoot = true;
	m_tDir = dir;
}

const INFO& Bullet::GetInfo() const
{
	return m_tInfo;
}

bool Bullet::IsShoot()
{
	return m_bIsShoot;
}
