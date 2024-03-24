#include <stdio.h>
#include <stdlib.h>

/**
4. (*) Sa se implementeze operatiile pe o list ˘ a dublu înl ˘ an¸tuit ˘ a de tip XOR. Pentru o astfel de list ˘ a nu avem pointerii ˘
prev sau next, ci se folose¸ste un singur pointer care reprezinta ¸si pointerul anterior ¸si pe cel urm ˘ ator. Acest lucru ˘
este posibil folosind opera¸tia XOR, ¸si urmatoarele considera¸tii: ˘
A XOR B = C
C XOR A = B
C XOR B = A
Când se creaza o astfel de list ˘ a se realizeaz ˘ a un XOR între ˘ next ¸si prev, ¸si se salveaza pointerul la primul element. ˘
Sa presupunem c ˘ a A = ˘ prev, B = next, C = valoarea stocata.˘
5
3 Stiva. Coada. Liste Dublu Inlantuite
prev XOR next = valoarea stocata
valoarea stocata XOR prev = next
valoarea stocata XOR next = prev
Daca se traverseaz ˘ a lista XOR dublu înl ˘ an¸tuit ˘ a, se cunoa¸ste elementul curent ¸si elementul anterior, asa c ˘ a utilizând ˘
opera¸tiile de mai sus se poate calcula adresa elementului urmator din list ˘ a
*/

typedef struct node
{
    int val;
    struct node *next;
} nodeT;

 nodeT* XOR(struct nodeT *p, struct nodeT *r)
{
    return (nodeT *) p^r;
}

int main()
{
    printf("%d",3^1);
    return 0;
}
