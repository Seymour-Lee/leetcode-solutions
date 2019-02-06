TARGET = proja

CPP = g++
CPPFLAGS = -std=c++11 -g -c -o

SRCS = $(shell ls *.cpp)
BASE = $(basename $(SRCS))
OBJS = $(addsuffix .o, $(addprefix obj/,$(BASE)))
DEPS = $(addsuffix .d, $(addprefix dep/,$(BASE)))

DEPFLAGS = -MM
DEPFILE = $@.$$$$

INCLUDEDIR := -I.\
              -I../include\

ifeq ("$(wildcard $(DIR_DEPS))", "")
	DEP_DIR_DEPS:=dep
endif

-include $(DEPS)

$(TARGET):$(OBJS)
		-rm -f $@
		$(CPP) -o $(TARGET) $(OBJS) -lpthread

obj/%.o: %.cpp
		@if test ! -d "obj"; then mkdir -p obj; else : ; fi
		$(CPP) $(CPPFLAGS) $@ -lpthread $(INCLUDEDIR) $<

dep/%.d: $(DEP_DIR_DEPS) %.cpp
		@if test ! -d "dep"; then mkdir -p dep; else : ; fi
		set -e; rm -f $@;
		$(CPP) $(DEPFLAGS) $(INCLUDEDIR) $< > $(DEPFILE); \
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
		rm -f $@.$$$$



all: $(SRCS) $(TARGET)

.PHONY:clean
clean:
	-rm -f $(TARGET) obj/*.o dep/*.d
	-rm -rf obj dep
