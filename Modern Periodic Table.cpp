#include<windows.h>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

#define GENERATE_BUTTON 1

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND textfield, button;

/*  Make the class name into a global variable  */
char szClassName[ ] = "CodeBlocksWindowsApp";

using namespace std;

struct Elements
{
	string name , symbol, chem_act, atomic_no,mass_no;

	Elements(string atomic , string s  , string n , string mass )
	{	
		this->name = n;
		this->symbol = s;
		//this->chem_act= chem;
		this->atomic_no = atomic;
		this->mass_no = mass;
	}
	string getName()
	{
		return name;
	}

};

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
	{
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1245, 1000);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1175, 1000);
	}
	
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
// file reading
    string line;
	ifstream myfile ("periodic.csv");
	vector<Elements> AllElements;
	if (myfile.is_open())

  {  
    while ( getline (myfile,line) )
    {
    	stringstream ss(line);
    	string token;
    	//Elements element;
    	string props[4] = {" " , " " , " " , " "};
    	int count = 0;
     	while (getline(ss,token, ','))
		{
		    props[count] = token;
		    count++;
		}
		AllElements.push_back(  Elements( props[0] , props[1] , props[2]  , props[3] )  );

    }
  }

    /* The Window structure */
    wincl.hInstance = hThisInstance;          // instant or id of application for registration
    wincl.lpszClassName = szClassName;        //  class declaration
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);       // data structure for window

    /* Use default icon and mouse-pointer */
    // for button icon
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);   
	//   
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    // for cursor
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return -1;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Modern Periodic Table",       /* Title Text */
           WS_MINIMIZEBOX | WS_SYSMENU, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1000,                 /* The programs width */
           750,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
	    case WM_CREATE:
	
	        
	
	
	        textfield = CreateWindow("EDIT",
	                                 " MODERN PERIODIC TABLE",
	                                 WS_VISIBLE | WS_CHILD,
	                                 350, 25, 185, 35,
	                                 hwnd, NULL, NULL, NULL);
	        CreateWindow("BUTTON",
	                              "H",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               120, 150, 60, 50,
	                               hwnd,(HMENU) 1, NULL, NULL);
	        CreateWindow("BUTTON",
	                              "Li",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               120, 190, 60, 50,
	                               hwnd, (HMENU) 2, NULL, NULL);
	        CreateWindow("BUTTON",
	                              "Na",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               120, 230, 60, 50,
	                               hwnd, (HMENU) 3, NULL, NULL);
	        CreateWindow("BUTTON",
	                              "K",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               120, 270, 60, 50,
	                               hwnd,(HMENU) 4, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Rb",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               120, 310, 60, 50,
	                               hwnd, (HMENU) 5, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Cs",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               120, 350, 60, 50,
	                               hwnd, (HMENU) 6, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Fr",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               120, 390, 60, 50,
	                               hwnd, (HMENU) 7, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Be",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               180, 190, 60, 50,
	                               hwnd, (HMENU) 8, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Mg",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               180, 230, 60, 50,
	                               hwnd, (HMENU) 9, NULL, NULL);
			button = CreateWindow("BUTTON",
	                              "Ca",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               180, 270, 60, 50,
	                               hwnd, (HMENU) 10, NULL, NULL);
			button = CreateWindow("BUTTON",
	                              "Sr",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               180, 310, 60, 50,
	                               hwnd, (HMENU) 11, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Ba",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               180, 350, 60, 50,
	                               hwnd, (HMENU) 12, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Ra",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               180, 390, 60, 50,
	                               hwnd, (HMENU) 13, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "B",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               380, 190, 60, 50,
	                               hwnd, (HMENU) 14, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Al",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               380, 230, 60, 50,
	                               hwnd, (HMENU) 15, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Ga",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               380, 270, 60, 50,
	                               hwnd, (HMENU) 16, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "In",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               380, 310, 60, 50,
	                               hwnd, (HMENU) 17, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Ti",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               380, 350, 60, 50,
	                               hwnd, (HMENU) 18, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "C",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               440, 190, 60, 50,
	                               hwnd, (HMENU) 19, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Si",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               440, 230, 60, 50,
	                               hwnd, (HMENU) 20, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Ge",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               440, 270, 60, 50,
	                               hwnd, (HMENU) 21, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Sn",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               440, 310, 60, 50,
	                               hwnd, (HMENU) 22, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Pb",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               440, 350, 60, 50,
	                               hwnd, (HMENU) 23, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "N",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               500, 190, 60, 50,
	                               hwnd, (HMENU) 24, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "P",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               500, 230, 60, 50,
	                               hwnd, (HMENU) 25, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "As",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               500, 270, 60, 50,
	                               hwnd, (HMENU) 26, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Sb",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               500, 310, 60, 50,
	                               hwnd, (HMENU) 27, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Bi",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               500, 350, 60, 50,
	                               hwnd, (HMENU) 28, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "O",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               560, 190, 60, 50,
	                               hwnd, (HMENU) 29, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "S",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               560, 230, 60, 50,
	                               hwnd, (HMENU) 30, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Se",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               560, 270, 60, 50,
	                               hwnd, (HMENU) 31, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Te",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               560, 310, 60, 50,
	                               hwnd, (HMENU) 32, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Po",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               560, 350, 60, 50,
	                               hwnd, (HMENU) 33, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "F",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               620, 190, 60, 50,
	                               hwnd, (HMENU) 34, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Cl",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               620, 230, 60, 50,
	                               hwnd, (HMENU) 35, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Br",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               620, 270, 60, 50,
	                               hwnd, (HMENU) 36, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "I",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               620, 310, 60, 50,
	                               hwnd, (HMENU) 37, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "At",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               620, 350, 60, 50,
	                               hwnd, (HMENU) 38, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "He",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               680, 150, 60, 50,
	                               hwnd, (HMENU) 39, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Ne",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               680, 190, 60, 50,
	                               hwnd, (HMENU) 40, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Ar",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               680, 230, 60, 50,
	                               hwnd, (HMENU) 41, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Kr",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               680, 270, 60, 50,
	                               hwnd, (HMENU) 42, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Xe",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               680, 310, 60, 50,
	                               hwnd, (HMENU) 43, NULL, NULL);
	        button = CreateWindow("BUTTON",
	                              "Rn",
	                               WS_VISIBLE | WS_CHILD | WS_BORDER,
	                               680, 350, 60, 50,
	                               hwnd, (HMENU) 44, NULL, NULL);
	        break;
        
	        case WM_COMMAND:
	        switch(LOWORD(wParam))
	        {
	        	case 1:
	        	::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Hydrogen\nSymbol: H\nAtomic Number: 1\nAtomic Mass: 1.00784 \nChemicallay Active: No","H",MB_OK);
	            break;
	            
	            case 2:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Lithium\nSymbol: Li\nAtomic Number: 3\nAtomic Mass: 6.941 \nChemicallay Active: Yes","Li",MB_OK);
	            break;
	            
				case 3:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Sodium\nSymbol: Na\nAtomic Number: 11\nAtomic Mass: 22.989769 \nChemicallay Active: Yes","Na",MB_OK);
	            break;
	            
				case 4:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Potassium\nSymbol: K\nAtomic Number: 19\nAtomic Mass: 39.0983 \nChemicallay Active: Yes","K",MB_OK);
	            break;
	            case 5:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Rubidium\nSymbol: Rb\nAtomic Number: 37\nAtomic Mass: 85.4678 \nChemicallay Active: Yes (radio active)","Rb",MB_OK);
	            break;
	            
				case 6:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name:Caesium\nSymbol: Cs\nAtomic Number: 55\nAtomic Mass: 132.90545 \nChemicallay Active: Yes (radio active)","Cs",MB_OK);
	            break;
	            
				case 7:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name:Francium\nSymbol: Fr\nAtomic Number: 87\nAtomic Mass: 223\nChemicallay Active: Yes (radio active)","Fr",MB_OK);
	            break;
	            
				case 8:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Beryllium \nSymbol: Be\nAtomic Number: 4\nAtomic Mass: 9.012182 \nChemicallay Active: Yes","Be",MB_OK);
	            break;
	            
				case 9:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Magnesium\nSymbol: Mg\nAtomic Number: 12\nAtomic Mass: 24.305 \nChemicallay Active: Yes","Mg",MB_OK);
	            break;
	            
				case 10:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Calcium\nSymbol: Ca\nAtomic Number: 20 \nAtomic Mass: 40.078\nChemicallay Active: Yes","Ca",MB_OK);
	            break;
	            
				case 11:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Strontium\nSymbol: Sr\nAtomic Number: 38\nAtomic Mass: 87.62 \nChemicallay Active: Yes","Sr",MB_OK);
	            break;
	            
				case 12:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Barium\nSymbol: Ba\nAtomic Number: 56 \nAtomic Mass: 137.327\nChemicallay Active: Yes","Ba",MB_OK);
	            break;
	            
				case 13:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Radium\nSymbol: Ra\nAtomic Number: 88\nAtomic Mass: 226 \nChemicallay Active: Yes (radio active)","Ra",MB_OK);
	            break;
	            
				case 14:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Boron\nSymbol: B\nAtomic Number: 5\nAtomic Mass: 10.81 \nChemically Active: Yes","B",MB_OK);
	            break;
	            
				case 15:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Aluminium\nSymbol: Al\nAtomic Number: 13\nAtomic Mass: 26.982 \nChemically active: Yes","Al",MB_OK);
	            break;
	            
				case 16:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Gallium\nSymbol: Ga\nAtomic Number: 31\nAtomic Mass: 69.723\nChemically active: Yes","Ga",MB_OK);
	            break;
	            
				case 17:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Indium\nSymbol: In\nAtomic Number: 49\nAtomic Mass: 114.82\nChemically Active: Yes","In",MB_OK);
	            break;
	            
				case 18:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Thallium\nSymbol: Tl\nAtomic Number: 81\nAtomic Mass: 204.38\nChemically Active: Yes","Tl",MB_OK);
	            break;
	            
				case 19:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Carbon\nSymbol: C\nAtomic Number: 6\nAtomic Mass: 12.011\nChemically Active: Yes","C",MB_OK);
	            break;
	            
				case 20:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Silicon\nSymbol: Si\nAtomic Number: 14\nAtomic Mass: 28.085\nChemically Active: Yes","Si",MB_OK);
	            break;
	            
				case 21:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Gemanium\nSymbol: Ge\nAtomic Number: 32\nAtomic Mass: 72.630\nChemically Active: Yes","Ge",MB_OK);
	            break;
	            
				case 22:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Tin\nSymbol: Sn\nAtomic Number: 50\nAtomic Mass: 118.71\nChemically Active: Yes","Sn",MB_OK);
	            break;
	            
				case 23:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Lead\nSymbol: Pb\nAtomic Number: 82\nAtomic Mass: 207.02\nChemically Active: Yes","Pb",MB_OK);
	            break;
	            
				case 24:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Nitrogen\nSymbol: N\nAtomic Number: 7\nAtomic Mass: 14.007\nChemically Active: Yes","N",MB_OK);
	            break;
	            
				case 25:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Phosporus\nSymbol: P\nAtomic Number: 15\nAtomic Mass: 30.974\nChemically Active: Yes","P",MB_OK);
	            break;
	           	
				case 26:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Arsenic\nSymbol: As\nAtomic Number: 33\nAtomic Mass: 74.922\nChemically Active: Yes","As",MB_OK);
	            break;
	            
				case 27:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Antimony\nSymbol: Sb\nAtomic Number: 51\nAtomic Mass: 121.76\nChemically Active: Yes","Sb",MB_OK);
	            break;
	            
	            case 28:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Bismuth\nSymbol: Bi\nAtomic Number: 83\nAtomic Mass: 208.98\nChemically Active: Yes","Bi",MB_OK);
	            break;
	            
				case 29:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Oxygen\nSymbol: O\nAtomic Number: 8\nAtomic Mass: 15.99\nChemically Active: Yes","O",MB_OK);
	            break;
	            
				case 30:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Sulphur\nSymbol: S\nAtomic Number: 16\nAtomic Mass: 32.06\nChemically Active: Yes","S",MB_OK);
	            break;
	            
				case 31:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Selenium\nSymbol: Se\nAtomic Number: 34\nAtomic Mass: 78.971\nChemically Active: Yes","Se",MB_OK);
	            break;
	            
				case 32:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Tellurium\nSymbol: Te\nAtomic Number: 52\nAtomic Mass: 127.60\nChemically Active: Yes","Te",MB_OK);
	            break;
	            
				case 33:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Polonium\nSymbol: Po\nAtomic Number: 84\nAtomic Mass: 209\nChemically Active: Radioactive","Po",MB_OK);
	            break;
	            
				case 34:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Fluorine\nSymbol: F\nAtomic Number: 9\nAtomic Mass: 18.998\nChemically Active: Yes","F",MB_OK);
	            break;
	            
				case 35:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Chlorine\nSymbol: Cl\nAtomic Number: 17\nAtomic Mass: 35.45\nChemically Active: Yes","Cl",MB_OK);
	            break;
	            
				case 36:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Bromine\nSymbol: Br\nAtomic Number: 35\nAtomic Mass: 79.904\nChemically Active: Yes","Br",MB_OK);
	            break;
	            
				case 37:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Iodine\nSymbol: I\nAtomic Number: 53\nAtomic Mass: 126.90\nChemically Active: Yes","I",MB_OK);	           
			    break;
	            
				case 38:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Astatine\nSymbol: At\nAtomic Number: 85\nAtomic Mass: 210\nChemically Active: Radioactive","At",MB_OK);
	            break;
	            
	            case 39:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Helium\nSymbol: He\nAtomic Number: 2\nAtomic Mass: 4.0026\nChemically Reactive: No","He",MB_OK);
	            break;
	            
	            case 40:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Neon\nSymbol: Ne\nAtomic Number: 10\nAtomic Mass: 20.180\nChemically Reactive: No","Ne",MB_OK);
	            break;
	            
	            case 41:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Argon\nSymbol: Ar\nAtomic Number: 18\nAtomic Mass: 39.948\nChemically Reactive: No","Ar",MB_OK);
	            break;
	            
	            case 42:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Krypton\nSymbol: Kr\nAtomic Number: 36\nAtomic Mass: 83.798\nChemically Reactive: No","Kr",MB_OK);
	            break;
	            
	            case 43:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Xenon\nSymbol: Xe\nAtomic Number: 54\nAtomic Mass: 131.29\nChemically Reactive: No","Xe",MB_OK);
	            break;
	            
	            case 44:
	            ::MessageBeep(MB_OK);
	            ::MessageBox(hwnd,"Element Name: Radon\nSymbol: Rn\nAtomic Number: 86\nAtomic Mass: 222\nChemically Reactive: Yes","Rn",MB_OK);          
	            break;  
	        }
	        
			break;
			
	        case WM_DESTROY:
	            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
	            break;
	            
	        default:                      /* for messages that we won't deal with */
	            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
