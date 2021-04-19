#include "MakeIntStack.h"
#include <iostream>
using namespace std;

MakeIntStack :: MakeIntStack(const MakeIntStack& s){
    tos = s.tos;
    size = s.size;
    p = new int[size];
    for(int i = 0;i<size; i++){
        p[i]=s.p[i];
    }
}
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
