
// This is a mini project which is a clone of grep tool in linux .

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc < 3) {
    printf("\n  Usage : %s [OPTIONS] <PATTERN> <FILENAME>\n\n", argv[0]);
    printf("    Options : \n");
    printf("        -i or --ignore-case         : Match pattern ignoring case "
           "regardless of case sensitivity\n");
    printf("        -a or --all                 : Highlight all occurrences of "
           "the pattern in a line  "
           "of pattern in file\n");
    printf("        -h or --help                : To dislplay this help "
           "message\n");
    printf("        -c or --count                : To dislplay number of time "
           "pattern is occured  \n");
    return 1;
  }

  int highlightAll = 0;
  int help = 0;
  int caseInsestive = 0;
  int countOnly = 0;

  char *pattern = NULL;
  char *filename = NULL;

  for (int i = 1; i < argc; i++) {

    if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--ignore-case") == 0) {
      caseInsestive = 1;
    }

    else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      help = 1;
    }

    else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--all") == 0) {
      highlightAll = 1;
    }

    else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--count") == 0) {
      countOnly = 1;
    }

    else if (pattern == NULL) {
      pattern = argv[i];
    }

    else if (filename == NULL) {
      filename = argv[i];
    } else {
      printf("Invalid arguments");
    }
  }

  if (help || !pattern || !filename) {
    printf("\n  Usage : %s [OPTIONS] <PATTERN> <FILENAME>\n\n", argv[0]);
    printf("    Options : \n");
    printf("        -i or --ignore-case         : For searching pattern "
           "regardless of case sensitivity\n");
    printf("        -a or --all                 : For searching all occurences "
           "of pattern in file\n");
    printf("        -h or --help                : To dislplay this help "
           "message\n");
    printf("        -c or --count                : To dislplay number of time "
           "pattern is occured  \n");
    return 1;
  }

  char buffer[512];
  int line_number = 0;

  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error ! Can't Open File..\n");
    return 1;
  }

  int total_matches = 0;

  if (countOnly) {
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      char *line = buffer;
      while (1) {
        char *match =
            caseInsestive ? strcasestr(line, pattern) : strstr(line, pattern);
        if (!match) {
          break;
        }
        total_matches++;
        line = match + strlen(pattern);
        if (!highlightAll) {
          break;
        }
      }
    }
    printf("%d\n", total_matches);
    fclose(fp);
    return 0;

  } else {
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {

      line_number++;
      char *line = buffer;
      char *match;
      int first_match = 1;

      while (1) {
        char *match =
            caseInsestive ? strcasestr(line, pattern) : strstr(line, pattern);
        if (!match) {
          break;
        }

        if (first_match) {
          printf("%d : ", line_number);
        }

        printf("%.*s", (int)(match - line), line);
        printf("\033[0;31m%s\033[0m", pattern);
        line = match + strlen(pattern);
        first_match = 0;

        if (!highlightAll) {
          break;
        }
      }

      if (!first_match) {
        printf("%s", line);
      }
    }
  }
  fclose(fp);
  return 0;
}