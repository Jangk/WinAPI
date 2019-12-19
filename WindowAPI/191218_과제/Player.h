#pragma once
#include "GameObject.h"
#include "Bullet.h"
class Player :	public GameObject
{
private:
	vector<Bullet*> m_Bullets;
	const int m_iBullet_Max = 100;
	int m_iBulletIndex = 0;
public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	// GameObject을(를) 통해 상속됨
	virtual void Render(HDC hdc) override;
	void KeyInput();

public:
	const vector<Bullet*>& GetBullets() const;
};

