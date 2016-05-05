#include <stdio.h>
#include <stdlib.h>

int* countBits(int num, int* returnSize) {
    int *result;
    do {
    	result = (int*)malloc((num + 1) * sizeof(int));
    } while(!result);
    *returnSize = num + 1;
    int i;
    for (i = 0; i <= num; ++i) {
    	int rx;
    	if (i == 0) {
    		rx = 0;
    	} else if ((i & 1) == 1) {
    		rx = result[i - 1] + 1;
    	} else {
    		int k = i;
    		rx = 0;
    		while(k) {
    			if ((k & 1) == 1) {
    				rx++;
    			}
    			k >>= 1;
    		}
    	}
    	result[i] = rx;
    }
    return result;
}

int main() {
	int n;
	int *p = countBits(5, &n);
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d\n", p[i]);
	}
	free(p);
	return 0;
}
