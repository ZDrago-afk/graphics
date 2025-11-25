#include <graphics.h>
#include <conio.h>

struct Point { int x, y; };

int xmin=100, ymin=100, xmax=400, ymax=300;

int inside(Point p, int edge) {
    if(edge==0) return p.x>=xmin;
    if(edge==1) return p.x<=xmax;
    if(edge==2) return p.y>=ymin;
    return p.y<=ymax;
}

Point intersect(Point p1, Point p2, int edge) {
    Point p;
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    if(edge==0){ p.x=xmin; p.y=p1.y+dy*(xmin-p1.x)/dx; }
    if(edge==1){ p.x=xmax; p.y=p1.y+dy*(xmax-p1.x)/dx; }
    if(edge==2){ p.y=ymin; p.x=p1.x+dx*(ymin-p1.y)/dy; }
    if(edge==3){ p.y=ymax; p.x=p1.x+dx*(ymax-p1.y)/dy; }
    return p;
}

void clipPolygon(Point poly[], int n) {
    Point temp[20];
    for(int edge=0; edge<4; edge++){
        int m=0;
        for(int i=0;i<n;i++){
            Point curr=poly[i];
            Point prev=poly[(i+n-1)%n];
            int currIn=inside(curr,edge);
            int prevIn=inside(prev,edge);

            if(currIn){
                if(!prevIn) temp[m++] = intersect(prev,curr,edge);
                temp[m++] = curr;
            } else if(prevIn){
                temp[m++] = intersect(prev,curr,edge);
            }
        }
        n = m;
        for(int i=0;i<n;i++) poly[i]=temp[i];
    }
    for(int i=0;i<n;i++)
        line(poly[i].x, poly[i].y, poly[(i+1)%n].x, poly[(i+1)%n].y);
}

int main(){
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(xmin,ymin,xmax,ymax);

    Point poly[5]={{50,150},{200,50},{350,150},{300,250},{100,250}};
    for(int i=0;i<5;i++)
        line(poly[i].x, poly[i].y, poly[(i+1)%5].x, poly[(i+1)%5].y);

    setcolor(RED);
    clipPolygon(poly,5);

    getch();
    closegraph();
    return 0;
}
