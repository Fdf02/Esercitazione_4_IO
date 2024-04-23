#include "iostream"
#include <string>
#include "fstream"
#include "sstream"
#include "Utils.hpp"

using namespace std;

int main()
{
    const string& inputFilePath = "./data.csv";
    int* n;
    double* w = nullptr;
    double* r = nullptr;
    int* S;

    if (!ImportData(inputFilePath, n, w, r, S))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else{
        cout<< "Import successful" << endl;

    }
    int a = n[0];
    double s = S[0];

    double rate = Rate(a, w, r);

    double V = FinalValue(rate,s);

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, s, a, w, r, rate, V))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}

