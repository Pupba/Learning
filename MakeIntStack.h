#ifndef MakeIntStack_h
#define MakeIntStack_h
#include <iostream>
using namespace std;
class MakeIntStack {
    int* p;
    int size;
    int tos;
public:
    MakeIntStack();
    MakeIntStack(int size);
    MakeIntStack(const MakeIntStack& s);
    ~MakeIntStack();
    bool push(int n);
    bool pop(int& n);
};
#endif
