#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Bad {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int BAD_HP = 1000;
	bool del = false;
	size_t zaderzka = 1000;
	size_t stop = 10;
	sf::Clock clock;
public:
	Bad();
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();

	void takedamage(int);
	int badHp();
	void setDel(bool);
	bool getDel();
};