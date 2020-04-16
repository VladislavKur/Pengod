#include "Juego.h"


Juego* Juego::pinstance = 0;

Juego::Juego(){ //WIP FUNCION CARGARNIVEL
    Mapa * mundo = Mapa::instance(); 
    mundo->cargarmapa("mapaxml/MapaBase2.tmx");
    mundo->hacerSprites();
}

Juego* Juego::instance(){

    if(pinstance == 0){

        pinstance = new Juego();

    }

    return(pinstance);
}


void Juego::Draw(sf::RenderWindow &window){
    Mapa * mundo = Mapa::instance(); 
    mundo->draw(window);

 }

