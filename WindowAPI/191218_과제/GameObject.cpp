#include "pch.h"
#include "GameObject.h"

void GameObject::SetPos(float x, float y)
{
	m_tInfo.fCenterX = x;
	m_tInfo.fCenterY = y;
}

void GameObject::UpdateRect()
{
	m_tRect.left	= LONG(m_tInfo.fCenterX - m_tInfo.fWidth  * 0.5f);
	m_tRect.top		= LONG(m_tInfo.fCenterY - m_tInfo.fHeight * 0.5f);
	m_tRect.right	= LONG(m_tInfo.fCenterX + m_tInfo.fWidth  * 0.5f);
	m_tRect.bottom	= LONG(m_tInfo.fCenterY + m_tInfo.fHeight * 0.5f);
}

GameObject::GameObject() : m_fSpeed(0.0f), m_tDir(Direction::UP)
{
}
