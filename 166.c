#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define NODES 40960
#define HASH_LEN 512
#define FK_LEN 40960
#define STR_LEN 40960

typedef struct NODE_ {
	uint64_t value; int pos;
	struct NODE_ *next;
} NODE;
#define ABS(x) ((x) < 0 ? -(x) : (x))

char* fractionToDecimal2(uint64_t numerator, uint64_t denominator) {
	char *result;
	do {
		result = (char*)malloc(STR_LEN);
	} while(!result);
	result[0] = '\0';
	
	uint64_t div = numerator / denominator;
	numerator -= div * denominator;
	
	if (numerator == 0) {
		sprintf(result, "%llu", div);
		return result;
	} else {
		sprintf(result, "%llu.", div);
	}
	
	int reps[FK_LEN];
	int rep_now = 0;
	
	NODE nodes[NODES], *nal = nodes;
	#define ALLOC_NODE() (nal++)
	NODE *table[HASH_LEN];
	
	#define GET_HASH(var, val) {\
		(var) = ((1 + (~(val ^ 0xFF))) << 1) + val ^ 0xAC;\
		if (var < 0) var = -var;\
	}
	
	int i;
	for (i = 0; i < HASH_LEN; ++i) {
		table[i] = NULL;
	}
	
	char *wsp = result + strlen(result);
	#define WRP(x) *(wsp++) = (x)
	#define WFALL() --wsp
	
	while(numerator != 0L) {
		numerator *= 10;
//		printf("NUM: %d\n", numerator);
		{
			int hash;
			GET_HASH(hash, numerator);
			hash %= HASH_LEN;
			NODE *p = table[hash];
			while(p) {
				if (p->value == numerator) {
					int k;
					for (k = p->pos; k < rep_now; ++k) {
						WFALL();
					}
					WRP('(');
					for (k = p->pos; k < rep_now; ++k) {
						WRP('0' + reps[k]);
					}
					WRP(')');
					WRP('\0');
					return result;
				}
				p = p->next;
			}
			NODE *nn = ALLOC_NODE();
			nn->value = numerator;
			nn->pos = rep_now;
			nn->next = table[hash];
			table[hash] = nn;
		}
		
		reps[rep_now] = (int)(numerator / denominator);
		numerator -= reps[rep_now] * denominator;
		WRP('0' + reps[rep_now]);
//		printf("KEEP:\n");
//		int rb;
//		scanf("%d", &rb);
//		printf("RP:%d\n", reps[rep_now]);
		rep_now ++;
	
	}
	
	
	WRP('\0');
	return result;
}

char* fractionToDecimal(int numerator, int denominator) {
	int64_t a1 = (int64_t)numerator, a2 = (int64_t)denominator;
	int k1, k2;
	k1 = (a1 < (int64_t)0LL ? -1 : 1);
	k2 = (a2 < (int64_t)0LL ? -1 : 1);
//	printf("%d %d\n", k1, k2);
	
	a1 = ABS(a1); a2 = ABS(a2);
	char *buf = fractionToDecimal2((uint64_t)a1, (uint64_t)a2);
	if (k1 * k2 < 0 && strcmp(buf, "0") != 0) {
		char buf2[STR_LEN];
		sprintf(buf2, "-%s", buf);
		strcpy(buf, buf2);
	}
	
	return buf;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	char *p = fractionToDecimal(a, b);
	if (p) {
		printf("%s\n", p);
		free(p);
	}
	return 0;
}
