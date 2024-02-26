V=1
SOURCE_DIR=src
BUILD_DIR=build
include $(N64_INST)/include/n64.mk

# Enable debug symbols and disable optimization
N64_C_AND_CXX_FLAGS += -g3 -ggdb -O0
N64_CXXFLAGS += -std=c++20

all: hello.z64
.PHONY: all

SRCS = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJS = $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

hello.z64: N64_ROM_TITLE="Hello World"

$(BUILD_DIR)/hello.elf: $(OBJS)

clean:
	rm -f $(BUILD_DIR)/* *.z64
	rm -f $(SOURCE_DIR)/*.d $(SOURCE_DIR)/*.o
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)