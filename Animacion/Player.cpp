#include <SFML/Graphics.hpp>
#include "Player.h"

Player::Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite, int movimiento) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)
{
    
    
    

    cuerpo.setSize(sf::Vector2f(25.0f,25.0f));
    cuerpo.setPosition(200.0f,200.0f);
    cuerpo.setTexture(textura);
}





Player::~Player(){}




void Player::Update(int movimiento, float deltaTime){
    sf::Vector2u movement;
    sf::Vector2u sprite;
    
    switch (movimiento){
        case -1:break;
        case 0: sprite.x = 1;  movement.y=  50;break;
        case 1: sprite.x = 3;  movement.x= -abs(50);break;
        case 2: sprite.x = 5;  movement.y= -abs(50);break;
        case 3: sprite.x = 7;  movement.x=  50;break;

        default : movement.x=0;movement.y=0;break;
    }

  
    

    animacion.Update(sprite, deltaTime);
    cuerpo.setTextureRect(animacion.textureRect);
    cuerpo.move(movement.x*deltaTime,movement.y*deltaTime);
}




void Player::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}