#include<stdio.h>
#define N 8
int falseCount(int arr[N][N],int row,int column){
    int cnt=0,i,j;
    for(i=0;i<N;){
        if(arr[i][column]==1){
            cnt++;
        }
        i++;
    }
    for(i=row-1,j=column-1;i>=0&&j>=0;){
        if(arr[i][j]==1){
            cnt++;
        }
        i--;
        j--;
    }
    for(i=row+1,j=column+1;i<=N-1&&j<=N-1;){
        if(arr[i][j]==1){
            cnt++;
        }
        i++;
        j++;
    }
    for(i=row-1,j=column+1;i>=0&&j<=N-1;){
        if(arr[i][j]==1){
            cnt++;
        }
        i--;
        j++;
    }
    for(i=row+1,j=column-1;i<=N-1&&j>=0;){
        if(arr[i][j]==1){
            cnt++;
        }
        i++;
        j--;
    }
    return cnt;
}
int main(){
    int arr[N][N],i,j,row=0,cnt=N,column=0,cnt1;
    for(i=0;i<N;i++){
        for(j=1;j<N;j++){
            arr[i][j]=0;
        }
    }
    for(i=0;i<N;i++){
        arr[i][0]=1;
    }
    for(i=0;i<N;i++){
        cnt=N;
        for(j=0;j<N;j++){
            arr[i][j]=0;
            cnt1=falseCount(arr,i,j);
            if(cnt>cnt1){
                cnt=cnt1;
                row=i;
                column=j;
            }
        }
        arr[row][column]=1;
        row=i+1;
        column=0;
    }
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}


