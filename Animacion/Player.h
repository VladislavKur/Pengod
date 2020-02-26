#include <SFML/Graphics.hpp>
#include "Animacion.h"

class Player{
    public:
    Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float cambioImagen, float speed, int accion);
    ~Player();
    void Update(float deltaTime, int accion);
    void Draw(sf::RenderWindow &window);
    void setmover(int accion);
    

    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;


    
    unsigned int fila;
    float speed;

};