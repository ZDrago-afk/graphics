#include <graphics.h>
#include <iostream>
using namespace std;

void multiply(float S[3][3], int p[3], float r[3]) {
    for (int i = 0; i < 3; i++) {
        r[i] = S[i][0] * p[0] +
               S[i][1] * p[1] +
               S[i][2] * p[2];
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x[3] = {100, 150, 200};
    int y[3] = {100,  50, 100};

    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);

    float shx;
    cin >> shx;

    float S[3][3] = {
        {1, shx, 0},
        {0, 1,   0},
        {0, 0,   1}
    };

    int sx[3], sy[3];

    for (int i = 0; i < 3; i++) {
        int p[3] = {x[i], y[i], 1};
        float r[3];
        multiply(S, p, r);
        sx[i] = r[0];
        sy[i] = r[1];
    }

    setcolor(YELLOW);
    line(sx[0], sy[0], sx[1], sy[1]);
    line(sx[1], sy[1], sx[2], sy[2]);
    line(sx[2], sy[2], sx[0], sy[0]);

    getch();
    closegraph();
}
