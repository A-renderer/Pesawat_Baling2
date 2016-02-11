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

int main() {
	float size=1;
	int iterasi=0;
	Polygon polyPlane = matrixToPolygon(plane,sizeof(plane)/sizeof(*plane));
	Polygon polyPropelerLeft = matrixToPolygon(propeler1,sizeof(propeler1)/sizeof(*propeler1));
	Polygon polyPropelerRight = matrixToPolygon(propeler2,sizeof(propeler2)/sizeof(*propeler2));
	Polygon polyParachute = matrixToPolygon(parachute,sizeof(parachute)/sizeof(*parachute));
	polyParachute.scale(1.2);
	polyParachute.moveRight(300);
	polyParachute.moveDown(100);
	FB.clearscreen();
	int startX = 0; int startY = 0; int finishX = 91; int finishY = 25;
	while(iterasi<35) {
		FB.rasterScan(polyPlane,0,0,0,0);
		FB.rasterScan(polyPropelerLeft,160,60,60,0);
		FB.rasterScan(polyPropelerRight,160,60,60,0);
		polyPlane.scale(1.05); polyPlane.moveDown(1); polyPlane.moveRight(1);
		polyPropelerLeft.scale(1.05); polyPropelerLeft.moveDown(1); polyPropelerLeft.moveRight(1); polyPropelerLeft.rotateCenter(15);
		polyPropelerRight.scale(1.05); polyPropelerRight.moveDown(1); polyPropelerRight.moveRight(1); polyPropelerRight.rotateCenter(15);
		usleep(100000);
		iterasi++;
		startX = startX * 1.05 + 0.5; finishX = finishX * 1.05 + 3; finishY = finishY * 1.05 + 2;
		FB.cleararea(startX, startY, finishX, finishY);
	}
	FB.clearscreen();
	FB.rasterScan(polyParachute,250,128,114,0);
	FB.rasterScan(polyPlane,0,0,0,0);
	FB.rasterScan(polyPropelerLeft,160,60,60,0);
	FB.rasterScan(polyPropelerRight,160,60,60,0);

	// Anggap ini sudah meledak
	FB.clearscreen();

	startX = 200; startY = 100; finishX = 500; finishY = 500;
	iterasi = 0; bool isRight = true;
	while(iterasi<30) {
		FB.cleararea(startX, startY, finishX, finishY);
		FB.rasterScan(polyParachute,255,128,114,0);
		if(iterasi%8==4) {
			if(isRight) isRight = false;
			else isRight = true;
		}
		if(isRight) {
			polyParachute.moveRight(3);
		}
		else {
			polyParachute.moveLeft(3);
		}
		polyParachute.moveDown(10);
		usleep(100000);
		iterasi++;
	}

}

Polygon matrixToPolygon(int object[][2], int col) {
	vector<Point> points;
	points.clear();
	for(int i=0;i<col;i++) {
		points.push_back(Point(object[i][0],object[i][1]));
	}
	return Polygon(points);
}