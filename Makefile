TARGETS = 01a 01a.s 01b 01c 01c.s 01d 02a 02b 03a 03b 04a 04b
DISFLAGS = -masm=intel

all: $(TARGETS)

01a.s: 01a.cpp
01c.s: 01c.cpp

.cpp.s:
	$(CXX) $(DISFLAGS) -S $<

clean:
	rm -f $(TARGETS) *.exe *.s
