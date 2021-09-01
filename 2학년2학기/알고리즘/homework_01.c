// 알고리즘 및 실습 A분반
// 20183343 정광원
#include <stdio.h>

// 1. 사용자에게 몇 개의 정수를 처리할 것인지 물어보는 함수 -> n 에 저장
int process_int(){
    int n=0;
    printf("Please enter how many integers you want to process --> ");
    scanf("%d",&n);
    return n;
}
// 2. n을 매개변수로 받아 n개의 정수를 저장하기 위한 배열을 동적으로 할당 받아 그 시작주소를 반환하는 함수
int * create_space(int n){
    int * ints;
    ints = (int *)malloc(n*sizeof(int));
    // dynamic allocation
    if(ints==NULL){
        printf("can't allocate memory\n");
    }
    return ints;
}
// 3. 배열의 시작주소와 원소의 개수 n을 매개변수로 받아 그 n개의 정수를 키보드로부터 입력받아 배열에 저장하는 함수
void input_ints(int * start_address, int count){
    for(int i=0;i<count;i++){
        printf("%d --> ",i+1);
        scanf("%d",start_address+i);
    }
}
// 4. 배열의 시작주소와 원소의 개수 n을 매개변수로 받아 그 평균을 반환하는 함수
double ret_avg(int * start_address, int count){
    int sum=0;
    double avg=0.0;
    for(int i=0;i<count;i++){
        sum += *(start_address+i);
    }
    avg = (double)sum / (double)count;
    return avg;
}
// 5. 위의 4개 함수를 적절히 호출하여 주어진 문제를 해결하기 위한 main() 함수
int main(){
    int count=0;
    int * ints=NULL;
    double avg = 0.0;
    count = process_int();
    ints = create_space(count);
    input_ints(ints,count);
    avg = ret_avg(ints,count);
    printf("%.2f\n",avg);
    free(ints); // destroy space
    system("pause");
    return 0;
}