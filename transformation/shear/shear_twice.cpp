#include <graphics.h>
#include <conio.h>
#include <cmath>

void shearY(int x, int y, float shy, int &sx, int &sy) {
    sx = x;
    sy = round(y + shy * x);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 200, y1 = 150;
    int x2 = 250, y2 = 200;

    line(x1, y1, x2, y2); // original line

    float shy = 0.5;
    int sx1, sy1, sx2, sy2;
    shearY(x1, y1, shy, sx1, sy1);
    shearY(x2, y2, shy, sx2, sy2);

    line(sx1, sy1, sx2, sy2); // sheared line

    getch();
    closegraph();
    return 0;
}
