#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
    int a;
    char b;
    short c;
}__attribute__((packed))AlignedStruct;
int main()
{
    AlignedStruct data;
    printf("size is %d \n",sizeof(AlignedStruct));
    printf("size of a is %p \n",&data.a);
    printf("size of b is %p \n",&data.b);
    printf("size of c is %p \n",&data.c);
    return 0;
}
// #include<stdio.h>
// #include<math.h>
// #include<stdlib.h>
// typedef struct{
//     int a;
//     char b;
//     short int c;
// }unaligned;
// int main()
// {
//     unaligned data;
//     printf("size is %zu \n",sizeof(unaligned));
//     printf("size of a is %p \n",&data.a);
//     printf("size of b is %p \n",&data.b);
//     printf("size of c is %p \n",&data.c);
//     return 0;
// }