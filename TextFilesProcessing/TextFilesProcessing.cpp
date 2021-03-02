#include <filesystem>
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
	if(filesystem::exists(directory))
	{
		if(!filesystem::is_empty(directory))
		{
			vector <student> allStudents=processDirectoryWithStudentsData(directory);
			allStudents = vectorSort(allStudents);
			makeOutFile(allStudents, directory);
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
