#include "population.h"

Population::Population(int seed, size_t init) {
    initial_genes.reserve(init);
    created_genes.reserve(init);
    for(size_t i = 0; i < init; ++i) {
        Gene *temp = new Gene(seed);
        initial_genes.push_back(temp);
        created_genes.push_back(temp);
        active_genes.push_back(temp);
    }
}
Population::~Population() {
    for(size_t i = 0; i < created_genes.size(); ++i) {
        delete created_genes[i];
    }
}

void Population::calculate_fitness(vector<Gene*>& set) {
    for(size_t i = 0; i < set.size(); ++i) {
        set[i]->calculate_fitness();
    }
}
void Population::sort_fitness(vector<Gene*>& set) {
    sort(set.begin(), set.end(), GeneComp());
}
void Population::fitness() {
    size_t tenth = (10 * active_genes.size()) / 100;
    if((active_genes.size() <= tenth)) {
        return;
    }
    active_genes.erase(active_genes.begin()+tenth, active_genes.end());
}

void Population::crossover() {
    //git

}
