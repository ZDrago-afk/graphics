#include <graphics.h>
#include <conio.h>

void reflectY(int x, int y, int &rx, int &ry, int midX) {
    rx = 2 * midX - x;
    ry = y;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midX = getmaxx() / 2;

    int x = 200, y = 150;
    circle(x, y, 5);
    line(midX, 0, midX, getmaxy());

    int rx, ry;
    reflectY(x, y, rx, ry, midX);
    circle(rx, ry, 5);

    getch();
    closegraph();
    return 0;
}
