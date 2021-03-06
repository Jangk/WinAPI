#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer()
	: m_fSpeed(0.f), m_pBulletList(nullptr)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::SetBulletList(OBJECT_LIST* pBulletList)
{
	m_pBulletList = pBulletList;
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 5.f;
}

int CPlayer::Update()
{
	KeyInput();

	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::KeyInput()
{
	// 0x0000: 키가 눌려있지 않음.
	// 0x0001: 이전에 눌렸었음.
	// 0x8000: 현재 눌렸지만 이전엔 안눌렸음.
	// 0x8001: 현재도 이전에도 눌렸음.
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
			m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
			m_tInfo.fY += m_fSpeed / sqrtf(2.f);
		}
		else
			m_tInfo.fX -= m_fSpeed;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_tInfo.fX += m_fSpeed / sqrtf(2.f);
			m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_tInfo.fX += m_fSpeed / sqrtf(2.f);
			m_tInfo.fY += m_fSpeed / sqrtf(2.f);
		}
		else
			m_tInfo.fX += m_fSpeed;
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tInfo.fY -= m_fSpeed;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tInfo.fY += m_fSpeed;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		NULL_CHECK(m_pBulletList);
		m_pBulletList->push_back(CObjectFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY));
	}
}
