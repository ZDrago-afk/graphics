#include <graphics.h>
#include <conio.h>
#include <cmath>

void liangBarskyClip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};
    float u1 = 0, u2 = 1;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return;
        } else {
            float u = q[i] / p[i];
            if (p[i] < 0) u1 = fmax(u1, u);
            else u2 = fmin(u2, u);
        }
    }

    if (u1 > u2) return;

    int nx1 = round(x1 + u1 * dx);
    int ny1 = round(y1 + u1 * dy);
    int nx2 = round(x1 + u2 * dx);
    int ny2 = round(y1 + u2 * dy);

    line(nx1, ny1, nx2, ny2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xmin = 100, ymin = 100, xmax = 400, ymax = 300;
    rectangle(xmin, ymin, xmax, ymax);

    liangBarskyClip(50, 50, 450, 350, xmin, ymin, xmax, ymax);
    liangBarskyClip(150, 150, 350, 250, xmin, ymin, xmax, ymax);
    liangBarskyClip(200, 400, 300, 50, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}
