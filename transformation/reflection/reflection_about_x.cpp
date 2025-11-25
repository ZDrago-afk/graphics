#include <graphics.h>
#include <conio.h>

void reflectX(int x, int y, int &rx, int &ry, int midY) {
    rx = x;
    ry = 2 * midY - y;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midY = getmaxy() / 2;

    int x = 200, y = 150;
    circle(x, y, 5);
    line(0, midY, getmaxx(), midY);

    int rx, ry;
    reflectX(x, y, rx, ry, midY);
    circle(rx, ry, 5);

    getch();
    closegraph();
    return 0;
}
