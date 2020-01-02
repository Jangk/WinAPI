#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public : 
	void InputKey();
	void UpdateGunPos();
	void SetShoot();
	void CheckMapOut();

public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC) override;
	virtual void Release() override;
	~Player();

private:
	GameObject* m_Bullets[100];
	POINT m_GunPos;
	float m_fGunLength;
	int m_iBulletIndex;


	int m_iBulletCount;

	
};

