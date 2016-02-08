#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

void setfillstyle( int pattern, int color);

drawCube(int x, int y, int x1, int y1, float angle){

	int a1,b1,a2,b2,p=x,q=y;
    a1=p+(x-p)*cos(angle)-(y-q)*sin(angle);
    b1=q+(x-p)*sin(angle)+(y-q)*cos(angle);

    a2=p+(x1-p)*cos(angle)-(y1-q)*sin(angle);
    b2=q+(x1-p)*sin(angle)+(y1-q)*cos(angle);

    x = (int)a1;
    y = (int)b1;

    x1 = (int)a2;
    y1 = (int)b2;

	int points1[]={x,y,x+100,y,x+100,y+100,x,y+100,x,y};
	int points2[]={x1,y1,x1+100,y1,x1+100,y1+100,x1,y1+100,x1,y1};
	int points3[]={x,y,x,y+100,x1,y1+100,x1,y1,x,y};
	int points4[]={x+100,y,x+100,y+100,x1+100,y1+100,x1+100,y1,x+100,y};
	int points5[]={x,y,x1,y1,x1+100,y1,x+100,y,x,y};
	int points6[]={x,y+100,x1,y1+100,x1+100,y1+100,x+100,y+100,x,y+100};


	setcolor(RED);
	fillpoly(5, points1);

	setcolor(BLUE);
	fillpoly(5, points2);

	setcolor(MAGENTA);
	fillpoly(5, points3);

	setcolor(YELLOW);
	fillpoly(5, points4);

	setcolor(12);
	fillpoly(5, points3);

	setcolor(GREEN);
	fillpoly(5, points4);


}
int main()
{
	int gd=DETECT,gm,x=200,y=200,x1,y1,i;
	x1=x+50;
	y1=y+50;

	initgraph(&gd, &gm, NULL);
	for(i=0;i<1000;i++){
		cleardevice();
		drawCube(x,y,x1,y1,i/80.0);
		delay(35);
	}
	delay(100000);
	closegraph();
	return 0;
}