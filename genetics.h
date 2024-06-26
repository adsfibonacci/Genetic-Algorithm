#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#ifndef GENE_H_
#define GENE_H_

const size_t GENE_SIZE = 10;

class Gene {

        private:
                size_t base[GENE_SIZE];
                size_t fitness;

        public:
                Gene();
                Gene(size_t* data1, size_t* data2, size_t end1, size_t end2 = GENE_SIZE);

                void fill(size_t begin, size_t end);
                void calculate_fitness();
                size_t get_fitness();

                void mutate();

                friend ostream& operator<<(ostream& os, Gene& allele);
                friend bool operator<(Gene& allele1, Gene& allele2);
                friend bool operator>(Gene& allele1, Gene& allele2);
                friend bool operator==(Gene& allele1, Gene& allele2);
                //friend const bool operator<(const Gene& allele1, const Gene& allele2);
                //friend const bool operator>(const Gene& allele1, const Gene& allele2);
                //friend const bool operator==(const Gene& allele1, const Gene& allele2);

                friend pair<Gene*, Gene*> SinglePointCrossover(Gene* p1, Gene* p2);
                friend pair<Gene*, Gene*> DoublePointCrossover(Gene* p1, Gene* p2);
                friend struct GeneComp;
};
#endif //GENE_H_

pair<Gene*, Gene*> SinglePointCrossover(Gene* p1, Gene* p2);
