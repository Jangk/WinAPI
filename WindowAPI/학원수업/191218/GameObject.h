#pragma once

#ifndef __GAMEOBJECT_H__

class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	void SetPos(float x, float y);

public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;

protected:
	virtual void Release() = 0;	

protected:
	void UpdateRect();

protected:
	INFO	m_tInfo;
	RECT	m_tRect;
};

#define __GAMEOBJECT_H__
#endif

