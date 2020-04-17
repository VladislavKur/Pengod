#pragma once
#include <SFML/Graphics.hpp>

class Animacion{

    public:
        Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite);
        ~Animacion();
        void Update(sf::Vector2u Sprites, float deltaTime);
        void setSprite(sf::Vector2u Sprites);
        


        sf::IntRect textureRect;

    private:
        sf::Vector2u cantidadImagenes;
        sf::Vector2u spriteActual;
        

        float tiempoTotalDelta;
        float SwitchTimeSprite;
        bool swit;
};