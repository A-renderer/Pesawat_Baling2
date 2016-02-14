#include "FrameBuffer.cpp"
#include <cstring>
#include <termios.h>
#include <fstream>
#include <pthread.h>
#include "assets.h"

using namespace std;

FrameBuffer FB;
vector<Point> P;

void printObject(Polygon Poly);
Polygon matrixToPolygon(int object[][2], int col);
void drawShip();

int main() {
	int iterasi=0;
	Polygon polyPlane = matrixToPolygon(plane,sizeof(plane)/sizeof(*plane));
	Polygon polyPropelerLeft = matrixToPolygon(propeler1,sizeof(propeler1)/sizeof(*propeler1));
	Polygon polyPropelerRight = matrixToPolygon(propeler2,sizeof(propeler2)/sizeof(*propeler2));
	

	FB.clearscreen();
	drawShip();
	

/*
	while(iterasi<10) {
		FB.clearscreen();
		FB.clearscreen();
		FB.rasterScan(polyPlane,0,0,0,0);
		FB.rasterScan(polyPropelerLeft,160,60,60,0);
		FB.rasterScan(polyPropelerRight,160,60,60,0);
		iterasi++;
		polyPlane.scale(1.1); polyPlane.moveDown(1); polyPlane.moveRight(5);
		polyPropelerLeft.scale(1.1); polyPropelerLeft.moveDown(1); polyPropelerLeft.moveRight(5); //polyPropelerLeft.rotateCenter(90);
		polyPropelerRight.scale(1.1); polyPropelerRight.moveDown(1); polyPropelerRight.moveRight(5); //polyPropelerRight.rotateCenter(90);
		usleep(1000000);
	}*/
}
Polygon matrixToPolygon(int object[][2], int col) {
	vector<Point> points;
	points.clear();
	for(int i=0;i<col;i++) {
		points.push_back(Point(object[i][0],object[i][1]));
	}
	return Polygon(points);
}

void drawShip(){
	Polygon polyShip1 = matrixToPolygon(ship1,sizeof(ship1)/sizeof(*ship1));
	Polygon polyShip2 = matrixToPolygon(ship2,sizeof(ship2)/sizeof(*ship2));
	Polygon polyShip3 = matrixToPolygon(ship3,sizeof(ship3)/sizeof(*ship3));
	Polygon polyShip4 = matrixToPolygon(ship4,sizeof(ship4)/sizeof(*ship4));
	polyShip1.scale(3);
	polyShip2.scale(3);
	polyShip3.scale(3);
	polyShip4.scale(3);
	polyShip1.moveDown(300);
	polyShip2.moveDown(300);
	polyShip3.moveDown(300);
	polyShip4.moveDown(300);
	polyShip1.moveRight(100);
	polyShip2.moveRight(100);
	polyShip3.moveRight(100);
	polyShip4.moveRight(100);
	FB.rasterScan(polyShip1,89,131,153,0);
	FB.rasterScan(polyShip2,37,66,84,0);
	FB.rasterScan(polyShip3,41,81,106,0);
	FB.rasterScan(polyShip4,255,255,255,0);
	
}
