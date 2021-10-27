//
// Created by Chandler Rowe on 10/26/21.
//

#ifndef PROJECT_3_INTERPRETER_RELATION_H
#define PROJECT_3_INTERPRETER_RELATION_H
#include <set>
#include <initializer_list>
#include "Tuple.h"
#include "Header.h"


class Relation {
public:
    Relation(std::string name, Header header) : name(std::move(name)), header(std::move(header)) {}
    void AddTuple(Tuple tup) {if (tup.Size() == header.Size()) tuples.insert(tup);}
    Relation Select(int i, std::string val);
    Relation Select(int i, int j);
    std::string ToString();
    Relation Project(std::initializer_list<int> indices); // list of indices
    Relation Rename(std::initializer_list<std::string> newAttr); // list of attributes

private:
    std::set<Tuple> tuples;
    Header header;
    std::string name;
};


#endif //PROJECT_3_INTERPRETER_RELATION_H
