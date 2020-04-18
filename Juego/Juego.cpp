#pragma once
#include "Juego.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>



Juego* Juego::pinstance = 0;

Juego::Juego(){ //WIP FUNCION CARGARNIVEL
    Mapa * mundo = Mapa::instance(); 
    mundo->cargarmapa("mapaxml/MapaBaseF.tmx");
    mundo->hacerSprites();
    crearBloques();
    crearEnemigos();
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


void Juego::crearBloques(){
     sf::Texture *text = new sf::Texture;
      text->loadFromFile("resources/CuboDeHielo.png");
    int sad= rand()%8;
    for(int i = 1; i <= 13;i++){
        for(int j = 1; j<= 15;j++){
               
            if(sad < 3){
                 // std::cout << i <<"," << j<< "rand -->"<< sad<<std::endl;
                listaBloque[i].push_back(new Bloque (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j),0));
            }
            sad= rand()%11;
        }
    }
}

void Juego::DrawBloques(sf::RenderWindow &window){
    
     for(unsigned int i = 0; i < listaBloque.size();i++){
        for(unsigned int j = 0; j < listaBloque[1].size();j++){
       
        listaBloque[i][j]->Draw(window);
    }
    
}

void Juego::crearEnemigos(){
     sf::Texture *text = new sf::Texture;
      text->loadFromFile("resources/pengoybees.png");
      int puto=rand()%10;

    for(int i = 1; i <= 15;i++){
        for(int j = 1; j<= 13;j++){

            //for(unsigned int k = 0; k < listaBloque.size();k++){
                //if(listaBloque[k]->getBody().getPosition().x !=i && listaBloque[k]->getBody().getPosition().y !=j){
                    if(puto == 0 ){

                        if(listaEnemigos.size() < 4 ){
                            
                        listaEnemigos.push_back(new Enemigo (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j)));
                        j++;

                        }
                    }

                //}
            //}

             puto = rand()%10;
        }
    }
}

void Juego::DrawEnemigos(sf::RenderWindow &window){
  
    for(unsigned int i = 0; i < listaEnemigos.size();i++){
        for(unsigned int j = 0; j < listaEnemigos[1].size();j++){
       
        listaEnemigos[i][j]->Draw(window);
    }
    
}























void Juego::Draw(sf::RenderWindow &window){
    Mapa * mundo = Mapa::instance(); 
    mundo->draw(window);

 }

