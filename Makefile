CC=gcc
CXX=g++
LC_ALL=cs_CZ.utf8
CFLAGS=-g -std=c99 -Wall -pedantic -Wextra -fPIC
CXXFLAGS=-g -std=c++11 -Wall -pedantic -Wextra
LDFLAGS=-lm

all: tail tail2 wordcount wordcount-dynamic

#tail -----------------------------------------

tail: tail.o

tail.o: tail.c

tail2: tail2.o
	$(CXX) $(CXXFLAGS) tail2.o -o tail2

tail2.o: tail2.cc
	$(CXX) $(CXXFLAGS) -c tail2.cc

io.o: io.c


#wordcount -------------------------------------
wordcount.o: wordcount.c

wordcount: wordcount.o io.o libhtab.a 
	$(CC) -static wordcount.o io.o -L. -lhtab -o wordcount

libhtab.a: htab_init.o hash_function.o htab_clear.o htab_remove.o htab_move.o htab_free.o htab_size.o htab_bucket_count.o htab_lookup_add.o htab_find.o htab_print_item.o htab_foreach.o
	ar rcs libhtab.a htab_init.o hash_function.o htab_clear.o htab_remove.o htab_move.o htab_free.o htab_size.o htab_bucket_count.o htab_lookup_add.o htab_find.o htab_print_item.o htab_foreach.o 

htab_move.o: htab_move.c

htab_init.o: htab_init.c

hash_function.o: hash_function.c

htab_clear.o: htab_clear.c

htab_remove.o: htab_remove.c

htab_free.o: htab_free.c

htab_size.o: htab_size.c

htab_bucket_count.o: htab_bucket_count.c

htab_lookup_add.o: htab_lookup_add.c

htab_find.o: htab_find.c

htab_print_item.o: htab_print_item.c

htab_foreach.o: htab_foreach.c


#wordcount-dynamic -----------------------------
wordcount-dynamic: wordcount.o libhtab.so io.o
	$(CC) wordcount.o io.o -o wordcount-dynamic -L. -lhtab

libhtab.so: htab_move.o htab_init.o hash_function.o htab_clear.o htab_remove.o htab_free.o htab_size.o htab_bucket_count.o htab_lookup_add.o htab_find.o htab_print_item.o htab_foreach.o 
	$(CC) $(CFLAGS) -shared -o libhtab.so htab_move.o htab_init.o hash_function.o htab_clear.o htab_remove.o htab_free.o htab_size.o htab_bucket_count.o htab_lookup_add.o htab_find.o htab_print_item.o htab_foreach.o 

clean:
	rm -rf *.o tail tail2 wordcount wordcount-dynamic libhtab.*

pack:
	zip xblask04.zip *.c *.cc *.h Makefile

