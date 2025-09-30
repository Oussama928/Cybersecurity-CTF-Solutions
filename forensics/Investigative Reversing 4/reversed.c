
undefined8 main(void)

{
  size_t sVar1;
  undefined4 local_4c;
  undefined1 local_48 [52];
  int local_14;
  FILE *local_10;
  
  flag = local_48;
  local_4c = 0;
  flag_index = &local_4c;
  local_10 = fopen("flag.txt","r");
  if (local_10 == (FILE *)0x0) {
    puts("No flag found, please make sure this is run on the server");
  }
  sVar1 = fread(flag,0x32,1,local_10);
  local_14 = (int)sVar1;
  if (local_14 < 1) {
    puts("Invalid Flag");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  fclose(local_10);
  encodeAll();
  return 0;
}


void encodeAll(void)

{
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  char local_9;
  
  local_28 = 0x635f31306d657449;
  local_20 = 0x706d622e70;
  local_18 = 0;
  local_48 = 0x622e31306d657449;
  local_40 = 0x706d;
  local_38 = 0;
  for (local_9 = '5'; '0' < local_9; local_9 = local_9 + -1) {
    local_48._0_6_ = CONCAT15(local_9,(undefined5)local_48);
    local_28._0_6_ = CONCAT15(local_9,(undefined5)local_28);
    encodeDataInFile(&local_48,&local_28);
  }
  return;
}


void encodeDataInFile(char *param_1,char *param_2)

{
  size_t sVar1;
  char local_2e;
  char local_2d;
  int local_2c;
  FILE *local_28;
  FILE *local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_20 = fopen(param_1,"r");
  local_28 = fopen(param_2,"a");
  if (local_20 != (FILE *)0x0) {
    sVar1 = fread(&local_2e,1,1,local_20);
    local_c = (int)sVar1;
    local_2c = 0x7e3;
    for (local_10 = 0; local_10 < local_2c; local_10 = local_10 + 1) {
      fputc((int)local_2e,local_28);
      sVar1 = fread(&local_2e,1,1,local_20);
      local_c = (int)sVar1;
    }
    for (local_14 = 0; local_14 < 0x32; local_14 = local_14 + 1) {
      if (local_14 % 5 == 0) {
        for (local_18 = 0; local_18 < 8; local_18 = local_18 + 1) {
          local_2d = codedChar(local_18,(int)*(char *)(*flag_index + flag),(int)local_2e);
          fputc((int)local_2d,local_28);
          fread(&local_2e,1,1,local_20);
        }
        *flag_index = *flag_index + 1;
      }
      else {
        fputc((int)local_2e,local_28);
        fread(&local_2e,1,1,local_20);
      }
    }
    while (local_c == 1) {
      fputc((int)local_2e,local_28);
      sVar1 = fread(&local_2e,1,1,local_20);
      local_c = (int)sVar1;
    }
    fclose(local_28);
    fclose(local_20);
    return;
  }
  puts("No output found, please run this on the server");
                    /* WARNING: Subroutine does not return */
  exit(0);
}


byte codedChar(int param_1,byte param_2,byte param_3)

{
  undefined1 local_20;
  
  local_20 = param_2;
  if (param_1 != 0) {
    local_20 = (byte)((int)(char)param_2 >> ((byte)param_1 & 0x1f));
  }
  return param_3 & 0xfe | local_20 & 1;
}

