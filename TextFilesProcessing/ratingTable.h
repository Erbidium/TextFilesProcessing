#pragma once
#include <iostream>
#include <vector>
#include <locale>
#include "student.h"
#include "ratingTable.h"
#include "processStudentsData.h"


using namespace std;

void vectorSort(vector<student>& allStudents);
void makeOutFile(vector<student> allStudents, string directory);