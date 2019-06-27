#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int median_of_median(int A[],int n){
    int i, j, pivot;
    int sublists[0];
    int medians[0];
    if (n <= 5){
        for (i=0; i< n ;i++) {
            for (j=i+1; j < n; j++) {
                if (A[i] > A[j]) {
                    swap(A + i, A + j);
                }
            }
        }}
        return A[(n/2)+1];
    if(n > 5){
        for (i = 0; i < (n -1/5)+1; i++){
            for(j = 0; j < 5; j++){
                sublists[j] = A[i];
            }
        medians[i] = median_of_median(sublists,5);
        }
        median_of_median(medians,(n -1)/5+1);
    }
}

int quick_select(int A[], int n, int k){
    int i, j, pivot;
    // 真ん中の要素をピボットとする
    pivot = median_of_median(A+0, n);
    for(i = j = 1; i < n; i++){
        if(A[i] <= pivot){
            swap(A+i, A+j);
            j++;
        }
    }
    if(j == k+1) return pivot;
    else if(j < k+1) return quick_select(A+j, n-j, k-j);
    else return quick_select(A+1, j-1, k);
}
    
int main(){
    int i;
    A[0] = 0;
    A[1] = 17; //原始元
    for(i=2;i<N;i++){
        A[i] = (long long int) A[i-1] * A[1] % N;
    }
    for(i=0;i<N;i++){
        //    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
        printf("%d th element is %d\n", i, median_of_median(A, N));
        fflush(stdout);
    }
}

