#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"

void Player::InputKey()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{	// m_fAngle�� degree���� �ﰢ�Լ�(���Ȱ�) �̿����Ѵ�.
		// y���� ��ī��Ʈ ��ǥ�� winAPi ��ǥ�� �ݴ뿩�� -
		// ��) ���� = ��׸� * PI / 180
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

	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_iBulletCount++;
		if (m_iBulletCount > 100)
		{
			SetLockOn();
			m_iBulletCount = 0;
		}
	}
	UpdateGunPos();
}

void Player::UpdateGunPos()
{
	m_GunPos.x = m_tInfo.fX + cosf(m_fAngle * PI / 180) * m_fGunLength;
	m_GunPos.y = m_tInfo.fY + -sinf(m_fAngle* PI / 180) * m_fGunLength;
}

void Player::CheckMapOut()
{	// ���� ����� �ݴ����� ������ ��.
	if (m_Rect.left > SCREEN_X)
		m_tInfo.fX = -m_tInfo.fWidth / 2;
	else if(m_Rect.right < 0)
		m_tInfo.fX = SCREEN_X + m_tInfo.fWidth/2;

	if (m_Rect.bottom < 0)
		m_tInfo.fY = SCREEN_Y + m_tInfo.fHeight / 2;
	else if (m_Rect.top > SCREEN_Y)
		m_tInfo.fY = -m_tInfo.fHeight / 2;
}

int Player::CheckNearMonster()
{
	float x, y;
	float min = 0;
	float temp = 0;
	int iCount = 0;
	int iIndex = 0;
	for (auto iter = m_Monsters->begin(); iter != m_Monsters->end(); ++iter)
	{
		x = (*iter)->GetInfo().fX;
		y = (*iter)->GetInfo().fY;
		temp = sqrtf(pow(x - m_GunPos.x, 2) + pow(y - m_GunPos.y, 2));
		if (temp < min || min == 0)
		{
			min = temp;
			iIndex = iCount;	
		}
		++iCount;
	}
	return iIndex;
}

void Player::SetShoot()
{
	// std::advance ����Ʈ�� ���� �� �����̳ʸ� �ε����� �����ϰ� ���ִ� �Լ�.
	auto iter = m_Bullets->begin();
	std::advance(iter, m_iBulletIndex);
	(*iter)->SetPos(m_GunPos.x, m_GunPos.y);
	dynamic_cast<Bullet*>(*iter)->SetShoot(m_fAngle);
	++m_iBulletIndex;
	m_iBulletIndex %= 100;
}

void Player::SetLockOn()
{
	// std::advance ����Ʈ�� ���� �� �����̳ʸ� �ε����� �����ϰ� ���ִ� �Լ�.
	auto iter = m_Bullets->begin();
	auto iter2 = m_Monsters->begin();
	std::advance(iter, m_iBulletIndex);
	std::advance(iter2, CheckNearMonster());
	(*iter)->SetPos(m_GunPos.x, m_GunPos.y);
	dynamic_cast<Bullet*>(*iter)->SetLockOn(*iter2);
	++m_iBulletIndex;
	m_iBulletIndex %= 100;
}

void Player::SetBullets(OBJECT_LIST* bullets)
{
	m_Bullets = bullets;
}

void Player::SetShield(OBJECT_LIST* shield)
{
	m_Shield = shield;
}

void Player::SetMonster(OBJECT_LIST* monsters)
{
	m_Monsters = monsters;
}

void Player::Initialize()
{
	// �θ� 
	m_fSpeed		= 200.0f;
	m_fAngle		= 0;
	m_tInfo.fWidth  = PLAYER_X;
	m_tInfo.fHeight = PLAYER_Y;

	// Player ����
	m_fGunLength	= 100.0f;
	m_GunPos.x		= 0;
	m_GunPos.y		= 0;

	// �Ѿ�
	m_iBulletCount  = 999;			// ù�߻�� �����̰� ���ֱ� ���ؼ�.
	m_iBulletIndex  = 0;

}

void Player::Update()
{
	InputKey();
	CheckMapOut();
}

void Player::Render(HDC hdc)
{
	GameObject::UpdateRect();

	//// �ؽ�Ʈ
	//TCHAR szBuf[64] = L"";
	//swprintf_s(szBuf, L"X = %f, Y = %f", m_tInfo.fX, m_tInfo.fY);
	////DrawText: ������ �簢�� ���� �ȿ� �ؽ�Ʈ ���
	//RECT rc = { 100, 100, 200, 200 };
	//DrawText(hdc, szBuf, lstrlen(szBuf), &rc, DT_NOCLIP);
	
	// �ѱ� ��
	MoveToEx(hdc, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hdc, m_GunPos.x, m_GunPos.y);

	// ��ü
	Ellipse(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void Player::Release()
{
}

Player::~Player()
{
	Release();
}
