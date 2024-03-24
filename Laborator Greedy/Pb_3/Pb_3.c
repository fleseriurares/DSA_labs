#include <stdio.h>
#include <string.h>
#include <math.h>

void converteste(long long x, int b, char* rez)
{
    //se converteste x in baza b si se memoreaza cifrele in sirul de caractere rez, terminat cu 0
    ///long long nr=pow(5,20);
    ///printf("%f\n",pow(2,1));
    int k=20;
    int ct=0;
    int ind=0;
    int nr=-1;
    while(x>0)
    {
        if(x>=pow(b,k))
        {
            x=x-pow(b,k);
            ct++;
            ind=1;

        }
        else
        {

            if(ind==1)
            {
                nr++;
                rez[nr]='0'+ct;
                /// printf("%c",rez[nr]);
                /// printf("ok");

                ct=0;
            }k--;
        }
    }
    nr++;
    rez[nr]='0'+ct;
    /// printf("%c",rez[nr]);
    /// printf("ok");
    if(ind==1)
    {

    while(k>0)
    {
        nr++;
        rez[nr]='0';
        k--;
    }
    }
}

void test(int testi, long long x, int b, char* ans)
{
    char rez[100]= {"0"};
    converteste(x, b, rez);
    if (strcmp(rez, ans) == 0)
        printf("Test %d corect, rezultat: %20s, asteptat: %20s\n", testi, rez, ans);
    else
        printf("Test %d incorect, rezultat: %20s, asteptat: %20s\n", testi, rez, ans);
}

int main()
{
    int testi = 0;
    long long xs[] = { 10, 345687, 100000000000, 1, 123456789456, 0 };
    int bs[] = { 2, 3, 8, 9, 5, 4 };
    ///printf("%.0lf\n",pow(5,20));
    char ans[][100] = { "1010", "122120012020", "1351035564000", "1", "4010314414230311", "0" };
    for (testi = 0; testi<sizeof(xs) / sizeof(long long); testi++)
        test(testi, xs[testi], bs[testi], ans[testi]);
    return 0;
}
