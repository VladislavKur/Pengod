#include <SFML/Graphics.hpp>
#include "Player.h"

Player::Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite, float speed) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)
{
    
    speed = 0;
    
    
    

    cuerpo.setSize(sf::Vector2f(100.0f,100.0f));
    cuerpo.setPosition(200.0f,200.0f);
    cuerpo.setTexture(textura);
}





Player::~Player(){}



                    
void Player::Update(int accion, float deltaTime, float speed){
    sf::Vector2f movement;
    sf::Vector2u sprite;
    
    switch (accion){
        case -1:sprite.x = 1; break;
        case 0: sprite.x = 1;  movement.y=  speed; ;break;
        case 1: sprite.x = 3;  movement.x= -abs(speed);;break;
        case 2: sprite.x = 5;  movement.y= -abs(speed);;break;
        case 3: sprite.x = 7;  movement.x=  speed;;break;

        default : movement.x=0;movement.y=0;break;
    }

  
    

    animacion.Update(sprite, deltaTime);
    cuerpo.setTextureRect(animacion.textureRect);
    cuerpo.move(movement.x*deltaTime,movement.y*deltaTime);
}


void Player::setPlayerSprite(sf::Vector2u Sprites){
    animacion.setSprite(Sprites);
}



void Player::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}
