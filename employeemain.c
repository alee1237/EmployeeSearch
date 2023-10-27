#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main() {
    EmployeePtr searchEmployeeByNumber(const Employee table[], int tableSize, long numberToFind);
    EmployeePtr searchEmployeeByName(const Employee table[], int tableSize, char* nameToFind);
    EmployeePtr searchEmployeeByPhone(const Employee table[], int tableSize, char* phoneToFind);
    EmployeePtr searchEmployeeBySalary(const Employee table[], int tableSize, double salaryToFind);

    extern Employee employeeTable[];
    extern const int employeeTableEntries;

    EmployeePtr matchPtr = searchEmployeeByNumber(employeeTable, employeeTableEntries, 1045);
    if (matchPtr != NULL) {
        printf("Employee ID 1045 is in record %d\n", matchPtr - employeeTable);
    } else {
        printf("Employee ID is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByName(employeeTable, employeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL) {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - employeeTable);
    } else {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }
}