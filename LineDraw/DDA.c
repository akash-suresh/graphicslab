#include <graphics.h>

int main(){
	int gd = DETECT,gm,X0,X1,Y0,Y1,dx,dy,Steps,x,y,Xincrement,Yincrement,v;
	
	printf("Enter the first coordinate - ");
	scanf("%d%d",&X0,&Y0);
	printf("Enter the second coordinate - ");
	scanf("%d%d",&X1,&Y1);

	dx = X1-X0;
	dy = Y1-Y0;

	if(dx>dy){
		Steps = abs(dx);
	}
	else{
		Steps = abs(dy);
	}

	Xincrement = dx / Steps;
	Yincrement = dy / Steps;
	
	//INITITALIZING GRAPH
	initgraph(&gd,&gm,NULL);
	
	x = X0;
	y = Y0;

	for(v=0;v<Steps;v++){
		putpixel(x,y,RED);
		x = (x + Xincrement);
		y = (y + Yincrement);
	}

	delay(50000);
	closegraph();
	return 0;
}