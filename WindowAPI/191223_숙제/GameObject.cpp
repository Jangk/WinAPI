#include "pch.h"
#include "GameObject.h"

void GameObject::UpdateRect()
{
	m_Rect.left	  = m_tInfo.fX - m_tInfo.fWidth  / 2;
	m_Rect.top	  = m_tInfo.fY - m_tInfo.fHeight / 2;
	m_Rect.right  = m_tInfo.fX + m_tInfo.fWidth  / 2;
	m_Rect.bottom = m_tInfo.fY + m_tInfo.fHeight / 2;
}

void GameObject::SetPos(float x, float y)
{
	m_tInfo.fX = x;
	m_tInfo.fY = y;
	UpdateRect();
}
