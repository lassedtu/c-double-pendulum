CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
OUT_DIR := out
TARGET := $(OUT_DIR)/app
SRC := main.c

# Prefer pkg-config (most robust). Fallback to Homebrew Apple Silicon defaults.
RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib 2>/dev/null)
RAYLIB_LIBS := $(shell pkg-config --libs raylib 2>/dev/null)

ifeq ($(strip $(RAYLIB_LIBS)),)
RAYLIB_CFLAGS := -I/opt/homebrew/include
RAYLIB_LIBS := -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(RAYLIB_CFLAGS) $(RAYLIB_LIBS) -lm

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
