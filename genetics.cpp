#include "genetics.h"
#include <new>

Gene::Gene(int seed) {
    srand(seed);
    fill(0, GENE_SIZE);
}

Gene::Gene(int* data, size_t end, int seed) {
    srand(seed);

    size_t i = 0;
    for(; i < min(end, GENE_SIZE); ++i) {
        base[i] = data[i];
    }

    fill(i, GENE_SIZE);
}

void Gene::fill(size_t begin, size_t end) {
    for(; begin < end; ++begin) {
        base[begin] = rand() % 10;
    }
}
void Gene::calculate_fitness() {
    fitness = 0;
    for(size_t i = 0; i < GENE_SIZE; ++i) {
        fitness += base[i];
    }
}
int Gene::get_fitness() {
    return fitness;
}

ostream& operator<<(ostream& os, Gene& allele) {
    for(size_t i = 0; i < GENE_SIZE; ++i) {
        os << allele.base[i] << "\t";
    }
    os << endl;
    return os;
}

pair<Gene*, Gene*> offspring(Gene* p1, Gene* p2) {
    Gene* c1 = new Gene();
    Gene* c2 = new Gene();
    return make_pair(c1, c2);
}
