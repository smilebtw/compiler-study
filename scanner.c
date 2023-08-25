#include <stdio.h>
#include <stdlib.h>
#include "declare.h"
#include "tokenizer.h"
#include "global.h"

static int next_char(void)
{
  int c;

  c = fgetc(Input);
  return c;
}

static int skip(void)
{
  unsigned c;

  c = next_char();
  while (c && c <= ' ')
  {
    c = next_char();
  }

  return c;
}

void scan(struct token *t)
{
  int c;

  c = skip();

  switch (c)
  {
  case EOF:
    t->type = TOKEN_EOF;
    break;
  case '+':
    t->type = TOKEN_OPERATOR;
    t->u.op = OP_PLUS;
    break;
  case '-':
    t->type = TOKEN_OPERATOR;
    t->u.op = OP_MINUS;
    break;
  case '*':
    t->type = TOKEN_OPERATOR;
    t->u.op = OP_STAR;
    break;
  case '/':
    t->type = TOKEN_OPERATOR;
    t->u.op = OP_SLASH;
    break;

  default:
    // if (isdigit(c))
    // {
    //   t->type = TOKEN_INTEGER;
    //   t->u.kw = KW_INT;
    //   t->u.i = get_integer(c);
    //   break;
    // }

    printf("Unknown character: %c\n", c);
    exit(1);
  }
}
