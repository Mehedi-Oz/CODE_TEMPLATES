#include <stdio.h>
void printar(int ar[], int n);
void mergesort(int ar[], int l, int r);
void merge (int ar[], int l, int r, int m);

void merge (int ar[], int l, int r, int m)
{
    //printf("Left = %d \t Right = %d\tmid = %d\n", l,r,m);
    int ls =  m -l + 1;
    int rs = r - m ;

    int L[ls], R[rs];

    for(int i = 0; i < ls; i++ )
        L[i] = ar[l+i];
    //printar()
    for(int i = 0; i < rs; i++ )
        R[i] = ar[m+1+i];

    int a1 = 0, a2 =0;
    int k = l;
    while((a1 < ls)  && (a2 < rs))
    {
        if (L[a1] > R[a2])
        {
            ar[k] = R[a2];
            a2++;
        }
        else
        {
            ar[k] =L[a1];
            a1++;
        }
        k++;
    }

    while(a1 < ls)
    {
        ar[k] = L[a1];
        k++;
        a1++;
    }
    while(a2 < rs)
    {
        ar[k] = R[a2];
        k++;
        a2++;

    }


}

void mergesort(int ar[], int l, int r)
{
    if(l>=r )  return;


    int m = (l+r) / 2;
    printar(ar, r+1);
    mergesort(ar, l, m);
    printar(ar, r+1);
    mergesort(ar, m+1, r);

    merge(ar, l, r, m);

}
void printar(int ar[], int n)
{
    for(int i = 0; i < n; i++ )
        printf("%d ", ar[i]);

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int ar[n];

    for(int i = 0; i < n; i++ )
        scanf("%d", &ar[i]);
    //printf("Before MergeSort: \n\t");
    //printar(ar,n);

    mergesort(ar, 0, n-1);

   // printf("After MergeSort: \n\t");
   // printar(ar,n);
    return 0;
}
