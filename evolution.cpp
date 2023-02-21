#include "genetics.h"
#include "population.h"
#include "gene_comparison.h"

int main() {
    int seed;
    cout << "Seed: ";
    cin >> seed;

    srand(seed);

    Population curse;
    Population cursed(5);
    cout << cursed << endl;



    return 0;
}
