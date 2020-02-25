#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

#define kVel 5

int main() {
  /////////////
  ////START////
  /////////////

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode (1024.0f,1024.0f), "Pengod", sf::Style::Close);

  sf::RectangleShape player(sf::Vector2f(100.0f,100.0f));
  player.setFillColor(sf::Color::Blue);
  player.setPosition(200.0f,200.0f);
  player.setOrigin(200.0f,200.0f);

  sf::Texture playerTexture;
  playerTexture.loadFromFile("");
  //////////////////
  ////BUCLE////////
  ////////////////
  while (window.isOpen()) {
    
    //////////////
    ////INPUT/////
    /////////////
    sf::Event evnt;
    while (window.pollEvent(evnt)) {

      switch (evnt.type) {
      case sf::Event::Closed: window.close(); break;
      case sf::Event::KeyPressed:
      default: break;
      }
       
    }


    ////////////
    ///UPDATE///
    ////////////
    

    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    window.draw(player);
    window.display();
    }
  

  return 0;
}