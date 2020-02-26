#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

#define kVel 5

int main() {
  /////////////
  ////START////
  /////////////

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode (1024.0f,1024.0f), "Pengod", sf::Style::Close);

// TEXTURAS PENGO
  sf::Texture playerTexture;
  playerTexture.loadFromFile("resources/pengoybees.png");
  

//ANIMACIOn
  Player player(&playerTexture, sf::Vector2u(40,19), 0.2f,100.0f);

  float deltaTime =0.0f;

  sf::Clock clock;

  //////////////////
  ////BUCLE////////
  ////////////////
  while (window.isOpen()) {

    deltaTime = clock.restart().asSeconds();
    
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
    player.Update(deltaTime);


    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    player.Draw(window);
    window.display();
    }
  

  return 0;
}