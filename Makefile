CC = clang
CFLAGS = 
DEPS = verifier.h performance.h matmul.h
OBJECTS = driver driver.o verifier.o performance.o matmul.o



%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

driver: driver.o verifier.o performance.o matmul.o
	$(CC) $(CFLAGS) -o $(OBJECTS)

clean: 
	rm -f $(OBJECTS) $(TARGET)