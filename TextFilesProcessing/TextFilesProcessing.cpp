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
	allStudents = vectorSort(allStudents);
	for (int i = 0; i < allStudents.size(); i++) {
		cout << allStudents[i].averageScore << endl;
	}
	makeOutFile(allStudents, directory);
}
