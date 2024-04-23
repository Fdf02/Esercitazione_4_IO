#include "Utils.hpp"
#include <string>
#include "iostream"
#include "fstream"
#include "sstream"

using namespace std;

bool ImportData(const string& inputFilePath,
                   int*& n,
                   double*& w,
                   double*& r,
                   int*& S)
{
    // Open File
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // Get the values from the file
    string line;
    int c = 0;
    n = new int;
    S = new int;
    w = new double[8];
    r = new double[8];
    while (!file.eof())
    {
        getline(file, line);
        string sum;
        string num;
        string w1;
        string r1;
        if (line[0] == 'S'){
            for (unsigned int i = 2; i < line.size(); i++){
                sum += line[i];
            }
            S[0] = stoi(sum);
        }
        if (line[0] == 'n'){
            for (unsigned int i = 2; i < line.size(); i++){
                num += line[i];
            }
            n[0] = stoi(num);
        }
        if (line[0] == '0'){
            for (unsigned int i = 0; i < 4; i++)
                if(line[i]!=';'){
                    w1 += line[i];
                }
            w[c] = stod(w1);
            for (unsigned int i = 4; i < line.size();i++){
                if (line[i] != ';'){
                    r1 += line[i];
                }
            }
            r[c] = stod(r1);
            c++;
        }

    }

    file.close();
    return true;
}

double Rate(const size_t& n,
            double*& w,
            double*& r)
{
    double rate = 0;
    for (unsigned int i = 0; i < n; i++)
        rate += w[i] * r[i];
    return rate;
}

double FinalValue(double rate,
                  double S)
{
    double V = (1.0 + rate)*S;
    return V;
}

bool ExportResult(const string& outputFilePath,
                  double S,
                  const size_t& n,
                  double*& w,
                  double*& r,
                  double rate,
                  double V)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << fixed << showpoint << setprecision(2)<<  "S = "<< S << ", n = " << n << endl;
    file << "w = [ ";
    for (unsigned int i = 0; i < n; i++)
        file<< (i != 0 ? " " : "")<< w[i];
    file<< " ]" << endl;

    file<< "r = [ ";
    for (unsigned int i = 0; i < n; i++)
        file<< (i != 0 ? " " : "")<< r[i];
    file<< " ]" << endl;

    file << fixed << showpoint << setprecision(4) << "Rate of return of the portfolio: " << rate << endl;
    file << fixed << showpoint << setprecision(2) << "V: " << V << endl;

    // Close File
    file.close();

    return true;
}


