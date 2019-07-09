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

int quick_select(int A[], int n, int k){
    int h, i, j, pivot;
    pivot = A[0];
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

int median_of_median(int A[],int n, int k){
    int medians[(N+4)/5];
    int i, pivot, j;
    if(n <= 5){
        return quick_select(A, n, k);
    }
    else{
        for(i = 0; i < n/5 + 1; i++){
            if(i < (n - n%5)/5){
                medians[i] = quick_select(A + 5 * i, 5, 2);
            }
            else{
                medians[i] = quick_select(A + 5 * i, n%5, n%5/2);
            }
        }
        pivot = quick_select(medians, (n+4)/5, (n+4)/10);
        if(A[0] != pivot){
            for(int i = 1; i < n; i++)
                if(A[i] == pivot){swap(A + 0, A + i);
            }
        }
        return quick_select(A, n, k);
    }
}

int main(){
    int i;
    A[0] = 0;
    A[1] = 17; //原始元
    for(i=2;i<N;i++){
        A[i] = (long long int) A[i-1] * A[1] % N;
    }
    
    for(i=0;i<N;i++){
        if(median_of_median(A, N, i) != i) printf("ERROR %d %d\n", i, median_of_median(A, N ,i));
        //    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
    }
}

