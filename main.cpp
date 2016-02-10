#include "FrameBuffer.cpp"
#include <cstring>
#include <termios.h>
#include <fstream>
#include <pthread.h>

using namespace std;

FrameBuffer FB;
vector<Point> P;

void printObject(int object[][2], int col, int size, int x, int y);

int main() {
	int plane[][2] = {{1,13},{3,15},{41,18},{41,16},{42,15},{31,13},{43,14},
		{47,14},{60,13},{48,15},{49,16},{49,18},{88,15},{89,13},
		{88,16},{49,20},{47,21},{43,21},{41,20},{2,16},{45,20}}; // dimensi 90 x 23
	
	FB.clearscreen();

	printObject(plane,sizeof(plane)/sizeof(*plane),10,0,0);



	/*
	P.push_back(Point (90,140));
	P.push_back(Point (120,140));
	P.push_back(Point (300,170));
	P.push_back(Point (200,270));
	P.push_back(Point (120,210));
	P.push_back(Point (105,270));
	P.push_back(Point (90,210));

	Polygon pol(P);
	FB.drawPolygon(pol, 255,204,0,0);
	pol.rotate(90);
	FB.drawPolygon(pol, 255,204,0,0);
	pol.rotate(180);
	FB.drawPolygon(pol, 255,204,0,0);
	*/

	FB.rasterScan(pol, 255,204,0,0);
	//pol.rotateCenter(90);
	//FB.drawPolygon(pol, 255,204,0,0);
	//pol.rotateCe(180);
	//FB.drawPolygon(pol, 255,204,0,0);
}

void printObject(int object[][2], int col, int size, int x, int y) {
	vector<Point> points;
	points.clear();
	for(int i=0;i<col-1;i++) {
		points.push_back(Point(object[i][0]*size+size*x,object[i][1]*size+size*y));
	}
	Polygon Poly(points);
	Poly.firePoint = Point(object[col-1][0]*size+size*x,object[col-1][1]*size+size*y);
	FB.drawPolygon(Poly.e,25,25,122,0);
	FB.floodFill(Poly.firePoint.x, Poly.firePoint.y, 255, 182, 193, 100, 149, 237);
}
