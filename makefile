EXE:=game
TEST:=ts

CXX= gcc

CXXFLAGS+=-Wall -Wformat
INC+= -I./src

MAIN_SRC+= ./src/main.c ./src/base.c ./src/deck.c ./src/pdfl.c



TEST_SRC+= ./test/test.c
TEST_OBJS= $(TEST_SRC:.c=.o)

$(EXE): $(foreach v, $(MAIN_SRC),$(v))
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

$(TEST): $(foreach v, $(TEST_SRC),$(v))
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

all: $(EXE)

ts: $(clean) $(TEST)

.PHONY: clean
clean:
	@rm -f $(EXE) $(TEST)
