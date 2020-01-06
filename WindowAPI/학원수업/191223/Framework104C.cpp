// Framework104C.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Framework104C.h"
#include "Maingame.h"

#define MAX_LOADSTRING 100

// ���� ����:
HWND g_hWnd;
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
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

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_FRAMEWORK104C, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FRAMEWORK104C));

    MSG msg;	
	msg.message = WM_NULL;

	CMaingame	mainGame;
	mainGame.Initialize();

	// GetTickCount: �ü���� ���۵� �ĺ��� �帥 �ð��� 1000���� 1�� ������ ī�����ϴ� �Լ�.
	DWORD dwOldTime = GetTickCount();
	DWORD dwCurTime = 0;

    // �⺻ �޽��� �����Դϴ�.
	while (WM_QUIT != msg.message)
	{
		// PM_REMOVE: �޽��� ť���� ���� ���� �޽����� ������.
		// PM_NOREMOVE: �޽��� ť���� �޽����� �������� �ʰ� �״�� ��.
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		dwCurTime = GetTickCount();
        
		if (dwCurTime - dwOldTime >= 10)
		{
			mainGame.Update();
			mainGame.Render();
        
			dwOldTime = dwCurTime;
		}		
	}	

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FRAMEWORK104C));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	// HINSTANCE: ���� ���α׷��� �ڵ�
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   RECT rc = { 0, 0, WINCX, WINCY };

   // ���� Ŭ���̾�Ʈ ������ ũ�⸦ �����ϴ� �Լ�.
   // ù��° ���ڷ� ����ڰ� ���ϴ� ũ���� RECT�� ����(�Է�)�ϸ� �� ũ�⸸ŭ Ŭ���̾�Ʈ ������ �ݿ��� �ǰ�
   // Ŭ���̾�Ʈ ���� ũ�� + �׵θ� ���� ũ�⸦ �ٽ� ù��° ���ڷ� ���(���)�Ѵ�.
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

   // H (Handle): �ν��Ͻ��� �ĺ��ϰ� �����ϱ� ���� ���� ��. 
   // �ý����� �ο��ϰ� �ߺ� ���� ���� �� ����.
   // HWND: ������ â(������)�� �ڵ�.
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   g_hWnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//CallBack �Լ�: ����ڰ� �ƴ϶� �ý����� ȣ���ϴ� �Լ�.

	// �Լ� ȣ�� �Ծ�
	// ���� ���� ������ ��� �ϸ�, �Լ� ����� �� ���� ������ ���� �� ���ΰ�?
	// __cdecl:		���� ���� ���� ������ -> ���� ����. ȣ���ڰ� stack ����.
	// __stdcall:	���� ���� ���� ������ -> ���� ����. ��ȣ���ڰ� stack ����.
	// __fastcall:	���� ���� ���� ������ -> ���� ����. ��ȣ���ڰ� stack ����.
	// __thiscall:	���� ���� ���� ������ -> ���� ����. ��ȣ���ڰ� stack ����.

    switch (message)
    {      
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		}
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}