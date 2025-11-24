#include<graphics.h>
#include<iostream>
#include<conio.h>
using namespace std;
void line_dda(int xs, int ys, int xe, int ye)
{
    int n;
    cout<<"tell amount of space betweeen dots";
    cin>>n;
    int x=0;
    if(xs>xe)
    {
        int t=xs;
        xs=xe;
        xe=t;
    }
    while(xs!=xe && ys!=ye)
    {
        int xc=xe-xs;
        int yc=ye-ys;
        if(x%n==0)
        {
        putpixel(xs,ys,WHITE);
        }
        int po=2*(yc)-xc;
        if(po<0)
        {
            xs=xs+1;
            po=po+2*(yc);
        }
        else
        {
            xs+=1;
            ys+=1;
            po=po+2*(yc)-2*(xc);
        }
        x++;
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line_dda(400,100,200,200);
    getch();
    closegraph();
    return 0;
}
