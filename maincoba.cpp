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
	FB.clearscreen();
	Polygon p= matrixToPolygon(people,sizeof(people)/sizeof(*people));
	p.moveDown(80);
	p.moveRight(22);
	FB.rasterScan(p,0,0,0,0);

	Polygon q= matrixToPolygon(parachute,sizeof(parachute)/sizeof(*parachute));
	q.scale(1.5);
	FB.rasterScan(q,0,0,0,0);
	return 0;
}

Polygon matrixToPolygon(int object[][2], int col) {
	vector<Point> points;
	points.clear();
	for(int i=0;i<col;i++) {
		points.push_back(Point(object[i][0],object[i][1]));
	}
	return Polygon(points);
}