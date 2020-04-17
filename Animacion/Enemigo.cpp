#include <SFML/Graphics.hpp>
#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite,sf::Vector2f pos) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)
{
    
    //matriz de 13*15 empezando en 1,1
    
    cuerpo.setSize(sf::Vector2f(16.0f*2,16.0f*2));
    cuerpo.setPosition(2*16*pos.x,2*16*pos.y);
    cuerpo.setTexture(textura);

    
   


    vida = 5;
    
}
 
Enemigo::~Enemigo(){}
          
void Enemigo::Update( float deltaTime){
    
    sf::Vector2f movement;
    sf::Vector2u sprite;
    
    for(int i = 0; i <= 4; i++){
    int acciones;
    
    acciones = rand()%4;
    
  
      switch (acciones){
            case -1: sprite.x = 1;sprite.y = 9; movement.x=0; movement.y=0;break;
            case 0: sprite.x = 1;sprite.y = 9;  movement.y=  speed; ;break;
            case 1: sprite.x = 3;sprite.y = 9;  movement.x= -abs(speed);;break;
            case 2: sprite.x = 5;sprite.y = 9;  movement.y= -abs(speed);;break;
            case 3: sprite.x = 7;sprite.y = 9;  movement.x=  speed;;break;
            

        default :  break;
        }
    }
        //std::cout << cuerpo.getPosition().x << ", " << cuerpo.getPosition().y <<" ====" << PosDestino.x <<", " << PosDestino.y << std::endl;
        
   cuerpo.move(movement.x*deltaTime,movement.y*deltaTime);

    animacion.Update(sprite, deltaTime);
    cuerpo.setTextureRect(animacion.textureRect);
    
}


void Enemigo::setEnemigoSprite(sf::Vector2u Sprites){
    animacion.setSprite(Sprites);
}




void Enemigo::setvidas(){
    vida--;
   // if(vida<= 0) morir();
}


void Enemigo::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}
