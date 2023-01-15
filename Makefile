CC := gcc
LDFLAGS := $(LDFLAGS) -pthread

%:
	$(CC) $(LDFLAGS) $@.c -o $@.o -lm

clean:
	rm -rf *.o
	rm -rf *.out