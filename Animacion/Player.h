#pragma once

#include <SFML/Graphics.hpp>
#include "Animacion.h"


class Player{
    public:
    Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite);
    ~Player();
    void Update(int accion, float deltaTime);
    void Draw(sf::RenderWindow &window);
     void setPlayerSprite(sf::Vector2u Sprites);
     void setPosDespues(float, float);
    sf::RectangleShape getBody(){return cuerpo;}
    sf::Vector2f posDestino(){return PosDestino;}
    bool velocidad(){return vel;}
    bool setVel(bool v){vel = v;}
    void setvidas();
    void setPosicionPlayer();
     

    

    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;
    sf::Vector2u fila;
    bool nopulsarCheck=false;
    float speed= 75;
    bool vel= false;
    int accion;
    
    sf::Vector2f PosDestino;

    int vida;
   
};