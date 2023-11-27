
BUILDDIR=$(CURDIR)/build

CC = g++

override CFLAGS += -g -std=c++11

TARGET = main

all: $(BUILDDIR) $(TARGET) 

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET): $(TARGET).cpp
			$(CC) $(CFLAGS) -o $(BUILDDIR)/$(TARGET) $(TARGET).cpp

clean:
			$(RM) -rv $(BUILDDIR)/*
			rmdir $(BUILDDIR)

run:	all
	$(BUILDDIR)/$(TARGET)