
S=..
PWDREL=nn

include $(S)/common.mk

nn_lib_src = nn.c
nn_lib_obj = $(patsubst %.c,%.o,$(nn_lib_src))

CFLAGS+= -I$(nn_inc_dir)

all: $(nn_lib)

$(nn_lib) : $(nn_lib_obj)
	$(AR) -cr $@ $?

.PHONY: test
test: $(nn_lib)
	@make -C tests

clean:
	rm -rf $(nn_lib) $(nn_lib_obj)
	@rm -rf .*~ *~
	@make -C tests clean

