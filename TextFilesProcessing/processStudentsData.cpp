#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include "student.h"

using namespace std;

string getNameOfDirectory()
{
	cout<<"Please, enter the name of directory: ";
	string directory;
	cin>>directory;
	return directory;
}

vector <string> getNamesOfCSVFiles(string directory)
{
	vector <string> files;
	for (const auto & entry : filesystem::directory_iterator(directory))
	{
		if(entry.path().extension()==".csv")
		{
			files.push_back(entry.path().string());
		}
	}
	return files;
}

student readOneStudentData(ifstream& fIn)
{
	student studentData;
	getline(fIn, studentData.lastName, ',');
	unsigned int sumOfGrades=0;
	for(int j=0;j<5;j++)
	{
		int grade;
		fIn>>grade;
		sumOfGrades+=grade;
		fIn.ignore();
	}
	studentData.averageScore = sumOfGrades / 5.0;
	string tuitionPaying;
	getline(fIn, tuitionPaying, '\n');
	studentData.isTuitionPaying=(tuitionPaying=="FALSE")?false:true;
	return studentData;
}

vector<student> processDirectoryWithStudentsData(string directory)
{
	vector <string> files=getNamesOfCSVFiles(directory);
	vector <student> allStudents;
	for(int i=0;i<files.size();i++)
	{
		int numberOfStudent;
		ifstream fIn(files[i]);
		if (!fIn.is_open())
		{
		cout << "Cannot open a file "<<endl;
		}
		else
		{
			fIn>>numberOfStudent;
			fIn.ignore();
			for(int k=0;k<numberOfStudent;k++)
			{
				student studentData=readOneStudentData(fIn);
				allStudents.push_back(studentData);
			}
			fIn.close();
		}
	}
	return allStudents;
}

