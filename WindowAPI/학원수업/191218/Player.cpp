#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
	: m_fSpeed(0.f)
{
}


CPlayer::~CPlayer()
{
	Release();
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

	return 0;
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
	// 0x0000: Ű�� �������� ����.
	// 0x0001: ������ ���Ⱦ���.
	// 0x8000: ���� �������� ������ �ȴ�����.
	// 0x8001: ���絵 �������� ������.
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_tInfo.fX -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_tInfo.fX += m_fSpeed;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tInfo.fY -= m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tInfo.fY += m_fSpeed;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		// ����1.
		// �Ѿ� ��������		
	}
}

