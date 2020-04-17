#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemigo.h"
#include "Juego/Juego.h"
#include <iostream>

int main() {
  /////////////
  ////START////
  /////////////

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode (720.0f,720.0f), "Pengod", sf::Style::Close);
  Juego* Juego = Juego::instance();

// TEXTURAS PENGO
  sf::Texture playerTexture;
  playerTexture.loadFromFile("resources/pengoybees.png");

//ANIMACIOn
  int accion= -1;
  bool nopulsar =true;
  srand(time(NULL));
  

  
  sf::Vector2u PlayerSprite(0,0);
  sf::Vector2u EnemigoSprite(0,9);
  Player player(&playerTexture, sf::Vector2u(40,18),0.25f);
  Enemigo enem1(&playerTexture, sf::Vector2u(40,18),0.25f, sf::Vector2f(2,2));
  Enemigo enem2(&playerTexture, sf::Vector2u(40,18),0.25f, sf::Vector2f(2,2));
  Enemigo enem3(&playerTexture, sf::Vector2u(40,18),0.25f, sf::Vector2f(2,2));
  Enemigo enem4(&playerTexture, sf::Vector2u(40,18),0.25f, sf::Vector2f(2,2));
  
 
   std::vector<Enemigo *>  listaEnem;
   listaEnem.push_back(&enem1);
   listaEnem.push_back(&enem2);
   listaEnem.push_back(&enem3);
   listaEnem.push_back(&enem4);

  /*for(unsigned int f = 0; f< listaEnem.size();f++)


  listaEnem.push_back(new Enemigo (&playerTexture, sf::Vector2u(40,18),0.25f, sf::Vector2f(2,2)) );*/

 

 

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
       
        if(Juego->ComprobarMov(player.getBody().getPosition().x))
          player.setPosDespues(player.getBody().getPosition().x+32, player.getBody().getPosition().y );

       
          break;

        case sf::Keyboard::Left:
        deltaTime = clock.restart().asSeconds();
          accion = 1;
           PlayerSprite.x = 3,PlayerSprite.y =0;
          // EnemigoSprite.x = 3,EnemigoSprite.y =9;
         
         player.setPlayerSprite(PlayerSprite);
       if(Juego->ComprobarMov(player.getBody().getPosition().x))
         player.setPosDespues(player.getBody().getPosition().x-32, player.getBody().getPosition().y );
         nopulsar = false;
          break;

        case sf::Keyboard::Up:
        deltaTime = clock.restart().asSeconds();
         accion = 2;
          PlayerSprite.x = 5,PlayerSprite.y =0;
         // EnemigoSprite.x = 5,EnemigoSprite.y =9;
                 player.setPlayerSprite(PlayerSprite);
         if(Juego->ComprobarMov(player.getBody().getPosition().y))
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y-32 );
          nopulsar = false;
          break;

        case sf::Keyboard::Down:
        deltaTime = clock.restart().asSeconds();
        
          accion = 0;
           PlayerSprite.x = 1,PlayerSprite.y =0;
           //EnemigoSprite.x = 1,EnemigoSprite.y =9;
         
         player.setPlayerSprite(PlayerSprite);
         if(Juego->ComprobarMov(player.getBody().getPosition().y))
         player.setPosDespues(player.getBody().getPosition().x, player.getBody().getPosition().y+32 );
           nopulsar = false;
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
      nopulsar=player.noPulsarChek();
      if(nopulsar)player.Update(accion,deltaTime);

 
  
    
    
    for(unsigned int k = 0; k < listaEnem.size();k++) {
     // listaEnem[k].setEnemigoSprite(EnemigoSprite);
      listaEnem[k]->Update(deltaTime);
    
    }


    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    Juego->Draw(window);
     for(unsigned int k = 0; k < listaEnem.size();k++) {
     // listaEnem[k].setEnemigoSprite(EnemigoSprite);
      listaEnem[k]->Draw(window);
    
    }
    player.Draw(window);
   
    
    window.display();
    }
  

  
return 0;}