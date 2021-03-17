cc=g++

all:flock_t1_read.exe flock_t1_write.exe

flock_t1_read.exe:flock_t1_read.cc
	$(cc) -o $@ $< -lspdlog

flock_t1_write.exe:flock_t1_write.cc
	$(cc) -o $@ $< -lspdlog

clean:
	rm *.exe

