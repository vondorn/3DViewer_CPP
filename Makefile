PROJECT_FOLDER = ./3dviewer
APP = ./3dviewer/3dviewer.app/Contents/MacOS/3dviewer

all: rebuild

build:
	sh build.sh

run:
	./$(APP)

clean:
	-$(MAKE) clean --directory=$(PROJECT_FOLDER)
	-$(MAKE) distclean --directory=$(PROJECT_FOLDER)

rebuild: clean build run

qt:
	sh ~/Projects/s21_INSTASCRYPTS/src/instaqt.sh