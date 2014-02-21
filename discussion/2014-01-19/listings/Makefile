CC := clang
CFLAGS := $(shell llvm-config --cflags)
LLVMLDFLAGS := $(shell llvm-config --ldflags)

SOURCES = $(shell ls *.c)

OBJECTS= $(SOURCES:.c=.o)
EXES = $(OBJECTS:.o=)

all: $(EXES) $(OBJECTS)

# %.o: %.c
# 	clang -o $@ $< $(CFLAGS)

%: %.c
	$(CC) -o $@ $< $(CFLAGS) $(LLVMLDFLAGS)

clean:
	-rm -f $(EXES) $(OBJECTS) *~