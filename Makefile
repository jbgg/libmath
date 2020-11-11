
S=.

include $(S)/common.mk

dirs= nn

.PHONY: $(dirs) all test clean

all: $(dirs)

test: $(dirs)

$(dirs) : 
	@make -C $@ $(MAKECMDGOALS)

clean: $(dirs)
	@rm -rf *~ .*~

