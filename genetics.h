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
        Gene();
        Gene(int* data1, int* data2, size_t end1, size_t end2 = GENE_SIZE);

        void fill(size_t begin, size_t end);
        void calculate_fitness();
        int  get_fitness();

        friend ostream& operator<<(ostream& os, Gene& allele);
        friend pair<Gene*, Gene*> SinglePointCrossover(Gene* p1, Gene* p2);
        friend pair<Gene*, Gene*> DoublePointCrossover(Gene* p1, Gene* p2);
        friend struct GeneComp;
};
#endif //GENE_H_
