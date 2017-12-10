# C++函数重载

### Tip 1: 重载引用参数，调用时选择最匹配的版本

```c++
void stove(double r);           //1
void stove(double  &r);         //2
void stove(const double &&r);   //3

double x = 11.98;
const double rx = 2.566;

stove(x);       //matchest 1
stove(rx);      //matchest 2
stove(x + rx);  //matchest 3
```

### Tip 2: 何时使用函数重载？
函数用于完成某个任务，但是参数可能是不同类型时

### Tip 3: 函数重载如何实现的？
C++编译器会对不同版本的函数使用名称修饰(name decoration)
