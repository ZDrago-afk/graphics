#include <graphics.h>
#include <conio.h>
#include <math.h>

void multiplyMatrix(float a[3][3], float b[3][3], float result[3][3]) {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            result[i][j] = 0;
            for(int k=0;k<3;k++)
                result[i][j] += a[i][k]*b[k][j];
        }
}

void transformPoint(float x, float y, float matrix[3][3], int &tx, int &ty) {
    float res[3][1] = {0};
    float point[3][1] = {{x}, {y}, {1}};
    for(int i=0;i<3;i++)
        for(int j=0;j<1;j++)
            for(int k=0;k<3;k++)
                res[i][j] += matrix[i][k]*point[k][j];
    tx = round(res[0][0]);
    ty = round(res[1][0]);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 200, yc = 200; // pivot point
    int x = 250, y = 200;   // point to scale
    float sx = 2, sy = 1.5; // scale factors

    float T1[3][3] = { {1,0,-xc}, {0,1,-yc}, {0,0,1} };
    float S[3][3]  = { {sx,0,0}, {0,sy,0}, {0,0,1} };
    float T2[3][3] = { {1,0,xc}, {0,1,yc}, {0,0,1} };

    float temp[3][3], M[3][3];
    multiplyMatrix(S, T1, temp);
    multiplyMatrix(T2, temp, M);

    int newX, newY;
    transformPoint(x, y, M, newX, newY);

    circle(x, y, 5);
    circle(newX, newY, 5);

    getch();
    closegraph();
    return 0;
}
