#include <vector>
using namespace std;
class  NN_Classifier {
public:
    void train(const vector<float>& trainingData); // must pass class label for each training instance 
    bool test(const vector<float>& testData); //returns F for class 1 and T for class 2  || do not include class labels.
private:
    
};