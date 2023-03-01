#include <stdio.h>
int coins (){
    int five = 0, ten = 0;
    // initialization
    int n = 0, current; 
    // n for the length of bills
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++){
        scanf("%d", &current);
        switch (current)
        {
        case 5:
            five++;
            break;
        case 10:
            ten++;
            five = five -2;
            if (five < 0) 
                return 0 ;
            break;
        case 20:
            if (five - 3 < 0 && (ten - 1 < 0 || five - 1 < 0))
                return 0 ;
            else if (ten -1 < 0 || five -1 < 0)
                five = five - 3;
            else {
                five--;
                ten--;
            }
            break;
        default:
            break;
        }
    }
    return 1;
}

int main (){
    int ans = coins();
    if (ans)
        printf("true\n");
    else 
        printf("false\n");
    return 0;
}