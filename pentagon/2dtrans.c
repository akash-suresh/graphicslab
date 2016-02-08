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


void pentagon(int x, int y, float scale, float angle){
	drawLine(x,y,x+100,y,WHITE,scale,angle);
	
	drawLine(x,y,x-30,y-80,WHITE,scale,angle);
	drawLine(x+100,y,x+130,y-80,WHITE,scale,angle);

	drawLine(x+50,y-150,x-30,y-80,WHITE,scale,angle);
	drawLine(x+50,y-150,x+130,y-80,WHITE,scale,angle);
}

int main(){
	int gd = DETECT, gm;

	int x = 200, y= 150,i,angle,choice;

	//pentagon(x,y,1,0);
	
	printf("Enter 1.translation, 2.Rotation 3.Scaling\n");
	scanf("%d",&choice);

	initgraph(&gd,&gm,NULL);
	switch(choice){
		case 1:for(i=0;i<100;i++){
			cleardevice();
			pentagon(x+3*i,y,1,0);
			delay(35);
			break;
		}

		case 2:for(i=0;i<100;i++){
			cleardevice();
			pentagon(x,y,1,i/80.0);
			delay(35);
			break;
		}

		case 3:for(i=0;i<100;i++){
			cleardevice();
			pentagon(x+3*i,y,(100+i)/100.0,0);
			delay(35);
			break;
		}
	}

	delay(100000000);
	closegraph();

	return 0;
}