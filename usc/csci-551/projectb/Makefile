BIN_NAME = projb

CPP = g++
CPPFLAGS = -std=c++11 -g -c -o

SRCS = $(shell ls *.cpp)
BASE = $(basename $(SRCS))
OBJS = $(addsuffix .o, $(addprefix obj/,$(BASE)))
DEPS = $(addsuffix .d, $(addprefix dep/,$(BASE)))

ifeq ("$(wildcard $(DIR_DEPS))", "")
	DEP_DIR_DEPS:=dep
endif

-include $(DEPS)

$(BIN_NAME):$(OBJS)
		-rm -f $@
		$(CPP) -o $(BIN_NAME) $(OBJS) -lpthread

obj/%.o: %.cpp
		@if test ! -d "obj"; then mkdir -p obj; else : ; fi
		$(CPP) $(CPPFLAGS) $@ -lpthread $(-I.) $<

dep/%.d: $(DEP_DIR_DEPS) %.cpp
		@if test ! -d "dep"; then mkdir -p dep; else : ; fi
		set -e; rm -f $@;
		$(CPP) $(-MM) $(-I.) $< > $($@.$$$$); \
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
		rm -f $@.$$$$

all: $(SRCS) $(BIN_NAME)

.PHONY:clean
clean:
	-rm -f $(BIN_NAME) obj/*.o dep/*.d
	-rm -rf obj dep
