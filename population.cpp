#include "population.h"

Population::Population(size_t init) {
    if(init < 2) {
        cerr << "Initial population must be at least 2. \nExiting..."<<endl;
        exit(1);}
    initial_genes.reserve(init);
    //created_genes.reserve(init);
    active_genes.reserve(init);
    next_genes.reserve(init);

    for(size_t i = 0; i < init; ++i) {
        Gene *temp = new Gene();
        initial_genes.push_back(temp);
        created_genes.push(temp);
        active_genes.push_back(temp);
    }
    sort_fitness();
    fitness(20);
}
//SAFE
Population::~Population() {
    while(!created_genes.empty()) {
        created_genes.pop();
    }
}

void Population::sort_fitness() {
    sort(active_genes.begin(), active_genes.end(), GeneComp());
}
bool Population::fitness(int perc) {
    tenth = (perc * active_genes.size()) / 100;
    if(active_genes.front()->get_fitness() == 90) {
        optimal_gene = active_genes.front();
        return true;
    }
    return false;
}

void Population::crossover(bool s) {
    size_t i = 0;
    for(; i < tenth; ++i) {
        next_genes.push_back(active_genes[i]);
    }
    for(; i < active_genes.size(); i+=2) {
        size_t p1 = rand() % (active_genes.size() / 2);
        size_t p2 = rand() % (active_genes.size() / 2);

        pair<Gene*, Gene*> spc;
        if(s) {spc = SinglePointCrossover(active_genes[p1], active_genes[p2]);}
        else  {spc = DoublePointCrossover(active_genes[p1], active_genes[p2]);}
        spc.first->mutate();
        spc.second->mutate();

        next_genes.push_back(spc.first);
        next_genes.push_back(spc.second);

        created_genes.push(spc.first);
        created_genes.push(spc.second);
    }
    active_genes = next_genes;
    next_genes.clear();
    sort_fitness();
}

ostream& operator<<(ostream& os, Population& p) {
    for(size_t i = 0; i < p.active_genes.size(); ++i) {
        os << p.active_genes[i]->get_fitness() << "\t\t" << *p.active_genes[i];
    }
    return os;
}
