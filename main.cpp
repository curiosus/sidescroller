#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::Color;
using sf::Event;




constexpr int windowWidth{1200};
constexpr int windowHeight{900};

int main() {

  RenderWindow window{{windowWidth, windowHeight}, "Side Scroller"};
  while (window.isOpen()) {
    window.clear(Color::Black);
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
        break;
      }
    }

    window.setTitle("Side Scroller");
    window.display();
    

  }


}

