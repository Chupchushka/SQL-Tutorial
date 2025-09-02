all:
	clang++ main.cpp -o main -lsqlite3
	./main
clean:
	rm main