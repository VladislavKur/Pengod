#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Juego/Juego.h"
#include <iostream>

int main() {
  /////////////
  ////START////
  /////////////

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode (1024.0f,1024.0f), "Pengod", sf::Style::Close);
  Juego* Juego = Juego::instance();

// TEXTURAS PENGO
  sf::Texture playerTexture;
  playerTexture.loadFromFile("resources/pengoybees.png");

//ANIMACIOn
  int accion= -1;
  
  sf::Vector2u sprite(0,0);
  Player player(&playerTexture, sf::Vector2u(40,19),0.25f);
  

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
        deltaTime = clock.restart().asSeconds();
        
         accion = 3; 
         sprite.x = 7,sprite.y =0;
         player.setPlayerSprite(sprite);
         if((((int)player.getBody().getPosition().y+48)%48 <= (((int)player.getBody().getPosition().y+48)%48)+0.01) 
         && ((int)player.getBody().getPosition().y+48)%48 >= (((int)player.getBody().getPosition().y+48)%48)-0.01)
         player.setPosDespues(player.getBody().getPosition().x+48, player.getBody().getPosition().y );
       
          break;

        case sf::Keyboard::A:
        deltaTime = clock.restart().asSeconds();
          accion = 1;
           sprite.x = 3,sprite.y =0;
         player.setPlayerSprite(sprite);
        if((((int)player.getBody().getPosition().x+48)%48 <= (((int)player.getBody().getPosition().x+48)%48)+0.01) 
         && ((int)player.getBody().getPosition().x+48)%48 >= (((int)player.getBody().getPosition().x+48)%48)-0.01)
         player.setPosDespues(player.getBody().getPosition().x-48, player.getBody().getPosition().y );
          break;

        case sf::Keyboard::W:
        deltaTime = clock.restart().asSeconds();
         accion = 2;
          sprite.x = 5,sprite.y =0;
         player.setPlayerSprite(sprite);
         if((((int)player.getBody().getPosition().y+48)%48 <= (((int)player.getBody().getPosition().y+48)%48)+0.01) 
         && ((int)player.getBody().getPosition().y+48)%48 >= (((int)player.getBody().getPosition().y+48)%48)-0.01)
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y-48 );
          break;

        case sf::Keyboard::S:
        deltaTime = clock.restart().asSeconds();
        
          accion = 0;
           sprite.x = 1,sprite.y =0;
         player.setPlayerSprite(sprite);
         if((((int)player.getBody().getPosition().y+48)%48 <= (((int)player.getBody().getPosition().y+48)%48)+0.01) 
         && ((int)player.getBody().getPosition().y+48)%48 >= (((int)player.getBody().getPosition().y+48)%48)-0.01)
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y+48 );
          
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
    Juego->Draw(window);
    player.Draw(window);
   
    
    window.display();
    }
  

  
return 0;}