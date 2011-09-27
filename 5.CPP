 #include <windows.h>
#include "section_1_5_1.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static char gszClassName[]  = "MyWindowClass";
static HINSTANCE ghInstance = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
        WNDCLASSEX WndClass;
        HWND hwnd;
        MSG Msg;

        ghInstance = hInstance;

        WndClass.cbSize        = sizeof(WNDCLASSEX);
        WndClass.style         = NULL;
        WndClass.lpfnWndProc   = WndProc;
        WndClass.cbClsExtra    = 0;
        WndClass.cbWndExtra    = 0;
        WndClass.hInstance     = ghInstance;
        WndClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
        WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
        WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
        WndClass.lpszMenuName  = "ID_MENU";
        WndClass.lpszClassName = gszClassName;
        WndClass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

        if(!RegisterClassEx(&WndClass)) {
                MessageBox(0, "Window Registration Failed!", "Error!", MB_ICONSTOP | MB_OK);
                return 0;
        }

        hwnd = CreateWindowEx(
                WS_EX_STATICEDGE,
                gszClassName,
                "Windows Title",
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, CW_USEDEFAULT,
                320, 240,
                NULL, NULL,
                ghInstance,
                NULL);

        if(hwnd == NULL) {
                MessageBox(0, "Window Creation Failed!", "Error!", MB_ICONSTOP | MB_OK);
                return 0;
        }

        ShowWindow(hwnd, nCmdShow);
        UpdateWindow(hwnd);

        while(GetMessage(&Msg, NULL, 0, 0)) {
                TranslateMessage(&Msg);
                DispatchMessage(&Msg);
        }
        return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
        switch(Message) {
                case WM_CLOSE:
                        DestroyWindow(hwnd);
                        break;
                case WM_DESTROY:
                        PostQuitMessage(0);
                        break;
                case WM_COMMAND:
                        switch(LOWORD(wParam)) {
                                case ID_FILE_NEW:
                                        MessageBox(hwnd, "New File", "Menu", 0);
                                        break;
                                case ID_FILE_OPEN:
                                        MessageBox(hwnd, "Open File", "Menu", 0);
                                        break;
                                case ID_FILE_SAVE:
                                        MessageBox(hwnd, "Save File", "Menu", 0);
                                        break;
                                case ID_FILE_EXIT:
                                        PostQuitMessage(0);
                                case ID_DO_SOMETHING:
                                        MessageBox(hwnd, "Do Something", "Menu", 0);
                                        break;
                                case ID_DO_SOMETHING_ELSE:
                                        MessageBox(hwnd, "Do Something Else", "Menu", 0);
                                        break;
                                case ID_HELP_ABOUT:
                                        MessageBox(hwnd, "Written By AZTEK", "About", 0);
                                        break;
                        }
                        break;
                default:
                        return DefWindowProc(hwnd, Message, wParam, lParam);
        }
        return 0;
}
