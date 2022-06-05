#include <iostream>
#include <vector>
#include <cmath>
#include "../header/FeatureSearch.h"
#include "../header/NN_Classifier.h"
#include "../header/Validator.h"
#include "../header/DataExtraction.h"

using namespace std;
class DataExtraction;

float calcMean (vector<float> &featureData, unsigned feature, unsigned numFeatures, unsigned numInstances) {
    //vector<float> featureData = fD;
    float mean = 0.0;
    float sum = 0.0;
    for (unsigned j = 0; j < numInstances; j++) {       //may need to swap here idk
        sum += featureData.at(feature + j * numFeatures);
    }
    mean = sum/(numInstances);    //sketchy may cause problems

    return mean;
}

void calcStdDev(vector<float> &stdDev, vector<float> &featureData, unsigned numFeatures, unsigned numInstances) {
    unsigned feature = 0;
    //vector<float> stdDev;
   //float val[5] = {12.5, 7.0, 10.0, 7.8, 15.5};
   float sum = 0.0;
    float variance = 0.0;
    float mean = 0.0;
    float stdDeviation;
/*
    for (unsigned j = 0; j < numInstances; j++) {       //may need to swap here idk
        for(unsigned i = 0; i < numFeatures; i++) {
            sum += featureData->at((i + j) * numFeatures);
            mean = sum/(numInstances);    //sketchy may cause problems
        }
    }
    */

    //unsigned i = 0;
    for (unsigned j = 0; j < numInstances; j++) {       //may need to swap here idk
        variance = 0.0;
        mean = calcMean(featureData, j, numFeatures, numInstances);
        for(unsigned i = 0; i < numFeatures; i++) {
            variance += pow((featureData.at(i + j * numFeatures) - mean), 2);
        }
        stdDev.push_back(sqrt(variance/numInstances));

    }
/*
   for(unsigned i = 0; i < numInstances; i++) {
       variance += pow(val[i] - mean, 2);
   }
   

   variance=variance/numInstances;
   stdDeviation = sqrt(variance);
   */
  //return stdDev;
}
void normalize(vector<float> &normalizedData, vector<float> &featureData, vector<float> &stdDev, unsigned numFeatures, unsigned numInstances) {
    //vector<float> normalizedData;
    float mean = 0.0;
    //unsigned i = 0;
    for (unsigned j = 0; j < numInstances; j++) {       //may need to swap here idk
        mean = calcMean(featureData, j, numFeatures, numInstances);
        for(unsigned i = 0; i < numFeatures; i++) {
            normalizedData.push_back((featureData.at(i + j * numFeatures) - mean)/stdDev.at(i + j * numFeatures));
        }
    }
    //return normalizedData;
}

int main() {
    unsigned numFeatures;
    unsigned algoChoice;

    cout << "Welcome to Owen Dolan's Feature Selection Algorithm." << endl;
    cout << "Please enter in number of total features in dataset: " << flush;
    cin >> numFeatures;
    if (cin.fail()) {
        cout << "invalid input." << endl;
        cin.clear();
        cin.ignore();
        cout << "Please enter in number of total features in dataset: " << flush;
        cin >> numFeatures;
    }
    
    cout << "Type the number of the algorithm you would like to choose:\n\t1. Forward Selection\n\t2. Backward Elimination" << endl;
    cin >> algoChoice;
    if (cin.fail()) {
        cout << "invalid input." << endl;
        cin.clear();
        cin.ignore();
        cout << "Type the number of the algorithm you would like to choose:\n\t1. Forward Selection\n\t2. Backward Elimination" << endl;
        cin >> algoChoice;
    }

    cout << "Beginning search..." << endl;

    unsigned numInstances = 0;
    DataExtraction data(numFeatures, numInstances);
    vector<bool> classValues;
    data.extractClasses(classValues, numInstances);
    vector<float> featureValues;
    data.extractFeatures(featureValues);

    int mean = 0;
    vector<float> stdDev;
    calcStdDev(stdDev, featureValues, numFeatures, numInstances);
    vector<float> normalizedData;
    normalize(normalizedData, featureValues, stdDev, numFeatures, numInstances);

    FeatureSearch search(numFeatures, featureValues);
    vector<unsigned> featureSubset;

    if (algoChoice == 1) {
        search.forwardSelection();
    }
    else if (algoChoice == 2) {
        search.backwardElimination();
    }
    else {
        cout << "invalid choice.\nExiting..." << endl;
        return 1; 
    }

    return 0;
}