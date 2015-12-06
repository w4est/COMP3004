#ifndef PPID_H
#define PPID_H
#include "ppid.h"
#include <math.h>
#include <stdlib.h>
#include <vector>
#include "ProfileEntity.h"
#include "project.h"
namespace ppid {


    static int* MinOfTwo(int **studentList, int numStudents);//returns the index of the most compatible pair
    static int GetMinStudent(int** studentList, int *currentGroup, int studentsInGroup, int numStudents);//returns the most compatible student for the current group


    static std::vector<std::vector<ProfileEntity>> RunAlgorithmStudents(std::vector<ProfileEntity> students, int numStudents, int groupSize);//run the student algorithm
    static std::vector<ProfileEntity> RunAlgorithmProjects(std::vector<ProfileEntity> students, Project currentProject, int groupSize);//run the Project algorithm
    static std::vector<ProfileEntity> RunAlgorithmGrades(std::vector<ProfileEntity> students, Project currentProject,int groupSize);//run the grades algorithm
}

#endif // PPID_H
