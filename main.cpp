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
  int accion= -1;
  Player player(&playerTexture, sf::Vector2u(40,19),0.20f,accion);
  

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

        switch (evnt.key.code) {

        //Mapeo del cursor
        case sf::Keyboard::D:
         accion = 3;
          break;

        case sf::Keyboard::A:
          accion = 1;
          break;

        case sf::Keyboard::W:
         accion = 2;
          break;

        case sf::Keyboard::S:
          accion = 0;
          
          break;
        
        //Tecla ESC para salir
        case sf::Keyboard::Escape:
          window.close();
          break;

        //Cualquier tecla desconocida se imprime por pantalla su código
        default:
          std::cout << evnt.key.code << std::endl;
          break;
        }

      
      default: break;
      }
       break;
    }


    ////////////
    ///UPDATE///
    ////////////
    
    player.Update(accion,deltaTime);


    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    player.Draw(window);
    window.display();
    }
  

  
return 0;}