#include "FrameBuffer.cpp"
#include <cstring>
#include <termios.h>
#include <fstream>
#include <pthread.h>
#include "assets.h"
#include <thread>

using namespace std;

FrameBuffer FB;
vector<Point> P;

void printObject(Polygon Poly);
Polygon matrixToPolygon(int object[][2], int col);
void *planeThread ();
bool isExploded();
void drawShip();

int main() {
	thread plane(planeThread);
	// PLAY BEGIN

	// KBHIT HERE

	// PLAY END
	plane.join();

	// TEMBAK
	Point P1(10,380);
	Point P2(300, 30);
	FB.shoot(P1,P2,255,0,0,0);

	// MELEDAK
	int iterasi = 0;
	int startX = 250, startY = 0, finishX = 400, finishY = 400;
	Polygon polyExplosion = matrixToPolygon(explode,sizeof(explode)/sizeof(*explode));
	polyExplosion.moveDown(150);
	polyExplosion.moveRight(350);
	while(iterasi<=20) {
		FB.rasterScan(polyExplosion,255,75+iterasi*9,0,0);
		iterasi++;
		usleep(100000);
		polyExplosion.scale(1.05);
		polyExplosion.moveLeft(17);
		polyExplosion.moveUp(8);
	}
	

	// PARACHUTE
	//FB.clearscreen();
	//drawShip();
	Polygon polyParachute = matrixToPolygon(parachute,sizeof(parachute)/sizeof(*parachute));
	polyParachute.scale(1.2);
	polyParachute.moveRight(360);
	polyParachute.moveDown(100);
	startX = 280; startY = 100; finishX = 500; finishY = 180;
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
		finishY += 10;
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

void *planeThread () {
	FB.clearscreen();
	drawShip();
	// while(!isExploded()) {
		float size=1;
		int iterasi=0;
		int startX = 0; int startY = 0; int finishX = 91; int finishY = 25;

		Polygon polyPlane = matrixToPolygon(plane,sizeof(plane)/sizeof(*plane));
		Polygon polyPropelerLeft = matrixToPolygon(propeler1,sizeof(propeler1)/sizeof(*propeler1));
		Polygon polyPropelerRight = matrixToPolygon(propeler2,sizeof(propeler2)/sizeof(*propeler2));
		
		while(iterasi<35) {
			FB.rasterScan(polyPlane,0,0,0,0);
			FB.rasterScan(polyPropelerLeft,160,60,60,0);
			FB.rasterScan(polyPropelerRight,160,60,60,0);
			polyPlane.scale(1.05); polyPlane.moveDown(1); polyPlane.moveRight(2);
			polyPropelerLeft.scale(1.05); polyPropelerLeft.moveDown(1); polyPropelerLeft.moveRight(2); //polyPropelerLeft.rotateCenter(15);
			polyPropelerRight.scale(1.05); polyPropelerRight.moveDown(1); polyPropelerRight.moveRight(2); //polyPropelerRight.rotateCenter(15);
			usleep(100000);
			iterasi++;
			startX = startX * 1.05 + 0.5; finishX = finishX * 1.05 + 3; finishY = finishY * 1.05 + 2;
			FB.cleararea(startX, startY, finishX, finishY);
		}
	// }
		FB.rasterScan(polyPlane,0,0,0,0);
		FB.rasterScan(polyPropelerLeft,160,60,60,0);
		FB.rasterScan(polyPropelerRight,160,60,60,0);
	
	return NULL;
}

bool isExploded() {
	return false;
}

void drawShip() {
	Polygon polyShip1 = matrixToPolygon(ship1,sizeof(ship1)/sizeof(*ship1));
	Polygon polyShip2 = matrixToPolygon(ship2,sizeof(ship2)/sizeof(*ship2));
	Polygon polyShip3 = matrixToPolygon(ship3,sizeof(ship3)/sizeof(*ship3));
	Polygon polyShip4 = matrixToPolygon(ship4,sizeof(ship4)/sizeof(*ship4));
	polyShip1.scale(3);
	polyShip2.scale(3);
	polyShip3.scale(3);
	polyShip4.scale(3);
	polyShip1.moveDown(380);
	polyShip2.moveDown(380);
	polyShip3.moveDown(380);
	polyShip4.moveDown(380);
	polyShip1.moveRight(10);
	polyShip2.moveRight(10);
	polyShip3.moveRight(10);
	polyShip4.moveRight(10);
	FB.rasterScan(polyShip1,89,131,153,0);
	FB.rasterScan(polyShip2,37,66,84,0);
	FB.rasterScan(polyShip3,41,81,106,0);
	FB.rasterScan(polyShip4,255,255,255,0);
	
}