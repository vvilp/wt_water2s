COMPILER=G++
C = cpp
OUTPUT_PATH = ./
SOURCE_PATH = ./
EXE = $(OUTPUT_PATH)testc

COPT = -DMAC
CCMD = g++
OBJFLAG = -o
EXEFLAG = -o

# INCLUDES = -I../.includes
INCLUDES =
LIBS = -framework GLUT -framework OpenGL -lGL -lGLU
LIBPATH = -L"/System/Library/Frameworks/OpenGL.framework/Libraries" 

CPPFLAGS = $(COPT) $(INCLUDES) 
LDFLAGS = $(LIBPATH) $(LIBS)

FILES =  \
./main.cpp \
./wt_glapp.cpp \
./wt_opengl.cpp \
./wt_sample.cpp \


main : main.o $(FILES)

		$(CCMD) $(OBJFLAG) main $(FILES) $(CPPFLAGS) $(LDFLAGS)