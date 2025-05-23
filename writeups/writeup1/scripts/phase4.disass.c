void phase_4(char *param_1)

{
  int n_read;
  int number;
  
  n_read = sscanf(param_1,"%d",&number);
  if ((n_read != 1) || (number < 1)) {
    explode_bomb();
  }
  n_read = fibonacci(number);
  if (n_read != 0x37) {
    explode_bomb();
  }
  return;
}

int fibonacci(int number)

{
  int a;
  int b;
  
  if (number < 2) {
    b = 1;
  }
  else {
    a = fibonacci(number + -1);
    b = fibonacci(number + -2);
    b = b + a;
  }
  return b;
