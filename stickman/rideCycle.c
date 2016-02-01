#include <graphics.h>
#include <math.h>
#define PI 3.14159265

void drawLine(int X0,int Y0,int X1,int Y1, int color, float scale, float angle){
	int dx,dy,Steps,v,a1,b1,a2,b2,p=0,q=0;
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

void Circle(int x, int y, int R, int color,float scale, float angle){
	int a1,b1,p=0,q=0;
	x = (int)x*scale;
	y=(int)y*scale;
	R= (int)R*scale;
	a1=p+(x-p)*cos(angle)-(y-q)*sin(angle);
    b1=q+(x-p)*sin(angle)+(y-q)*cos(angle);

    x = (int)a1;
    y = (int)b1;

	int P = 0 ,Q, D;
	Q = R;
	D = 3 - 2 * R;
	
	while(P<Q){
		drawcircle(x,y,P,Q,color);
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

void cycle(int x, int y, float scale, float angle){

	int x1,y1,i,color=WHITE;
	angle=(angle*PI)/180.0;
	//cycle
	Circle(x+20,y+200,50,color,scale,angle);
	Circle(x+20,y+200,49,color,scale,angle);
	Circle(x+20,y+200,48,color,scale,angle);
	Circle(x+200,y+200,50,color,scale,angle);
	Circle(x+200,y+200,49,color,scale,angle);
	Circle(x+200,y+200,48,color,scale,angle);

	float val = PI / 180.0;
	for(i=0;i<20;i++){
		x1 = (int)50*(cos(val*i*360/20.0));
		y1 = (int)50*(sin(val*i*360/20.0));
		drawLine(20+x+x1,200+y+y1,20+x-x1,200+y-y1,color,scale,angle);
		drawLine(200+x+x1,200+y+y1,200+x-x1,200+y-y1,color,scale,angle);
	}
	//handlebar to front wheel
	drawLine(x+170,y+100,x+200,y+200,color,scale,angle);
	//straight rod from seat to handlebar
	drawLine(x+50,y+125,x+175,y+125,color,scale,angle);
	//seat to back wheel
	drawLine(x+50,y+125,x+20,y+200,color,scale,angle);
	//front rod to pedals
	drawLine(x+110,y+200,x+180,y+135,color,scale,angle);
	//seat to pedal
	drawLine(x+50,y+125,x+100,y+200,color,scale,angle);
	//pedal to back wheel
	drawLine(x+20,y+200,x+110, y+200,color,scale,angle);
	//handle
	drawLine(x+170,y+100,x+150,y+90,color,scale,angle);
	drawLine(x+170,y+100,x+150,y+110,color,scale,angle);
	//seat
	drawLine(x+50,y+125,x+52,y+115,color,scale,angle);
	drawLine(x+42,y+115,x+70,y+118,color,scale,angle);

	//Stickman
	color = RED;
	//body
	drawLine(x+52,y+115, x+85,y+55,color,scale,angle);
	//head
	Circle(x+100,y+30,25,color,scale,angle);
	Circle(x+100,y+30,24,color,scale,angle);
	//hands
	drawLine(x+70,y+80,x+150,y+90,color,scale,angle);
	drawLine(x+70,y+80,x+150,y+110,color,scale,angle);
	//legs
	drawLine(x+52,y+115,x+110,y+155,color,scale,angle);
	drawLine(x+52,y+115,x+115,y+140,color,scale,angle);
	//lower legs
	drawLine(x+110,y+155,x+100,y+200,color,scale,angle);
	drawLine(x+115,y+140,x+100,y+200,color,scale,angle);


}
int main(){
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);

	int x = 300, y= 200,i,angle;

	//code for moving cycle
	for(i=0;i<100;i++){
		cleardevice();
		cycle(x+i,y,(i+50)/80.0,-1*i);
		delay(35);
	}

	delay(100000);
	closegraph();
	return 0;
}