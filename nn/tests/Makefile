
S=../..
PWDREL=nn/tests

include $(S)/common.mk

SUBDIRS=$(wildcard */)

.PHONY: $(SUBDIRS)

all clean: $(SUBDIRS)

$(SUBDIRS) :
	@rm -rf .*~ *~
	@make -C $@ $(MAKECMDGOALS)



