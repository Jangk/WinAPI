#pragma once
#ifndef __ENUM_H__
#define __ENUM_H__

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum GameObjectType
{
	PLAYER,
	MONSTER,
	BULLET,
	GAMEOBJECT_END
};

enum EventType
{
	DEAD,
	NO_EVENT
};
#endif // !__ENUM_H__
