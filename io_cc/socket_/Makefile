cc=g++

all:client1.exe server1.exe 

client1.exe:client1.cc
	$(cc) -o $@ $< -lspdlog

server1.exe:server1.cc
	$(cc) -o $@ $< -lspdlog

clear:
	rm *.exe
