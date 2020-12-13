#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <process.h>
using namespace std;

HWND b1,b2,b3,b4;
HWND g1,g2,g3,g4;
HWND op1,op2,op3;
int cb1=0,cb2=0,cb3=0,cb4=0,cg1=0,cg2=0,cg3=0,cg4=0;
int password = 1234;

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);


TCHAR szClassName[ ] = _T("Election system App");

int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow)
{
	
    HWND hwnd;             
    MSG messages;           
    WNDCLASSEX wincl;       

 
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      
    wincl.style = CS_DBLCLKS;                
    wincl.cbSize = sizeof (WNDCLASSEX);

 
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                
    wincl.cbClsExtra = 0;                     
    wincl.cbWndExtra = 0;                      
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;


    if (!RegisterClassEx (&wincl))
        return 0;

 
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Election system App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           600,                 /* The programs width */
           500,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

   
    ShowWindow (hwnd, nCmdShow);

   
    while (GetMessage (&messages, NULL, 0, 0))
    {
     
        TranslateMessage(&messages);
     
        DispatchMessage(&messages);
    }

  
    return messages.wParam;
}



void des_buttonb()
    {
       DestroyWindow(b1);
       DestroyWindow(b2);
       DestroyWindow(b3);
       DestroyWindow(b4);
    }
void des_buttong()
    {
       DestroyWindow(g1);
       DestroyWindow(g2);
       DestroyWindow(g3);
       DestroyWindow(g4);
    }
