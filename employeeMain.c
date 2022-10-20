#include <string.h> 

#include <stdlib.h> 

#include "employee.h" 

int main(void){ 

    //defined in employeeSearchOne.c 

    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 

    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 

    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind); //added function call for Salary

    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind); //added function call for Phone

 

    //defined in employeeTable.c 

    extern Employee EmployeeTable[];     

    extern const int EmployeeTableEntries;      

 

    PtrToEmployee matchPtr;  //Declaration 

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

 

    //Example not found 

    if (matchPtr != NULL) 

        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 

    else 

        printf("Employee ID is NOT found in the record\n"); 

 

    //Example found 

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 

    if (matchPtr != NULL) 

        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 

    else 

        printf("Employee Tony Bobcat is NOT found in the record\n"); 

     
     
     matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78); 

    
    if (matchPtr != NULL) 

        printf("Employee salary of 8.78 is in the record %d\n", matchPtr - EmployeeTable); 

    else 

        printf("Employee salary of 8.78 is NOT found in the record\n");   

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134"); 

    
    if (matchPtr != NULL) 

        printf("Employee number of 909-555-2134 is in the record %d\n", matchPtr - EmployeeTable); 

    else 

        printf("Employee number of 909-555-2134 is NOT found in the record\n");         

     

    return EXIT_SUCCESS; 

} 