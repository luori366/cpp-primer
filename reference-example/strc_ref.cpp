//
// Created by Administrator on 2017-12-10.
//

#include <iostream>
#include <string>

struct FreeThrows {
  std::string name;
  int made;
  int attempts;
  float percent;
};

void display(const FreeThrows &ft);

void set_percent(FreeThrows &ft);

FreeThrows &accumulate(FreeThrows &target, const FreeThrows &source);

int main(int argc, char *argv[]) {
  FreeThrows one = {"One", 11, 21};
  FreeThrows two = {"Two", 12, 22};
  FreeThrows three = {"Three", 13, 23};
  FreeThrows four = {"Four", 14, 24};
  FreeThrows five = {"Five", 15, 25};
  FreeThrows team = {"Team", 19, 29};

  set_percent(one);
  display(one);
  accumulate(team, one);
  display(team);

  display(accumulate(team, one));
  accumulate(accumulate(team, two), three);
  display(team);

  FreeThrows dup = accumulate(team, five);

  return 0;
}

void display(const FreeThrows &ft) {
  using std::cout;
  using std::endl;
  cout << "Name: " << ft.name << endl;
  cout << "  Made: " << ft.made << '\t';
  cout << "Attempts: " << ft.attempts << '\t';
  cout << "Percent: " << ft.percent << endl;
}

void set_percent(FreeThrows &ft) {
  if (ft.attempts != 0) {
    ft.percent = 100.0f * ft.made / ft.attempts;
  } else {
    ft.percent = 0;
  }
}
/**
 * 链式返回，当不允许返回值被修改时，可以修改为返回const引用
 *
 * @param target
 * @param source
 * @return
 */
FreeThrows &accumulate(FreeThrows &target, const FreeThrows &source) {
  target.attempts += source.attempts;
  target.made += source.made;
  set_percent(target);
  return target;
}