#include "genetics.h"
#include "gene_comparison.h"


Gene::Gene() {
    fill(0, GENE_SIZE);
    calculate_fitness();
}

Gene::Gene(size_t* data1, size_t* data2, size_t end1, size_t end2) {
    size_t i = 0;
    for(; i < end1; ++i) {
        base[i] = data1[i];
    }
    for(; i < end2; ++i) {
        base[i] = data2[i];
    }
    for(; i < GENE_SIZE; ++i) {
        base[i] = data1[i];
    }
    calculate_fitness();
}

void Gene::fill(size_t begin, size_t end) {
    for(; begin < end; ++begin) {
        base[begin] = rand() % 10;
    }
    calculate_fitness();
}
void Gene::calculate_fitness() {
    fitness = 0;
    for(size_t i = 0; i < GENE_SIZE; ++i) {
        fitness += base[i];
    }
}
size_t Gene::get_fitness() {
    return fitness;
}

void Gene::mutate() {
    size_t num_mutations = random(1);
    cout << num_mutations << "\t\t\t";
    for(size_t i = 0; i < num_mutations; ++i) {
        size_t point = rand() % GENE_SIZE;
        size_t mutation = rand() % GENE_SIZE;
        base[point] = mutation;
    }
}

ostream& operator<<(ostream& os, Gene& allele) {
    for(size_t i = 0; i < GENE_SIZE; ++i) {
        os << allele.base[i] << "\t";
    }
    os << endl;
    return os;
}
bool operator<(Gene& allele1, Gene& allele2) {return allele1.fitness < allele2.fitness;}
bool operator>(Gene& allele1, Gene& allele2) {return allele1.fitness > allele2.fitness;}
bool operator==(Gene& allele1, Gene& allele2) {return allele1.fitness == allele2.fitness;}

//const bool operator<(const Gene& allele1, const Gene& allele2) {return allele1.fitness < allele2.fitness;}
//const bool operator>(const Gene& allele1, const Gene& allele2) {return allele1.fitness > allele2.fitness;}
//const bool operator==(const Gene& allele1, const Gene& allele2){return allele1.fitness == allele2.fitness;}

pair<Gene*, Gene*> SinglePointCrossover(Gene* p1, Gene* p2) {

    size_t point = 0 + rand() % (GENE_SIZE - 1);
    cout << "Crossover point at " << point << endl;

    Gene* c1 = new Gene(p1->base, p2->base, point);
    Gene* c2 = new Gene(p2->base, p1->base, point);
    return make_pair(c1, c2);
}
pair<Gene*, Gene*> DoublePointCrossover(Gene* p1, Gene* p2) {

    size_t point1 = 1 + rand() % (GENE_SIZE - 2);
    size_t point2 = point1 + rand() % (GENE_SIZE - 1);

    Gene* c1 = new Gene(p1->base, p2->base, point1, point2);
    Gene* c2 = new Gene(p2->base, p1->base, point1, point2);

    return make_pair(c1, c2);
}
