#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
	: m_fSpeed(0.f)
{
}


CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_fSpeed = 10.f;
}

int CBullet::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	m_tInfo.fY -= m_fSpeed;

	return NO_EVENT;
}

void CBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}
