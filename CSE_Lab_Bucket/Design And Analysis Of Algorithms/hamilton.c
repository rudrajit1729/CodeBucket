#include <stdlib.h>
 
static unsigned int circuit_contains(const unsigned int *circuit, unsigned int c, unsigned int v)
{
    unsigned int i;
    unsigned int contains = 0;
    for (i = 0; i < c && !contains; i++) {
        contains = circuit[i] == v;
    }
    return contains;
}
 
typedef void (*circuitfn)(const unsigned int *, size_t);
 
static void hamiltonian_circuits_recursive(unsigned int **adjmat, size_t n, unsigned int *circuit,
       unsigned int c, circuitfn fun)
{
    if (c == n) {
        fun(circuit, n);
    }
    else {
        unsigned int v;
        for (v = 1; v < n; v++) {
            if (!circuit_contains(circuit, c, v) 
                && adjmat[circuit[ c - 1]][v] == 1 
                && (c < n - 1 || (adjmat[0][v] == 1 
                    && v < circuit[1]))) 
            {
                circuit[ c] = v;
                hamiltonian_circuits_recursive(adjmat, n, circuit, c + 1, fun);
            }
        }
    }
} 
 
void hamiltonian_circuits(unsigned int **adjmat, size_t n, circuitfn fun)
{
    unsigned int *circuit;
    circuit = malloc(n * sizeof(unsigned int));
    if (circuit == NULL) {
        return;
    }
    circuit[0] = 0;
    hamiltonian_circuits_recursive(adjmat, n, circuit, 1, fun);
    free(circuit);
}

static void print_circuit(const unsigned int *circuit, size_t len)
{
    unsigned int v;
    for (v = 0; v < len; v++) {
        printf("%d ", circuit[v]);
    }
    putchar('\n');
}
 
int main(void)
{
    unsigned int **adjmat;
    const size_t n = 5;
    unsigned int i, j;
 
    adjmat = malloc(n * sizeof(unsigned int *));
    for (i = 0; i < n; i++) {
        adjmat[i] = malloc(n * sizeof(unsigned int));
        for (j = 0; j < n; j++) {
            adjmat[i][j] = 1;
        }
    }
 
    hamiltonian_circuits(adjmat, n, print_circuit);
    for (i = 0; i < n; i++) {
        free(adjmat[i]);
    }
    free(adjmat);
 
    return 0;
}
