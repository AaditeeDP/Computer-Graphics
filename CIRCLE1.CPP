#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>



void Drawcircle(int x1, int y1,int r)
{
     int x = 0;
     int y = r;
     int p = 1 - r;
    while(x<y){
	
	putpixel(x1 + x, y1 + y, WHITE);
	delay(100);
	putpixel(x1 + y, y1 + x, WHITE);
	delay(100);
	putpixel(x1 + y, y1 - x, WHITE);
	delay(100);
	putpixel(x1 + x, y1 - y, WHITE);
	delay(100);
	putpixel(x1 - x, y1 - y, WHITE);
	delay(100);
	putpixel(x1 - y, y1 - x, WHITE);
	delay(100);
	putpixel(x1 - y, y1 + x, WHITE);
	delay(100);
	putpixel(x1 - x, y1 + y, WHITE);
	delay(100);
   x=x+1;
	if (p<0)
	{
		y = y;
		p = p + 2*x+1;
	}
	else
	{
		y = y-1;
		p = p + 2*x+1-2*y;
	}
}
}

int main()
{
    clrscr();
    int x1,y1,r;
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cleardevice();
    cout<< "Enter the centre of the circle";
    cin>>x1>>y1;
    cout<<"enter the value of radius";
    cin>>r;
    Drawcircle(x1,y1,r);
    getch();
    closegraph();
    return 0;
}