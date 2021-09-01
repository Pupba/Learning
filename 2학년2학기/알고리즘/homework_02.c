// 알고리즘 및 실습 A분반
// 20183343 정광원
#include <stdio.h>

/* 1. 이번 학기 수강하는 과목정보를 저장하기 위한 타입을 정의(type definition) 하라. 
과목 정보는 과목명, 담당교수명, 학점 등을 비롯한 기본적인 정보를 포함할 수 있도록 한다.*/
struct subject{
    char sub_name[50];
    char prof_name[50];
    char grades;
};
typedef struct subject SubjectT;

/* 2. 1에서 정의한 타입을 동적으로 할당받기 위한 함수 allocMem(int n) 함수를 작성한다. 
이 함수는 1에서 정의한 타입을 n개 저장할 수 있는 공간을 동적으로 할당받아 그 시작 주소를 반환하는 함수이다.*/
SubjectT * allocMem(int n){
    SubjectT * sub;
    sub = (SubjectT *)malloc(n*sizeof(SubjectT));
    if(sub==NULL){
        printf("can't allocate memory\n"); exit(1);
    }
    return sub;
}

// 3. main 함수에서는
int main(){
    int n,i;
    SubjectT * sub;
    // 1) 사용자로부터 이번 학기 수강신청한 과목의 개수를 입력받은 다음,
    printf("How many courses did you take? --> "); scanf("%d",&n);
    // 2) 2에서 정의한 함수를 호출하여 수강신청한 과목들을 모두 저장하기 위한 메모리를 동적으로 할당 받는다. 
    sub = allocMem(n);
    // 3) for 반복문과 scanf() 함수, gets() 함수를 호출하여 과목정보들을 입력받은 다음,  별도의 함수 작성
    for(i=0;i<n;i++){
        printf("-----------------%d------------------\n",i+1);
        getchar();
        printf("Subject Name---> ");gets((sub+i)->sub_name);
        printf("Professor Name---> ");gets((sub+i)->prof_name);
        printf("Grades ----> ");scanf("%c",&(sub+i)->grades);
        printf("------------------------------------\n\n");
    }
    // 4) 입력된 과목 정보들을 화면에 그대로 출력하고,
    printf("\n------------Subject Info------------\n");
    for(i=0;i<n;i++){
        printf("-----------------%d------------------\n",i+1);
        printf("Subject Name---> %s\n",(sub+i)->sub_name);
        printf("Professor Name---> %s\n",(sub+i)->prof_name);
        printf("Grades ----> %c\n",(sub+i)->grades);
        printf("------------------------------------\n\n");
    }
    // 5) 마지막으로 동적으로 할당 받은 메모리를 반환하고 종료한다.
    free(sub);
    system("pause");
}