#include <graphics.h>
#include <cmath>
using namespace std;
void line_dda(int xs, int ys, int xe, int ye)
{
    int dx = xe - xs;
    int dy = ye - ys;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float x = xs;
    float y = ys;
    for(int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), WHITE);
        x += Xinc;
        y += Yinc;
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line_dda(400, 100, 200, 200);
    line_dda(100, 100, 400, 300);
    getch();
    closegraph();
    return 0;
}
