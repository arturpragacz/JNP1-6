//
// Created by ap on 20.01.2020.
//

#ifndef INC_6_TRACK_H
#define INC_6_TRACK_H
#include "Playable.h"
#include "Exceptions.h"
#include <regex>

class Track : public Playable {
private:
    std::list<std::shared_ptr<Playable>> dummy;

public:
    virtual std::list<std::shared_ptr<Playable>> &get_children() {
        return dummy;
    }

    virtual void play() {std::cout<<"EMPTY TRACK!"<<std::endl;}
};


#endif //INC_6_TRACK_H
