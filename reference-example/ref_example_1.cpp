//
// Created by Administrator on 2017/12/6.
//

#include <iostream>

double refcube(const double &ra);

int main(int argc, char * argv[]) {
    using namespace std;

    int rat = 101;
    int & rat_ref = rat;

    cout << "A rat: " << rat << std::endl;
    cout << "A rat reference: " << rat_ref << std::endl;
    rat_ref = 1001;
    cout << "Rat changed:  " << rat_ref << std::endl;

    cout << endl << "初始化引用为指针求值"<< endl;
    int * ptr = &rat;
    int & ref_a = *ptr;
    rat = 199;
    cout << "init ref use ptr deference:  " << ref_a << endl;


    cout << endl << "函数调用中创建引用临时变量" << endl;
    double side = 3;
    double * pd = &side;
    double & rd = side;
    long edge = 5L;
    double arr[4] = {
        2.0, 3.0, 4.0, 5.0
    };
    cout << "right type: " << refcube(side) << endl;
    cout << "de-referenced pointer " << refcube(*pd) << endl;
    cout << "reference " << refcube(rd) << endl;
    cout << "member of an array " << refcube(arr[2]) << endl;
    cout << "different type " << refcube(edge) << endl;
    cout << "literal: " << refcube(7.0) << endl;
    cout << "expression " << refcube(side + 1.0) << endl;

    return EXIT_SUCCESS;
}

double refcube(const double &ra) {
    return ra * ra * ra;
}