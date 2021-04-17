#ifndef MakeIntStack_h
#define MakeIntStack_h
#include <iostream>
using namespace std;
class MakeIntStack {
    int* p;
    int size;
    int tos;
public:
    MakeIntStack(){p = new int[5]; size = 5; tos = -1;};
    MakeIntStack(int size){p = new int[5];size = 5;tos = -1;};
    ~MakeIntStack();
    bool push(int n);
    bool pop(int& n);
};
#endif