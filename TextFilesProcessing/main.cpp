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
	if(argc>1)
	{
		minimalGrade=atoi(argv[1]);
	}
	string directory=getNameOfDirectory();
	if(filesystem::exists(directory))
	{
		if(!filesystem::is_empty(directory))
		{
			vector <student> allStudents=processDirectoryWithStudentsData(directory);
			vectorSort(allStudents);
			makeOutFile(allStudents, directory, minimalGrade);
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
