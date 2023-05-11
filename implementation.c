#include "implementation.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

InputReader* IR_create() {
  InputReader *ir = (InputReader*) malloc(sizeof(InputReader));
  if(!ir) return null;
  ir->pos = 0;

  printf("Digite a expressao: ");
  scanf("%[^\n]", ir->input);
  getchar();
  printf("\n");

  ir->curr = ir->input[0];

  return ir;
}

void IR_free(InputReader *ir) {
  if(!ir) return;

  free(ir);
}

char IR_next(InputReader *ir) {
  return ir->input[++(ir->pos)];
}

char IR_actual(InputReader *ir) {
  return ir->input[ir->pos];
}

char IR_back(InputReader *ir) {
  return ir->input[--(ir->pos)];
}

static bool isDigit(char c) {
  return (c - 48) >= 0 && (c - 48) <=9;
}

static i32 charToDigit(char c) {
  return c-48;
}

f32 evaluateDigit(InputReader *ir) {
  i32 num = 0;

  if(!isDigit(IR_actual(ir))) exit(1);
  //TODO: add decimal numbers

  do {
    i32 digit = charToDigit(IR_actual(ir));
    num = num * 10;
    num = num + digit;
  } while(isDigit(IR_next(ir)));

  return (f32)num;
}

f32 evaluateNegative(InputReader *ir) {
  if(ir->input[ir->pos] == '-') {
    IR_next(ir);
    return evaluateDigit(ir) * -1;
  } else {
    return evaluateDigit(ir);
  }
}

f32 evaluatePrio(InputReader *ir) {
  f32 value = 0;

  if(IR_actual(ir) == '(') {
      IR_next(ir);
      value = evaluateExpr(ir);
      return value;
    } else if(IR_actual(ir) == ')') {
      IR_next(ir);
      return value;
    } else {
      return evaluateNegative(ir);
    }

  return value;
}

f32 evaluatePot(InputReader *ir) {
  f32 value = evaluatePrio(ir);

  while(IR_actual(ir) == '^') {
    IR_next(ir);
    value = pow(value, evaluatePrio(ir));
  }

  return value;
}

f32 evaluateMult(InputReader *ir) {
  f32 value = evaluatePot(ir);

  while(IR_actual(ir) == '*' || IR_actual(ir) == '/') {
    if(IR_actual(ir) == '*') {
      IR_next(ir);
      value *= evaluatePot(ir);
    } else if(IR_actual(ir) == '/') {
      IR_next(ir);
      value /= evaluatePot(ir);
    }
  }

  return value;
}

f32 evaluateAdic(InputReader *ir) {
  f32 value =  evaluateMult(ir);

  while(IR_actual(ir) == '+' || IR_actual(ir) == '-') {
    if(IR_actual(ir) == '+') {
      IR_next(ir);
      value += evaluateMult(ir);
    } else if(IR_actual(ir) == '-') {
      IR_next(ir);
      value -= evaluateMult(ir);
    }
  }

  return value;
}

f32 evaluateExpr(InputReader *ir) {
  return evaluateAdic(ir);
}

i32 main() {

  InputReader *ir = IR_create();

  printf("Retorno da expressao: %f\n", evaluateExpr(ir));

  IR_free(ir);
  return 0;
}