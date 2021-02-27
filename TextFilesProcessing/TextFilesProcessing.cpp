#include <iostream>
#include <vector>
#include <locale>
#include "student.h"
#include "ratingTable.h"
#include "processStudentsData.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	string directory=getNameOfDirectory();
    vector <student> allStudents=processDirectoryWithStudentsData(directory);
	vectorSort(allStudents);
}
