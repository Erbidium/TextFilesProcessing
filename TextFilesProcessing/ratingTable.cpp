#include "ratingTable.h"
#include "student.h"
#include "processStudentsData.h"
#include <filesystem>
#include <iomanip>
#include <fstream>

vector<student> vectorSort(vector<student> allStudents) {
	for (int i = 0; i < allStudents.size(); i++) {
		for (int i = 0; i < allStudents.size() - 1; i++) {
			if (allStudents[i].averageScore < allStudents[i + 1].averageScore) {
				student temp = allStudents[i];
				allStudents[i] = allStudents[i + 1];
				allStudents[i + 1] = temp;
			}
		}
	}
	return allStudents;
}
void makeOutFile(vector<student> allStudents,string directory){
	ofstream fOut;
	string finalDirectory = directory + "/result.csv";
	fOut.open(finalDirectory);
	if (!fOut)
	{
		cout << "Cannot open a file \n";
	}
	else 
	{
		int k = 0;
		double minGrade = 0;
		for (int i = 0; i < allStudents.size(); i++) {
			if (k <= (allStudents.size() * 0.4)) {
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
