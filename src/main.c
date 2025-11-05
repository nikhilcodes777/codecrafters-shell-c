#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage
  printf("$ ");
  char buf[100];
  scanf("%s",buf);
  printf("%s: command not found",buf);

  return 0;
}
