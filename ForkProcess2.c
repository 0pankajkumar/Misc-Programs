#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int *a = 0;

int main()
{

if (fork() == 0) {
    *a = *a + 5;
    printf("%d\n",  &a);
}
else {
    *a = *a - 5;
    printf("%d\n", &a);
}

}