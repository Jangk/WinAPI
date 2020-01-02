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
	PLAYER_BULLET,
	MONSTER_BULLET,
	GAMEOBJECT_END
};

enum EventType
{
	DEAD,
	NO_EVENT
};

enum MonsterType
{
	MONSTER1,
	MONSTER2,
	MONSTER3
};
#endif // !__ENUM_H__
