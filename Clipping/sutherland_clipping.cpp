#include <graphics.h>
#include <conio.h>

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int xmin = 100, ymin = 100, xmax = 400, ymax = 300;

int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 | code2) == 0) {
            accept = true;
            break;
        } else if (code1 & code2) break;
        else {
            int x, y;
            int outcode = code1 ? code1 : code2;

            if (outcode & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (outcode & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (outcode & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (outcode == code1) { x1 = x; y1 = y; code1 = computeCode(x1, y1); }
            else { x2 = x; y2 = y; code2 = computeCode(x2, y2); }
        }
    }

    if (accept) line(x1, y1, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(xmin, ymin, xmax, ymax);

    cohenSutherlandClip(50, 50, 450, 350);
    cohenSutherlandClip(150, 150, 350, 250);
    cohenSutherlandClip(200, 400, 300, 50);

    getch();
    closegraph();
    return 0;
}
