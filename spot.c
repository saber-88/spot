
// This is a mini project which is a clone of grep tool in linux .

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("\nUsage : %s [OPTIONS] <PATTERN> <FILENAME>\n\n", argv[0]);
    printf("    Options : \n\n");
    printf("        -i or --ignore-case         : Highlight all occurrences "
           "of pattern in a file ignoring case \n");
    printf("        -c or --count               : To dislplay number of time "
           "pattern is occured throughout the file \n");
    printf("        -h or --help                : To dislplay this help "
           "message\n");

    return 1;
  }

  int help = 0;
  int caseInsestive = 0;
  int countOnly = 0;
  int invalid_args = 0;

  char *pattern = NULL;
  char *filename = NULL;

  for (int i = 1; i < argc; i++) {

    if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--ignore-case") == 0) {
      caseInsestive = 1;
    }

    else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      help = 1;
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
      invalid_args = 1;
      printf("Invalid arguments\n");
    }
  }

  if (help || !pattern || invalid_args) {
    printf("\nUsage : %s [OPTIONS] <PATTERN> <FILENAME>\n\n", argv[0]);
    printf("    Options : \n\n");
    printf("        -i or --ignore-case         : Highlight all occurrences "
           "of pattern in a file ignoring case \n");
    printf("        -c or --count               : To dislplay number of time "
           "pattern is occured throughout the file \n");
    printf("        -h or --help                : To dislplay this help "
           "message\n");

    return 1;
  }

  char buffer[1024];   // creating a buffer to store the line of 1024 bytes from
                       // target file.
  int line_number = 0; // to keep track of line number.

  FILE *fp; //

  if (filename == NULL) {
    fp = stdin;
  } else {
    fp = fopen(filename, "r");
  }

  if (fp == NULL) {
    printf("Error ! Can't Open File..\n");
    return 1;
  }

  int total_matches =
      0; // for keeping track of count of how many time pattern occurs in file.

  if (countOnly) { // if count flag is parsed in argument then this block will
                   // run.
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      char *line = buffer;
      while (1) {
        char *match =
            caseInsestive ? strcasestr(line, pattern) : strstr(line, pattern);
        if (!match) {
          break;
        }
        total_matches++;
        line =
            match +
            strlen(
                pattern); // The line will point to next word after the pattern.
      }
    }
    printf("%d\n", total_matches);
    fclose(fp);
    return 0;

  } else {
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {

      line_number++;
      char *line = buffer;
      int first_match = 1; // for line numbering

      while (1) {
        char *match =
            caseInsestive ? strcasestr(line, pattern) : strstr(line, pattern);
        if (!match) {
          break;
        }

        if (first_match) {
          printf("\033[0;31m%d\033[0m : ", line_number);
        }

        printf("%.*s", (int)(match - line),
               line); // prints text before the pattern in normal colors.
        printf("\033[0;31m%s\033[0m",
               pattern); // prints pattern in hihghlighted color.

        line =
            match +
            strlen(
                pattern); // moves pointer to the next char after the pattern.
        first_match = 0;

      } // end of inner loop

      if (!first_match) {
        printf("%s", line);
      }

    } // end of outer loop

  } // end of if - else block

  fclose(fp);
  return 0;
}
