#include "Playlist.h"
#include "Exceptions.h"
#include <iostream>
#include <unordered_set>
#include <queue>

bool Playlist::contains(const std::shared_ptr<Playable>& other) {
	std::unordered_set<std::shared_ptr<Playable> > reached;
	std::queue<std::shared_ptr<Playable> > q;
	q.push(other);
	while (!q.empty()) {
		std::shared_ptr<Playable> me = q.front();
		q.pop();
		std::list<std::shared_ptr<Playable> > children = me->get_children();
		for (auto ptr : children) {
			if (ptr.get() == this)
				return true;
			if (reached.find(ptr) == reached.end()) {
				reached.insert(ptr);
				q.push(ptr);
			}
		}
		std::cout << std::endl;
	}
	return false;
}

void Playlist::add(const std::shared_ptr<Playable>& element) {
	if (element.get() == this || contains(element)) {
		throw CycleException();
	}
	play_list.push_back(element);
}

void Playlist::add(const std::shared_ptr<Playable>& element, size_t position) {
	if (element.get() == this || contains(element)) {
		throw CycleException();
	}
	auto itr = play_list.begin();
	while (itr != play_list.end()) {
		if (position == 0) {
			play_list.insert(itr, element);
			return;
		}
		else {
			position--;
			++itr;
		}
	}
}

void Playlist::remove(size_t position) {
	auto itr = play_list.begin();
	while (itr != play_list.end()) {
		if (position == 0) {
			play_list.erase(itr);
			return;
		}
		else {
			position--;
			++itr;
		}
	}
}

void Playlist::play() {
	std::cout << "Playlist [" + name + "]" << std::endl;
	std::vector<std::list<std::shared_ptr<Playable>>::iterator> indexes;
	for (auto i = play_list.begin(); i != play_list.end(); ++i) {
		indexes.push_back(i);
	}
	if (mode != nullptr)
		indexes = mode->permutation(indexes);
	for (auto it : indexes) {
		(*it)->play();
	}
}
