CXX=g++
CXXFLAGS+= -Wall -Werror
CXXFLAGS+= -std=c++20 -O3 -save-temps
CXXFLAGS+= -fconcepts-diagnostics-depth=10
CXXINCS=-Isrc -Ideps/n/dist/

all: \
	clean \
	test

clean:
	rm -rf building
	rm -f test*

building:
	mkdir -p building

tests-ares: src/tests-ares.cpp building
	${CXX} -o  building/tests-ares.app src/tests-ares.cpp ${CXXFLAGS} ${CXXINCS}
	./building/tests-ares.app

test: tests-ares

stats:
	wc -l building/*.s
