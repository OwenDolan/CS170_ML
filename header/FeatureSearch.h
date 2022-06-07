#include <vector>
#include <cmath>
#include "NN_Classifier.h"
#include "Validator.h"
using namespace std;

class FeatureSearch {
public:
    FeatureSearch(vector<float> &normalizedData, vector<bool> &classValues, unsigned numF, unsigned numI);
    vector<unsigned> forwardSelection();
    vector<unsigned> backwardElimination();
    void recursiveSubsets(vector<unsigned>& A, vector<vector<unsigned> >& res, vector<unsigned>& subset, unsigned index);        //adapted from foreverrookie for optimality
    vector< vector<unsigned> > retFinalSubset(vector<unsigned>& initialSet);    //adapted from foreverrookie for optimality
private:
    unsigned numFeatures;
    unsigned numInstances;
    unsigned selectFeatures;
    NN_Classifier *classifier;
    Validator *val;

    vector<float> normailizedData;
    vector<bool> classValues;
};

FeatureSearch::FeatureSearch(vector<float> &normal, vector<bool> &classValues, unsigned numF, unsigned numI) {
        this->numFeatures = numF;
        this->numInstances = numI;
        this->normailizedData = normal;
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
        selectFeatures = finalSubsets[i].size();
        float temp = val->validate(finalSubsets[i], normailizedData, classValues, numFeatures, selectFeatures, numInstances);

        cout << "For feature subsets: " << flush;
        for (unsigned j = 0; j < finalSubsets[i].size(); j++) {
             cout << finalSubsets[i][j] << " ";
        }
        cout << flush << "accuracy was " << temp << " percent." << endl;
        

        if (temp > accuracy) {
            accuracy = temp;
            bestSubset = finalSubsets[i];
        }
    }

    cout << "Feature subset: " << flush;
    for (unsigned j = 0; j < bestSubset.size(); j++) {
        cout << bestSubset[j] << " ";
    }
    cout << flush << " had the highest accuracy of " << accuracy << " percent." << endl;


    return bestSubset;
}

void FeatureSearch::recursiveSubsets(vector<unsigned>& initialSet, vector<vector<unsigned> >& finalSubsets, vector<unsigned>& subset, unsigned index) {
    finalSubsets.push_back(subset);
    for (unsigned i = index; i < initialSet.size(); i++) {
 
        // include the A[i] in subset.
        subset.push_back(initialSet[i]);
 
        // move onto the next element.
        recursiveSubsets(initialSet, finalSubsets, subset, i + 1);
 
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

