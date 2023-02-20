#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef GENE_H_
#define GENE_H_

const size_t GENE_SIZE = 10;

class Gene {
    private:
        int base[GENE_SIZE];
        int fitness;
    public:
        Gene(int seed = 1);
        Gene(int* data, size_t end, int seed = 1);

        void fill(size_t begin, size_t end);
        void calculate_fitness();
        int  get_fitness();

        friend ostream& operator<<(ostream& os, Gene& allele);
        friend pair<Gene*, Gene*> offspring(Gene* p1, Gene* p2);
        friend struct GeneComp;
};
#endif //GENE_H_
