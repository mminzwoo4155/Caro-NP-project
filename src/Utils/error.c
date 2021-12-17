
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

#define NUM_OF_ERRORS 3

struct ErrorMessage {
  ErrorCode errorCode;
  char *message;
} errors[NUM_OF_ERRORS] = {
  {ERROR_COMMAND_NOT_FOUND, "Command not found!"},
  {ERROR_INVALID_STATUS_COMMAND, "Command can't execute in this status"},
  {ERROR_USER_DATABASE_NOTFOUND, "User database not found"}
};

void error(ErrorCode err) {
  int i;
  for (i = 0 ; i < NUM_OF_ERRORS; i ++) {
    if (errors[i].errorCode == err) {
      printf("ERROR: %s\n", errors[i].message);
      break;
    }
  }
  exit(i);
}