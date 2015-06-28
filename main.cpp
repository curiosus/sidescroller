#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const sf::Vector2u windowSize{1200, 900};

int main() {

  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("background.png")) {
    std::cout << "fuck!!!" << std::endl;
    return 1;
  }

  const sf::Vector2f& startPosition{0.0f, 0.0f};
  const sf::Vector2f& endPosition{-1790.0f, 0.0f};
  sf::Sprite backgroundSprite;
  backgroundSprite.setTexture(backgroundTexture);

  const sf::Vector2f& moveRight{-10.0f, 0.f};
  const sf::Vector2f& moveLeft{10.0f, 0.0f};

  sf::Texture playerTexture;
  if (!playerTexture.loadFromFile("player.png")) {
    std::cout << "fuck fuck fuck!!!" << std::endl;
    return 1;
  }
  sf::Sprite playerSprite;
  playerSprite.setTexture(playerTexture);
  playerSprite.setPosition(600.0f, 800.0f);

  sf::Texture monsterTexture;
  if (!monsterTexture.loadFromFile("monster.png")) {
    std::cout << "fuck fuckity fuck fuck fuck!" << std::endl;
  }
  sf::Sprite monsterSprite;
  monsterSprite.setTexture(monsterTexture);
  monsterSprite.setPosition(1050.0f, 700.0f);
  
  sf::RenderWindow window{{windowSize.x, windowSize.y}, "Side Scroller"};
  
  while (window.isOpen()) {
    window.clear(sf::Color::Black);

    //event polling
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }
      if (event.type == sf::Event::KeyPressed) {
        const sf::Vector2f& pos = backgroundSprite.getPosition();
        std::cout << pos.x << std::endl; 
        if (event.key.code == sf::Keyboard::Key::D) {
          if (pos.x == -1790.f) {
            backgroundSprite.setPosition(startPosition); 
          }
          backgroundSprite.move(moveRight);
          monsterSprite.move(moveLeft);
        } else if (event.key.code == sf::Keyboard::Key::A) {
          if (pos.x == 0.f) {
            backgroundSprite.setPosition(endPosition);
          }   
          backgroundSprite.move(moveLeft);
          monsterSprite.move(moveRight);
        }
      }
    }

    window.draw(backgroundSprite);
    window.draw(playerSprite);
    window.draw(monsterSprite);
    window.display();
    
  }

  return 0;
}


