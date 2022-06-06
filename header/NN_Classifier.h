#include <vector>
#include <cmath>
#include <numeric>
#pragma once
using namespace std;
class  NN_Classifier {
public:
    NN_Classifier(unsigned numF, unsigned numI, vector<bool> &classVal);
    void train(const vector<float>& trainingData, const vector<bool> &classes); // must pass class label for each training instance 
    bool test(NN_Classifier *, unsigned testInstance); //returns F for class 1 and T for class 2  || do not include class labels.
    vector<bool> classes;
private:
    vector<float> trainedData;
    unsigned numFeatures;
    unsigned numInstances;
};
    NN_Classifier::NN_Classifier(unsigned numF, unsigned numI, vector<bool> &classVal) {
        this->numFeatures = numF;
        this->numInstances = numI;
        this->classes = classVal;
    }
    void NN_Classifier::train(const vector<float>& trainingData, const vector<bool> &c) {
        this->trainedData = trainingData;
        this->classes = c;
    } 
    bool NN_Classifier::test(NN_Classifier *classifier, unsigned testInstance) {
        double euclidDist = 0.0;
        vector<double> minDist;
        vector<double> minSum;
        double closestNeighbor = 1000000.0;
        unsigned closestNeighborIndex = 0;
        vector< vector<double> > temp;

        //vector< vector
        for (unsigned j = 0; j < classifier->numFeatures; j++) {
            for (unsigned i = 0; i < classifier->numInstances; i++) {
                if (i != testInstance) {
                    temp[i].push_back(sqrt(classifier->trainedData.at(j + testInstance * numFeatures) - (classifier->trainedData.at(j + i * numFeatures))));
                }
            }
            temp.push_back(vector<double>());
        }

        for (unsigned j = 0; j < classifier->numFeatures; j++) {
            for (unsigned i = 0; i < classifier->numInstances; i++) {
                minDist.push_back(temp[i][j]);
            }
        }

        for (unsigned i = 0; i < classifier->numInstances; i++) {
            minSum.push_back(accumulate(minDist.begin(), minDist.begin() + classifier->numFeatures, 0));

        }
        for (unsigned i = 0; i < classifier->numInstances; i++) {

            if (minSum[i] < closestNeighbor) {
                closestNeighbor = minSum[i];
                closestNeighborIndex = i;
            }
        }
        return classes.at(closestNeighborIndex);
  
    } 