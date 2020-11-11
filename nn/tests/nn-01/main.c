/* vim: set sw=1 : */

#include <stdio.h>
#include "nn.h"


#define test_number_createfromstr(nn, str) \
 do { \
  nn_number n ## nn; \
  printf("nn_createfromstr" #nn " = \"" str "\":"); \
  if(nn_createfromstr(n ## nn, str) == 0) \
  { nn_print(n ## nn); printf("\n"); } \
  else \
  { printf("n" #nn " failed\n"); return 1;} \
 }while(0)

int main(int argc, char *argv[]){

 test_number_createfromstr(1, "0");
 test_number_createfromstr(2, "");
 test_number_createfromstr(3, "1");
 test_number_createfromstr(4, "42");
 test_number_createfromstr(5, "2893893298");
 test_number_createfromstr(6, "010");
 test_number_createfromstr(7, "0010");

 return 0;
}
