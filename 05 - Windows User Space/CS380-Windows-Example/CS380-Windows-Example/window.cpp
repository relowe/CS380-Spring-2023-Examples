#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int msgCounter = 0;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";
    

    WNDCLASS wc = { };

    //Add the following code to get a console open
    FILE* pConsole;

    AllocConsole();
    freopen_s(&pConsole, "CONIN$", "r", stdin);
    freopen_s(&pConsole, "CONOUT$", "w", stdout);
    freopen_s(&pConsole, "CONOUT$", "w", stderr);

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL
    );

    //create a button
    HWND hButton = CreateWindow(L"BUTTON",
                                L"Click Me",
                                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                                0, 0, 
                                200, 100, 
                                hwnd, (HMENU) 10, hInstance, NULL
        );
    HWND hButton2 = CreateWindow(L"BUTTON",
        L"No, Click Me",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        210, 0,
        200, 100,
        hwnd, (HMENU) 11, hInstance, NULL
    );
    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{ 

    printf("Message #%d - 0x%X\n", ++msgCounter, uMsg);
    switch (uMsg)
    {

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND:
        printf("Received WM_COMMAND\n");
        if (HIWORD(wParam) == BN_CLICKED) {
            printf("  it was a button click\n");
            printf("  it was button id %d\n", LOWORD(wParam));
        }
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}