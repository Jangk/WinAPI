#include "pch.h"
#include "Monster.h"

void Monster::Initialize()
{
	m_tInfo.fWidth  = 100;
	m_tInfo.fHeight = 100;
	m_bIsDead = false;
}

void Monster::Update()
{
}

void Monster::Release()
{
}

void Monster::Render(HDC hdc)
{
	if(!m_bIsDead)
		Ellipse(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Monster::CollisionBullet(Bullet* bullet)
{
	if (bullet->IsShoot())
	{
		//충돌식 잘못됨 고쳐 (x,y) (x2, y2)로 계산할것
		float fMin = m_tInfo.fWidth * 0.5f + bullet->GetInfo().fWidth * 0.5f; // 둘의 반지름 더하기
		float fDisX = 0.0f;
		float fDisY = 0.0f;
		float fTotal = 0.0f;
		if (bullet->GetInfo().fCenterX > m_tInfo.fCenterX)
			fDisX = bullet->GetInfo().fCenterX - m_tInfo.fCenterX;
		else
			fDisX = m_tInfo.fCenterX - bullet->GetInfo().fCenterX;

		if (bullet->GetInfo().fCenterY > m_tInfo.fCenterY)
			fDisY = bullet->GetInfo().fCenterY - m_tInfo.fCenterY;
		else
			fDisY = m_tInfo.fCenterY - bullet->GetInfo().fCenterY;
		fTotal = sqrt((fDisX * fDisX) + (fDisY * fDisY));
		if (fMin > fTotal)
			m_bIsDead = true;
	}
}
