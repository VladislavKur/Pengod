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
         if(player.getvelocidadx() == false && player.getvelocidady() == false  ){
         PlayerSprite.x = 7,PlayerSprite.y =0;
          player.setPlayerSprite(PlayerSprite);

          if(!Juego->PlayerBloqueColision(&player,3)){
          deltaTime = clock.restart().asSeconds();
        
        accion = 3;
        
       
      // std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
       if(abs((int)player.getBody().getPosition().x %32)==0 && abs((int)player.getBody().getPosition().y %32)==0){
          player.setPosDespues(player.getBody().getPosition().x+32, player.getBody().getPosition().y );
          player.setVelx(true);player.setVely(true);
          
          }
          
       }
        }

        
          break;

        case sf::Keyboard::Left:
         if(player.getvelocidadx() == false && player.getvelocidady() == false  ){
          PlayerSprite.x = 3,PlayerSprite.y =0;
          player.setPlayerSprite(PlayerSprite);

          if(!Juego->PlayerBloqueColision(&player,1)){
          deltaTime = clock.restart().asSeconds();
          accion = 1;
           
         //std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
        if(abs((int)player.getBody().getPosition().x %32)==0)
         player.setPosDespues(player.getBody().getPosition().x-32, player.getBody().getPosition().y );
          player.setVelx(true);player.setVely(true);
          
          }
        }
          break;

        case sf::Keyboard::Up:
         if(player.getvelocidadx() == false && player.getvelocidady() == false  ){
        PlayerSprite.x = 5,PlayerSprite.y =0;
        player.setPlayerSprite(PlayerSprite);

        if(!Juego->PlayerBloqueColision(&player,2)){
        deltaTime = clock.restart().asSeconds();
         accion = 2;
          
                // std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
          if(abs((int)player.getBody().getPosition().y %32)==0 && abs((int)player.getBody().getPosition().x %32)==0)
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y-32 );
         player.setVelx(true);player.setVely(true);
        }
        }
          break;

        case sf::Keyboard::Down:
        if(player.getvelocidadx() == false && player.getvelocidady() == false  ){
        PlayerSprite.x = 1,PlayerSprite.y =0;
         player.setPlayerSprite(PlayerSprite);

        if(!Juego->PlayerBloqueColision(&player,0)){
        deltaTime = clock.restart().asSeconds();
        
          accion = 0;
           
         //std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
         if(abs((int)player.getBody().getPosition().y %32)==0)
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y+32 );
          //else player.setPosicionPlayer();
          player.setVelx(true);player.setVely(true);
        }}
          break;
          case sf::Keyboard::Space:
            //empujar
          break;
          case sf::Keyboard::G:
            //player.PUTODIOS();
          break;
          case sf::Keyboard::X:
            Juego->Reinicio(window);
          break;
          case sf::Keyboard::N:
            Juego->Next(window);
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

      Juego->update(deltaTime);

 
  
    
    
    

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