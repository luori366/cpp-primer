//
// Created by Administrator on 2017-12-10.
//

#include <iostream>
#define NUL '\0'
const int kArSize = 64;

char *left(const char *str, int n = 1);

int main(int argc, char *argv[]) {
  using namespace std;
  char sample[kArSize] = "This is a wonderful world1";

  char *ps = left(sample, 4);
  cout << ps << endl;
  delete[] ps;

  ps = left(sample);
  cout << ps << endl;
  delete[] ps;

  ps = left(sample, -2);
  cout << ps << endl;
  delete[] ps;

  return 0;
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