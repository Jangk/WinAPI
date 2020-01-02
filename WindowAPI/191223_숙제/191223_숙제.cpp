// 191223_숙제.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "191223_숙제.h"
#include "MainGame.h"

#define MAX_LOADSTRING 100


// 과제1.
// - a눌리면 쉴드 생성
// - 쉴드 오브젝트 만들기
// - 쉴드가 어떻게 타겟(플레이어)를 불러올것인가.

// 과제2
// - 플레이어 따라가는 몬스터
// - 몬스터와 플레이어 각도를 구하고 그각도로 움직이게 할것. 
//   acosf(밑변/빗면) asin(높이/빗면) 이용할것.(역삼각함수) 이번과제는 acosf만 사용해서 만들것.

// 과제3
// - s키를 눌리면 몬스터를 추적하는 유도미사일 구현(미사일 기준으로 가까운 몬스터를 추적)


// 전역 변수:
// exturn
HWND            g_hWnd;
float           g_fDeltaTime;


HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY191223, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY191223));


    MSG msg;
    MainGame CMainGame;
  

    // 타이머 관련 부분. 
    // https://moai27.tistory.com/58
    _LARGE_INTEGER tSecond;
    _LARGE_INTEGER tLastTime;
    _LARGE_INTEGER tCurTime;
    // 초당 쿨럭수(성능) 구하기.
    QueryPerformanceFrequency(&tSecond);
    // 이전 프레임 쿨럭수 구하기.
    QueryPerformanceCounter(&tLastTime);
    // deltaTime = (현재 클럭 - 이전 프레임 클럭수) / 성능 클럭 수
    // deltaTime = (현재 클럭 - g_tTime) / g_tSecond)
   

    CMainGame.Initialize();
    msg.message = WM_NULL;

    // 기본 메시지 루프입니다:
    while (WM_QUIT != msg.message)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        QueryPerformanceCounter(&tCurTime);
        g_fDeltaTime = (tCurTime.QuadPart - tLastTime.QuadPart) / (float)tSecond.QuadPart;
        tLastTime = tCurTime;

        CMainGame.Update();
        CMainGame.Render();
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY191223));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, SCREEN_X, SCREEN_Y, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   g_hWnd = hWnd;
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
        if (VK_ESCAPE == wParam)
            DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}