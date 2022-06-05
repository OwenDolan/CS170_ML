#include <vector>
using namespace std;

class Validator {
public:
    Validator();
    float validate(const vector<unsigned>& featureSubset, const vector<float>& data); //needs to utilize NN_Classifier::test() to determine accuracy of featureSubset
private:
};