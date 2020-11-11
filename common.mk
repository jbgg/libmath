
nn_dir=$(S)/nn
nn_lib=$(nn_dir)/libnn.a
nn_inc_dir=$(nn_dir)



CROSS=
AS=$(CROSS)as
CC=$(CROSS)gcc
AR=$(CROSS)ar
LD=$(CROSS)ld

CFLAGS=
LDFLAGS=


%.o : %.c
	@echo [CC] $(PWDREL)/$@
	@$(CC) $(CFLAGS) -c -o $@ $^

