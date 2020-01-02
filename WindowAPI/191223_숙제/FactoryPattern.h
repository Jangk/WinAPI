#pragma once
#ifndef __FACTORYPATTERN_H__
#define __FACTORYPATTERN_H__

template<typename T>
class GameObjectCreator
{
public:
	// default create
	static GameObject* CreateGameObject()
	{
		GameObject* obj = new T;
		obj->Initialize();
		return obj;
	}

	// SetPos Create
	static GameObject* CreateGameObject(float x, float y)
	{
		GameObject* obj = new T;
		obj->Initialize();
		obj->SetPos(x, y);
		return obj;
	}
};

#endif // !__FACTORYPATTERN_H__
