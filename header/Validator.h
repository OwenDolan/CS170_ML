#include <vector>
#include <exception>
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

        NN_Classifier classifier(featSize, numI, classValues);
        vector<float> trainingData;
        vector<bool> trainingClassData;
        unsigned featureCounter = 0;
        for (unsigned i = 0; i < featSize; i++) {
            for (unsigned j = 0; j < numI; j++) {
                try{
                trainingData.push_back(normalizedData.at(featureSubset[i] + j * featSize));
                }
                catch (const std::out_of_range& e) {
                    cout << "out of range line 23" << endl;
                }
                try {
                if (j <101) {
                    trainingClassData.push_back(classValues.at(j));

                }
                }
                catch (const std::out_of_range& e) {
                    cout << "out of range line 30" << endl;
                }
            }
            featureCounter++;
        }

        unsigned success = 0;
        unsigned failures = 0;

        classifier.train(trainingData, trainingClassData);

        for (unsigned j = 0; j < numI; j++) {
            bool testResult = classifier.test(classifier, j, featSize);
            try{
            if (testResult == trainingClassData[j]) {       //suspicious, can change classifier to return true or false based on if predicion is correct
                success++;
            }
            
            else {
                failures++;
            }
            }
            catch (const std::out_of_range& e) {
                cout << "out of range Validator_Class line 49" << endl;
                }

        }
        float accuracy = (float)success / ((float)failures + (float)success);
        return accuracy;

    }
