#pragma once

#ifndef TOKENIZER_H
#define TOKENIZER_H
typedef enum
{
  OP_PLUS,  // +
  OP_MINUS, // -
  OP_STAR,  // *
  OP_SLASH  // /
} TK_OP;

typedef enum
{
  KW_INT,   // int
  KW_FLOAT, // float
  KW_STRING // string
} TK_KW;

typedef enum
{
  TOKEN_OPERATOR, // +, -, *, /
  TOKEN_KEYWORD,  // int, float, string
  TOKEN_INTEGER,  // 123
  TOKEN_FLOAT,    // 123.456
  TOKEN_STRING,   // "abc"
  TOKEN_EOF       // EOF
} TokenType;

struct token
{
  TokenType type;
  union
  {
    TK_KW kw;
    int op;
    int i;
    float f;
    char *s;
  } u;
};

#endif
