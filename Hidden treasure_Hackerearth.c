#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


int getSumOfDigits(int n) {
    int sum = 0;
    if (n < 0) n = -n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long solve(int n, int* nums) {
   
    long long count[200] = {0}; 
    long long totalPairs = 0;

    for (int i = 0; i < n; i++) {
        int sum = getSumOfDigits(nums[i]);
        
        totalPairs += count[sum];
        
    
        count[sum]++;
    }

    return totalPairs;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int i_nums;
    int *nums = (int *)malloc(sizeof(int) * (n));
    for(i_nums = 0; i_nums < n; i_nums++) {
        scanf("%d", &nums[i_nums]);
    }

    long long out_ = solve(n, nums);
    printf("%lld", out_);
    
    free(nums);
    return 0;
}
