#ifndef INC_6_TRACKFACTORY_H
#define INC_6_TRACKFACTORY_H

#include <memory>
#include <map>
#include "File.h"
#include "Track.h"

class TrackFactory {
public:
	using CreateMethod = std::shared_ptr<Track>(*)(const File& file);

private:
	static std::map<std::string, CreateMethod>& createMethods() {
		static std::map<std::string, CreateMethod> createMethods;
		return createMethods;
	}

public:
	static std::shared_ptr<Track> create(const File& file) {
		if (auto it = createMethods().find(file.get_type()); it != createMethods().end())
			return it->second(file);
		else
			return nullptr;
	}

	static bool registerClass(const std::string& type, CreateMethod createFunc) {
		if (auto it = createMethods().find(type); it == createMethods().end()) {
			createMethods()[type] = createFunc;
			return true;
		}
		else
			return false;
	}
};


#endif //INC_6_TRACKFACTORY_H
