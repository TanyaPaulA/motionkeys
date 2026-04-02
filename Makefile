CC = gcc
CFLAGS = $(shell pkg-config --cflags opencv4)
LIBS = $(shell pkg-config --libs opencv4)

all:
	$(CC) src/main.c src/piano.c src/detector.c src/recorder.c -o motionkeys $(CFLAGS) $(LIBS)

clean:
	rm -f motionkeys
