void phase_6(char *str)

{
  int *piVar1;
  int j;
  int i;
  undefined1 *global;
  int *new_tab [6];
  int int_tab [6];
  int *ptr;
  
  global = node1;
  read_six_numbers(str,int_tab);
  i = 0;
  do {
    j = i;
    if (5 < int_tab[i] - 1U) {
      explode_bomb();
    }
    while (j = j + 1, j < 6) {
      if (int_tab[i] == int_tab[j]) {
        explode_bomb();
      }
    }
    i = i + 1;
  } while (i < 6);
  i = 0;
  do {
    j = 1;
    ptr = (int *)global;
    if (1 < int_tab[i]) {
      do {
        ptr = (int *)ptr[2];
        j = j + 1;
      } while (j < int_tab[i]);
    }
    new_tab[i] = ptr;
    i = i + 1;
  } while (i < 6);
  i = 1;
  ptr = new_tab[0];
  do {
    piVar1 = new_tab[i];
    ptr[2] = (int)piVar1;
    i = i + 1;
    ptr = piVar1;
  } while (i < 6);
  piVar1[2] = 0;
  i = 0;
  do {
    if (*new_tab[0] < *(int *)new_tab[0][2]) {
      explode_bomb();
    }
    new_tab[0] = (int *)new_tab[0][2];
    i = i + 1;
  } while (i < 5);
  return;
}
