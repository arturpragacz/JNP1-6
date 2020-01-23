#ifndef INC_6_PLAYABLE_H
#define INC_6_PLAYABLE_H
#include <list>
#include <memory>
#include <iostream>

class Playable {
public:
    virtual std::list<std::shared_ptr<Playable>> &get_children() = 0;

public:
    virtual void play() {std::cout<<"EMPTY!"<<std::endl;}
};


#endif //INC_6_PLAYABLE_H
