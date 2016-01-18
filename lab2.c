/*  demo.c*/
#include<graphics.h> 
int main()
{
   int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius;
   initgraph(&gd,&gm,NULL);
   //rectangle(left, top, right, bottom);
   for(radius=15;radius<150;radius+=20)
   {
      circle(x, y, radius);
      floodfill(x,y,RED);
      //setcolor(BLUE);
   }
   //bar(left + 300, top, right + 300, bottom);
   //line(left - 10, top + 150, left + 410, top + 150);
   //ellipse(x, y + 200, 0, 360, 100, 50);

   delay(5000);
   closegraph();
   return 0;
}