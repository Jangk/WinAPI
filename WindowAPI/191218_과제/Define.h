#pragma once
#ifndef __DEFINE_H__


#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define MONSTER_MAX 5
extern HWND g_hWnd;



#define SAFE_DELETE(ptr) {if(nullptr != ptr) delete(ptr);ptr =nullptr;}

#define __DEFINE_H__
#endif // !__DEFINE_H__
