int func4(int num)

{
  int iVar1;
  int b;
  
  if (num < 2) {
    b = 1;
  }
  else {
    iVar1 = func4(num + -1);
    b = func4(num + -2);
    b = b + iVar1;
  }
  return b;
}
#include <stdio.h>
int main(void) {
	for (int i = 0; i < 100; i++)
	{
		printf("%d = %d\n", i, func4(i));
	}
}
