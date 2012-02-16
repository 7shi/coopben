TARGETS = 01a 01a.s 01b 01c 01c.s 01d
DISFLAGS = -masm=intel

all: $(TARGETS)

01a.s: 01a.cpp
01c.s: 01c.cpp

.cpp.s:
	$(CXX) $(DISFLAGS) -S $<

clean:
	rm -f $(TARGETS) *.exe *.s
