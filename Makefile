.PHONY: all debug release clean

# RELEASE_FLAGS = -O2 -Wall -DNDEBUG
# DEBUG_FLAGS   = -g -O0 -Wall
RELEASE_EXEC  = calk
DEBUG_EXEC    = calk-dbg
SOURCE        = calk

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): calk.cpp
	g++ $(DEBUG_FLAGS) calk.cpp -o $(DEBUG_EXEC) 

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): calk.cpp
	g++ $(RELEASE_FLAGS) calk.cpp -o $(RELEASE_EXEC)

clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)
