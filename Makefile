all:
	g++ -o main FrameBuffer.cpp Line.cpp Point.cpp Polygon.cpp main.cpp -pthread -std=c++11

run:
	./main

clean:
	rm main
