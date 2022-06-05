#include <vector>
#include <cmath>
using namespace std;
class  NN_Classifier {
public:
    void train(const vector<float>& trainingData, const vector<bool> &classes); // must pass class label for each training instance 
    bool test(const vector<float>& testData); //returns F for class 1 and T for class 2  || do not include class labels.
private:
    vector<float> trainedData;
    vector<bool> classes;
};

    void NN_Classifier::train(const vector<float>& trainingData, const vector<bool> &c) {
        this->trainedData = trainingData;
        this->classes = c;
    } 
    bool NN_Classifier::test(NN_Classifier *classifier) {
        float euclidDist = sqrt ()
    } 