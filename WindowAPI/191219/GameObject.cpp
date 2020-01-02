#include "pch.h"
#include "GameObject.h"



void GameObject::SetPos(float x, float y)
{
	m_tInfo.fX = x;
	m_tInfo.fY = y;
}

const INFO& GameObject::GetInfo()
{
	return m_tInfo;
}

const Direction& GameObject::GetDir()
{
	return m_eDir;
}

void GameObject::DontEscapeMap()
{
	if (SCREEN_X < m_tInfo.fX)
		m_tInfo.fX = 0;
	if (0 > m_tInfo.fX)
		m_tInfo.fX = SCREEN_X - 1;
	if (SCREEN_Y < m_tInfo.fY)
		m_tInfo.fY = 0;
	if (0 > m_tInfo.fY)
		m_tInfo.fY = SCREEN_Y - 1;
}

void GameObject::UpdateRect()
{
	m_Rect.left		= LONG(m_tInfo.fX - m_tInfo.fWidthHalf );
	m_Rect.top		= LONG(m_tInfo.fY - m_tInfo.fHeightHalf);
	m_Rect.right	= LONG(m_tInfo.fX + m_tInfo.fWidthHalf );
	m_Rect.bottom	= LONG(m_tInfo.fY + m_tInfo.fHeightHalf);
}

void GameObject::SetDead()
{
	m_bIsDead = true;
}

const RECT& GameObject::GetRect()
{
	return m_Rect;
}

bool GameObject::IsEscapeMap()
{
	if (SCREEN_X < m_tInfo.fX)
		return true;
	if (0 > m_tInfo.fX)
		return true;
	if (SCREEN_Y < m_tInfo.fY)
		return true;
	if (0 > m_tInfo.fY)
		return true;
	return false;
}

GameObject::GameObject() : m_eDir(UP)
{
	m_eDir = UP;	// 디폴트 방향지정
}

GameObject::~GameObject()
{
	
}
