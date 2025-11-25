#include <graphics.h>
#include <conio.h>

void reflectOrigin(int x, int y, int &rx, int &ry, int midX, int midY) {
    rx = 2 * midX - x;
    ry = 2 * midY - y;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;

    int x = 250, y = 150;
    circle(x, y, 5);
    line(0, midY, getmaxx(), midY);
    line(midX, 0, midX, getmaxy());

    int rx, ry;
    reflectOrigin(x, y, rx, ry, midX, midY);
    circle(rx, ry, 5);

    getch();
    closegraph();
    return 0;
}
