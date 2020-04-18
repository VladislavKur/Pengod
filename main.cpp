#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemigo.h"
#include "Bloque.h"
#include "Juego/Juego.h"
#include <iostream>


int main() {
  srand(time(NULL));
  /////////////
  ////START////
  /////////////

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode (720.0f,720.0f), "Pengod", sf::Style::Close);
  Juego* Juego = Juego::instance();

// TEXTURAS PENGO
  sf::Texture playerTexture;
  sf::Texture BloqueTexture;
  playerTexture.loadFromFile("resources/pengoybees.png");
  BloqueTexture.loadFromFile("resources/CuboDeHielo.png");

//ANIMACIOn
  int accion= -1;
  
 
  
  
bool algo=false;
  
  sf::Vector2u PlayerSprite(0,0);

  Player player(&playerTexture, sf::Vector2u(40,18),0.25f);

  
 

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
        case sf::Keyboard::Right:
        
          
          deltaTime = clock.restart().asSeconds();
        
        accion = 3;
        
        PlayerSprite.x = 7,PlayerSprite.y =0;
        player.setPlayerSprite(PlayerSprite);
      // std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
       if(abs((int)player.getBody().getPosition().x %32)==0 && abs((int)player.getBody().getPosition().y %32)==0){
          player.setPosDespues(player.getBody().getPosition().x+32, player.getBody().getPosition().y );
           //else player.setPosicionPlayer();

          
          }
          
       
        

        
          break;

        case sf::Keyboard::Left:
          
          
          deltaTime = clock.restart().asSeconds();
          accion = 1;
           PlayerSprite.x = 1,PlayerSprite.y =0;
          
         
         player.setPlayerSprite(PlayerSprite);
         //std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
        if(abs((int)player.getBody().getPosition().x %32)==0)
         player.setPosDespues(player.getBody().getPosition().x-32, player.getBody().getPosition().y );
          //else player.setPosicionPlayer();
          
          
          break;

        case sf::Keyboard::Up:
        
        deltaTime = clock.restart().asSeconds();
         accion = 2;
          PlayerSprite.x = 5,PlayerSprite.y =0;
       
                 player.setPlayerSprite(PlayerSprite);
                // std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
          if(abs((int)player.getBody().getPosition().y %32)==0 && abs((int)player.getBody().getPosition().x %32)==0)
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y-32 );
         //else player.setPosicionPlayer();
        
        
          break;

        case sf::Keyboard::Down:
        
        deltaTime = clock.restart().asSeconds();
        
          accion = 0;
           PlayerSprite.x = 1,PlayerSprite.y =0;
           
         
         player.setPlayerSprite(PlayerSprite);
         //std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
         if(abs((int)player.getBody().getPosition().y %32)==0)
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y+32 );
          //else player.setPosicionPlayer();
          
        
          break;
          case sf::Keyboard::Space:
            //empujar
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

 
  
    
    
    for(unsigned int k = 0; k < Juego->getListaEnemigos().size();k++) {
      for(unsigned int n = 0; n < Juego->getListaEnemigos()[1].size();n++) {
    
      Juego->getListaEnemigos()[k][n]->Update(deltaTime);
    
    }


    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    Juego->Draw(window);
   
    Juego->DrawBloques(window);
    Juego->DrawEnemigos(window);
   
    
    player.Draw(window);
   
    
    window.display();
    
  }

  
return 0;}