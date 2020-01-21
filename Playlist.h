#ifndef INC_6_PLAYLIST_H
#define INC_6_PLAYLIST_H

#include "Playable.h"
#include "Playmode.h"

class Playlist : public Playable {
	/*
	 *  Dodaje element na koniec listy odtwarzania
	 */
	void add(Playable element) {

	}

	/*
	 *  Dodaje element na określonej pozycji w liście odtwarzania (pozycje są numerowane od 0).
	 */
	void add(Playable element, unsigned int position) {

	}

	/*
	 *  Usuwa ostatni element z listy odtwarzania.
	 */
	void remove() {

	}

	/*
	 *  Usuwa element z określonej pozycji listy odtwarzania.
	 */
	void remove(unsigned int position) {

	}

	/*
	 *  Ustawia sposób (kolejność) odtwarzania utworów; sposób odtwarzania może
	 *  zostać utworzony za pomocą funkcji createSequenceMode(), createShuffleMode(seed),
	 *  createOddEvenMode().
	 */
	void setMode(Playmode mode) {

	}

	/*
	 *  Odtwarza utwory na liście zgodnie z zadaną kolejnością:
           (a) sekwencyjnie - zgodnie z kolejnością na liście odtwarzania,
           (b) losowo - zgodnie z kolejnością określoną przez std::shuffle wywołane
               z std::default_random_engine,
           (c) nieparzyste/parzyste - najpierw wszystkie nieparzyste, a następnie wszystkie
               parzyste elementy listy odtwarzania.
	 */
	virtual void play() {

	}
};


#endif //INC_6_PLAYLIST_H
