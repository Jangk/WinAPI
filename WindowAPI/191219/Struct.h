#pragma once
#ifndef __STRUCT_H__
class GameObject;
typedef struct tagPosInfo
{
	float fX, fY;
	float fWidthHalf, fHeightHalf;
}INFO;

typedef list<GameObject*> OBJECT_LIST;

#define __STRUCT_H__
#endif // !__STRUCT_H__
