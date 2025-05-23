void phase_2(char *numbers)

{
  int i;
  int tab [7];
  
  read_six_numbers(numbers,tab + 1);
  if (tab[1] != 1) {
    explode_bomb();
  }
  i = 1;
  do {
    if (tab[i + 1] != (i + 1) * tab[i]) {
      explode_bomb();
    }
    i = i + 1;
  } while (i < 6);
  return;
}
