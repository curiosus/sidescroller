#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::View;
using sf::Color;
using sf::Event;
using sf::Keyboard;
using sf::Texture;
using sf::Sprite;
using sf::Vector2u;
using sf::Vector2i;
using sf::Vector2f;
using std::cout;
using std::endl;


const Vector2u windowSize{1200, 900};

int main() {

  Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("background.png")) {
    cout << "whoops" << endl;
    return 1;
  }
  Sprite backgroundSprite;
  backgroundSprite.setTexture(backgroundTexture);

  Texture playerTexture;
  if (!playerTexture.loadFromFile("player.png")) {
    cout << "whoops2" << endl;
    return 1;
  }
  Sprite playerSprite;
  playerSprite.setTexture(playerTexture);

  playerSprite.setPosition(150.0,750.0);
  const Vector2f& playerMovement{-2.f, 0.f};

  
  RenderWindow window{{windowSize.x, windowSize.y}, "Side Scroller"};
  while (window.isOpen()) {
    window.clear(Color::Black);
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
        break;
      } else if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Key::A) {
            backgroundSprite.move(playerMovement);
        }
        
      }
    }

    window.draw(backgroundSprite);
    window.draw(playerSprite);
    window.display();
    

  }


}

