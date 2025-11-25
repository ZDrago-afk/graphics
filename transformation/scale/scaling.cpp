#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;

void multiplyMatrix(int mat[3][3], int point[3], int result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += mat[i][j] * point[j];
        }
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x[3] = {100, 150, 200};
    int y[3] = {100,  50, 100};
    setcolor(WHITE);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
    int Sx, Sy;
    cout << "Enter Sx and Sy: ";
    cin >> Sx >> Sy;

    int S[3][3] = {
        {Sx, 0,  0},
        {0,  Sy, 0},
        {0,  0,  1}
    };
    
    int newx[3], newy[3];

    for (int i = 0; i < 3; i++) {
        int point[3]  = {x[i], y[i], 1};
        int result[3];

        multiplyMatrix(S, point, result);

        newx[i] = result[0];
        newy[i] = result[1];
    }
    cout<<"new coordinates are: \n";
    for(int i=0;i<3;i++){
        cout<<"("<<newx[i]<<","<<newy[i]<<")\n";
    }
    setcolor(BLACK);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
    setcolor(YELLOW);
    line(newx[0], newy[0], newx[1], newy[1]);
    line(newx[1], newy[1], newx[2], newy[2]);
    line(newx[2], newy[2], newx[0], newy[0]);
    getch();
    closegraph();
    return 0;
}
