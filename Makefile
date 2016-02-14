INC = -I/Library/Frameworks/glui.framework/Headers/
FRM = -framework OpenGL -framework GLUT -framework GLUI


%.o : %.cpp *.h
	g++   -Wno-deprecated -c -o $@ $<

a1: Assignment1.o 
	g++ -g *.o -o a1 $(INC) $(FRM)
