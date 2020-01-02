#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual EventType Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


	// �̵� ����
	void SetPlayerPosition(float x, float y);
	Direction SetMovePatten(int iMoveLenght);
	void Move(Direction dir);


	// ��� ����
	void Shoot();

private:
	MonsterType m_MonsterType;
	float m_fPlayerX;
	float m_fPlayerY;
	int m_iMoveCount;
	int m_iDir;
};

