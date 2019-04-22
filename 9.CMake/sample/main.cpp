//main.cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sdk.h" // 导入int sdk_add(const int a, const int b)函数的声明

int main(int argc, char* argv[])
{

  int a = 1;
  int b = 2;
  int sum = sdk_add(a, b);

  printf("sum[%d].\n", sum);

  return 0;
}
