# Directories
BUILD_DIR = build
BIN_DIR = bin
SRC_DIR = test
INCLUDES = src \
           test/catch
# Files
SOURCES = $(wildcard test/*.cpp)
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
EXECUTABLE = $(BIN_DIR)/GMathTest
# Flags
CFLAGS = $(addprefix -I , $(INCLUDES))
LDFLAGS =


$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp $(BUILD_DIR) $(BIN_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

.PHONY: clean
clean:
	rm -f $(OBJECTS) EXECUTABLE
	rm -rf $(BIN_DIR) $(BUILD_DIR)
