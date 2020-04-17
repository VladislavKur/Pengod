#pragma once
#include "Juego.h"
//#include <stdlib.h>
//#include <time.h>


Juego* Juego::pinstance = 0;

Juego::Juego(){ //WIP FUNCION CARGARNIVEL
    Mapa * mundo = Mapa::instance(); 
    mundo->cargarmapa("mapaxml/MapaBaseF.tmx");
    mundo->hacerSprites();
}

Juego* Juego::instance(){

    if(pinstance == 0){

        pinstance = new Juego();

    }

    return(pinstance);
}



bool Juego::ComprobarMov(float pos){
    if((((int)pos+32)%32 <= (((int)pos+32)%32)+0.01) 
         && ((int)pos+32)%32 >= (((int)pos+32)%32)-0.01){
             
            return true;
         }


return false;
}
int Juego::MovAleatorio(){

    int res=0;
    
    
    return res;
}

void Juego::Draw(sf::RenderWindow &window){
    Mapa * mundo = Mapa::instance(); 
    mundo->draw(window);

 }

