cc=g++

all:qsort.exe insert_sort.exe sort_stability.exe

qsort.exe:qsort.cc
	$(cc) -o $@ $< -lfmt

insert_sort.exe: insert_sorted.cc
	$(cc) -o $@ $<

sort_stability.exe: sort_stability.cc
	$(cc) -o $@ $<

shell_sort.exe:shell_sort.cc
	$(cc) -o $@ $<

heap_sorted.exe:heap_sorted.cc
	$(cc) -o $@ $<

clean:
	rm *.exe
