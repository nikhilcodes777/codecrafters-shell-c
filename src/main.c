#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  while (1) {
    printf("$ ");
    char buf[100];
    scanf("%s", buf);
    printf("%s: command not found\n", buf);
  }
  return 0;
}
