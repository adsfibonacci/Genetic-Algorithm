#include "population.h"

Population::Population(int seed, size_t init) {
    initial_genes.reserve(init);
    created_genes.reserve(init);
    active_genes.reserve(init);
    next_genes.reserve(init);
    for(size_t i = 0; i < init; ++i) {
        Gene *temp = new Gene();
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
    tenth =   (10 * active_genes.size()) / 100;
    if((active_genes.size() <= tenth)) {
        return;
    }
}

void Population::crossover() {
    size_t i = 0;
    for(; i < tenth; ++i) {
        next_genes.push_back(active_genes[i]);
    }
    for(; i < active_genes.size(); ++i) {
        size_t p1 = rand() % (active_genes.size() / 50);
        size_t p2 = rand() % (active_genes.size() / 50);

        pair<Gene*, Gene*> spc = SinglePointCrossover(active_genes[p1], active_genes[p2]);
        spc.first->mutate();
        spc.second->mutate();
        next_genes.push_back(spc.first);
        next_genes.push_back(spc.second);
    }

}
