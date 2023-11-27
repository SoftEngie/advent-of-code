CXX = g++
CXXFLAGS = -std=c++17
SRCDIR = ./

# Define the targets for days 1 to 25
days := $(shell seq 1 25)

all: $(days)

$(days): %: $(SRCDIR)/%.cpp $(wildcard $(SRCDIR)/*.hpp)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(days)