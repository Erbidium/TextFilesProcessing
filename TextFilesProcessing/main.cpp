#include <filesystem>
#include <iostream>
#include <vector>
#include "student.h"
#include "ratingTable.h"
#include "processStudentsData.h"

using namespace std;


int main(int argc, char * argv[])
{
	int minimalGrade=60;
	double percentOfStudents = 40;
	if(argc>1)
	{
		minimalGrade=atoi(argv[1]);
	}
	if (argc > 2)
	{
		percentOfStudents = atof(argv[2]);
	}
	string directory=getNameOfDirectory();
	if(filesystem::exists(directory))
	{
		if(!filesystem::is_empty(directory))
		{
			vector <student> allStudents=processDirectoryWithStudentsData(directory);
			vectorSort(allStudents);
			makeOutFile(allStudents, directory, minimalGrade,percentOfStudents);
		}
		else
		{
			cout<<"Empty directory!\n";
		}
	}
	else
	{
		cout<<"Entered the wrong path!\n";
	}
	return 0;
}
