CC=gcc
CFLAGS=-Wall
EXECUTABLE = $(BUILDDIR)/cleaner
SOURCEDIR = .
BUILDDIR = ./build
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp $(SOURCEDIR)/*.c)
OBJECTS = $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))
MKDIR_P = mkdir -p

all: $(BUILDDIR) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(CFLAGS)  -o $@ $^

$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS)  -o $@ -c $^

.PHONY: $BUILDDIR
$(BUILDDIR): 
	$(MKDIR_P) $(BUILDDIR)

.PHONY : clean
clean : $(BUILDDIR)
	find $(BUILDDIR) | xargs rm -f

.PHONY : test
test:
	@echo $(OBJECTS) -- $(SOURCES)
