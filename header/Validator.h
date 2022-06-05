#include <vector>
#include "NN_Classifier.h"
using namespace std;

class Validator {
public:
    Validator();
    float validate(const vector<unsigned>& featureSubset, NN_Classifier *classifier,  vector<float>& normalizedData, vector<bool>& classValues); //needs to utilize NN_Classifier::test() to determine accuracy of featureSubset
private:
};

    float Validator::validate(const vector<unsigned>& featureSubset, NN_Classifier *classifier,  vector<float>& normalizedData, vector<bool>& classValues){

    }
