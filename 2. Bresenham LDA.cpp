#include<iostream>
#include<cmath>
#include<graphics.h>
#include<dos.h>
using namespace std;
void LDA(int x1,int y1,int x2,int y2)
{
    float m=(y1-y2)*1.0/(x1-x2);
    if(x1>x2)
    {
        int temp=x1;
        x1=x2;
        x2=temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }
    int dx=x2-x1,dy=y2-y1,p;
    int xinc=0,yinc=0;
    if(m>=0&&m<=1)
        xinc=1;
    else if(m>1)
       p=2*dx-dy;
    else if(m<0&&m>=-1)
        p=-2*dy-dx;

    else
        p=-2*dx-dy;

    int start,end;
    if(m>=-1&&m<=1)
    {start=x1;end=x2;}
    else start=y1;end=y2;
    int x=x1;
    int y=y1;
    for(int i=start;i<=end;i++)
    {
        putpixel(x,y,2);

        if(m>=0&&m<=1)
        {
            if(p<0)
                p+=2*dy;
            else
            {p+=2*dy-2*dx;
            y++;}
            x++;
        }
    else if(m>1)
        {
            if(p<0)
                p+=2*dx;
            else {p+=2*dx-2*dy;
            x++;}
            y++;
        }
    else if(m<0&&m>=-1)
        {
            if(p<0)
                p+=-2*dy;
            else {p+=-2*dy-2*dx;
            y--;}
            x++;
        }
    else
        {
            if(p<0)
                p+=-2*dx;
            else {p+=-2*dx-2*dy;
            x++;}
            y--;
        }
    }

}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\Program Files (x86)\CodeBlocks\MinGW\lib\libbgi.a");
    int x1=120,y1=200,x2=300,y2=300;

    LDA(x1,y1,x2,y2);
    system("pause");
    closegraph();
    return 0;
}
