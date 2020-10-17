#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


// Heplers
bool get(bool *a, int i);
void set(bool *a, int i, bool x);


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage:\n  ./primes <N>    where N - the greatest prime number to genetare.\n");
        return 1;
    }

    // Max prime number
    long N = atol(argv[1]);

    // Array of booleans
    bool *A = malloc(N/2);
    for (long i = 0; i < N/2; i++)
        A[i] = true;

    // The actual computation
    // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    long i = 3;
    long max = (long)sqrtl((long double)N);
    for (long i = 3; i <= max; i += 2)
        if (get(A, i))
            for (long p = i*i; p <= N; p += i)
                set(A, p, false);


    // Print the answer
    printf("2\n");
    for (long i = 0; i < N/2; i++) {
        if (A[i])
            printf("%li\n", (i+1)*2+1);
    }
    
    return 0;
}


bool get(bool *a, int i) {
    if (i % 2 == 0)
        return false;
    return a[i/2 - 1];
}
void set(bool *a, int i, bool x) {
    if (i % 2 == 1)
        a[i/2 - 1] = x;
}
