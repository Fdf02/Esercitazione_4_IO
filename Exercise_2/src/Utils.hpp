#pragma once
#include "iostream"

using namespace std;

bool ImportData(const string& inputFilePath,
                int*& n,
                double*& w,
                double*& r,
                int*& S);


double Rate(const size_t& n,
                        double*& w,
                        double*& r);

double FinalValue(double rate,
                  double S);


bool ExportResult(const string& outputFilePath,
                  double S,
                  const size_t& n,
                  double*& w,
                  double*& r,
                  double rate,
                  double V);
