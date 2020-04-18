#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)
{
    
    //matriz de 13*15 empezando en 1,1
    int multiX = 1*2; //min
    int multiY = 1*2;
    cuerpo.setSize(sf::Vector2f(16.0f*2,16.0f*2));
    cuerpo.setPosition(16*multiX,16*multiY);
    cuerpo.setTexture(textura);
    PosDestino= cuerpo.getPosition();
    


    vida = 5;
    
}
 
Player::~Player(){}
          
void Player::Update(int acciones, float deltaTime){
    sf::Vector2f movement;
    sf::Vector2u sprite;
    
        
        

      switch (acciones){
            case -1: sprite.x = 1; movement.x=0; movement.y=0;break;
            case 0: sprite.x = 1;  movement.y=  speed;break;
            case 1: sprite.x = 3;  movement.x= -abs(speed); break;
            case 2: sprite.x = 5;   movement.y= -abs(speed); break;
            case 3: sprite.x = 7;  movement.x=  speed; break;
            

        default :  break;
        }
        //std::cout << cuerpo.getPosition().x << ", " << cuerpo.getPosition().y <<" ====" << PosDestino.x <<", " << PosDestino.y << std::endl;
      
     // std:: cout << cuerpo.getPosition().x <<", " <<cuerpo.getPosition().y <<"====" << PosDestino.x <<", " <<PosDestino.y << std::endl;
     if((int)cuerpo.getPosition().x == (int)PosDestino.x){ movement.x = 0;} 
     
     if((int)cuerpo.getPosition().y == (int)PosDestino.y) { movement.y = 0;} 
        
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


void Player::setvidas(){
    vida--;
   // if(vida<= 0) morir();
}

void Player::setPosicionPlayer(){
    float resto =0;
    float necesito = 0;
    int final =0;
    if((int)cuerpo.getPosition().x%32 != 0){
        resto= (cuerpo.getPosition().x/32)-(int)(cuerpo.getPosition().x/32) ;
        std::cout << resto <<std::endl;
        necesito = 32-resto*32;
        if(resto >= 16){
            final = 32-necesito;
            cuerpo.setPosition(cuerpo.getPosition().x+final,cuerpo.getPosition().y);
            
        }else{
            cuerpo.setPosition(cuerpo.getPosition().x-necesito,cuerpo.getPosition().y);
            
        }

        
       

    }

     
     if((int)cuerpo.getPosition().y %32 != 0) {
        resto= (cuerpo.getPosition().x/32)-(int)(cuerpo.getPosition().x/32) ;
        necesito = 32-resto*32;
        if(resto >= 16){
            final = 32-necesito;
            cuerpo.setPosition(cuerpo.getPosition().x,cuerpo.getPosition().y+final);
            
        }else{
            cuerpo.setPosition(cuerpo.getPosition().x,cuerpo.getPosition().y-necesito);
            
        }
            

     }

}


void Player::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}


