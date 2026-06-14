HEADERS = include 
SOURCE = src
BUILD = build
OBJS_DIR = $(BUILD)/obj
TARGET = $(BUILD)/run

CC = g++
LINKED = -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl
FLAGS = -I$(HEADERS) 

$(BUILD):
	mkdir -p $@

# find all cpp and c programms in source dir
DOTC = $(wildcard $(SOURCE)/*.cpp) $(wildcard $(SOURCE)/*.c)

# match every sourc/.cpp  to object_dir/.o (just the name)
# the first parameter says what you are looking and where it is
# the second parameter says how it looks like and where to place it 
# the third parameter says what to replace the actuall names of the files 
OBJSCPP = $(patsubst $(SOURCE)/%.cpp, $(OBJS_DIR)/%.o, $(DOTC))

# match every sourc/.c  to object_dir/.o (just the name)
OBJS = $(patsubst $(SOURCE)/%.c, $(OBJS_DIR)/%.o, $(OBJSCPP)) 


all: $(BUILD) $(OBJS_DIR) $(TARGET)

$(OBJS_DIR):
	mkdir -p $@

# target check if $(objs) has the .o. Check the $(objdir) if they exist.
$(TARGET): $(OBJS) 
	$(CC) $(OBJS) $(LINKED) -o $@

# specifies on how to create the .o when you see an objs_dir file 
$(OBJS_DIR)/%.o: $(SOURCE)/%.cpp
	$(CC) $(FLAGS)  -c $< -o $@ 

$(OBJS_DIR)/%.o: $(SOURCE)/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(BUILD)
