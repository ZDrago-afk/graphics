#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int max_x = getmaxx();
    int max_y = getmaxy();
    int y = max_y / 2;
    int R = 20;
    int collisionPoint = (max_x / 2) - R;

    while (true) {
        for (int i = 0; i <= collisionPoint; i++) {
            int left = i;
            int right = max_x - i;
            circle(left, y, R);
            circle(right, y, R);
            delay(1);
            cleardevice();
        }
        for (int i = collisionPoint; i >= 0; i--) {
            int left = i;
            int right = max_x - i;
            circle(left, y, R);
            circle(right, y, R);
            delay(1);
            cleardevice();
        }
    }

    closegraph();
    return 0;
}
