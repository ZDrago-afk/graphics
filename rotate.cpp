#include <graphics.h>
#include <cmath>

void multiply(int R[3][3], int p[3], int result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = R[i][0] * p[0] +
                    R[i][1] * p[1] +
                    R[i][2] * p[2];
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x[3] = {100, 150, 200};
    int y[3] = {100,  50, 100};

    float a = 0;

    while (1) {
        cleardevice();

        float rad = a * 3.14159 / 180;

        int Rm[3][3] = {
            {  (int)round(cos(rad)), (int)round(-sin(rad)), 0 },
            {  (int)round(sin(rad)), (int)round( cos(rad)), 0 },
            {  0, 0, 1 }
        };

        int rx[3], ry[3];

        for (int i = 0; i < 3; i++) {
            int p[3] = { x[i], y[i], 1 };
            int res[3];

            multiply(Rm, p, res);

            rx[i] = res[0];
            ry[i] = res[1];
        }

        line(rx[0], ry[0], rx[1], ry[1]);
        line(rx[1], ry[1], rx[2], ry[2]);
        line(rx[2], ry[2], rx[0], ry[0]);

        a += 2;
        delay(20);
    }

    closegraph();
}
