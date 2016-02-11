#include "FrameBuffer.cpp"
#include <cstring>
#include <termios.h>
#include <fstream>
#include <pthread.h>

using namespace std;

FrameBuffer FB;
vector<Point> P;

void printObject(Polygon Poly);
Polygon matrixToPolygon(int object[][2], int col, int x, int y);

int main() {
	int plane[][2] = {{1,13},{2,15},{41,18},{41,16},{42,15},{31,13},{43,14},
		{47,14},{60,13},{48,15},{49,16},{49,18},{88,15},{89,13},
		{88,16},{49,20},{47,21},{43,21},{41,20},{2,16}}; // dimensi 90 x 23
	float size=1;
	Polygon polyPlane = matrixToPolygon(plane,sizeof(plane)/sizeof(*plane),0,0);

	int propeler1[][2]={{28,18},{23,18},{25,19},{27,19},{28,18},{27,17},{27,15},{28,13},{28,18},{29,17},{31,17},{33,18},{28,18},{29,19},{29,21},{28,23},{28,18}};

	/*while(size<10) {
		usleep(100000);
		FB.clearscreen();		
		printObject(polyPlane);
		size+=0.05;
		polyPlane.scale(size);
	}*/

	//FB.drawCircle(Point(400,200),50, 25,25,122,0);
 
	Polygon prop = matrixToPolygon(propeler1,sizeof(propeler1)/sizeof(*propeler1),0,0);
	prop.scale(5);
	while (true) {
		FB.rasterScan(prop,25,25,122,0);
		//op.scale()
		FB.clearscreen();
		prop.rotateCenter(10);
	}

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

	//FB.rasterScan(pol, 255,204,0,0);
	//pol.rotateCenter(90);
	//FB.drawPolygon(pol, 255,204,0,0);
	//pol.rotateCe(180);
	//FB.drawPolygon(pol, 255,204,0,0);
}

void printObject(Polygon Poly) {
	//FB.drawPolygon(Poly.e56);
	// Sky blue : 135 206 235
	FB.rasterScan(Poly, 0, 0, 0, 0);
}

Polygon matrixToPolygon(int object[][2], int col, int x, int y) {
	vector<Point> points;
	points.clear();
	for(int i=0;i<col;i++) {
		points.push_back(Point(object[i][0]+x,object[i][1]+y));
	}
	return Polygon(points);
}