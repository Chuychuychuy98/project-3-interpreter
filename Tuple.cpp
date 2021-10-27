//
// Created by Chandler Rowe on 10/26/21.
//

#include "Tuple.h"

void Tuple::AddVal(const std::string &toAdd) {
    vals.push_back(toAdd);
}

bool Tuple::RemVal(int index) {
    try {
        vals.erase(vals.begin() + index);
        return true;
    }
    catch (std::out_of_range &e) {
        return false;
    }
}

