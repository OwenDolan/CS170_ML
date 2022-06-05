#include <vector>
#include <fstream>
#include <exception>
using namespace std;
class DataExtraction {
public:
    DataExtraction(unsigned numF, unsigned &numI); //pass file data over to constructor
    //~DataExtraction();
    vector<float>* extractFeatures();
    vector<bool>* extractClasses(unsigned &numInstances); 

private:
unsigned numFeatures;
unsigned numInstances;
};

    DataExtraction::DataExtraction(unsigned numF, unsigned &numI) {
        numFeatures = numF;
        //numInstances = numI;    //  may not work need to check
    }


    vector<float>* DataExtraction::extractFeatures() {
        vector<float> *features = new vector<float>;

        ifstream myData;     //fix to choose which data set to use (ask user in main loop)       may also define as private member variable that is initialized in constructor
        myData.open("../data/small-test-dataset.txt");
        vector<float> lines;
        float line;
        if (myData.is_open()) {
            while (!myData.eof()) {
                myData >> line;
                //myData.ignore( std::numeric_limits<std::streamsize>::max(), ' ' );
                //myData.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
                if (cin.fail()) {
                    cout << "cin failed" << endl;
                }
                lines.push_back(line);
            }
        }
        else {
            cout << "error opening file." << endl;
            throw out_of_range("error opening file");
        }

        for (int i = 0; i < lines.size(); i++) {
            if (lines.at(i) != 1 && lines.at(i) != 2) {
                features->push_back(lines[i]);
            }
        }
        myData.close();
        return features;

    }

    vector<bool>* DataExtraction::extractClasses(unsigned &numInstances) {
        ifstream myData;     //fix to choose which data set to use (ask user in main loop)       may also define as private member variable that is initialized in constructor
        myData.open("../data/small-test-dataset.txt");
        vector<double> lines;
        double line;
        if (myData.is_open()) {
            while (!myData.eof()) {
                myData >> line;
                //myData.ignore( std::numeric_limits<std::streamsize>::max(), ' ' );
                myData.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
                if (cin.fail()) {
                    cout << "cin failed" << endl;
                }
                lines.push_back(line);
            }
        }
        else {
            cout << "error opening file." << endl;
            throw out_of_range("error opening file");
        }
        numInstances = lines.size();
        vector<bool> *classes = new vector<bool>;

        for (unsigned i = 0; i < lines.size(); i++) {
            if (int(lines.at(i)) == 1 ) {
                classes->push_back(false);
            }
            else if (int(lines.at(i)) == 2 ) {
                classes->push_back(true);
            }
            else {
                cout << "invalid logic." << endl;
            }
        }
        myData.close();
        return classes;
    }
/*
        vector<bool>* DataExtraction::extractClasses() {
        ifstream myData;     //fix to choose which data set to use (ask user in main loop)       may also define as private member variable that is initialized in constructor
        myData.open("../data/small-test-dataset.txt");
        vector<string> lines;
        string line;
        if (myData.is_open()) {
            while (getline(myData, line)) {
            myData.ignore( std::numeric_limits<std::streamsize>::max(), ' ' );
            //myData.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
            lines.push_back(line);
            }
        }
        else {
            cout << "error opening file." << endl;
            throw out_of_range("error opening file");
        }
        vector<bool> *classes = new vector<bool>;

        for (unsigned i = 0; i < lines.size(); i++) {
            if (lines.at(i).at(3) == 2 ) {
                classes->push_back(false);
            }
            else if (lines.at(i).at(1) == 2 ) {
                classes->push_back(true);
            }
            else {
                cout << "invalid logic." << endl;
            }
        }
        return classes;
    }
    */