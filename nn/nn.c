/* vim: set sw=1 : */

#include "nn.h"

int nn_getndigits(nn_number n_a){
 return n_a->ndig;
}

int nn_clearndigits(nn_number n_a){
 n_a->ndig = 0;
 return 0;
}

nn_digit nn_getdigit(nn_number n_a, int index){
 int ndig = nn_getndigits(n_a);
 if(index < 0 || ndig <= index)
  return 0;
 return n_a->n[index];
}

int nn_setdigit(nn_number n_a, int index, nn_digit d){
 int k;
 if(index >= MAXDIGITS)
  return 1;
 int ndig = nn_getndigits(n_a);
 if(index >= ndig){
  n_a->n[index] = d;
  n_a->ndig = index + 1;
  for(k=index-1; k>=ndig; k--)
   n_a->n[k] = 0;
 }else
  n_a->n[index] = d;
 /* update ndigits */
 k = nn_getndigits(n_a)-1;
 while(k>=0 && nn_getdigit(n_a, k) == 0)
   k--;
 n_a->ndig = k + 1;
 return 0;
}

int nn_createfromstr(nn_number n_a, char *s){
 int k=0;
 if(nn_clearndigits(n_a) != 0)
  return 1;
 /* checking string */
 while(s[k] != 0){
  if(s[k] < '0' || s[k] > '9')
   return 1;
  k++;
 }
 /* empty string case */
 if(k==0) return 0;
 /* otherwise */
 /* s[0]   s[1]   .. s[k-2] s[k-1]
  * n[k-1] n[k-2] .. n[1]   n[0] */
 int index=0;
 while(k>0){
  k--;
  if(nn_setdigit(n_a, index, s[k]-'0') != 0)
   return 1;
  index++;
 }
 return 0;
}

int nn_addint(nn_number n_a, int n){
 int index = 0;
 if(n<0) return 1;
 while(n!=0){
  n += nn_getdigit(n_a, index);
  if(nn_setdigit(n_a, index, n % 10) != 0)
   return 1;
  n /= 10;
  index++;
 }
 return 0;
}

void nn_print(nn_number n_a){
 int k;
 int ndigits=nn_getndigits(n_a);
 if(ndigits == 0)
  printf("0");
 for(k = ndigits-1;k>=0;k--)
  printf("%d", nn_getdigit(n_a, k));
}

int nn_addto(nn_number n_o, nn_number n_a, nn_number n_b){
 int index = 0;
 int n = 0;
 nn_clearndigits(n_o);
 int a_ndigts = nn_getndigits(n_a);
 int b_ndigts = nn_getndigits(n_b);
 do{
  n += nn_getdigit(n_a, index) + nn_getdigit(n_b, index);
  if(nn_setdigit(n_o, index, n % 10) != 0)
   return 1;
  n /= 10;
  index++;
 }while(n!=0 || index < a_ndigts || index < b_ndigts);

 return 0;
}
