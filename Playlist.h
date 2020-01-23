#ifndef INC_6_PLAYLIST_H
#define INC_6_PLAYLIST_H

#include <utility>
#include <vector>
#include <memory>
#include <iostream>
#include "Playable.h"
#include "Playmode.h"

class Playlist : public Playable {
private:
	std::string name;
	std::vector<std::shared_ptr<const Playable>> list;
	std::shared_ptr<Playmode> playmode;
public:
	/*
	 *  Dodaje element na koniec listy odtwarzania
	 */
	void add(const std::shared_ptr<const Playable>& element) {
		list.push_back(element);//TODO: exception?
	}

	/*
	 *  Dodaje element na określonej pozycji w liście odtwarzania (pozycje są numerowane od 0).
	 */
	void add(const std::shared_ptr<const Playable>& element, unsigned int position) {
		list.insert(list.begin() + position, element);//TODO: exception
	}

	/*
	 *  Usuwa ostatni element z listy odtwarzania.
	 */
	void remove() {
		list.pop_back();//TODO: exception
	}

	/*
	 *  Usuwa element z określonej pozycji listy odtwarzania.
	 */
	void remove(unsigned int position) {
		list.erase(list.begin() + position);//TODO: exception
	}

	/*
	 *  Ustawia sposób (kolejność) odtwarzania utworów; sposób odtwarzania może
	 *  zostać utworzony za pomocą funkcji createSequenceMode(), createShuffleMode(seed),
	 *  createOddEvenMode().
	 */
	void setMode(const std::shared_ptr<Playmode>& mode) {
		this->playmode = mode;
	}

	/*
	 *  Odtwarza utwory na liście zgodnie z zadaną kolejnością:
           (a) sekwencyjnie - zgodnie z kolejnością na liście odtwarzania,
           (b) losowo - zgodnie z kolejnością określoną przez std::shuffle wywołane
               z std::default_random_engine,
           (c) nieparzyste/parzyste - najpierw wszystkie nieparzyste, a następnie wszystkie
               parzyste elementy listy odtwarzania.
	 */
	virtual void play() const override {
		std::cout << "Playlist [" << name << "]\n";
		auto arrangedList = playmode->arrange(list);
		for (auto& playable : arrangedList)
			playable->play();
	}
};


#endif //INC_6_PLAYLIST_H
