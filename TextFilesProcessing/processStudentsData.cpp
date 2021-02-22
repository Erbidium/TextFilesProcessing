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

vector<student> processDirectoryWithStudentsData(string directory)
{
	vector <string> files;
	for (const auto & entry : filesystem::directory_iterator(directory))
        files.push_back(entry.path().string());
	
}

