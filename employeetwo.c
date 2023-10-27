#include <string.h>
#include "employee.h"

// second set of parenthesis is func params
static EmployeePtr searchEmployeeTable(ConstEmployeePtr ptr, int tableSize, const void *targetPtr, int (*functionPtr) (const void *, ConstEmployeePtr)) {
    ConstEmployeePtr endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if ((*functionPtr) (targetPtr, ptr) == 0) {
            return (EmployeePtr) ptr;
        }
    }
    return NULL;
}

static int compareEmployeeNumber(const void *targetPtr, ConstEmployeePtr ptr) {
    return * (long*) targetPtr != ptr -> number; // typecast then dereference
}

static int compareEmployeeName(const void *targetPtr, ConstEmployeePtr ptr) {
    return strcmp((char*) targetPtr, ptr -> name);
}

// these are wrappers, used in main
EmployeePtr searchaEmployeeByNumber(ConstEmployeePtr ptr, int size, long number) {
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

EmployeePtr searchEmploayeeByName(ConstEmployeePtr ptr, int size, char* name) {
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}