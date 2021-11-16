
all: mkbuild app.exe

app.exe: build/data.o build/display.o build/main.o
	gcc -o app.exe build/data.o build/display.o build/main.o

build/data.o: data.c data.h
	gcc -c data.c -o build/data.o

build/display.o: display.c display.h
	gcc -c display.c -o build/display.o

build/main.o: main.c display.h data.h
	gcc -c main.c -I./  -o build/main.o

.PHONY: all clean mkbuild

clean:
	rm -rf build

mkbuild:
	@mkdir -p build

run: all
	@echo ""
	@echo "*********************"
	@echo "***Run The Program***"
	@echo "*********************"
	@echo ""
	@./app.exe
