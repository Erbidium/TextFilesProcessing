#pragma once
#include <vector>
#include "student.h"

using namespace std;

void vectorSort(vector<student>& allStudents);
int countBudgetStudents(const vector<student>& allStudents);
void makeOutFile(vector<student> allStudents, string directory, int minimalGrade);