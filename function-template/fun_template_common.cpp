//
// Created by Administrator on 2017-12-10.
//

#include <iostream>

template<typename T>
void my_swap(T &a, T &b);

int main(int argc, char *argv[]) {
  using namespace std;
  int ai = 3, bi = 5;
  my_swap(ai, bi);
  cout << "ai: " << ai << ", bi: " << bi << endl;

  float af = 3.9, bf = 5.8;
  my_swap(af, bf);
  cout << "af: " << af << ", bf: " << bf << endl;

  return 0;
}

template<typename T>
void my_swap(T &a, T &b) {
  T temp;
  temp = b;
  b = a;
  a = temp;
}