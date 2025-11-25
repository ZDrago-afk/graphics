#include <graphics.h>
#include <conio.h>
#include <cmath>
void shearX(int x, int y, float shx, int &sx, int &sy) {
    sx = round(x + shx * y);
    sy = y;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 200, y1 = 150;
    int x2 = 250, y2 = 200;

    line(x1, y1, x2, y2); // original line

    float shx = 0.5;
    int sx1, sy1, sx2, sy2;
    shearX(x1, y1, shx, sx1, sy1);
    shearX(x2, y2, shx, sx2, sy2);

    
    line(sx1, sy1, sx2, sy2); // sheared line

    getch();
    closegraph();
    return 0;
}
