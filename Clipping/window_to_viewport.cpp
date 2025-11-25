#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xwmin = 0, ywmin = 0, xwmax = 100, ywmax = 100;
    int xvmin = 200, yvmin = 100, xvmax = 400, yvmax = 300;

    int xw1 = 20, yw1 = 30;
    int xw2 = 80, yw2 = 70;

    int xv1 = xvmin + (xw1 - xwmin) * (xvmax - xvmin) / (xwmax - xwmin);
    int yv1 = yvmin + (yw1 - ywmin) * (yvmax - yvmin) / (ywmax - ywmin);
    int xv2 = xvmin + (xw2 - xwmin) * (xvmax - xvmin) / (xwmax - xwmin);
    int yv2 = yvmin + (yw2 - ywmin) * (yvmax - yvmin) / (ywmax - ywmin);

    rectangle(xwmin, ywmin, xwmax, ywmax);
    rectangle(xvmin, yvmin, xvmax, yvmax);
    line(xw1, yw1, xw2, yw2);
    line(xv1, yv1, xv2, yv2);

    getch();
    closegraph();
    return 0;
}
