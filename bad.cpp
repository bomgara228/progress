#include "bad.h"
#include "settings.h"



Bad::Bad() {
	texture.loadFromFile(IMAGES_FOLDER + BAD_SHIP );
	sprite.setScale(1.4f, 1.3f);
	sprite.setTexture(texture);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sprite.setPosition(WINDOW_WIDTH / 2 - g_bounds.width / 2,
		WINDOW_HEIGHT /6);
}

void Bad::update() {
	sf::Vector2f position = sprite.getPosition();
	sf::FloatRect g_bounds = sprite.getGlobalBounds();

	sf::Time now = clock.getElapsedTime();
	if (now.asMilliseconds() > zaderzka) {
		size_t dodge = rand() % 1000;
		if (dodge >= 500) {
			sprite.move(20.0f, 0.0f); 
		}
		else if (dodge < 500) {
			sprite.move(-20.0f, 0.0f);
		}
		if (position.x > WINDOW_WIDTH - g_bounds.height) { sprite.move(-50.0f, 0.f); }
		if (position.x < 0) { sprite.move(50.0f, 0.f); }
		clock.restart();
	}
}
	
void Bad::draw(sf::RenderWindow& window) { window.draw(sprite); }
sf::FloatRect Bad::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Bad::getPosition() { return sprite.getPosition(); }
void Bad::takedamage(int damage) {BAD_HP -= damage ; }
int Bad::badHp() { return BAD_HP; }
void Bad::setDel(bool a) { del = a; }
bool Bad::getDel() { return del; }