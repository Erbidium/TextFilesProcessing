#include "student.h"
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

void vectorSort(vector<student>& allStudents) {
	for (int i = 0; i < allStudents.size(); i++) {
		for (int i = 0; i < allStudents.size() - 1; i++) {
			if (allStudents[i].averageScore < allStudents[i + 1].averageScore) {
				student temp = allStudents[i];
				allStudents[i] = allStudents[i + 1];
				allStudents[i + 1] = temp;
			}
		}
	}
}
int countBudgetStudents(const vector<student>& allStudents) {
	int countBudget = 0;
	for (int i = 0; i < allStudents.size(); i++) {
		if (!(allStudents[i].isTuitionPaying))
			countBudget++;
	}
	return countBudget;
}
void makeOutFile(vector<student> allStudents,string directory){
	ofstream fOut;
	string finalDirectory = directory + "/rating.csv";
	fOut.open(finalDirectory);
	if (!fOut)
	{
		cout << "Cannot open a file \n";
	}	
	else 
	{
		int countFree = countBudgetStudents(allStudents);
		int k = 0;
		double minGrade = 0;
		for (int i = 0; i < allStudents.size(); i++) {
			if (k < static_cast<int>((countFree * 0.4))) {
				if (!allStudents[i].isTuitionPaying) {
					fOut << allStudents[i].lastName << "," << fixed << setprecision(3) << allStudents[i].averageScore << endl;
					k++;
					minGrade = allStudents[i].averageScore;
				}
			}
		}
		cout << "\nMinimal grade for scholarship: " << minGrade << endl;
	}
}
