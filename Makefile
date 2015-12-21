# PongPlusPlus-Client Makefile

# Version 0.1
# Author: Wojciech Bednarzak

##################################
# Editable compilation variables #
##################################

# Compiler
CC := g++

# Source directory
SRCDIR := src

# Build directory for 
BUILDDIR := build

# Target Output file
TARGET := bin/pppc

# Source file extention
SRCEXT := cpp

# List of flags
CFLAGS := -Wall -std=c++14

# Libraries to be used
LIB := -pthread -lGL -lSDL2 -lGLEW

# ------------------------------------------------------------------------------

############################################
# AUTOMATIC FILE GATHERING AND COMPILATION #
#               DO NOT EDIT                #
############################################
# Includes
INCLUDE := -I include
# All source files
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# All object files
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

$(TARGET): $(OBJECTS)
	@mkdir -p ./bin
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)
	@echo " Build Complete."

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) "; $(RM) -r $(BUILDDIR) $(TARGET)
	@echo " $(RM) -r bin "; $(RM) -r bin

# Tests
test:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester
