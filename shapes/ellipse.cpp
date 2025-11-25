#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    float x = 0, y = ry;
    float dx = 2 * ry * ry * x;
    float dy = 2 * rx * rx * y;
    float d1 = (ry*ry) - (rx*rx*ry) + (0.25*rx*rx);

    while (dx < dy) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        } else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
    float d2 = (ry*ry*(x + 0.5f)*(x + 0.5f)) +
               (rx*rx*(y - 1)*(y - 1)) -
               (rx*rx*ry*ry);

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawEllipse(300, 250, 120, 60);

    getch();
    closegraph();
    return 0;
}
