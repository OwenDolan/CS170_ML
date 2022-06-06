#include <vector>
#include <cmath>
#include <numeric>
#include <exception>
#pragma once
using namespace std;
class  NN_Classifier {
public:
    NN_Classifier(unsigned numF, unsigned numI, vector<bool> &classVal);
    void train(const vector<float>& trainingData, const vector<bool> &classes); // must pass class label for each training instance 
    bool test(NN_Classifier &, unsigned testInstance, unsigned featSize); //returns F for class 1 and T for class 2  || do not include class labels.
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
    bool NN_Classifier::test(NN_Classifier &classifier, unsigned testInstance, unsigned featSize) {
        double euclidDist = 0.0;
        vector<double> minDist;
        vector<double> minSum;
        double closestNeighbor = 1000000.0;
        unsigned closestNeighborIndex = 0;
        vector< vector<double> > temp;

        //vector< vector
        for (unsigned i = 0; i < classifier.numFeatures; i++) {
            temp.push_back(vector<double>());
            for (unsigned j = 0; j < classifier.numInstances; j++) {
                if (j != testInstance) {
                    try {

        
                    temp[i].push_back(sqrt(classifier.trainedData.at(i + testInstance * featSize) - (classifier.trainedData.at(i + j * featSize))));
                    }
                    catch (const std::out_of_range& e) {
                        cout << "out of range NN_Class line 42" << endl;
                    }
                }
            }
        }

        for (unsigned i = 0; i < classifier.numFeatures; i++) {
            for (unsigned j = 0; j < classifier.numInstances; j++) {
                try {
                minDist.push_back(temp[i][j]);
                }
                catch (const std::out_of_range& e) {
                cout << "out of range NN_Class line 55" << endl;
                }
            }
        }

        for (unsigned j = 0; j < classifier.numInstances; j++) {
            minSum.push_back(accumulate(minDist.begin(), minDist.begin() + classifier.numFeatures, 0));

        }
        for (unsigned j = 0; j < classifier.numInstances; j++) {

            try {
            if (minSum[j] < closestNeighbor) {

                closestNeighbor = minSum[j];
                closestNeighborIndex = j;
            }
            }
            catch (const std::out_of_range& e) {
                cout << "out of range NN_Class line 70" << endl;
                }
        }
        return classes.at(closestNeighborIndex);
  
    } 