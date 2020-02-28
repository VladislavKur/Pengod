#include <SFML/Graphics.hpp>
#include "Animacion.h"

class Player{
    public:
    Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite, int movimiento);
    ~Player();
    void Update(int movi, float deltaTime);
    void Draw(sf::RenderWindow &window);

    

    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;
    sf::Vector2u fila;
   
};