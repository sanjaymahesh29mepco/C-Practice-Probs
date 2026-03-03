#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
 
    int n,l,s = 0,t;
    scanf("%d", &n);
    t = n;
 
    while(t > 0)
    {
        l=t%10;
        s=s+l;
        t=t/10;
    }
    printf("%d",s);
}
