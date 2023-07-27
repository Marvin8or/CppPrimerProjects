#pragma once
#include <vector>
#include <iostream>
#include <memory>
using namespace std;

vector<int>* getDynamicallyAllocatedVector(int size);
void fillVectorWithValues(vector<int>* vptr);
void printVectorValues(vector<int>* vptr);

shared_ptr<vector<int>> getSafeDynamicallyAllocatedVector(int size);
void fillSafeVectorWithValues(shared_ptr<vector<int>> vptr);
void printSafeVectorValues(shared_ptr<vector<int>> vptr);