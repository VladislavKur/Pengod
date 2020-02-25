#include <SFML/Graphics.hpp>
#include "Player.h"

Player::Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float cambioImagen, float speed) : animacion(textura, cantidadImagenes,cambioImagen)
{
    this->speed = speed;
    fila = 0;


    cuerpo.setSize(sf::Vector2f(25.0f,25.0f));
    cuerpo.setPosition(200.0f,200.0f);
    cuerpo.setTexture(textura);
}





Player::~Player(){}





void Player::Update(float deltaTime){
    sf::Vector2f movement(0.0f,0.0f);

    if(sf::Keyboard().isKeyPressed(sf::Keyboard::Left)){
        movement.x -= speed; fila = 3;
    }
        
    if(sf::Keyboard().isKeyPressed(sf::Keyboard::Right)){
        movement.x += speed; fila = 7;
    }
       
    if(sf::Keyboard().isKeyPressed(sf::Keyboard::Up)){
        movement.y -= speed; fila = 5;
    }
        
    if(sf::Keyboard().isKeyPressed(sf::Keyboard::Down)){
        movement.y += speed; fila= 0;
    }
        

    

    animacion.Update(fila,deltaTime);
    cuerpo.setTextureRect(animacion.textureRect);
    cuerpo.move(movement*deltaTime);
}




void Player::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}