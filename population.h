#include "genetics.h"
#include "gene_comparison.h"

#ifndef POPULATION_H_
#define POPULATION_H_

class Population {
        private:
                vector<Gene*> initial_genes;
                vector<Gene*> created_genes;
                vector<Gene*> active_genes;
                vector<Gene*> next_genes;
                Gene* optimal_gene;

                size_t tenth;
        public:
                //initial populations
                Population(size_t init = 2);
                ~Population();

                //fitness
                void sort_fitness();
                bool fitness();

                //crossover
                void crossover(bool s);

                friend ostream& operator<<(ostream& os, Population& p);
                friend int main();
};

#endif // POPULATION_H_
