/* CS261- Assignment 1 - Q.1*/
/* Name: Kais Saradi    
 * Date: 10/14/2019
 * Solution description: a program a structure to create a student with an id and score
 * as well as fuctions to allocate memory for ten students, genrate random id and scores, 
 * display the summary of scores, and free memory.
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     int studentNum = 10;
     struct student *students = malloc(studentNum * sizeof(struct student));
     return students;
     /*Return the pointer*/
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/
     int studentNum = 10;
     int idArray[10] = {0};
     for(int i = 0; i < studentNum; i++){
        students[i].score = rand() % 101;
        students[i].id =rand() % 10 + 1;
        for(int j = 0; j < studentNum; j++){
            if(students[i].id == idArray[j])
            {
                students[i].id = rand() % 10 + 1;
                j = -1;
            }
        }
        idArray[i] = students[i].id;
     }
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int studentNum = 10;
    for(int i = 1; i <= studentNum; i++){
        printf("\nStudent ID%d:%d\tScore%d:%d\n",i,students[i-1].id,i,students[i-1].score);
    }
    
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the 
ten students*/
     double studentNum = 10;
     int min = 100;
     int max = 0;
     double total = 0;
     for(int i = 1; i < studentNum; i++){
         if(students[i].score <= min){
             min = students[i].score;
         }
         if(students[i].score >= max){
             max = students[i].score;
         }
         total += students[i].score;
     }
     double average = total / studentNum;

     printf("\nMinimum Score:%d\tMaximum Score:%d\tAverage Score:%g\n",min,max,average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if(stud != NULL){
        free(stud);
     }
}

int main(){
    struct student* stud = NULL;
    srand(time(0));
    /*Call allocate*/
    stud = allocate();
    /*Call generate*/
    generate(stud);
    /*Call output*/
    output(stud);
    /*Call summary*/
    summary(stud);
    /*Call deallocate*/
    deallocate(stud);

    return 0;
}

