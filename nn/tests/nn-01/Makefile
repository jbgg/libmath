
S=../../..
PWDREL=nn-01

include $(S)/common.mk

n01_src= main.c
n01_obj= $(patsubst %.c,%.o,$(n01_src))

CFLAGS=-I$(nn_inc_dir)

.PHONY: test clean

all: test

test : $(n01_obj)
	@gcc $(CFLAGS) -o $@ $(n01_obj) $(nn_lib)
	@./$@

clean :
	rm -rf test
	@rm -rf *~ .*~
