//
// Created by Chandler Rowe on 10/26/21.
//

#include "Relation.h"

std::string Relation::ToString() {
    std::string toReturn;
    for (Tuple tup : tuples) {
        for (int i = 0; i < header->Size(); ++i) {
            toReturn += header->GetVal(i) + "=" + tup.GetVal(i);
            if (i < header->Size() - 1) {
                toReturn += ", ";
            }
        }
        toReturn += "\n";
    }
    return toReturn;
}

Relation* Relation::Select(int i, std::string val) {
    Relation* newRel= new Relation(name, header);
    for (Tuple tup : tuples) {
        if (tup.GetVal(i) == val) {
            newRel->AddTuple(tup);
        }
    }
    return newRel;
}
Relation* Relation::Select(int i, int j) {
    Relation* newRel = new Relation(name, header);
    for (Tuple tup : tuples) {
        if (tup.GetVal(i) == tup.GetVal(j)) {
            newRel.AddTuple(tup);
        }
    }
    return newRel;
}

Relation* Relation::Project(std::initializer_list<int> indices) {
    for (Tuple tup : tuples) {
        Tuple newTup;
        for (int i : indices) {
            newTup.AddVal(tup.GetVal(i));
        }
    }
    std::vector<std::string> vals;
    for (int i : indices) {
        vals.push_back(header->GetVal(i));
    }
    Header* newHead = new Header(vals);
    return new Relation(name, newHead);
}

Relation* Relation::Rename(std::initializer_list<std::string> newAttr) {

    Header *newHeader = new Header(newAttr);
    return new Relation(name, newHeader);
}
