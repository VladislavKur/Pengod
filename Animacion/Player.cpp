#include <SFML/Graphics.hpp>
#include "Player.h"

Player::Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float cambioImagen, float speed, int accion) : 
animacion(textura, cantidadImagenes,cambioImagen,accion)
{
    this->speed = speed;
    fila = 0;
    

    cuerpo.setSize(sf::Vector2f(25.0f,25.0f));
    cuerpo.setPosition(200.0f,200.0f);
    cuerpo.setTexture(textura);
}





Player::~Player(){}




void Player::Update(float deltaTime,int accion){
    sf::Vector2f movement(0.0f,0.0f);
    
    
    switch (accion){
        case -1:break;
        case 0: movement.y= 75.03f;break;
        case 1: movement.x= -abs(75.03f);break;
        case 2: movement.y= -abs(75.0f);break;
        case 3: movement.x=75.03f;break;
    }

  
    

    animacion.Update(fila,deltaTime,accion);
    cuerpo.setTextureRect(animacion.textureRect);
    cuerpo.move(movement.x*deltaTime,movement.y*deltaTime);
}




void Player::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}