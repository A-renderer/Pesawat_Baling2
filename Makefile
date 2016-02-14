all:
	g++ -o main *.cpp -pthread -std=c++11

run:
	./main

clean:
	rm main
