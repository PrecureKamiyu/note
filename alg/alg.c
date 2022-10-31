#include <stdio.h>
#define infty 1000
int main (){
    int p[8];
    int q[8]; 
    int e[9][9], w[9][9];
    int root[8][8];
    for (int i = 0 ; i < 9 ; i++){
        for (int j = 0 ; j < 9; j++){
            e[i][j] = 0 ; 
            w[i][j] = 0 ;
        }
    }


    for (int i = 1 ; i < 8 ; i ++){
        scanf("%d", &p[i]);
    }
    // 这里是从 1 开始
    for (int i = 0 ; i < 8 ; i++){
        scanf("%d", &q[i]);
    }
    int n = 7;
    // n 真的是这个数?
    for (int i = 1; i <= n+1 ; i++) { // 真的是到 n+1 吗
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    // 初始化
    for (int l = 1; l <=n ; l++){
        for (int i = 1; i <= n - l+1; i++){
            int j = i+l-1;
            e[i][j] = infty;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for (int r = i ; r <= j ; r++){
                int t = e[i][r-1]+ e[r+1][j];
                if (t < e[i][j]){
                    e[i][j] = t; 
                    root[i][j] = r;
                }
            }
        }
    }
    for (int i = 0 ; i < 9 ; i++){
        for (int j = 0 ; j < 9 ; j++){
            printf ("%d ", e[i][j]);
        }
        printf ("\n");
    }
}