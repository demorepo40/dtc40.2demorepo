#include<stdio.h>
#include<stdlib.h>
int main()
{
    int limit,i,sum=0,*ptr;
    printf("enter number of element");
    scanf("%d",&limit);
    ptr=(int*)malloc(limit*sizeof(int));
    if(ptr==NULL)
    {
        printf("memory not allocated");
    }
    printf("enter tha elements of tha array");
    for(i=0;i<limit;i++)
    {
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("sum=%d",sum);
    free (ptr);
    return 0;
}