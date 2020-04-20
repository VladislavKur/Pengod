#pragma once

#include <SFML/Graphics.hpp>
#include "Animacion.h"


class Bloque{
    public:
    Bloque(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite,sf::Vector2f pos, int );
    ~Bloque();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);
     void setBloqueSprite(sf::Vector2u Sprites);
     void setPosDespues(float, float);
    sf::RectangleShape getBody(){return cuerpo;}
    sf::Vector2f posDestino(){return PosDestino;}

    

    

    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;
    sf::Vector2u fila;
    bool nopulsarCheck=false;
    float speed= 0;
    int accion;
    int tipo = 0;
    
    sf::Vector2f PosDestino;

   
};