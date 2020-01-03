#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public : 
	void InputKey();
	void UpdateGunPos();
	void CheckMapOut();
	int CheckNearMonster();
	void SetShoot();
	void SetLockOn();
	void SetBullets(OBJECT_LIST* bullets);
	void SetShield(OBJECT_LIST* shield);
	void SetMonster(OBJECT_LIST* monsters);

public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC) override;
	virtual void Release() override;
	virtual void IsDead() override;
	~Player();

private:
	OBJECT_LIST* m_Bullets;
	OBJECT_LIST* m_Shield;
	OBJECT_LIST* m_Monsters;
	POINT m_GunPos;
	float m_fGunLength;
	int m_iBulletIndex;
	int m_iBulletCount;
};

