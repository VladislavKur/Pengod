#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)
{
    
    //matriz de 13*15 empezando en 1,1
    int multiX = 7*2; //min
    int multiY = 8*2;
    cuerpo.setSize(sf::Vector2f(16.0f*2,16.0f*2));
    cuerpo.setPosition(16*multiX,16*multiY);
    cuerpo.setTexture(textura);
    PosDestino= cuerpo.getPosition();

    
    


    vida = 3;
    
}
 
Player::~Player(){}
          
void Player::Update(int acciones, float deltaTime){
    sf::Vector2f movement;
    sf::Vector2u sprite;
    
    accion= acciones;    
        

      switch (acciones){
            case -1: sprite.x = 1; movement.x=0; movement.y=0;break;
            case 0: sprite.x = 1;  movement.y=  speed;break;
            case 1: sprite.x = 3;  movement.x= -abs(speed); break;
            case 2: sprite.x = 5;   movement.y= -abs(speed); break;
            case 3: sprite.x = 7;  movement.x=  speed; break;
            

        default :  break;
        }
       
     if((int)cuerpo.getPosition().x == (int)PosDestino.x){ movement.x = 0; velx=false;} 
     if((int)cuerpo.getPosition().y == (int)PosDestino.y) { movement.y = 0; vely= false;} 
    if(perVi)cuerpo.setPosition(7*32,8*32);
    cuerpo.move(movement.x*deltaTime,movement.y*deltaTime);

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


bool Player::PerderVida(sf::RenderWindow &window){
    bool res = false;
    Juego * juego= Juego::instance();
    if(vida > 0 && !godMod){
        vida--;
        
        std::cout << "VIDAS :" << vida << std::endl;
    }
        
    else{
        std::cout << "Pengo a Muerto..." <<std::endl;
        std::cout << "Se Reinicia el nivel..." << vida << std::endl;
        return true;
        //juego->Reinicio(this,window);
        }
        return res;
}




void Player::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}

void Player::setGod(){
    if(godMod == true){
        
        std::cout << "!!GodMode DESACTIVADO :( !!!" << std::endl;
        godMod= false;
     } else{
         std::cout << "!!GodMode ACTIVADO :) !!!" << std::endl;
         godMod = true;
     } 
}


