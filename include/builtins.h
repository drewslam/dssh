// dssh - Drewslam's Shell
#ifndef DSSH_BUILTINS
#define DSSH_BUILTINS

#include <stdbool.h>

void handleCD(char *in);

void handlePWD();

bool isBuiltin(char *c[]);

#endif
