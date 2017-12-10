#include "inline_fun.h"

#include <cstdio>

inline int add(int x, int y) {
    return x + y;
}

int main(int argc, char *argv[]) {
    printf("%d\n", add(9, 8));
    return 0;
}

