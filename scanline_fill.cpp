#include <graphics.h>
#include <conio.h>

void scanlineFill(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    int ymin = y1 < y2 ? (y1 < y3 ? y1 : y3) : (y2 < y3 ? y2 : y3);
    int ymax = y1 > y2 ? (y1 > y3 ? y1 : y3) : (y2 > y3 ? y2 : y3);

    for (int y = ymin; y <= ymax; y++) {
        int nodes[10], n = 0;

        if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y))
            nodes[n++] = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
        if ((y2 <= y && y3 > y) || (y3 <= y && y2 > y))
            nodes[n++] = x2 + (y - y2) * (x3 - x2) / (y3 - y2);
        if ((y3 <= y && y1 > y) || (y1 <= y && y3 > y))
            nodes[n++] = x3 + (y - y3) * (x1 - x3) / (y1 - y3);

        for (int i = 0; i < n - 1; i += 2) {
            if (nodes[i] > nodes[i + 1]) {
                int temp = nodes[i];
                nodes[i] = nodes[i + 1];
                nodes[i + 1] = temp;
            }
            for (int x = nodes[i]; x <= nodes[i + 1]; x++)
                putpixel(x, y, color);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 50;
    int x3 = 250, y3 = 150;

    scanlineFill(x1, y1, x2, y2, x3, y3, RED);

    getch();
    closegraph();
    return 0;
}
