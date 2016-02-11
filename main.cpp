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
	int iterasi=0;
	Polygon polyPlane = matrixToPolygon(plane,sizeof(plane)/sizeof(*plane));
	Polygon polyPropelerLeft = matrixToPolygon(propeler1,sizeof(propeler1)/sizeof(*propeler1));
	Polygon polyPropelerRight = matrixToPolygon(propeler2,sizeof(propeler2)/sizeof(*propeler2));


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