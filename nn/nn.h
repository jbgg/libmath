/* vim: set sw=1 : */


#ifndef __NN_H__
#define __NN_H__

#include <stdio.h>

#define MAXDIGITS 100

typedef char nn_digit;

typedef struct {
 nn_digit n[MAXDIGITS];
 int ndig;
} nn_number[1];

int nn_getndigits(nn_number n_a);
nn_digit nn_getdigit(nn_number n_a, int index);
int nn_createfromstr(nn_number n_a, char *s);
int nn_addint(nn_number n_a, int n);
void nn_print(nn_number n_a);

int nn_addto(nn_number n_o, nn_number n_a, nn_number n_b);


#endif /* __NN_H__ */

