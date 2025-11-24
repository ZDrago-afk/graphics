#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
void line_bresenham(int xs, int ys, int xe, int ye)
{
    int dx = abs(xe - xs);
    int dy = abs(ye - ys);
    int x = xs;
    int y = ys;
    int sx = (xe > xs) ? 1 : -1;  
    int sy = (ye > ys) ? 1 : -1;  
    if (dx > dy)  
    {
        int p = 2 * dy - dx;
        while (x != xe)
        {
            putpixel(x, y, WHITE);
            x += sx;
            if (p < 0)
            {
                p += 2 * dy;
            }
            else
            {
                y += sy;
                p += 2 * dy - 2 * dx;
            }
        }
    }
    else  
    {
        int p = 2 * dx - dy;
        while (y != ye)
        {
            putpixel(x, y, WHITE);
            y += sy;
            if (p < 0)
            {
                p += 2 * dx;
            }
            else
            {
                x += sx;
                p += 2 * dx - 2 * dy;
            }
        }
    }
    putpixel(x, y, WHITE); 
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line_bresenham(100, 100, 400, 200); 
    line_bresenham(100, 100, 200, 400);
    line_bresenham(400, 400, 100, 200); 
    line_bresenham(200, 100, 200, 400); 
    line_bresenham(100, 300, 400, 300); 
    getch();
    closegraph();
    return 0;
}
