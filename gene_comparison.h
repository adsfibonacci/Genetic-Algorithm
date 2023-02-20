#include "genetics.h"

#ifndef GENECOMP_H_
#define GENECOMP_H_

struct GeneComp {
    bool operator() (Gene* allele1, Gene* allele2) {
        return allele1->fitness > allele2->fitness;
    }
    const bool operator() (const Gene* allele1, const Gene* allele2) {
        return allele1->fitness > allele2->fitness;
    }
};
#endif //GENECOMP_H_

template<typename T>
T weighted_probability() {

    vector<int> weights = {};

    for(size_t i = 0; i < GENE_SIZE; ++i) {

    }

}