int check_window(void)
{
	int status = 16;
	if(IsWindow(b1) == 0 && IsWindow(b2) == 0 && IsWindow(b3) == 0 && IsWindow(b4) == 0 && IsWindow(g1) == 0 && IsWindow(g2) == 0 && IsWindow(g3) == 0 && IsWindow(g4) == 0)
	{
		status = 0;
	}
	return status;
}
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
																							
    void des_buttonb();
    void des_buttong();
    int check_window();

    switch (message)                  
    {
    case WM_CREATE:

        CreateWindow("STATIC","candidate 1",WS_CHILD|WS_BORDER|WS_VISIBLE,20,20,100,20,hwnd,NULL,NULL,NULL);
        CreateWindow("STATIC","candidate 2",WS_CHILD|WS_BORDER|WS_VISIBLE,20,60,100,20,hwnd,NULL,NULL,NULL);
        CreateWindow("STATIC","candidate 3",WS_CHILD|WS_BORDER|WS_VISIBLE,20,100,100,20,hwnd,NULL,NULL,NULL);
        CreateWindow("STATIC","candidate 4",WS_CHILD|WS_BORDER|WS_VISIBLE,20,140,100,20,hwnd,NULL,NULL,NULL);
        CreateWindow("STATIC","candidate 5",WS_CHILD|WS_BORDER|WS_VISIBLE,20,180,100,20,hwnd,NULL,NULL,NULL);
        CreateWindow("STATIC","candidate 6",WS_CHILD|WS_BORDER|WS_VISIBLE,20,220,100,20,hwnd,NULL,NULL,NULL);
        CreateWindow("STATIC","candidate 7",WS_CHILD|WS_BORDER|WS_VISIBLE,20,260,100,20,hwnd,NULL,NULL,NULL);
        CreateWindow("STATIC","candidate 8",WS_CHILD|WS_BORDER|WS_VISIBLE,20,300,100,20,hwnd,NULL,NULL,NULL);
        b1 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,20,80,20,hwnd,(HMENU) 1,NULL,NULL);
        b2 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,60,80,20,hwnd,(HMENU) 2,NULL,NULL);
        b3 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,100,80,20,hwnd,(HMENU) 3,NULL,NULL);
        b4 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,140,80,20,hwnd,(HMENU) 4,NULL,NULL);
        g1 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,180,80,20,hwnd,(HMENU) 11,NULL,NULL);
        g2 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,220,80,20,hwnd,(HMENU) 12,NULL,NULL);
        g3 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,260,80,20,hwnd,(HMENU) 13,NULL,NULL);
        g4 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,300,80,20,hwnd,(HMENU) 14,NULL,NULL);
        op1 = CreateWindow("BUTTON","Show",WS_CHILD|WS_BORDER|WS_VISIBLE,20,340,50,20,hwnd,(HMENU) 21,NULL,NULL);
        op2 = CreateWindow("BUTTON","Reset",WS_CHILD|WS_BORDER|WS_VISIBLE,220,340,50,20,hwnd,(HMENU) 22,NULL,NULL);
        op3 = CreateWindow("BUTTON","Exit",WS_CHILD|WS_BORDER|WS_VISIBLE,460,340,50,20,hwnd,(HMENU) 23,NULL,NULL);
        break;

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
            case 1:
            cb1++;
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd,"You have elected candidate 1","Elected",MB_OK);
            des_buttonb();
            des_buttong();
            break;

            case 2:
            cb2++;
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd,"You have elected candidate 2","Elected",MB_OK);
            des_buttonb();
             des_buttong();
            break;

            case 3:
            cb3++;
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd,"You have elected candidate 3","Elected",MB_OK);
            des_buttonb();
             des_buttong();
            break;

            case 4:
            cb4++;
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd,"You have elected candidate 4","Elected",MB_OK);
            des_buttonb();
             des_buttong();
            break;

            case 11:
             cg1++;
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd,"You have elected candidate 5","Elected",MB_OK);
            des_buttong();
             des_buttonb();

            break;

            case 12:
            cg2++;
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd,"You have elected candidate 6","Elected",MB_OK);
            des_buttong();
             des_buttonb();

            break;

            case 13:
            cg3++;
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd,"You have elected candidate 7","Elected",MB_OK);
            des_buttong();
             des_buttonb();

            break;

            case 14:
            cg4++;
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd,"You have elected candidate 8","Elected",MB_OK);
            des_buttong();
             des_buttonb();

            break;

            case 21:
            int temp;
            cout<<"Enter password:";
            cin>>temp;
            cout<<endl;

            if( temp == 1)
            {
            	int ch;
                system("cls");
                cout<<"Candidate 1: "<<cb1<<endl;
                cout<<"Candidate 2: "<<cb2<<endl;
                cout<<"Candidate 3: "<<cb3<<endl;
                cout<<"Candidate 4: "<<cb4<<endl;
                cout<<"Candidate 5: "<<cg1<<endl;
                cout<<"Candidate 6: "<<cg2<<endl;
                cout<<"Candidate 7: "<<cg3<<endl;
                cout<<"Candidate 8: "<<cg4<<endl;
               
                
            }
            else
            {
                cout<<"Sorry wrong password!!!"<<endl;
            }
            temp = 0;
            break;

            case 22:

			if(check_window() == 0)
			{
            b1 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,20,80,20,hwnd,(HMENU) 1,NULL,NULL);
            b2 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,60,80,20,hwnd,(HMENU) 2,NULL,NULL);
            b3 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,100,80,20,hwnd,(HMENU) 3,NULL,NULL);
            b4 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,140,80,20,hwnd,(HMENU) 4,NULL,NULL);
            g1 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,180,80,20,hwnd,(HMENU) 11,NULL,NULL);
            g2 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,220,80,20,hwnd,(HMENU) 12,NULL,NULL);
            g3 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,260,80,20,hwnd,(HMENU) 13,NULL,NULL);
            g4 = CreateWindow("BUTTON","Press here",WS_CHILD|WS_BORDER|WS_VISIBLE,460,300,80,20,hwnd,(HMENU) 14,NULL,NULL);
            }
            else
            {
				::MessageBox(hwnd,"Complete the election first","Error",MB_OK);
			}

            break;

            case 23:
            PostQuitMessage(0);
            break;
        }

        default:                    
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
