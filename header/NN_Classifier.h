#include <vector>
#include <cmath>
#include <numeric>
#include <queue>
#pragma once
using namespace std;
class  NN_Classifier {
public:
    NN_Classifier(unsigned numF, unsigned numI);
    void train(const vector<float>& trainingData, const vector<bool> &classes); // must pass class label for each training instance 
    bool test(NN_Classifier, unsigned testInstance); //returns F for class 1 and T for class 2  || do not include class labels.
private:
    vector<float> trainedData;
    vector<bool> classValues;
    unsigned numFeatures;
    unsigned numInstances;
    
};
    NN_Classifier::NN_Classifier(unsigned numF, unsigned numI) {
        this->numFeatures = numF;
        this->numInstances = numI;
    }
    void NN_Classifier::train(const vector<float>& tData, const vector<bool> &classes) {
        this->trainedData = tData;
        this->classValues = classes;
    } 
    bool NN_Classifier::test(NN_Classifier classifier, unsigned testInstance) {
        double euclidDist = 0.0;
        double minDist;
        //priority_queue <double, vector<double>, greater<double> > minSum;
        vector<double> minSum;

        double closestNeighbor = 1000000.0;
        unsigned closestNeighborIndex = 0;
        deque<double> temp;

        //vector< vector
        for (unsigned i = 0; i < classifier.numFeatures; i++) {
            for (unsigned j = 0; j < classifier.numInstances; j++) {
                if (j != testInstance) {
                    temp.push_back(sqrt(abs(classifier.trainedData.at(i + testInstance * numFeatures) - (classifier.trainedData.at(i + j * numFeatures)))));
                }
            }
        }

        for (unsigned j = 0; j < classifier.numInstances; j++) {     //can optimize finding minDist with stack or priority min queue
            euclidDist = 0.0;
            for (unsigned i = 0; i < classifier.numFeatures; i++) {
                euclidDist += temp.at(j + i * classifier.numFeatures); 
            }
            minSum.push_back(euclidDist);
        }

        for (unsigned i = 0; i < classifier.numInstances; i++) {     //can optimize finding minDist with stack or priority min queue
            if (classifier.numFeatures != 0) { //literally fucking unexplainable why this check is here
                if (minSum[i] < closestNeighbor) {
                    closestNeighbor = minSum[i];
                    closestNeighborIndex = i;
                }
            }
        }

        return classValues.at(closestNeighborIndex);
  
    } 