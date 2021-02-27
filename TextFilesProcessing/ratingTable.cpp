#include "ratingTable.h"
#include "student.h"
#include "processStudentsData.h"

void vectorSort(vector<student> allStudents) {
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
