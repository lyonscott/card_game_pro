EXE:=game

CXX= gcc

CXXFLAGS+=-Wall -Wformat
INC+= -I./src

MAIN_SRC+= ./src/main.c \
./src/base.c \
./src/deck.c \
./src/pdfl.c \
./src/re.c \
./src/cstring.c
MAIN_OBJS= $(MAIN_SRC:.c=.o)

$(EXE): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

$(TEST): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

all: $(EXE) $(TEST)

clean:
	@rm -f $(EXE) $(MAIN_OBJS) $(TEST_OBJS)

%.o: %.c
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $^
