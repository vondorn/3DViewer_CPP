PROJECT_FOLDER = ../opengl
APP = ../opengl/opengl.app//Contents/MacOS/opengl

all: rebuild

build:
	sh build.sh

run:
	./$(APP)

clean:
	-$(MAKE) clean --directory=$(PROJECT_FOLDER)
	-$(MAKE) distclean --directory=$(PROJECT_FOLDER)

rebuild: clean build run