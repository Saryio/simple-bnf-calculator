#ifndef __IMPLEMENTATION_H__
#define __IMPLEMENTATION_H__

#include "types.h"

#define LEN_MAX 100

typedef struct inputReader {
  char curr;
  u8 pos;
  char input[LEN_MAX];
} InputReader;

InputReader* IR_create();
void IR_free(InputReader *ir);
char IR_next(InputReader *ir);
char IR_back(InputReader *ir);
char IR_actual(InputReader *ir);

f32 evaluateExpr(InputReader *ir);
f32 evaluateAdic(InputReader *ir);
f32 evaluateMult(InputReader *ir);
f32 evaluatePot(InputReader *ir);
f32 evaluatePrio(InputReader *ir);
f32 evaluateNegative(InputReader *ir);
f32 evaluateDigit(InputReader *ir);

#endif //__IMPLEMENTATION_H__
