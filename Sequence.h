#ifndef H_SEQUENCE_MODE
#define H_SEQUENCE_MODE

class SeqMode {
public:
    SeqMode() {}

    virtual std::vector<std::list<std::shared_ptr<Playable>>::iterator> permutation(std::vector<std::list<std::shared_ptr<Playable>>::iterator> elements) {std::cout<<"Dupa"<<std::endl;return elements;}

};

std::shared_ptr<Playmode> createSequenceMode() {
    return std::dynamic_pointer_cast<Playmode>(std::make_shared<SeqMode>(SeqMode()));
}

#endif // H_SEQUENCE_MODE
