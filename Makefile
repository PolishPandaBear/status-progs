CXXFLAGS := -Ofast -std=c++2b $(CXXFLAGS)
targets = $(patsubst src/%.cpp, %, $(wildcard src/*.cpp))

all: $(targets)

%: src/%.o
	g++ $(LDFLAGS) $^ -o $@

src/%.o: src/%.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(targets) src/*.o

.PHONY: clean
