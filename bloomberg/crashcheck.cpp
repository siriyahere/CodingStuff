#include <string.h>
#include<stdio.h>


int *p = NULL;

int func()
{
	int a;
	scanf("%d",&a);
  return *p;
}

static int c = func();

int main()
{
	printf("inside main");
  int a = 5;
  printf("%d",a);
  return 0;
}



