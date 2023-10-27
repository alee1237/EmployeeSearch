#include <string.h>
#include "employee.h"

EmployeePtr searchEmployeeByNumber(ConstEmployeePtr ptr, int tableSize, long targetNumber) {
    const ConstEmployeePtr endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if (ptr -> number == targetNumber) {
            return (EmployeePtr) ptr;
        }
    }
    return NULL;
}

EmployeePtr searchEmployeeByName(ConstEmployeePtr ptr, int tableSize, char* targetName) {
    const ConstEmployeePtr endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if (strcmp(ptr -> name, targetName) == 0) {
            return (EmployeePtr) ptr;
        }
    }
    return NULL;
}