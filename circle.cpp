#include<graphics.h>
#include<iostream>
using namespace std;
void make_circle(int r, int xc, int yc)
{
    int x=0;
    int y=r;
    int p=1-r;
    while(x<=y)
    {
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc+y,yc+x,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc-y,yc+x,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc+y,yc-x,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc-y,yc-x,WHITE);
        if(p<0)
        {
            x++;
            p=p+2*x+1;
        }
        else
        {
            x++;
            y--;
            p=p+2*x-2*y+1;
        }
    }
}
int main()
{
    int d=DETECT;
    int m;
    initgraph(&d,&m,"");
    make_circle(100,100,100);
    getch();
    closegraph();
    return 0;
}
