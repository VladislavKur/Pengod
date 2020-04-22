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
  bool reini = false;
  
  
  sf::Vector2u PlayerSprite(0,0);

  Player player(&playerTexture, sf::Vector2u(40,18),0.25f);

  std::vector<std::vector<Bloque *>>  listaBloque;
 

  float deltaTime =0.0f;

  listaBloque =Juego->getListaBloque();
  

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
        PlayerSprite.x = 7,PlayerSprite.y =0;
          player.setPlayerSprite(PlayerSprite);
          accion = 3;
         if(player.getvelocidadx() == false && player.getvelocidady() == false  ){
         

          if(!Juego->PlayerBloqueColision(&player,3)){
          deltaTime = clock.restart().asSeconds();
        
        
        
       
      // std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
       if(abs((int)player.getBody().getPosition().x %32)==0 && abs((int)player.getBody().getPosition().y %32)==0){
          player.setPosDespues(player.getBody().getPosition().x+32, player.getBody().getPosition().y );
          player.setVelx(true);player.setVely(true);
          
          }
          
       }
        }

        
          break;

        case sf::Keyboard::Left:
        PlayerSprite.x = 3,PlayerSprite.y =0;
          player.setPlayerSprite(PlayerSprite);
          accion = 1;
         if(player.getvelocidadx() == false && player.getvelocidady() == false  ){
          

          if(!Juego->PlayerBloqueColision(&player,1)){
          deltaTime = clock.restart().asSeconds();
          
           
         //std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
        if(abs((int)player.getBody().getPosition().x %32)==0)
         player.setPosDespues(player.getBody().getPosition().x-32, player.getBody().getPosition().y );
          player.setVelx(true);player.setVely(true);
          
          }
        }
          break;

        case sf::Keyboard::Up:
        PlayerSprite.x = 5,PlayerSprite.y =0;
        player.setPlayerSprite(PlayerSprite);
        accion = 2;
         if(player.getvelocidadx() == false && player.getvelocidady() == false  ){
        

        if(!Juego->PlayerBloqueColision(&player,2)){
        deltaTime = clock.restart().asSeconds();
         
          
                // std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
          if(abs((int)player.getBody().getPosition().y %32)==0 && abs((int)player.getBody().getPosition().x %32)==0)
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y-32 );
         player.setVelx(true);player.setVely(true);
        }
        }
          break;

        case sf::Keyboard::Down:
        PlayerSprite.x = 1,PlayerSprite.y =0;
         player.setPlayerSprite(PlayerSprite);
          accion = 0;
        if(player.getvelocidadx() == false && player.getvelocidady() == false  ){
        

        if(!Juego->PlayerBloqueColision(&player,0)){
        deltaTime = clock.restart().asSeconds();
        
         
           
         //std::cout << player.posDestino().x << ", " << player.posDestino().y << std::endl;
         if(abs((int)player.getBody().getPosition().y %32)==0)
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y+32 );
          //else player.setPosicionPlayer();
          player.setVelx(true);player.setVely(true);
        }}
          break;
        
          case sf::Keyboard::G:
            //player.PUTODIOS();
          break;
          case sf::Keyboard::X:
            reini = Juego->Reinicio(&player,window);
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

      Juego->update(deltaTime, &player,window);

 
  
    
    
    

    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    Juego->Draw(window);
   
   
    
    if(!reini){
      Juego->DrawBloques(window);
      Juego->DrawEnemigos(window);
    }
    else {
      Juego->DrawrBloques(window);
      Juego->DrawrEnemigos(window);
    }
    player.Draw(window);
    
    window.display();
    
  }

  
return 0;}