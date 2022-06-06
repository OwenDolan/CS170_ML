#include <vector>
#include "NN_Classifier.h"
#pragma once
using namespace std;

class Validator {
public:
    //Validator();
    float validate(vector<unsigned>& featureSubset, /*NN_Classifier *classi, */ vector<float>& normalizedData, vector<bool>& classValues, unsigned numF, unsigned featSize, unsigned numI); //needs to utilize NN_Classifier::test() to determine accuracy of featureSubset
private:
};

    float Validator::validate(vector<unsigned>& featureSubset,  vector<float>& normalizedData, vector<bool>& classValues, unsigned numF, unsigned featSize, unsigned numI) {

        NN_Classifier *classifier = new NN_Classifier(featSize, numI, classValues);
        vector<float> trainingData;
        vector<bool> trainingClassData;
        for (unsigned j = 0; j < featureSubset.size(); j++) {
            for (unsigned i = 0; i < normalizedData.size(); i++) {
                trainingData[j] = normalizedData.at(j + i * numF);
                trainingClassData[j] = classValues.at(j + i * numF);
            }
        }

        unsigned success = 0;

        classifier->train(trainingData, trainingClassData);

        for (unsigned i = 0; i < normalizedData.size(); i++) {
            bool testResult = classifier->test(classifier, i);
            if (testResult == trainingClassData[i]) {       //suspicious, can change classifier to return true or false based on if predicion is correct
                success++;
            }
        }

        return (float)success / (float)normalizedData.size();

    }
