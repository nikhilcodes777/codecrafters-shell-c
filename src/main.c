#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  while (1) {
    printf("$ ");
    char buf[100];
    if (!fgets(buf, sizeof(buf), stdin)) {
      printf("Error reading from stdin\n");
      exit(0);
    }
    buf[strcspn(buf, "\n")] = 0;
    int exit_code = 0;
    if (sscanf(buf, "exit %d", &exit_code) >= 1) {
      exit(exit_code);
    }
    if (strncmp(buf, "exit", 4) == 0) {
      exit(0);
    }
    if (strncmp(buf, "echo", 4) == 0) {
      printf("%s\n", &buf[5]);
      continue;
    }

    if (strncmp(buf, "type", 4) == 0) {
      char *cmd = buf + 5;
      while (*cmd == ' ')
        cmd++;
      // TODO: Use Array but this works for now
      if (strcmp(cmd, "echo") == 0 || strcmp(cmd, "exit") == 0 ||
          strcmp(cmd, "type") == 0) {
        printf("%s is a shell builtin\n", cmd);
      } else if (*cmd == '\0') {
        continue;

      } else {
        printf("%s: not found\n", cmd);
      }
      continue;
    }
    printf("%s: command not found\n", buf);
  }

  return 0;
}
