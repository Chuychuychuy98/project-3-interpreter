//
// Created by Chandler Rowe on 10/26/21.
//

#ifndef PROJECT_3_INTERPRETER_DATABASE_H
#define PROJECT_3_INTERPRETER_DATABASE_H
#include <set>
#include <map>
#include "Relation.h"
class Database {
public:
    Database();
    void AddRelation(Relation *rel) {relations.insert(rel);}
    bool ContainsRelation(Relation *rel) {return relations.find(rel) != relations.end();}
    void RemoveRelation(Relation *rel) {relations.erase(rel);}
    Relation* GetRelation(const std::string &name) {return names.at(name);}


private:
    std::set<Relation*> relations;
    std::map<std::string, Relation*> names;
};


#endif //PROJECT_3_INTERPRETER_DATABASE_H
