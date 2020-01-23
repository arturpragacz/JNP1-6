//
// Created by ap on 20.01.2020.
//

#ifndef INC_6_PLAYMODE_H
#define INC_6_PLAYMODE_H
#include "Playable.h"
#include <memory>
#include <vector>

class Playmode {
public:
    virtual std::vector<std::list<std::shared_ptr<Playable>>::iterator> permutation(std::vector<std::list<std::shared_ptr<Playable>>::iterator> elements) {std::cout<<"Dupa"<<std::endl;return elements;}

};

#endif //INC_6_PLAYMODE_H
