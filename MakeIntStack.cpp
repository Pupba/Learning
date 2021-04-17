#include "MakeIntStack.h"
#include <iostream>
using namespace std;

bool MakeIntStack::push(int n)
{
if (tos + 1 == size)
{ cout << "스택이 꽉 찼습니다." << endl; return false; }
tos++;
p[tos] = n;
}

bool MakeIntStack::pop(int& n)
{
if (tos == -1)
{ cout << "스택이" << endl; return false; }
n = p[tos];
tos--;
}
MakeIntStack:: ~MakeIntStack(){
    delete[] p;
}