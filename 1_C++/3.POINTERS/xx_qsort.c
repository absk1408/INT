#include<stdlib.h>
#include<stdio.h>

int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int arr[5]={5,3,2,8,1};

    qsort(arr,5,sizeof(int), compare);

    for(int i=0;i<5;i++){
        printf("%d\n",arr[i]);
    }
}