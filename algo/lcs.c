#include "stdio.h"
#include "string.h"

int max(int a, int b) {
  return a > b ? a : b;
}



int main(int argc, char *argv[]) {
  if(argc < 3) {
    printf("Bad input. Enter two strings like xBCATCGA xGBTACCGTCA\n");
    return -1;;
  }
  char *str1 = argv[1];
  char *str2 = argv[2];
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int lcslenmat[len1][len2];
  for(int i = 0; i < len1; ++i) {
    lcslenmat[i][0] = 0;
  }
  for(int j = 0; j < len2; ++j) {
    lcslenmat[0][j] = 0;
  }
  for(int i = 1; i < len1; ++i) {
    for(int j = 1; j < len2; ++j) {
      if(str1[i] == str2[j]) {
        lcslenmat[i][j] = 1 + lcslenmat[i-1][j-1];
      }
      else {
        lcslenmat[i][j] = max(lcslenmat[i-1][j], lcslenmat[i][j-1]);
      }
    }
  }
  int lcslen = lcslenmat[len1-1][len2-1];
  char lcs[lcslen+1];
  lcs[lcslen] = '\0';
  int i = len1-1;
  int j = len2-1;
  int k = lcslen-1;
  while(k >= 0) {
      if(str1[i] == str2[j]) {
        lcs[k] = str1[i];
        --k; --i; --j;
      }
      else if(lcslenmat[i-1][j] > lcslenmat[i][j-1]){
        --i;
      }
      else {
        --j; 
      }
  } 
  printf("===================================\n");
  printf("length of lcs: %i\n", lcslen); 
  printf("lcs: %s\n", lcs); 
  printf("===================================\n");
  return 0;
}
