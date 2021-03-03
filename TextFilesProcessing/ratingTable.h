#pragma once
#include <vector>
#include "student.h"

void vectorSort(vector<student>& allStudents);
int countBudgetStudents(const vector<student>& allStudents);
void makeOutFile(vector<student> allStudents, string directory);