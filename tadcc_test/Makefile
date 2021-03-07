gtestlib=-lgtest -lgmock -lgtest_main
pthread=-lpthread

all:string_alg_test.exe

string_alg_test.exe:string_alg.test.cc 
	g++ -o $@ $< -I../tadcc/ $(gtestlib) $(pthread)

test:string_alg_test.exe
	./string_alg_test.exe
