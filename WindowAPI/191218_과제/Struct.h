#pragma once
#ifndef __STRUCT_H__
typedef struct tagInfo
{
	float fCenterX, fCenterY;
	float fWidth, fHeight;
}INFO;

enum class Direction
{
	UP,
	Down,
	Left,
	Right,
};

#define __STRUCT_H__
#endif // !__STRUCT_H__
