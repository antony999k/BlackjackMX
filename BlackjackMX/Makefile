CXX = g++
CXXFLAGS = -Wall -std=c++11 -pedantic -pedantic
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lsfml-network -lm

#LDFLAGS = "-L/c/SFML-2.5.1/lib"
#CPPFLAGS = "-I/c/SFML-2.5.1/include"

#File that must be compiled
OBJECTS_SERVER = mainServer.o sockets.o gameInterface.o game.o blackjack.o blackjackRender.o socketsServer.o
OBJECTS_CLIENT = mainClient.o sockets.o gameInterface.o game.o blackjack.o blackjackRender.o
#Header files
DEPENDS = sockets.hpp gameInterface.hpp CODES.hpp DEFINITIONS.hpp game.hpp blackjack.hpp blackjackRender.hpp
#Output files
SERVER = mainServer
CLIENT = mainClient

all: $(SERVER) $(CLIENT)

#Make the server executable
$(SERVER): $(OBJECTS_SERVER)
	$(CXX) $^ -o $@ $(LDLIBS) $(LDFLAGS)

#Make the client executable
$(CLIENT): $(OBJECTS_CLIENT)
	$(CXX) $^ -o $@ $(LDLIBS) $(LDFLAGS)

%.o: %.c $(DEPENDS)
	$(CXX) $< -c -o $@ $(CXXFLAGS)

clean:
	$(RM) all $(OBJS)
