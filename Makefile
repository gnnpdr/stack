CC = g++

CFLAGS ?= -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
OUT_O_DIR ?= build
COMMONINC = -I./include
SRC = ./source

ROOT_DIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

override CFLAGS += $(COMMONINC)
CSRC = main.cpp source/errors.cpp source/check.cpp source/stk.cpp source/user.cpp
COBJ := $(addprefix $(OUT_O_DIR)/,$(CSRC:.cpp=.o))
DEPS = $(COBJ:.o=.d)

TARGET = stk

.PHONY: all
all: $(OUT_O_DIR)/$(TARGET)

$(OUT_O_DIR)/$(TARGET):$(COBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(COBJ):$(OUT_O_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(DEPS):$(OUT_O_DIR)/%.d : %.cpp
	@mkdir -p $(@D)
	$(CC) -E $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	rm -rf $(COBJ) $(DEPS) $(OUT_O_DIR)/$(TARGET) $(OUT_O_DIR)/$(SRC) $(OUT_O_DIR)/*.log log_file.txt text.txt
	
NODEPS = clean
	ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
	include $(DEPS)
endif