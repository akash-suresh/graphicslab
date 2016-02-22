#include <graphics.h>
#include <math.h>
#define PI 3.14159265

void drawLine(int X0,int Y0,int X1,int Y1, int color, float scale, float angle, int s){
	int dx,dy,Steps,v,a1,b1,a2,b2,p=0,q=0,s_y=250;
	float x,y,Xincrement,Yincrement;
	X0 = (int)X0*scale;
	X1 = (int)X1*scale;
	Y0 = (int)Y0*scale;
	Y1 = (int)Y1*scale;

    a1=p+(X0-p)*cos(angle)-(Y0-q)*sin(angle);
    b1=q+(X0-p)*sin(angle)+(Y0-q)*cos(angle);

    a2=p+(X1-p)*cos(angle)-(Y1-q)*sin(angle);
    b2=q+(X1-p)*sin(angle)+(Y1-q)*cos(angle);

    X0 = (int)a1;
    Y0 = (int)b1;

    X1 = (int)a2;
    Y1 = (int)b2;

    if(s==1){
    	dy= abs(Y1-s_y)*0.30;
    	X1-=dy;
    	dy=abs(Y0-s_y)*0.30;
    	X0-=dy;
    }
	dx = abs(X1-X0);
	dy = abs(Y1-Y0);

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

void drawcircle(x,y,P,Q,color){
	putpixel(x+P,y+Q,color);
	putpixel(x-P,y+Q,color);
	putpixel(x+P,y-Q,color);
	putpixel(x-P,y-Q,color);
	putpixel(x+Q,y+P,color);
	putpixel(x-Q,y+P,color);
	putpixel(x+Q,y-P,color);
	putpixel(x-Q,y-P,color);
}

void house(int x, int y, float scale, float angle, int r,float sh){
	int color=RED;
/*	drawLine(x,y,x+200,y,color,scale,angle,s);
	drawLine(x,y-r*100,x+200,y-r*100,color,scale,angle,s);
	if(r==1){
		drawLine(x,y-r*100,x,y,color,scale,angle,s);
		drawLine(x+80,y-r*100,x+80,y,color,scale,angle,s);
		drawLine(x+200,y-r*100,x+200,y,color,scale,angle,s);
	}
	else{
		drawLine(x,y,x,y-r*100,color,scale,angle,s);
		drawLine(x+80,y,x+80,y-r*100,color,scale,angle,s);
		drawLine(x+200,y,x+200,y-r*100,color,scale,angle,s);
	}
	
	drawLine(x,y-r*100,x+40,y-r*150,color,scale,angle,s);
	drawLine(x+40,y-r*150,x,y-r*100,color,scale,angle,s);
	drawLine(x+40,y-r*150,x+80,y-r*100,color,scale,angle,s);

	drawLine(x+40,y-r*150,x+160,y-r*150,color,scale,angle,s);
	drawLine(x+160,y-r*150,x+200,y-r*100,color,scale,angle,s);
*/

	int points1[]={x,y,x+100,y,x+100+100*sh,y-r*100,x+100*sh,y-r*100,x,y};
	int points2[]={x+30,y-r*30,x+130,y-r*30,x+130+100*sh,y-r*130,x+30+100*sh,y-r*130,x+30,y-30};
	int points3[]={x,y,x+100*sh,y-r*100,x+30+100*sh,y-r*130,x+30,y-r*30,x,y};
	int points4[]={x+100,y,x+100+100*sh,y-r*100,x+130+100*sh,y-r*130,x+130,y-r*30,x+100,y};
	int points5[]={x+100*sh,y-r*100,x+50+170*sh,y-r*170,x+100+100*sh,y-r*100,x+100*sh,y-r*100};
	int points6[]={x+30+100*sh,y-r*130,x+50+170*sh,y-r*170,x+100*sh,y-r*100,x+30+100*sh,y-r*130};
	int points7[]={x+100+100*sh,y-r*100,x+50+170*sh,y-r*170,x+130+100*sh,y-r*130,x+100+100*sh,y-r*100};
	
	
	setlinestyle(0,1,1);
	//setcolor(RED);
	drawpoly(5, points1);
	drawpoly(5, points4);
	drawpoly(4, points5);
	drawpoly(4, points7);


	setlinestyle(3,2,1);
	//setcolor(BLUE);
	drawpoly(5, points2);
	//setcolor(MAGENTA);
	drawpoly(5, points3);
	drawpoly(4, points6);

}
int main(){
	int gd = DETECT, gm,choice;
	initgraph(&gd,&gm,NULL);

	int x = 100, y= 250,i,angle;
	printf("Menu : 1. Reflect 2.Shear\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			house(x,y,1,0,1,0);
			house(x,y,1,0,-1,0);
			break;

		case 2:house(x,y,1,0,1,0.3);
			break;

		case 3:house(x,y,1,0,1,0);
			break;
	}
//	house(x,y,1,0,-1);
	/*
	//code for moving cycle
	for(i=0;i<100;i++){
		cleardevice();
		house(x+i,y,(i+50)/80.0,-1*i);
		delay(35);
	}
*/
	delay(100000);
	closegraph();

	return 0;
}