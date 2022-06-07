#include <vector>
#include "NN_Classifier.h"
#pragma once
using namespace std;

class Validator {
public:
    //Validator();
    float validate(vector<unsigned>& featureSubset, /*NN_Classifier *classi, */ vector<float>& normalizedData, vector<bool>& classValues, unsigned numFeatures, unsigned selectFeatures, unsigned numInstances); //needs to utilize NN_Classifier::test() to determine accuracy of featureSubset
private:
};

    float Validator::validate(vector<unsigned>& featureSubset,  vector<float>& normalizedData, vector<bool>& classValues, unsigned numFeatures, unsigned selectFeatures, unsigned numInstances) {

        NN_Classifier classifier(selectFeatures, numInstances);
        
        vector<float> trainingData;
        for (unsigned i = 0; i < selectFeatures; i++) {
            for (unsigned j = 0; j < numInstances; j++) {
                trainingData.push_back(normalizedData.at(i + j * selectFeatures));
            }
            //trainingClassData.push_back(classValues.at(i));
        }

        unsigned success = 0;
        classifier.train(trainingData, classValues);

        for (unsigned i = 0; i < numInstances; i++) {
            bool testResult = classifier.test(classifier, i);
            if (testResult == classValues[i]) {       //suspicious, can change classifier to return true or false based on if predicion is correct
                success++;
            }
        }
        float accuracy = (float)success / (float)numInstances;
        return accuracy;

    }
