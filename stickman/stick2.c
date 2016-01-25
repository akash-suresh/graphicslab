#include <graphics.h>
#include <math.h>


void drawLine(int X0, int Y0, int X1, int Y1){
	putpixel(X0,Y0,RED);
	int dx = X1-X0, dy = Y1-Y0;
	int p0 = 2*dy - dx, x, y,p=p0,xk,pk,yk,v;
	float m = (dy/(float)dx);
	if(dx==0){
		for(x=X0,y=Y0;y<=Y1;y++){
			putpixel(x,y,RED);
		}
		return;
	}
	y=Y0;
	for(x=X0;x<X1;x++){
		xk = x+1;
		yk = m*(xk - X0) + Y0;  
		if(p>0){
			putpixel(xk,yk,RED);
			pk = p + 2*dy - 2*dx;
		}
		else{
			putpixel(xk,y,RED);
			pk= p + 2*dy;
		}
		y = yk;
		p = pk;
	}
}
void dc(int xc, int yc, int x, int y){
	putpixel(xc + x, yc + y, RED);
	putpixel(xc - x, yc + y, RED);
	putpixel(xc + x, yc - y, RED);
	putpixel(xc - x, yc - y, RED);
	putpixel(xc + y, yc + x, RED);
	putpixel(xc - y, yc + x, RED);
	putpixel(xc + y, yc - x, RED);
	putpixel(xc - y, yc - x, RED);
}
void drawcircle(int xc, int yc, int R){
	int x=0 ,y=R;
	float p = 1 - R;

	while(x<y){
		dc(xc,yc,x,y);
		x= x+1;
		if(p<0){
			p=p+2*x+6;
		}
		else{
			y = y-1;
			p = p +2*(x-y) + 1;
		}
		dc(xc,yc,x,y);
	}
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);

	int x = 100, y = 60;
	//head
	drawcircle(80,70,50);
	//body
	drawLine(80,120,80,250);
	//hands
	drawLine(20,160,140,160);
	//legs
	drawLine(80,250,140,330);
	drawLine(20,330,80,250);

	delay(100000);
	closegraph();
	return 0;
}