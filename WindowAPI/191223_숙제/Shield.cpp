#include "pch.h"
#include "Shield.h"

void Shield::SetActive()
{
	m_bIsActive = true;
}

void Shield::Initialize()
{
	m_fDistance		= 100;
	m_fSpeed		= 300;
	m_fAngle		= 0;
	m_tInfo.fWidth  = 50;
	m_tInfo.fHeight = 50;
	m_bIsActive     = false;
}

void Shield::Update()
{
	if (m_bIsActive)
	{
		if (m_fAngle > 360)
			m_fAngle = 0;

		m_fAngle += m_fSpeed * g_fDeltaTime;

		m_tInfo.fX = 800.f + cosf(m_fAngle * PI / 180) * m_fDistance;
		m_tInfo.fY = 450.f - sinf(m_fAngle * PI / 180) * m_fDistance;
	}
}

void Shield::Render(HDC hdc)
{
	if (m_bIsActive)
	{
		GameObject::UpdateRect();
		Ellipse(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	}
}

void Shield::Release()
{
}

Shield::~Shield()
{
	Release();
}
