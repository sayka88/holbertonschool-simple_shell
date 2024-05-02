#include "main.h"

char *_getline(void)
{
  size_t size = 0;
  char *line = NULL;
  int input_cmd;
  size_t len_str;

  if (isatty(STDIN_FILENO))
  {
   printf("$ ");
  }
  input_cmd = getline(&line, &size, stdin);
  
  if (input_cmd == -1)
  {
    free(line);
    return NULL;
  }
  
  len_str = strlen(line);
  
  if (len_str > 0 && line[len_str - 1] == '\n')
  {
      line[len_str - 1] = '\0';
  }

  return line;
}
