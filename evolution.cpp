#include "genetics.h"
#include "population.h"
#include "gene_comparison.h"

int main() {
    int seed;
    cout << "Seed: ";
    cin >> seed;

    srand(seed);

    Gene parent1;
    parent1.fill(0, GENE_SIZE);
    cout << parent1 << endl;
    for(size_t i = 0; i < 100000; ++i) {
        parent1.mutate();
        cout << parent1 << endl;
    }

    //pair<Gene*, Gene*> offspring = SinglePointCrossover(&parent1, &parent2);

    //cout << "Parent 1:\t\t" << parent1;
    //cout << "Parent 2:\t\t" << parent2;
    //
    //cout << endl;
    //
    //cout << "Offspring 1:\t" << *offspring.first;
    //cout << "Offspring 2:\t" << *offspring.second;

    return 0;
}
