#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"

void Player::InputKey()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{	// m_fAngle은 degree지만 삼각함수(라디안값) 이여야한다.
		// y축은 데카르트 좌표와 winAPi 좌표가 반대여서 -
		// 식) 라디안 = 디그리 * PI / 180
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180)* g_fDeltaTime;
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180)* g_fDeltaTime;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_tInfo.fX -= m_fSpeed * cosf(m_fAngle * PI / 180) * g_fDeltaTime;
		m_tInfo.fY += m_fSpeed * sinf(m_fAngle * PI / 180) * g_fDeltaTime;
	}
	
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_fAngle += 180 * g_fDeltaTime;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_fAngle -= 180 * g_fDeltaTime;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000 )
	{
		m_iBulletCount++;
		if (m_iBulletCount > 100)
		{
			SetShoot();
			m_iBulletCount = 0;
		}
	}

	if (GetAsyncKeyState('A') & 0x8000)
		dynamic_cast<Shield*>(m_Shield->front())->SetActive();
	UpdateGunPos();
}

void Player::UpdateGunPos()
{
	m_GunPos.x = m_tInfo.fX + cosf(m_fAngle * PI / 180) * m_fGunLength;
	m_GunPos.y = m_tInfo.fY + -sinf(m_fAngle* PI / 180) * m_fGunLength;
}

void Player::SetShoot()
{
	m_Bullets[m_iBulletIndex]->SetPos(m_GunPos.x, m_GunPos.y);
	dynamic_cast<Bullet*>(m_Bullets[m_iBulletIndex])->SetShoot(m_fAngle);
	++m_iBulletIndex;
	m_iBulletIndex %= 100;
}

void Player::CheckMapOut()
{	// 맵을 벗어나면 반대편에서 나오게 함.
	if (m_Rect.left > SCREEN_X)
		m_tInfo.fX = -m_tInfo.fWidth / 2;
	else if(m_Rect.right < 0)
		m_tInfo.fX = SCREEN_X + m_tInfo.fWidth/2;

	if (m_Rect.bottom < 0)
		m_tInfo.fY = SCREEN_Y + m_tInfo.fHeight / 2;
	else if (m_Rect.top > SCREEN_Y)
		m_tInfo.fY = -m_tInfo.fHeight / 2;
}

void Player::SetShield(OBJECT_LIST* shield)
{
	m_Shield = shield;
}

void Player::Initialize()
{
	// 부모 
	m_tInfo.fX		= 0;
	m_tInfo.fY		= 0;
	m_tInfo.fWidth  = PLAYER_X;
	m_tInfo.fHeight = PLAYER_Y;

	// Player 변수
	m_fAngle		= 0;
	m_fGunLength	= 100.0f;
	m_fSpeed		= 200.0f;
	m_GunPos.x		= 0;
	m_GunPos.y		= 0;

	// 총알
	m_iBulletCount  = 999;			// 첫발사는 딜레이가 없애기 위해서.
	m_iBulletIndex  = 0;
	for (int i = 0; i < 100; ++i)
	{
		m_Bullets[i] = new Bullet;
		m_Bullets[i]->Initialize();
	}
}

void Player::Update()
{
	InputKey();
	CheckMapOut();
	for (auto iter : m_Bullets)
		iter->Update();
}

void Player::Render(HDC hdc)
{
	GameObject::UpdateRect();

	//// 텍스트
	//TCHAR szBuf[64] = L"";
	//swprintf_s(szBuf, L"X = %f, Y = %f", m_tInfo.fX, m_tInfo.fY);
	////DrawText: 지정한 사각형 영역 안에 텍스트 출력
	//RECT rc = { 100, 100, 200, 200 };
	//DrawText(hdc, szBuf, lstrlen(szBuf), &rc, DT_NOCLIP);
	
	// 총알
	for (auto iter : m_Bullets)
		iter->Render(hdc);

	// 총구 선
	MoveToEx(hdc, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hdc, m_GunPos.x, m_GunPos.y);

	// 몸체
	Ellipse(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void Player::Release()
{
	for (auto& iter : m_Bullets)
		delete(iter);
}

Player::~Player()
{
	Release();
}
