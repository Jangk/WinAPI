#include "pch.h"
#include "Player.h"

void Player::Initialize()
{
	Bullet* bullet;
	m_tInfo.fCenterX = static_cast<float>(SCREEN_WIDTH*0.5f);
	m_tInfo.fCenterY = static_cast<float>(SCREEN_HEIGHT *0.5f);
	m_tInfo.fWidth	 = 100.f;
	m_tInfo.fHeight  = 100.f;

	m_fSpeed = 5.f;
	m_tDir = Direction::UP;

	for (int i = 0; i < m_iBullet_Max; ++i)
	{
		bullet = new Bullet;
		bullet->Initialize();
		m_Bullets.push_back(bullet);
	}
}

void Player::Update()
{
	for (auto& bullet : m_Bullets)
		bullet->Update();
	KeyInput();
}

void Player::Render(HDC hdc)
{
	Rectangle(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	for (auto& bullet : m_Bullets)
	{
		if (bullet->IsShoot())
			bullet->Render(hdc);
	}
	
}

void Player::Release()
{
	
}

void Player::KeyInput()
{
	// 0x0000: 키가 눌려있지 않음.
	// 0x0001: 이전에 눌렸었음.
	// 0x8000: 현재 눌렸지만 이전엔 안눌렸음.
	// 0x8001: 현재도 이전에도 눌렸음.
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_tInfo.fCenterX -= m_fSpeed;
		m_tDir = Direction::Left;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_tInfo.fCenterX += m_fSpeed;
		m_tDir = Direction::Right;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_tInfo.fCenterY -= m_fSpeed;
		m_tDir = Direction::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_tInfo.fCenterY += m_fSpeed;
		m_tDir = Direction::Down;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_Bullets[m_iBulletIndex]->SetShoot(m_tInfo.fCenterX, m_tInfo.fCenterY, m_tDir);
		m_iBulletIndex++;
		m_iBulletIndex %= m_iBullet_Max;
	}
}

const vector<Bullet*>& Player::GetBullets() const
{
	return m_Bullets;
}
