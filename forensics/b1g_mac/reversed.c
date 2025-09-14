
int __cdecl _main(int _Argc,char **_Argv,char **_Env)

{
  undefined4 local_60;
  undefined1 local_5a [50];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  FILE *local_18;
  int local_14;
  
  __main();
  _isOver = 0;
  local_28 = 0x65742f2e;
  local_24 = 0x7473;
  local_20 = 0;
  _folderName = &local_28;
  local_14 = 0;
  _pLevel = 0;
  local_18 = (FILE *)fopen("flag.txt","r");
  if (local_18 == (FILE *)0x0) {
    puts("No flag found, please make sure this is run on the server");
  }
  local_1c = fread(local_5a,1,0x12,local_18);
  if (local_1c < 1) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  _flag = local_5a;
  _flag_size = 0x12;
  local_60 = 0;
  _flag_index = &local_60;
  puts("Work is done!");
  listdir(local_14,_folderName);
  puts("Wait for 5 seconds to exit.");
  sleep(5);
  return 2;
}

/* listdir */

void __cdecl listdir(int param_1,undefined4 param_2)

{
  int iVar1;
  BOOL BVar2;
  char local_958 [2048];
  _WIN32_FIND_DATAA local_158;
  HANDLE local_18;
  bool local_11;
  int local_10;
  
  local_18 = (HANDLE)0x0;
  sprintf(local_958,"%s\\*.*");
  local_18 = FindFirstFileA(local_958,&local_158);
  if (local_18 == (HANDLE)0xffffffff) {
    printf("Path not found: [%s]\n");
  }
  else {
    local_10 = 1;
    local_11 = true;
    while (local_11 != false) {
      iVar1 = strcmp(local_158.cFileName,".");
      if ((iVar1 != 0) && (iVar1 = strcmp(local_158.cFileName,".."), iVar1 != 0)) {
        sprintf(local_958,"%s\\%s");
        if ((local_158.dwFileAttributes & 0x10) == 0) {
          if (local_10 == 1) {
            if (param_1 == 0) {
              hideInFile(local_958);
            }
            else if (param_1 == 1) {
              decodeBytes(local_958);
            }
          }
          local_10 = 1 - local_10;
        }
        else {
          printf("Folder: %s\n");
          listdir(param_1,local_958);
        }
      }
      if (_isOver != '\0') break;
      BVar2 = FindNextFileA(local_18,&local_158);
      local_11 = BVar2 != 0;
    }
    FindClose(local_18);
  }
  return;
}



/* hideInFile */

void __cdecl hideInFile(LPCSTR param_1)

{
  BOOL BVar1;
  _FILETIME local_2c;
  _FILETIME local_24;
  _FILETIME local_1c;
  char local_12;
  char local_11;
  HANDLE local_10;
  
  local_10 = CreateFileA(param_1,0x100,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  _DoNotUpdateLastAccessTime(local_10);
  if (local_10 == (HANDLE)0xffffffff) {
    printf("Error:INVALID_HANDLED_VALUE");
  }
  else {
    BVar1 = GetFileTime(local_10,&local_1c,&local_24,&local_2c);
    if (BVar1 == 0) {
      printf("Error: C-GFT-01");
    }
    else {
      local_11 = *(char *)(*_flag_index + _flag);
      *_flag_index = *_flag_index + 1;
      local_12 = *(char *)(*_flag_index + _flag);
      *_flag_index = *_flag_index + 1;
      encodeBytes(local_11,local_12,&local_2c.dwLowDateTime);
      if (0 < _pLevel) {
        local_11 = *(char *)(*_flag_index + _flag);
        *_flag_index = *_flag_index + 1;
        local_12 = *(char *)(*_flag_index + _flag);
        *_flag_index = *_flag_index + 1;
        encodeBytes(local_11,local_12,&local_1c.dwLowDateTime);
      }
      if (_pLevel == 2) {
        local_11 = *(char *)(*_flag_index + _flag);
        *_flag_index = *_flag_index + 1;
        local_12 = *(char *)(*_flag_index + _flag);
        *_flag_index = *_flag_index + 1;
        encodeBytes(local_11,local_12,&local_24.dwLowDateTime);
      }
      BVar1 = SetFileTime(local_10,&local_1c,&local_24,&local_2c);
      if (BVar1 == 0) {
        printf("Error: C-SFT-01");
      }
      else {
        if (_flag_size <= *_flag_index) {
          _isOver = 1;
        }
        CloseHandle(local_10);
      }
    }
  }
  return;
}




/* decodeBytes */

void __cdecl decodeBytes(LPCSTR param_1)

{
  BOOL BVar1;
  undefined4 local_40;
  undefined1 local_3c;
  undefined3 uStack_3b;
  undefined4 local_38;
  _FILETIME local_34;
  _FILETIME local_2c;
  _FILETIME local_24;
  int local_1c;
  uint local_18;
  HANDLE local_14;
  int local_10;
  
  local_14 = CreateFileA(param_1,0x80,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  _DoNotUpdateLastAccessTime(local_14);
  if (local_14 == (HANDLE)0xffffffff) {
    printf("error loading the file");
  }
  else {
    BVar1 = GetFileTime(local_14,&local_24,&local_2c,&local_34);
    if (BVar1 == 0) {
      printf("error getting the times of the file");
    }
    else {
      local_38 = 0;
      local_40 = CONCAT13((char)(local_24.dwLowDateTime & 0xffff),
                          CONCAT12((char)((local_24.dwLowDateTime & 0xffff) >> 8),
                                   (short)CONCAT31((int3)local_34.dwLowDateTime,
                                                   (char)(local_34.dwLowDateTime >> 8))));
      local_18 = local_2c.dwLowDateTime & 0xffff;
      _local_3c = CONCAT31(CONCAT21(0x6472,(char)local_18),(char)(local_18 >> 8));
      local_1c = (_pLevel + 1) * 2;
      local_10 = 0;
      while ((local_10 < local_1c && (*_buff_index < _buff_size))) {
        *(undefined1 *)(_buff + *_buff_index) = *(undefined1 *)((int)&local_40 + local_10);
        *_buff_index = *_buff_index + 1;
        local_10 = local_10 + 1;
      }
      if (_buff_size <= *_buff_index) {
        _isOver = 1;
      }
    }
  }
  return;
}


