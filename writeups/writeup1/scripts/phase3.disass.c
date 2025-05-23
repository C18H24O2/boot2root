void phase_3(char *param_1)

{
  int n_scanned;
  char character;
  uint first_number;
  char letter;
  int second_number;
  
  n_scanned = sscanf(param_1,"%d %c %d",&first_number,&letter,&second_number);
  if (n_scanned < 3) {
    explode_bomb();
  }
  switch(first_number) {
  case 0:
    character = 'q';
    if (second_number != 0x309) {
      explode_bomb();
    }
    break;
  case 1:
    character = 'b';
    if (second_number != 0xd6) {
      explode_bomb();
    }
    break;
  case 2:
    character = 'b';
    if (second_number != 0x2f3) {
      explode_bomb();
    }
    break;
  case 3:
    character = 'k';
    if (second_number != 0xfb) {
      explode_bomb();
    }
    break;
  case 4:
    character = 'o';
    if (second_number != 0xa0) {
      explode_bomb();
    }
    break;
  case 5:
    character = 't';
    if (second_number != 0x1ca) {
      explode_bomb();
    }
    break;
  case 6:
    character = 'v';
    if (second_number != 0x30c) {
      explode_bomb();
    }
    break;
  case 7:
    character = 'b';
    if (second_number != 0x20c) {
      explode_bomb();
    }
    break;
  default:
    character = 'x';
    explode_bomb();
  }
  if (character != letter) {
    explode_bomb();
  }
  return;
}
