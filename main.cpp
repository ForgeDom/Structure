#include <iostream>
#include <Windows.h>
using namespace std;

struct MyRectangle {
    int x;
    int y;
    int width;
    int height;
};


void changeSize(MyRectangle& rect, int newWidth, int newHeight) {
    rect.width = newWidth;
    rect.height = newHeight;
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void moveRect(MyRectangle& rect, int x, int y)
{
    rect.x = x;
    rect.y = y;
}

void printRect(MyRectangle& rect) {
    int x = rect.x;
    int y = rect.y;
    for (int i = 0; i < rect.height; ++i) {
        gotoxy(x, y);
        for (int j = 0; j < rect.width; ++j) {
            if (i == 0 || i == rect.height - 1 || j == 0 || j == rect.width - 1) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        y++;
    }
    cout << endl;
}

int main() {
    MyRectangle rect = { 0,0,6,4 };
    printRect(rect);
    system("pause");
    system("cls");
    moveRect(rect, 10, 12);
    printRect(rect);
    system("pause");
    system("cls");
    changeSize(rect, 20, 10);
    printRect(rect);
    return 0;
}