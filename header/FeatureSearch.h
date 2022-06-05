#include <vector>
#include <cmath>
#include "NN_Classifier.h"
#include "Validator.h"
using namespace std;

class FeatureSearch {
public:
    FeatureSearch(vector<float> &normalizedData, vector<bool> &classValues, unsigned numFeatures);
    vector<unsigned> forwardSelection();
    vector<unsigned> backwardElimination();
    void recursiveSubsets(vector<unsigned>& A, vector<vector<unsigned> >& res, vector<unsigned>& subset, unsigned index);        //adapted from foreverrookie for optimality
    vector< vector<unsigned> > retFinalSubset(vector<unsigned>& initialSet);    //adapted from foreverrookie for optimality
private:
    unsigned numFeatures;
    NN_Classifier *classifier = new NN_Classifier;
    Validator *val = new Validator;

    vector<float> normailizedData;
    vector<bool> classValues;
};

FeatureSearch::FeatureSearch(vector<float> &normalizedData, vector<bool> &classValues, unsigned numFeatures) {
        this->numFeatures = numFeatures;
        this->normailizedData = normailizedData;
        this->classValues = classValues;
}

vector<unsigned> FeatureSearch::forwardSelection() {
    for (unsigned i = 0; i < pow(numFeatures, 2); i++) {

    }
}
vector<unsigned> FeatureSearch::backwardElimination() {
    vector<unsigned> initialSet;
    for (unsigned i = 1; i <= numFeatures; i++) {
        initialSet.push_back(i);
    }
    vector< vector<unsigned> > finalSubsets = retFinalSubset(initialSet);
    float accuracy = 0.0;
    vector<unsigned> bestSubset;
    for (unsigned i = 0; i < finalSubsets.size(); i ++) {
        float temp = val->validate(finalSubsets[i], classifier, normailizedData, classValues);
        if (temp > accuracy) {
            accuracy = temp;
            bestSubset = finalSubsets[i];
        }
    }

    return bestSubset;
}

void FeatureSearch::recursiveSubsets(vector<unsigned>& initialSet, vector<vector<unsigned> >& finalSubsets, vector<unsigned>& subset, unsigned index) {
    finalSubsets.push_back(subset);
    for (unsigned i = index; i < initialSet.size(); i++) {
 
        // include the A[i] in subset.
        subset.push_back(initialSet[i]);
 
        // move onto the next element.
        recursiveSubsets(initialSet, finalSubsets, subset, i++);
 
        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
 
    return;
}
 
// below function returns the subsets of vector A.
vector< vector<unsigned> > FeatureSearch::retFinalSubset(vector<unsigned>& initialSet)   {
    vector<unsigned> subset;
    vector<vector<unsigned> > finalSubsets;
 
    // keeps track of current element in vector A;
    unsigned index = 0;
    recursiveSubsets(initialSet, finalSubsets, subset, index);
 
    return finalSubsets;
}

