#include <stdio.h>

int n;
int k;
int A[100000];

//区間内の値がxに抑えられ、区間の個数がk個以下に抑えられるかを判定

int p(int x){
    int sum = 0;
    int count=1;
    int i;

    for(i=0;i<n;i++){
        if(sum+A[i] > x){
            count +=1;
            sum =0;
        }
        sum += A[i];
    }
    return count<=k;
}


int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    lb=0;
    ub=100000001;




    while(ub-lb>1){
        unsigned int m= (ub+lb)/2;
        if(p(m)){
            ub=m;
        }
        else{
            lb=m;
        }

    }
    printf("%d\n",ub);
    return 0;
}
