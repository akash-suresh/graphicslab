#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

void setfillstyle( int pattern, int color);

int main()
{
   int gd=DETECT,gm,x=200,y=200,x1,y1;
   x1=x+50;
   y1=y+50;

   int points1[]={x,y,x+100,y,x+100,y+100,x,y+100,x,y};
   int points2[]={x1,y1,x1+100,y1,x1+100,y1+100,x1,y1+100,x1,y1};
   int points3[]={x,y,x,y+100,x1,y1+100,x1,y1,x,y};
   int points4[]={x+100,y,x+100,y+100,x1+100,y1+100,x1+100,y1,x+100,y};
   initgraph(&gd, &gm, NULL);
   
   setcolor(RED);
   fillpoly(5, points1);
/*
   setfillstyle(SOLID_FILL, BLUE);
   fillpoly(5, points2);

   setfillstyle(SOLID_FILL, WHITE);
   fillpoly(5, points3);

   setfillstyle(SOLID_FILL, YELLOW);
   fillpoly(5, points4);
*/
	delay(100000);
   closegraph();
   return 0;
}