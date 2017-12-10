//
// Created by Administrator on 2017-12-10.
//

#include <iostream>

#define NUL '\0'
const int kArSize = 64;

// 函数重载： 不取决于返回值，函数名相同，参数列表不同则是重载
unsigned long left(unsigned long num, unsigned ct);
char *left(const char *str, int n);

int main(int argc, char *argv[]) {
  using namespace std;
  char sample[kArSize] = "This is a wonderful world1";

  char *ps = left(sample, 4);
  cout << ps << endl;
  delete[] ps;

  unsigned long n = 123456789;
  cout <<left(n, 4) << endl;

  return 0;
}

unsigned long left(unsigned long num, unsigned ct) {
  unsigned digits = 1;
  unsigned long n = num;

  if (ct == 0 || num == 0) return 0;

  while(n /= 10)
    digits++;
  if (digits > ct) {
    ct = digits  - ct;
    while(ct--) {
      num /= 10;
    }
    return num;
  } else {
    return num;
  }
}

char *left(const char *str, int n) {
  if (n < 0) n = 0;
  char *p = new char[n + 1];
  int i;
  for (i = 0; i < n && str[i]; i++)
    p[i] = str[i];
  while (i <= n) p[i++] = NUL;
  return p;
}

