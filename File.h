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
	explicit File(const char* data) :
			File(std::string(data)) {}

	explicit File(std::string data);

	bool contains(const std::string& key) {
		return tokens.find(key) != tokens.end();
	}

	std::string get_token(const std::string& key) {
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
