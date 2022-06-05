#include <vector>
using namespace std;

class FeatureSearch {
public:
    FeatureSearch(unsigned numFeatures, vector< float > &featureSet);
    vector<unsigned> forwardSelection();
    vector<unsigned> backwardElimination();
private:
    unsigned totalFeatures;
    vector< float > featureValues;
};

FeatureSearch::FeatureSearch(unsigned numFeatures, vector< float > &featureSet) {
        totalFeatures = numFeatures;
        featureValues = featureSet;
}

vector<unsigned> FeatureSearch::forwardSelection() {

}
vector<unsigned> FeatureSearch::backwardElimination() {

}

