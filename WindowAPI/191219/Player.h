#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual EventType Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
	void SetBulletList(OBJECT_LIST* objList);
	void Input();
	~Player();
private :
	OBJECT_LIST* m_BulletList;
};

