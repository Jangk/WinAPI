#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	void SetShoot(float angle);
	void SetLockOn(GameObject* target);
public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC) override;
	virtual void Release() override;
private:
	GameObject* m_Target;
	bool m_bIsShoot;
	bool m_bIsLockOn;

};

