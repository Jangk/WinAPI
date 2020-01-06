#pragma once
#ifndef __CREATEMANAGER_H__
#define __CREATEMANAGER_H__
class GameObject;
template<typename T>
class CreateManager
{
private:

public:
	static GameObject* CreateObject()
	{
		GameObject* obj = new T;
		obj->Initializes();
		return obj;
	}

	static GameObject* CreateObject(float x, float y)
	{
		GameObject* obj = new T;
		obj->Initialize();
		obj->SetPos(x, y);
		return obj;
	}
};

#endif // !__CREATEMANAGER_H__