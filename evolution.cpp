#include "genetics.h"
#include "population.h"
#include "gene_comparison.h"

int main() {
    cout << boolalpha;

    int seed;
    cout << "Seed: ";
    cin >> seed;

    srand(seed);

    Population humanity(20);

    while(!humanity.fitness()) {
        //cout << "Marker" << endl;
        //cout << humanity << endl;
        humanity.crossover();
    }

    cout << endl;
    cout << *humanity.optimal_gene << endl;

    return 0;
}
