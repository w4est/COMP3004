#include "ppid.h"
#include "ProfileEntity.h"
#include <math.h>
#include <stdlib.h>
#include <vector>
#include "project.h"
#include <tuple>
namespace ppid {
static int* MinOfTwo(int **studentList, int numStudents)
{//returns the index of the most compatible pair
    int minValue = 999;
    int * pair = new int[2];
    pair[0]=-1;
    pair[1]=-1;
    for(int i=0; i<numStudents; i++){
        for(int j = i+1; j<numStudents; j++){
            if(studentList[i][j]==1000||studentList[j][i]==1000){}
            else if(minValue>studentList[i][j]){
                pair[0]=i;
                pair[1]=j;
                minValue = studentList[i][j];
            }
        }
    }
    return pair;
}
static int GetMinStudent(int** studentList, int *currentGroup,  int studentsInGroup, int numStudents)
{//returns the most compatible student for the current group
    int minValue = 999;
    int res = -1;
    for(int i = 0; i<numStudents; i++){
        int NV= 0;
        for(int j = 0; j< studentsInGroup; j++){
            NV+=studentList[currentGroup[j]][i];

        }
        if(minValue>NV){
            res = i;
            minValue = NV;
        }
    }
    return res;

}
static std::vector<std::vector<ProfileEntity>> RunAlgorithmStudents(std::vector<ProfileEntity> students, int numStudents, int groupSize)//run the student algorithm
{
                                               //generate qualifications table
                                               int** gVals = new int*[numStudents];
                                               int** gVals2 = new int*[numStudents];
                                               for(int i=0; i <numStudents; i++){
    gVals[i]=new int[numStudents];//list of student values
    gVals2[i] = new int[numStudents];//new values
}


int numberOfGroups = (int)ceil(numStudents/groupSize);
for(int i=0; i<numStudents; i++)
{
    for (int j=i; j<numStudents; j++){
        int sumQual =0;
        for(int k =0; k<students.at(i).getPersonalQual().size(); k++){
            sumQual += abs(get<1>(students.at(i).getPersonalQual().at(k))+get<1>(students.at(i).getPersonalQual().at(k)));
        }
        gVals[i][j]=sumQual;
        gVals[j][i] =sumQual;
        gVals2[i][j] = 1000;//dummy value
        gVals2[j][i] = 1000;
    }
}

int** pList = new int*[numberOfGroups];
for(int i=0;i<numberOfGroups; i++){
    pList[i]= new int[groupSize];
}

for(int i = 0; i<numberOfGroups; i++){
    int * cG = new int[groupSize];
    int * sG =  ppid::MinOfTwo(gVals, numStudents);
    cG[0] = sG[0];
    cG[1]=sG[1];
    for(int j=0; j<numStudents;j++){
        //set g2Vals
        gVals2[sG[0]][j] = gVals[sG[0]][j];
        gVals2[j][sG[0]] = gVals[j][sG[0]];

        gVals2[sG[1]][j] = gVals[sG[1]][j];
        gVals2[j][sG[1]] = gVals[j][sG[1]];
        //clear the gVal values
        gVals[sG[0]][j] = 1000;
        gVals[j][sG[0]] = 1000;

        gVals[sG[1]][j] = 1000;
        gVals[j][sG[1]] = 1000;
    }
    pList[i]=cG;
}
for(int j = 0; j<groupSize-2; j++){
    for(int i=0; i<numberOfGroups; i++){
        int a = ppid::GetMinStudent(gVals2, pList[i], j+2, numStudents);
        if(a ==-1){
            i=numberOfGroups;
            j=groupSize;
        }else{
            pList[i][j]=a;
            for(int k=0; k<numStudents; k++){
                gVals2[a][k] = 1000;
                gVals2[k][a] = 1000;
            }
        }
    }
}

//std::vector<tuple<int,std::vector<ProfileEntity>>> groups(numberOfGroups);
std::vector< std::vector<ProfileEntity> > ret;//new std::vector< std::vector<ProfileEntity> >;//(numberOfGroups, std::vector<ProfileEntity> (groupSize))
for(int i =0; i<numberOfGroups; i++){



                                            //(0, std::vector<ProfileEntity> (groupSize));
std::vector<ProfileEntity> res (groupSize);

    for(int j = 0; j<groupSize; j++){
        res.push_back(students[pList[i][j]]);
    }
    ret.push_back(res);
    //get<0>ret = i;
    //get<1>(ret)=res;
    //groups[i] = ret //new tuple<i,res>;
}

return ret;
}
static std::vector<ProfileEntity>RunAlgorithmProjects(std::vector<ProfileEntity> students, Project currentProject, int groupSize);//run the Project algorithm
static std::vector<ProfileEntity>RunAlgorithmGrades(std::vector<ProfileEntity> students, Project currentProject,int groupSize);//run the grades algorithm
}
