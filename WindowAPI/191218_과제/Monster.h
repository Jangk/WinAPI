#pragma once
#include "GameObject.h"
class Monster :	public GameObject
{
public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	// GameObject을(를) 통해 상속됨
	virtual void Render(HDC hdc) override;

	void CollisionBullet(Bullet* bullet);
private:
	bool m_bIsDead;
};

