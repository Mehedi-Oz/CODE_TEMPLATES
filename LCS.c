#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char in1[100], in2[100];
    scanf("%s %s", in1, in2);
    printf("%s %s\n", in1,in2);
    int l1 = strlen(in1);
    int l2 = strlen(in2);

    int LCS[l1+1][l2+1];
    for(int i = 0; i<(l1+1); i++)
    {
        for(int j = 0; j<(l2+1); j++)
        {
            LCS[i][j] = 0;
        }
    }

    for(int i = 1; i<(l1+1); i++)
    {
        for(int j = 1; j<(l2+1); j++)
        {
            if(in1[i-1] == in2[j-1])
            {

                LCS[i][j] = LCS[i-1][j-1] + 1; // ??
            }
            else
            {
                if(LCS[i-1][j] > LCS[i][j-1])
                {
                    LCS[i][j] = LCS[i-1][j];
                }
                else
                {
                    LCS[i][j] = LCS[i][j-1];
                }
            }
        }
    }

    for(int i = 0; i<(l1+1); i++)
    {
        for(int j = 0; j<(l2+1); j++)
        {
            printf("%d\t",LCS[i][j]);
        }
        printf("\n");
    }

    return 0;
}
