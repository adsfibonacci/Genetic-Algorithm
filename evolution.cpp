#include "genetics.h"
#include "population.h"
#include "gene_comparison.h"

int main() {
    cout << boolalpha;

    srand((unsigned int)time(NULL));

    //vector<int> singles;
    //singles.reserve(50);
    //
    //vector<int> doubles;
    //doubles.reserve(50);
    //
    //for(size_t i = 0; i < 50; ++i) {
    //    Population humanity(50);
    //
    //    int round = 0;
    //    while(!humanity.fitness()) {
    //        humanity.crossover(false);
    //        round++;
    //    }
    //    singles.push_back(round);
    //}
    //
    //for(size_t i = 0; i < 50; ++i) {
    //    Population humanity(50);
    //
    //    int round = 0;
    //    while(!humanity.fitness()) {
    //        humanity.crossover(true);
    //        round++;
    //    }
    //    doubles.push_back(round);
    //}
    //
    //int s_avg = 0;
    //int d_avg = 0;
    //
    //for(size_t i = 0; i < 50; ++i) {
    //    s_avg += singles[i];
    //    d_avg += doubles[i];
    //}
    //
    //cout << "Single Crossover Average is " << (double)s_avg/50 << endl;
    //cout << "Double Crossover Average is " << (double)d_avg/50 << endl;

    Population humanity(4);
    while(!humanity.fitness()) {
        humanity.crossover(false);
    }

    cout << *humanity.optimal_gene << endl;

    return 0;
}
