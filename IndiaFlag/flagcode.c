#include <graphics.h>
#include <math.h>
#define PI 3.14159265
void drawLine(int X0,int Y0,int X1,int Y1, int color){
	int dx,dy,Steps,v;
	float x,y,Xincrement,Yincrement;

	dx = X1-X0;
	dy = Y1-Y0;

	if(dx>dy){
		Steps = abs(dx);
	}
	else{
		Steps = abs(dy);
	}

	Xincrement = dx / (float)Steps;
	Yincrement = dy / (float)Steps;
		
	x = X0;
	y = Y0;

	for(v=0;v<Steps;v++){
		putpixel(x,y,color);
		x = (x + Xincrement);
		y = (y + Yincrement);
	}
}
void drawcircle(x,y,P,Q){
	putpixel(x+P,y+Q,BLUE);
	putpixel(x-P,y+Q,BLUE);
	putpixel(x+P,y-Q,BLUE);
	putpixel(x-P,y-Q,BLUE);
	putpixel(x+Q,y+P,BLUE);
	putpixel(x-Q,y+P,BLUE);
	putpixel(x+Q,y-P,BLUE);
	putpixel(x-Q,y-P,BLUE);
}

void Circle(int x, int y, int R){
	int P = 0 ,Q, D;
	Q = R;
	D = 3 - 2 * R;
	
	while(P<Q){
		drawcircle(x,y,P,Q);
		P+=1;
		if(D<0){
			D = D + 4*P + 6;
		}
		else{
			Q--;
			D = D + 4 *(P-Q) + 10;
		}
	}
}

void DrawPolarCircle(int xc,int yc,int r)
{


   float dtheta,theta=0;
   int x,y; 
   
   x=r;
   y=0;
   
   dtheta=1.0/r;
   drawcircle(xc,yc,x,y);
   while(x>y)
   {
      theta+=dtheta;
      x=round(r*cos(theta));
      y=round(r*sin(theta));
      drawcircle(xc,yc,x,y);
   }
      
}
int main(){
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);
	int x=0, i, y, length=500;
	for(i=0;i<100;i++){
		drawLine(x,y+i,x+length,y+i,LIGHTRED);
		drawLine(x,y+100+i,x+length, y+100+i, WHITE);
		drawLine(x,y+200+i,x+length, y+200+i, GREEN);
	}
	DrawPolarCircle(length/2,150,50);
	DrawPolarCircle(length/2,150,49);
	float val = PI / 180.0;
	for(i=0;i<24;i++){
		x = (int)50*(cos(val*i*360/24.0));
		y = (int)50*(sin(val*i*360/24.0));
		drawLine(250+x,150+y,250-x,150-y, BLUE);
	}
	delay(100000);
	closegraph();
	return 0;
}