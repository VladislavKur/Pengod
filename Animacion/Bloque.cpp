
#include <SFML/Graphics.hpp>
#include "Bloque.h"
#include <iostream>

Bloque::Bloque(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite,sf::Vector2f pos, int t) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)

{
         sf::Texture *text = new sf::Texture;
         tipo = t; if (t == 0){
             text->loadFromFile("resources/CuboDeHielo.png");
             if(!text->loadFromFile("resources/CuboDeHielo.png")) std::cout << "sadasds";

         }else {
                text->loadFromFile("resources/CuboDeDiamante.png");
             if(!text->loadFromFile("resources/CuboDeDiamante.png")) std::cout << "sadasds";

         }
   
   
    //matriz de 13*15 empezando en 1,1
    
    cuerpo.setSize(sf::Vector2f(16.0f*2,16.0f*2));
    cuerpo.setPosition(2*16*pos.x,2*16*pos.y);

     
    cuerpo.setTexture(text);
    

   //por defecto es un bloque de hielo, no diamante ese raro

    
   



    
}
 
Bloque::~Bloque(){}
          
void Bloque::Update(float deltaTime, bool mov, Player* player){
    sf::Vector2u sprite;
    sf::Vector2f movim;
    Juego* juego = Juego::instance();
    int dir = player->getAcciones();
    int bbColision = juego->BloqueBloqueColision();
    //dir 0 abajo  1 izq 2 arriba 3 der
    
        switch (dir)
        {
        case -1: movim.x = 0; movim.y= 0;
            break;
        case 0: movim.y = speed;
            break;
        case 1: movim.x = speed;
            break;
        case 2: movim.y = -speed;
            break;
        case 3: movim.x = -speed;
            break;
    
        default:
            break;
    }


    if(bbColision != 0){
        switch (bbColision)
        {
        case -1:if(movim.x != 0 && movim.y == 0){ // esto esto derecha
                    
                }
                if(movim.y != 0 && movim.x == 0){ // esto es abajo

                }
            break;
        case 1: if(movim.x != 0 && movim.y == 0){ // esto es izq

                }
                if(movim.y != 0 && movim.x == 0){ // esto es arriba

                }
            break;
        
        default:
            break;
        }
    }

        
        
   cuerpo.move(movim.x*deltaTime,movim.y*deltaTime);

    animacion.Update(sprite, deltaTime);
    cuerpo.setTextureRect(animacion.textureRect);
    
}


void Bloque::setBloqueSprite(sf::Vector2u Sprites){
    animacion.setSprite(Sprites);
}


void Bloque::setMov(bool semueve){
    mov = semueve;
}



void Bloque::Draw(sf::RenderWindow &window){
    cuerpo.setTextureRect(sf::IntRect (0,0,16,16));
    window.draw(cuerpo);
}
