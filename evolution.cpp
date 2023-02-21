#include "genetics.h"
#include "population.h"

int main() {
    int seed;
    cout << "Seed: ";
    cin >> seed;

    srand(seed);

    Gene parent1;
    Gene parent2;

    pair<Gene*, Gene*> offspring = SinglePointCrossover(&parent1, &parent2);

    cout << "Parent 1:\t\t" << parent1;
    cout << "Parent 2:\t\t" << parent2;

    cout << endl;

    cout << "Offspring 1:\t" << *offspring.first;
    cout << "Offspring 2:\t" << *offspring.second;

    return 0;
}
