#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// main function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) 
{
    WNDCLASS wndclass;
    HWND hwnd;
    MSG msg;

// window class reset and Enrollment os
    wndclass.style = CS_HREDRAW | CS_VREDRAW; // styling
    wndclass.lpfnWndProc = WndProc; // Window Procedure name
    wndclass.cbClsExtra = 0; // Extra Memory(0byte)
    wndclass.cbWndExtra = 0; // Extra Memory(0byte)
    wndclass.hInstance = hInstance; // Instance handle
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Icon shape
    wndclass.hCursor = LoadCursor(NULL,IDC_ARROW); // Cursor shape
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // Background color
    wndclass.lpszMenuName = NULL; // Menu(NULL-->No Menu)
    wndclass.lpszClassName = TEXT("HelloClass"); // WindowClass Name
    if(!RegisterClass(&wndclass)) return 1;

    // Create Window & Pop on the screen
    hwnd = CreateWindow(TEXT("HelloClass"),TEXT("HelloSDK"),
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd,nCmdShow);

    // Get messages from the message queue one by one and process them
    while(GetMessage(&msg,NULL,0,0)>0){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message,
                        WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    const TCHAR *str = TEXT("Hello, SDK");

    // Appropriate handling according to the type of message generated
    switch(message){
    case WM_CREATE:
        return 0;
    case WM_LBUTTONDOWN:
        MessageBox(hwnd,TEXT("마우스 클릭!"),TEXT("마우스 메시지"),MB_OK);
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd,&ps);
        TextOut(hdc,100,100,str,lstrlen(str));
        EndPaint(hwnd,&ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    // Messages that are not processed by the application are processed by the operating system.
    return DefWindowProc(hwnd,message,wParam,lParam);
}