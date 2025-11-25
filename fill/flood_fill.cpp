#include <graphics.h>
#include <conio.h>

void floodFill(int x, int y, int fillColor, int bgColor) {
    if (getpixel(x, y) == bgColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, bgColor);
        floodFill(x - 1, y, fillColor, bgColor);
        floodFill(x, y + 1, fillColor, bgColor);
        floodFill(x, y - 1, fillColor, bgColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(100, 100, 300, 250);
    floodFill(150, 150, RED, BLACK);

    getch();
    closegraph();
    return 0;
}
