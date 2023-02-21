#include "genetics.h"

#ifndef GENECOMP_H_
#define GENECOMP_H_

struct GeneComp {
    bool operator() (Gene* allele1, Gene* allele2) {
        return allele1->fitness > allele2->fitness;
    }
    //const bool operator() (const Gene* allele1, const Gene* allele2) {
    //    return allele1->fitness > allele2->fitness;
    //}
};
#endif //GENECOMP_H_

#ifndef RANDOM
#define RANDOM
inline size_t random(size_t num) {
    size_t val = rand() % GENE_SIZE;
    if(val <= GENE_SIZE - 2) {
        return num;
    }
    else {
        return random(num+1);
    }
}
#endif
