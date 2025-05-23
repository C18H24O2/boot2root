void phase_5(char *str)

{
  int len;
  char key [6];
  
  len = string_length(str);
  if (len != 6) {
    explode_bomb();
  }
  len = 0;
  do {
    key[len] = (&array)[(char)(str[len] & 0xf)];
    len = len + 1;
  } while (len < 6);
  len = strings_not_equal(key,"giants");
  if (len != 0) {
    explode_bomb();
  }
  return;
}
