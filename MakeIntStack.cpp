#include "MakeIntStack.h"
#include <iostream>
using namespace std;

MakeIntStack :: MakeIntStack(int size){
    this->size = size;
    tos = -1;
    p = new int[size];
}
MakeIntStack :: MakeIntStack(const MakeIntStack& s){
    this->size = s.size;
    this->tos = s.tos;
    this->p = new int[size];
    for(int i=0;i<size;i++){
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
