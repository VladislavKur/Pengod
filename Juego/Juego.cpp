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

bool Juego::PlayerBloqueColision(Player * jugador, int dir){
    sf:: Vector2f posBloque;
    sf::Vector2f posant;
    
   // 0 abajo 1 izq 2 up 3 der
    
    std::cout << "asdsad";
    for(unsigned int i = 0; i < listaBloque.size();i++){
        for(unsigned int j = 0; j <listaBloque[i].size();j++){

       if(listaBloque[i][j] != nullptr){
           posBloque = listaBloque[i][j]->getBody().getPosition();

            switch (dir)
            {
            case 0: if((int)posBloque.y == (int)jugador->getBody().getPosition().y+32 && (int)posBloque.x == (int)jugador->getBody().getPosition().x){
                   
                return true;
                    }
                break;
            case 1 :if((int)posBloque.x == (int)jugador->getBody().getPosition().x-32 && (int)posBloque.y == (int)jugador->getBody().getPosition().y){
                
                return true;
                    }
                break;
            case 2: if((int)posBloque.y == (int) jugador->getBody().getPosition().y-32 && (int)posBloque.x == (int)jugador->getBody().getPosition().x){
                
                return true;
                    }
                break;
            case 3: if((int)posBloque.x == (int)jugador->getBody().getPosition().x+32 && (int)posBloque.y == (int)jugador->getBody().getPosition().y){
                
                return true;
                    }
                break;

            
            default:
                break;
            } 
       }
       

        }//fin forj
    }//fin fori
    return false;
}





void Juego::crearBloques(){
     sf::Texture *text = new sf::Texture;
     std::vector<Bloque *> auxB;
      text->loadFromFile("resources/CuboDeHielo.png");
    int sad= rand()%8;
    for(int i = 1; i <= 13;i++){
        for(int j = 1; j<= 15;j++){
            if(i != 1 || j != 1){ // PREGUNTAR A FIDEL QUE MIERDAS PASA, ESTO HACE QUE NO HAYA BLOQUE EN EL 1,1 SIN SENTIDO CON OPERADOR ||
            if(sad < 3){
                 // std::cout << i <<"," << j<< "rand -->"<< sad<<std::endl;
                auxB.push_back(new Bloque (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j),0));
            }else auxB.push_back(NULL);
            sad= rand()%8;
        }
        }
        listaBloque.push_back(auxB);
        auxB.clear();
    }
}

void Juego::DrawBloques(sf::RenderWindow &window){
    
     for(unsigned int i = 0; i < listaBloque.size();i++){
        for(unsigned int j = 0; j < listaBloque[i].size();j++){
        if(listaBloque[i][j]!= nullptr)
        listaBloque[i][j]->Draw(window);
        }
    }
    
}

void Juego::crearEnemigos(){
     sf::Texture *text = new sf::Texture;
     std::vector<Enemigo *> auxE;
      text->loadFromFile("resources/pengoybees.png");
      int ran=rand()%10;
    int contadro = 0;
    while(contadro < 4)
    for(int i = 1; i <= 15;i++){
        for(int j = 1; j<= 13;j++){
            
            
                    if(ran == 0 ){
                        
                        if(contadro < 4 && listaBloque[i][j] == NULL){
                            
                        auxE.push_back(new Enemigo (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j)));
                        j++;
                        contadro++;

                        }else auxE.push_back(nullptr);
                    }

                //}
            //}

             ran = rand()%10;
        }
        listaEnemigos.push_back(auxE);
        auxE.clear();
    }
}

void Juego::DrawEnemigos(sf::RenderWindow &window){
  
    for(unsigned int i = 0; i < listaEnemigos.size();i++){
        for(unsigned int j = 0; j < listaEnemigos[i].size();j++){
       if(listaEnemigos[i][j]!= nullptr)
        listaEnemigos[i][j]->Draw(window);
    }
    }
    
}























void Juego::Draw(sf::RenderWindow &window){
    Mapa * mundo = Mapa::instance(); 
    mundo->draw(window);

 }

