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

void quick_sort(int A[], int n){
    int i,j,pivot;
    pivot = A[0];
    for(i = j = 1; i < n; i++){
        if(A[i] <= pivot){
            swap(A + i, A + j);
            j ++;
        }
    }
    swap(A + 0 ,A + (j-1));
    if(n == 0) return;
    else return quick_sort(A + 0 ,j-1),quick_sort(A + j ,n-j);
}

int sublists[5];
int medians[N/5];

int median_of_median(int A[],int n){
    int i, j, k;
    if (n <= 5){
        quick_sort(A,n);
        return A[n/2];
    }
    else{
        for (i = 0; i < n / 5; i++){
            k = 5 * i;
            for(j = 0; j < 5 && k < n; j++){
                sublists[j] = A[k];
                k += 1 ;
            }
            medians[i] = median_of_median(sublists,5);
        }
    quick_sort(medians,n/5);
    return medians[n/10];
    }
}

int quick_select(int A[], int n, int k){
    int h, i, j, pivot;
    pivot = median_of_median(A,n);
    for(i = 0 ;i <n ;i++){
        if(A[i] == pivot) h = i;
    }
    swap(A+0,A+h);
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
        if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
        //    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
    }
}

