#include <graphics.h>
#include <dos.h>     
#include <conio.h>   
void grow(int r, int x, int y)
{
    for (r = 100; r >= 10; r--) {
        cleardevice();               
        circle(x, y, r);             
        delay(50);                   
    }
}
void shrink(int r, int x, int y)
{
    for (int r = 10; r <= 100; r++) {
        circle(x, y, r);              
        delay(50);                    
        cleardevice();               
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = getmaxx() / 2;   
    int y = getmaxy() / 2;  
    int r;
    while(1)
    {
    grow(r, x, y);
    shrink(r, x, y);
    }
    getch();
    closegraph();
    return 0;
}
