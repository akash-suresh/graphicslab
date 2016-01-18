#include <graphics.h>

void drawcircle(x,y,P,Q){
	putpixel(x+P,y+Q,RED);
	putpixel(x-P,y+Q,RED);
	putpixel(x+P,y-Q,RED);
	putpixel(x-P,y-Q,RED);
	putpixel(x+Q,y+P,RED);
	putpixel(x-Q,y+P,RED);
	putpixel(x+Q,y-P,RED);
	putpixel(x-Q,y-P,RED);
}
int main(){
	int gd = DETECT, gm, x, y,  R, P = 0 ,Q, D;
	printf("Enter the coordinates and radius of circle: ");
	scanf("%d%d%d",&x,&y,&R);
	Q = R;
	D = 3 - 2 * R;
	initgraph(&gd,&gm,NULL);
	
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
	drawcircle(x,y,P,Q);
	delay(60000);
	closegraph();
	return 0;
}