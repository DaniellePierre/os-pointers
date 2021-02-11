// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    student.f_name = new char[128];
    student.l_name = new char[128];

    // Sequence of user input -> store in fields of `student`   
    std::cout << "Please enter the student's id number: ";
    std::cin >> student.id;

    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;
    
    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;
    
    std::cout << "Please enter how many assignments were graded: ";
    std::cin >> student.n_assignments;
    std::cout << std::endl;
    
    
    for(int i = 0; i<student.n_assignments; i++){
        std::cout << "Please enter grade for assignment " << (i) << ": ";
        std::cin >> student.grades[i];
    }

    std::cout << std::endl;
    
    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, &average);

    // Output `average`
    std::cout << "Student: " << student.f_name <<" "<< student.l_name << " [" << student.id <<"]" << std::endl;
    std::cout << "  Average grade: ";
    printf("%0.1f", average);
    std::cout << std::endl;

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    double sum = 0;
    double final = 0;
    
    Student student = *((Student*)object);

    for(int i = 0; i < student.n_assignments; i++){
        sum += student.grades[i];
    }

    final = sum/student.n_assignments;

    *avg = final;
        
}
