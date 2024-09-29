#include <stdio.h>
#include <limits.h>

int main() {
	int exemplo = INT_MAX + 5;
	
	// Valores minimos e maximos de cada variavel
	
    printf("Char:\n\nmin: %d \nMax: %d\n\n", CHAR_MIN, CHAR_MAX);
    printf("Int:\n\nmin: %d \nMax: %d\n\n", INT_MIN, INT_MAX);
    printf("Short int:\n\nmin: %d \nMax: %d\n\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned int:\n\nmin: %u \nMax: %u\n\n", 0, UINT_MAX);
    printf("Long int:\n\nmin: %ld \nMax: %ld\n\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long int:\n\nmin: %lu \nMax: %lu\n\n", 0UL, ULONG_MAX);
    printf("Long long int:\n\nmin: %lld \nMax: %lld\n\n", LLONG_MIN, LLONG_MAX);
    printf("Unsigned long long int:\n\nmin: %llu \nMax: %llu\n\n", 0ULL, ULLONG_MAX);
    
    // Exemplo de overflow
    
    printf("%d", exemplo);
    
    return 0;
}
