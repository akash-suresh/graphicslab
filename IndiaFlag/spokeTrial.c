#include <graphics.h>
#include <math.h>
#define PI 3.14159265

int main(){
	int gd = DETECT,gm,x,y,i;
	initgraph(&gd,&gm,NULL);

	float val = PI / 180.0;
	for(i=0;i<48;i++){
		x = 125+(int)125*(cos(val*i*360/24.0));
		y = 75+(int)75*(sin(val*i*360/24.0));
		//printf("%d %d \n",(int)125*(cos(val*i*360/24.0)),(int)75*(sin(val*i*360/24.0)));
		putpixel(x,y,RED);
	}
	
	delay(50000);
	closegraph();
	return 0;
}