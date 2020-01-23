//
// Created by ap on 20.01.2020.
//

#ifndef INC_6_FILE_H
#define INC_6_FILE_H
#include <unordered_map>
#include <string>

class File {

private:
    std::string type;
    std::string data;
    std::unordered_map<std::string, std::string> tokens;

public:
    File(const char* data) : File(std::string(data)) {

    }

    File(std::string data);

    bool contains(std::string key) {
        return tokens.find(key) != tokens.end();
    }

    std::string get_token(std::string key) {
        return tokens[key];
    }

    std::string get_type() {
        return type;
    }

    std::string get_data() {
        return data;
    }

    bool empty() {
        return tokens.empty();
    }
};


#endif //INC_6_FILE_H
