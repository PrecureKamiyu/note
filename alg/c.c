#include <stdio.h> 
#include <stdlib.h>
#define infty 100000
int dfs (int CurrentSpecial , int *ShinNeeds, int **special, int n, int *price, int NumofSpecial){
    int CopyNeeds[10] = {0};    // cpoy 一个数组, 向下进行一个传递. 
    int temp = 0, ans = 0;
    for (int i  = 0 ; i < n ; i++){
        CopyNeeds[i] = ShinNeeds[i] - special[CurrentSpecial][i];
                                // 根据这个礼包, 更新这个needs数组
        if (CopyNeeds[i] < 0)   // 如果说不用买这个礼包就直接返回最大值. 
        return infty;
    }
    // ans 更新为不买礼包的情况. 
    for (int i = 0 ; i < n ; i++)
        ans = ans + price[i] * CopyNeeds[i];
    // 遍历买各种礼包的情况.
    for (int i = 0 ; i < NumofSpecial ; i++){
        temp = dfs(i, CopyNeeds, special, n, price, NumofSpecial);
        if (temp < ans)
    // 如果说dfs结果更低一些, 就将ans更新.
            ans = temp;
    }
    return ans + special[CurrentSpecial][n];
}
int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize){
    int ans = infty;                // ans for answer
    int NumofSpecial = specialSize; // NumofSpecial , the number of specials
    int n = priceSize;              // n for number of items
    int temp; 
    for (int i = 0; i < NumofSpecial; i++){
        for (int j = 0; j < n+1; j++)
            scanf("%d", &special[i][j]);
    }
    // ans 更新为直接购入
    for (int i = 0; i < n; i++)
        ans = ans + needs[i] * price[i];
    // 
    for (int i = 0 ; i < NumofSpecial ; i++){
        temp = dfs(i , needs,special , n , price , NumofSpecial);
        if (temp < ans)
        ans = temp;
    }
    return ans;
}

int main (){

    int n = 0; // n , the number of items
    int price[10] ={0}, needs[10] = {0}; 
    int NumofSpecial = 0;
    int special[100][11] = {0};

    // initialization
    // read data
    printf("please input the number of items\n");
    scanf("%d", &n);
    printf("please input the price of items\n");
    for (int i = 0 ; i < n ; i++){
        scanf("%d", price+i);
    }
    printf ("please input the needs of items\n");
    for (int  i = 0; i < n; i++)
    {
        scanf("%d", needs+i);
    }
    printf("please input the number of special\n");
    scanf("%d", &NumofSpecial);
    printf("please input the special\n");

    int temp = shoppingOffers(price , n , special , NumofSpecial , n+1, needs , n);
    printf("%d", temp);
}