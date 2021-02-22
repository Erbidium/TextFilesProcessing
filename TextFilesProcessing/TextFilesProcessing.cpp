#include <iostream>
#include <vector>
#include "student.h"
#include "ratingTable.h"
#include "processStudentsData.h"

using namespace std;

int main()
{
	string directory=getNameOfDirectory();
    vector <student> allStudents=processDirectoryWithStudentsData(directory);
	
}
