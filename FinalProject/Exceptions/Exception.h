//
// Created by Usuario on 9/11/2022.
//

#ifndef FINALPROJECT_EXCEPTION_H
#define FINALPROJECT_EXCEPTION_H

#include <exception>

using namespace std;

class NoTextException: public exception {
public:
    const char * what() const noexcept override;

};


#endif //FINALPROJECT_EXCEPTION_H
