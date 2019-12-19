#pragma once
#include "GameObject.h"
class Monster :	public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	// GameObject��(��) ���� ��ӵ�
	virtual void Render(HDC hdc) override;

	void CollisionBullet(Bullet* bullet);
private:
	bool m_bIsDead;
};

