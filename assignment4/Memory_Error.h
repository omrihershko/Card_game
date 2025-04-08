//
// Created by omri_hershkovich on 3/9/24.
//

#ifndef EX_4_OMRI_MEMORY_ERROR_H
#define EX_4_OMRI_MEMORY_ERROR_H
#include <exception>
using namespace std;

/**
 * @class Memory_Error
 * @brief Represents a custom exception class for memory-related errors.
 */
class Memory_Error:public exception{
public:
    /**
    * @brief Overrides the what() function of the base exception class to provide custom error message.
    * @return A C-style string describing the memory problem.
    */
    virtual const char* what() const  throw(){
        return "Memory Problem\n";
    }
};







#endif //EX_4_OMRI_MEMORY_ERROR_H
;