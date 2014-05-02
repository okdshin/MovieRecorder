CXX = g++ -std=gnu++11
CXXFLAGS = -Wall -g -D MOVIERECORDER_UNIT_TEST
INCLUDES = `pkg-config --cflag opencv` 
LIBS = `pkg-config --libs opencv`
OBJS = MovieRecorder.o
PROGRAM = MovieRecorder.out

all:$(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(INCLUDES) $(LIBS) -o $(PROGRAM)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -c $<

.PHONY: clean
clean:
	rm -f *o $(PROGRAM)
