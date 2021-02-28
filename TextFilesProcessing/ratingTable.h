#pragma once
#include <iostream>
#include <vector>
#include <locale>
#include "student.h"
#include "ratingTable.h"
#include "processStudentsData.h"


using namespace std;

vector<student> vectorSort(vector<student> allStudents);
void makeOutFile(vector<student> allStudents, string directory);