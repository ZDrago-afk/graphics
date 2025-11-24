#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int cx = getmaxx() / 2;
    int cy = getmaxy() / 2;

    int R, smallR;
    cout << "Enter revolution radius: ";
    cin >> R;
    cout << "Enter circle radius: ";
    cin >> smallR;

    float angle = 0;

    while (!kbhit()) {
        int x = cx + R * cos(angle);
        int y = cy + R * sin(angle);

        circle(cx, cy, smallR);
        circle(x, y, smallR);
        angle += 0.03;
        delay(10);
        cleardevice();
    }

    closegraph();
    return 0;
}
