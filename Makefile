# Programmer: Alfredo Yebra Jr.
# Date: March 20, 2016

#---- Target executable ----
TARGET 		= run

# ---- Project directories ----
SRC 		= src
INCS 		= include

# ---- Sources and Objects ----
SRCFILES	= $(wildcard $(SRC)/*.cpp)
OBJS 		= $(SRCFILES:.cpp=.o)

# ---- Compiler optiions ----
CXX			= g++
CFLAGS		= -g -Wall -I $(INCS) -fopenmp

# ---- Clean-up macro ----
RM			= rm -rf


# Use phony to ensure proper functionality of 'make' command.
.PHONY:
all:		$(TARGET)

# Build executable from objects.
$(TARGET): 	$(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

# Recipe to generate object files from .cpp files.
%.o:		%.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

# Clean up objects and executables.
.PHONY:
clean:
	$(RM) $(TARGET)
	$(RM) $(SRC)/*.o
