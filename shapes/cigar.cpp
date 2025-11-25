#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (1) {
        int cigarX1 = 200, cigarX2 = 400, cigarY = 300;
        int smokeX = cigarX2, smokeY = cigarY, smokeRadius = 30;

        while (smokeRadius > 0) {
            cleardevice();
            setcolor(BROWN);
            setlinestyle(SOLID_LINE, 0, 5);
            line(cigarX1, cigarY, cigarX2, cigarY);
            setcolor(LIGHTGRAY);
            circle(smokeX, smokeY, smokeRadius);
            delay(100);
            smokeY -= 5;
            smokeRadius -= 2;
        }
    }

    getch();
    closegraph();
    return 0;
}
