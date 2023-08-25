#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define extern_
#include "global.h"
#undef extern_
#include "declare.h"

char *tokens[] = {"+", "-", "*", "/"};

static void scanner()
{
  struct token t;

  while (1)
  {
    scan(&t);
    if (t.type == TOKEN_EOF)
    {
      printf("Token identified: EOF\n");
      break;
    }
    printf("Token identified: %s\n", tokens[t.u.op]);
  }
}

void main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <input file>\n", argv[0]);
    exit(1);
  }

  if ((Input = fopen(argv[1], "r")) == NULL)
  {
    printf("Cannot open input file %s\n", argv[1]);
    exit(1);
  }

  scanner();
  exit(0);
}
