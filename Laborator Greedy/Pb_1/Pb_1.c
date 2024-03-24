#include <stdio.h>

int n = 7;
int a[] = {1, 5, 10, 50, 100, 200, 500};

int descompune(int x){

    if(x==0)
    {
        return 0;
    }
    if(x>=500)
    {
        return 1+descompune(x-500);
    }
    if(x>=200)
    {
        return 1+descompune(x-200);
    }
    if(x>=100)
    {
        return 1+descompune(x-100);
    }
    if(x>=50)
    {
        return 1+descompune(x-50);
    }
    if(x>=10)
    {
        return 1+descompune(x-10);
    }
    if(x>=5)
    {
        return 1+descompune(x-5);
    }
    if(x>=1)
    {
        return 1+descompune(x-1);
    }
  //se afiseaza decompunerea optimala si se returneaza numarul de termeni
  return 0;
}

int test(int testi, int x, int ans){
  int rez = descompune(x);
  if (ans == rez)
    printf("Test %d corect, rezultat: %d, asteptat: %d\n", testi, rez, ans);
  else
    printf("Test %d incorect, rezultat: %d, asteptat: %d\n", testi, rez, ans);
}

int main(){
  int testi=0;
  int xs[] = {7,130,1,741,2000};
  int ans[] = {3,4,1,7,4};
  for(testi=0; testi<sizeof(xs)/sizeof(int); testi++)
    test(testi, xs[testi], ans[testi]);
  return 0;
}
