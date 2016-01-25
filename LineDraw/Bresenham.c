#include <graphics.h>


void drawLine(int X0, int Y0, int X1, int Y1){
	putpixel(X0,Y0,RED);
	int dx = X1-X0, dy = Y1-Y0;
	int p0 = 2*dy - dx, x, y,p=p0,xk,pk,yk;
	float m = (dy/(float)dx);
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
int main(){
	int gd = DETECT,gm,X0,X1,Y0,Y1;
	
	printf("Enter the first coordinate - ");
	scanf("%d%d",&X0,&Y0);
	printf("Enter the second coordinate - ");
	scanf("%d%d",&X1,&Y1);

	initgraph(&gd,&gm,NULL);
	drawLine(X0,Y0,X1,Y1);
	delay(50000);
	closegraph();
	return 0;
}