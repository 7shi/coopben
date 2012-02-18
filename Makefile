TARGETS = 01a 01a.s 01b 01c 01d 01d.s 01e 02a 02b 03a 03b 04a 04b \
          05a 05b 05c 06a 06b 07a 07b 08a 08b 08c 08d 09a 09b 09c \
          10a 10b 11 11.s 12a 12b 13 14 15a 15b
DISFLAGS = -masm=intel

all: $(TARGETS)

01a 01a.s: 01a.cpp
01d 01d.s: 01d.cpp
11 11.s: 11.cpp
13: 13a.o 13b.o
14: 14a.o 14b.o

13 14:
	$(CXX) -o $@ $^

.cpp.s:
	$(CXX) $(DISFLAGS) -S $<

clean:
	rm -f $(TARGETS) *.exe *.s *.o
