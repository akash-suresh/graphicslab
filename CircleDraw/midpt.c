#include <graphics.h>

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
	int gd = DETECT, gm, x, y,  R;
	printf("Enter the coordinates and radius of circle: ");
	scanf("%d%d%d",&x,&y,&R);
	
	initgraph(&gd,&gm,NULL);
	drawcircle(x,y,R);
	delay(60000);
	closegraph();
	return 0;
}