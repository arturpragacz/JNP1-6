#ifndef INC_6_PLAYLIST_H
#define INC_6_PLAYLIST_H

#include "Playable.h"
#include "Playmode.h"
#include "Track.h"

class Playlist : public Playable {

private:
	std::string name;
	std::shared_ptr<Playmode> mode;
	std::list<std::shared_ptr<Playable> > play_list;

private:
	bool contains(const std::shared_ptr<Playable>& other);

public:
	explicit Playlist(std::string& name) {
		this->name = name;
	}

	/*
	 * Dodaje element na koniec listy odtwarzania
	 */
	void add(const std::shared_ptr<Playable>& element);

	template<typename T>
	void add(const std::shared_ptr<T>& element) {
		add(std::static_pointer_cast<Playable>(element));
	}

	/*
	 * Dodaje element na określonej pozycji w liście odtwarzania (pozycje są numerowane od 0).
	 */
	void add(const std::shared_ptr<Playable>& element, size_t position);

	template<typename T>
	void add(const std::shared_ptr<T>& element, size_t position) {
		add(std::static_pointer_cast<Playable>(element), position);
	}

	/*
	 *  Usuwa ostatni element z listy odtwarzania.
	 */
	void remove() {
		remove(play_list.size() - 1);
	}

	/*
	 *  Usuwa element z określonej pozycji listy odtwarzania.
	 */
	void remove(size_t position);

	/*
	 *  Ustawia sposób (kolejność) odtwarzania utworów; sposób odtwarzania może
	 *  zostać utworzony za pomocą funkcji createSequenceMode(), createShuffleMode(seed),
	 *  createOddEvenMode().
	 */
	void setMode(std::shared_ptr<Playmode> mode) {
		this->mode = mode;
	}

	/*
	 *  Odtwarza utwory na liście zgodnie z zadaną kolejnością:
           (a) sekwencyjnie - zgodnie z kolejnością na liście odtwarzania,
           (b) losowo - zgodnie z kolejnością określoną przez std::shuffle wywołane
               z std::default_random_engine,
           (c) nieparzyste/parzyste - najpierw wszystkie nieparzyste, a następnie wszystkie
               parzyste elementy listy odtwarzania.
	 */
	void play() override;

	std::list<std::shared_ptr<Playable>>& get_children() override {
		return play_list;
	}
};


#endif //INC_6_PLAYLIST_H
