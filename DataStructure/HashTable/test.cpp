#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"

int main()
{
    int N, i, p, j;
    long NoTem;
    char passwordTem[17];
    char op;
    HashTable H;
    
    scanf("%d", &N);
    getchar();
    H=InitializeTable(3 * N);
    
    for (i = 1; i <= N; i++)
    {
        scanf("%c", &op);
        scanf("%ld ", &NoTem);
        scanf("%s", passwordTem);
        getchar();
        
        j = Find(NoTem,H);
        if((H->TheCells[j]).Info == 1)
            p = 1;
        else
            p = 0;
        
        if ((op == 'R') && (p == 0))
        {
            Insert(NoTem, H,passwordTem);
            printf("Register Successful\n");
            continue;
        }
        
        if ((op == 'R') && (p != 0))
        {
            printf("ERROR: Account Number Already Exists\n");
            continue;
        }
        
        if ((op == 'L') && (p == 0))
        {
            printf("ERROR: Account Not Exist\n");
            continue;
        }
        
        if ((op == 'L') && (p != 0))
        {
            if (strcmp((H->TheCells[j]).Password, passwordTem) == 0)
                printf("Log in Successful\n");
            else
                printf("ERROR: Wrong Password\n");
            continue;
        }
        
    }
    return 0;
    
}

