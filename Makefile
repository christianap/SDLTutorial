default: debug
all: build/debug/main build/release/main
debug: build/debug/main
release: build/release/main
run: build/release/main
	./build/release/main

build/debug/main: src/main/c/main.c
	mkdir -p build/debug/
	gcc -std=c99 -Wall -g -Og src/main/c/*.c -lSDL2 -o build/debug/main

build/release/main: src/main/c/main.c
	mkdir -p build/release/
	gcc -std=c99 -Wall -O3 src/main/c/*.c -lSDL2 -o build/release/main

clean:
	rm -rf build/