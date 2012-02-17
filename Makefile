TARGETS = 01a 01a.s 01b 01c 01d 01d.s 01e 02a 02b 03a 03b 04a 04b \
          05a 05b 05c 06a 06b 07a 07b 08a 08b 08c 08d 09a 09b 09c \
          10a 10b
DISFLAGS = -masm=intel

all: $(TARGETS)

01a 01a.s: 01a.cpp
01d 01d.s: 01d.cpp

.cpp.s:
	$(CXX) $(DISFLAGS) -S $<

clean:
	rm -f $(TARGETS) *.exe *.s
