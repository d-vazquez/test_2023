
CC := g++
CFLAGS := -std=c++11  -g
TARGET := unit_test
BUILDDIR=$(CURDIR)/build

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(BUILDDIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(BUILDDIR)/$@ $(addprefix $(BUILDDIR)/,$^)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(BUILDDIR)/$@

clean:
	$(RM) -rv $(BUILDDIR)/*
	rmdir $(BUILDDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	
run: all
	$(BUILDDIR)/$(TARGET)

.PHONY: all clean run
