

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h> 


using namespace std;


bool quit = false;


int direction, goright, upp, down, goleft;
struct point2d {
	int x, y; 
};

struct location {
    int x, y;
};

struct Grid {
	int totalX, totalY;
    void render(location obj, location obj2)
    {
        for (int col = 0; col < totalX; col++) {
            for (int row = 0; row < totalY; row++) {
                if (obj.x == row && obj.y == col)
                {
                    cout << "$";
                }
                else if (obj2.x == row && obj2.y == col) {
                    cout << "#";
                }
                else
                { 
                    cout << "*";
                }
            }
            cout << endl;
        }
    }
};
void input()
{
	
    if (_kbhit()) {
        switch (_getch()) {
        case 'd':
            if (direction != goleft) {
                goright = direction;
                upp = 0, goleft = 0, down = 0;
            }
            break;
        case 'w':
            if (direction != down) {
                upp = direction;
                goright = 0, goleft = 0, down = 0;
            }
            break;
        case 'a':
            if (direction != goright) {
                goleft = direction;
                upp = 0, goright = 0, down = 0;
            }
            break;
        case 's':
			if (direction != upp) {
				down = direction;
				upp = 0, goleft = 0, goright = 0;
			}
        break;
        case 'q':
         quit = true;
            break;
        //BUG in het bewegen van slang na een  paar keer tegen direction te doen.

       }
    }
}

void startlocation() {
    point2d starts = { 8, 15 };
	for (int i = 0; i < starts.x; i++) {
		cout << " ";
	}
    for
        (int i = 0; i < starts.y; i++) {
        cout << endl;
    }
    cout << "*";
}
void draw() {
    int  lengte = 15;
    int breete = 35;
    cout << "#";
    for (int i = 0; i < breete; i++) {
        cout << "-";
        
    }
    cout << "#";
    for (int j = 0; j < lengte; j++) {
         cout << endl << "|" << "                                   " << "|";
    }
    cout << endl << "#";
    for (int i = 0; i < breete; i++) {
        cout << "-";
       
    }
    cout << "#";
}

int main()
{
    int xs = 1, ys = 6, xc =1, yc=1;
    bool start = false;
    bool startbutton = false;
    

    cout  << "Press k to begin!" << endl << endl << "-----------------"<< endl;

    while (start == false) {
        if (_kbhit()) {
            switch (_getch()) {
            case 'k': start = true;
                break;

            }

        }

    }

    while (start == true) {
        direction = 2;
        cout << endl << endl;
        input();
        Grid grid{ 13,17 };
        location obj{ xs,ys }, obj2{ xc ,yc };
        grid.render(obj, obj2);

        if (direction == goright) {  
            xs++;
        }
        if (direction == goleft) {
            xs--;
        }
        if (direction == upp) {
            ys--;
        }
        if (direction == down) {
            ys++;
        }
       
        if (quit == true) {
            return 0;
        }
        Sleep(900);
        system("cls");
        
    }


}