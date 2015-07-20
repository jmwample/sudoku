# Kyle Barron-Kraus <kbarronk>

BIN_NAME = sudoku

sudoku_SOURCES = sudokuBoard.cpp Sudoku.cpp 


CXX = g++
CXX_FLAGS = -std=c++11 -pedantic -Wall  -g -O0   #-wextra
LINK_FLAGS = -g -O0

BUILD_PATH = build

.PHONY: all
all: $(BIN_NAME)

$(BUILD_PATH):
	@echo "Creating directory: $@"
	@mkdir -p $@

$(BUILD_PATH)/%.o: %.cpp | $(BUILD_PATH)
	@echo "Compiling: $< -> $@"
	@$(CXX) $(CXX_FLAGS) -MP -MMD -c -o $@ $<

$(BIN_NAME):
	@echo "Linking: $@"
	@$(CXX) $(LINK_FLAGS) $($@_OBJS) -o $@

define BIN_T
 sudoku_OBJS = $$(sudoku_SOURCES:%.cpp=$$(BUILD_PATH)/%.o)
 sudoku: $$(sudoku_OBJS)
 SOURCES += $$(sudoku_SOURCES)
 OBJECTS += $$(sudoku_OBJS)
endef

$(foreach BIN,$(BIN_NAME),$(eval $(call BIN_T,$(BIN))))

DEP_FILES = $(OBJECTS:.o=.d)
-include $(DEP_FILES)

.PHONY: clean
clean:
	@$(RM) -r $(BIN_NAME) $(BUILD_PATH)
