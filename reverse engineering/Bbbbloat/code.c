
undefined8 FUN_00101307(void)

{
  long in_FS_OFFSET;
  int local_48;
  undefined4 local_44;
  char *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = 0x4c75257240343a41;
  local_30 = 0x3062396630664634;
  local_28 = 0x65623066635f3d33;
  local_20 = 0x4e326560623535;
  local_44 = 0xd2c49;
  printf("What\'s my favorite number? ");
  local_44 = 0xd2c49;
  __isoc99_scanf(&DAT_00102020,&local_48);
  local_44 = 0xd2c49;
  if (local_48 == 0x86187) {
    local_44 = 0xd2c49;
    local_40 = (char *)FUN_00101249(0,&local_38);
    fputs(local_40,stdout);
    putchar(10);
    free(local_40);
  }
  else {
    puts("Sorry, that\'s not it!");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


char * FUN_00101249(undefined8 param_1,char *param_2)

{
  char cVar1;
  char *__s;
  size_t sVar2;
  ulong local_20;
  
  __s = strdup(param_2);
  sVar2 = strlen(__s);
  for (local_20 = 0; local_20 < sVar2; local_20 = local_20 + 1) {
    if ((' ' < __s[local_20]) && (__s[local_20] != '\x7f')) {
      cVar1 = (char)(__s[local_20] + 0x2f);
      if (__s[local_20] + 0x2f < 0x7f) {
        __s[local_20] = cVar1;
      }
      else {
        __s[local_20] = cVar1 + -0x5e;
      }
    }
  }
  return __s;
}

