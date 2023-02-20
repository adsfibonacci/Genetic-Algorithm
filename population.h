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

                int tenth;
        public:
                //initial populations
                Population(int seed = 1, size_t init = 2);
                ~Population();

                //fitness
                void calculate_fitness(vector<Gene*>& set);
                void sort_fitness(vector<Gene*>& set);
                void fitness();

                //crossover
                void crossover();
};

#endif // POPULATION_H_
