// Demo_Project.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Demo_Project.h"
#include "Ellipse.h"
#include "Rectangle.h"

#include <vector>
using namespace std;
#define MAX_LOADSTRING 100
typedef int(*AddFunc)(std::vector<CPolygon*> &vectorInput, int);
typedef void(*FunctionFunc)();


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DEMO_PROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEMO_PROJECT));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEMO_PROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DEMO_PROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
HWND hedit , crlInput;
HWND hwndButton;
vector<void*> vec;
HINSTANCE hInstLibrary;
AddFunc _AddFunc;
FunctionFunc _FunctionFunc;
void Draw(std::vector<void*> &vectorInput, HWND hWnd)
{
	for each (void* attack in vectorInput) // Problem part
	{
		CPolygon* attack2 = static_cast<CPolygon*>(attack);
		int nLeftRect = attack2->nBottomRect;
		attack2->draw(hWnd);
		delete attack2;
		int a = 0;
	}
}
int Add(std::vector<void*> &vectorInput, int b)
{
	CRectangle * demo = new CRectangle();
	demo->nLeftRect = 0;
	demo->nTopRect = 0;
	demo->nRightRect = 300;
	demo->nBottomRect = 300;
	vectorInput.push_back(static_cast<CRectangle *>(demo));
	CEllipse * demo2 = new CEllipse();
	demo2->nLeftRect = 100;
	demo2->nTopRect = 100;
	demo2->nRightRect = 300;
	demo2->nBottomRect = 300;
	vectorInput.push_back(static_cast<CEllipse *>(demo2));
	return(b);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	int width;
	int height;
	CRectangle demo;
	CRectangle * hinhcn = new CRectangle();
	hinhcn->nBottomRect = 10;
	//vec.push_back(static_cast<CRectangle*>(hinhcn));
	
    switch (message)
    {
	case WM_CREATE:
		RECT rect;
		if (GetWindowRect(hWnd, &rect))
		{
			 width = rect.right - rect.left;
			 height = rect.bottom - rect.top;
			
		}
		hedit = CreateWindow(
			TEXT("EDIT"), TEXT(""),
			WS_CHILD | WS_VISIBLE | ES_LEFT | ES_WANTRETURN |
			ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_MULTILINE |
			WS_VSCROLL | WS_HSCROLL,
			width/2, 0, width, height, hWnd,  // use WM_SIZE and MoveWindow() to size
			NULL, GetModuleHandle(NULL), NULL);
		crlInput=  CreateWindow(
			TEXT("EDIT"), TEXT(""),
			WS_CHILD | WS_VISIBLE | ES_LEFT | ES_WANTRETURN |
			ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_MULTILINE |
			WS_VSCROLL | WS_HSCROLL,
			0, 0, width/2, height/2, hWnd,  // use WM_SIZE and MoveWindow() to size
			NULL, GetModuleHandle(NULL), NULL);
		hwndButton = CreateWindow(
			L"BUTTON",  // Predefined class; Unicode assumed 
			L"OK",      // Button text 
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
			10,         // x position 
			300,         // y position 
			100,        // Button width
			100,        // Button height
			hWnd,     // Parent window
			NULL,       // No menu.
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
			NULL);      // Pointer not needed.

		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
              //  DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				

				/* hInstLibrary = LoadLibrary(L"DLL.dll");
				_AddFunc = (AddFunc)GetProcAddress(hInstLibrary, "Add");
				_AddFunc(vec, 1);
				demo.nLeftRect = 0;
				demo.nTopRect = 0;
				demo.nRightRect = 300;
				demo.nBottomRect = 300;
				demo.draw(crlInput);*/
				Add(vec, 1);
				Draw(vec, hWnd);

                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
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

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
