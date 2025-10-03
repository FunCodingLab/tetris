# Makefile for the Tetris project
# This Makefile is designed for GCC/Clang and works on Linux, macOS,
# and on Windows with a build environment like MinGW-w64.

# Compiler and flags
CC = gcc
# CFLAGS: -Wall (warn all) -Wextra (extra warnings) -std=c99 (C standard) -g (debug symbols)
CFLAGS = -Wall -Wextra -std=c99 -g

# --- Cross-platform setup ---
# Default to Unix-like commands and executable names.
EXEC = tetris
RM = rm -f

# If on Windows, override the commands and add .exe suffix.
# Note: This requires 'make' from a shell that defines OS=Windows_NT, like Git Bash or MSYS2.
ifeq ($(OS),Windows_NT)
    EXEC := $(EXEC).exe
    RM = del /Q
endif

# Directories
APP_DIR = app
CORE_DIR = core
PLATFORM_DIR = platform

# Source files
# We list all the .c files we plan to have in the project.
SRCS = $(APP_DIR)/main.c \
       $(CORE_DIR)/game.c \
       $(CORE_DIR)/board.c \
       $(CORE_DIR)/tetromino.c \
       $(PLATFORM_DIR)/renderer.c \
       $(PLATFORM_DIR)/input.c

# Object files are derived from source files
OBJS = $(SRCS:.c=.o)

# Default target: build the executable
all: $(EXEC)

# Rule to link the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile .c files into .o files
# This is a generic rule that works for all our source directories.
# $< is the source file (e.g., app/main.c)
# $@ is the target file (e.g., app/main.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target to clean up the project directory
# The '-' prefix tells make to ignore errors (e.g., if files don't exist).
clean:
	-$(RM) $(OBJS) $(EXEC)

# Phony targets are not actual files
.PHONY: all clean

