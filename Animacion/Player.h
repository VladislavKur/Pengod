#include <SFML/Graphics.hpp>
#include "Animacion.h"

class Player{
    public:
    Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float cambioImagen, float speed);
    ~Player();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);


    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;

    unsigned int fila;
    float speed;

};