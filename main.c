#include <time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

char *formatdate(char *str, time_t val)
{
  strftime(str, 36, "%04d%02d%02d_%02d%02d%02d.png", localtime(&val));
  return str;
}

int main()
{
  int errno = 0;
  const char *filename;
  filename = "test.png";

  struct stat *file_info = malloc(sizeof(struct stat));
  if(lstat(filename, file_info) != 0)
    {
      perror("Error");
      exit(1);
    }

  char date[36];
  rename(filename, formatdate(date, file_info->st_ctime));

  free(file_info);

  return 0;
}
