#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)
{
    
    //matriz de 13*15 empezando en 1,1
    int multiX = 1*3; //min
    int multiY = 1*3;
    cuerpo.setSize(sf::Vector2f(16.0f*3,16.0f*3));
    cuerpo.setPosition(16*multiX,16*multiY);
    cuerpo.setTexture(textura);
    PosDestino= cuerpo.getPosition();
}
 
Player::~Player(){}
          
void Player::Update(int acciones, float deltaTime, float speed){
    sf::Vector2f movement;
    sf::Vector2u sprite;
  
    tiempoMov += deltaTime;

  
      switch (acciones){
            case -1: sprite.x = 1; movement.x=0; movement.y=0;break;
            case 0: sprite.x = 1;  movement.y=  speed; ;break;
            case 1: sprite.x = 3;  movement.x= -abs(speed);;break;
            case 2: sprite.x = 5;  movement.y= -abs(speed);;break;
            case 3: sprite.x = 7;  movement.x=  speed;;break;

        default :  break;
        }
    if(cuerpo.getPosition() != PosDestino) {
        cuerpo.move(0,0);
        
        }else cuerpo.move(movement.x*deltaTime,movement.y*deltaTime);
    animacion.Update(sprite, deltaTime);
    cuerpo.setTextureRect(animacion.textureRect);
    
}


void Player::setPlayerSprite(sf::Vector2u Sprites){
    animacion.setSprite(Sprites);
}

void Player::setPosDespues(float x, float y){
    PosDestino.x = x;
    PosDestino.y = y;
}





void Player::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}
