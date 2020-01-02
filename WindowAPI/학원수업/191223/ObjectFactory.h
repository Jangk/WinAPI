#pragma once

#ifndef __OBJECT_FACTORY_H__

class CGameObject;

/* �߻� ���丮 ���� */
// ��ü ���� ���� �� ĸ��ȭ�� ������ �� ������ ����

template <typename T>
class CObjectFactory 
{
public:
	static CGameObject* CreateObject()
	{
		CGameObject* pObject = new T;
		pObject->Initialize();	

		return pObject;
	}

	static CGameObject* CreateObject(float x, float y)
	{
		CGameObject* pObject = new T;
		pObject->Initialize();
		pObject->SetPos(x, y);

		return pObject;
	}
};

#define __OBJECT_FACTORY_H__
#endif
