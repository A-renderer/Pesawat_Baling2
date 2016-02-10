#include "FrameBuffer.cpp"
#include <cstring>
#include <termios.h>
#include <fstream>
#include <pthread.h>

using namespace std;

FrameBuffer FB;
vector<Point> P;

int main() {

	P.push_back(Point (90,140));
	P.push_back(Point (120,140));
	P.push_back(Point (300,170));
	P.push_back(Point (200,270));
	P.push_back(Point (120,210));
	P.push_back(Point (105,270));
	P.push_back(Point (90,210));

	Polygon pol(P);

	FB.rasterScan(pol, 255,204,0,0);
	//pol.rotateCenter(90);
	//FB.drawPolygon(pol, 255,204,0,0);
	//pol.rotateCe(180);
	//FB.drawPolygon(pol, 255,204,0,0);
}
