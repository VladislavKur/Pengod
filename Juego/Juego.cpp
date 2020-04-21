
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
void Juego::update(float deltatime){

    for(unsigned int k = 0; k < listaEnemigos.size();k++) {
      for(unsigned int n = 0; n < listaEnemigos[k].size();n++) {
        
        if(listaEnemigos[k][n] == nullptr) continue;
            listaEnemigos[k][n]->Update(deltatime);

       
    
      }
    }
    for(unsigned int k = 0; k < listaBloque.size();k++) {
      for(unsigned int n = 0; n < listaBloque[k].size();n++) {
       

        if(listaBloque[k][n] == nullptr) continue;
            //listaBloque[k][n]->Update(deltatime,false, player);
    
      }
    }

    


}

int Juego::BloqueBloqueColision(Player * player){
    int dir = 0;
    int dirPlayer = player->getAcciones();
    float xb =0, yb = 0, xe = 0, ye = 0;
    for(unsigned int i = 0; i< listaBloque.size();i++){
        for(unsigned int j = 0; j<listaBloque[i].size();j++){
            if(listaBloque[i][j]->getMov() == true){

            
                /*for(unsigned int n = 0; i< listaBloque.size();i++){
                    for(unsigned int m = 0; j<listaBloque[i].size();j++){
                        if(listaBloque[i][j]->getBody().getGlobalBounds().intersects(listaBloque[n][m]->getBody().getGlobalBounds())){

                            xe = (int) listaBloque[i][j]->getBody().getPosition().x/32;
                            ye = (int) listaBloque[i][j]->getBody().getPosition().y/32;

                            xb = (int) listaBloque[n][m]->getBody().getPosition().x/32;
                            yb = (int) listaBloque[n][m]->getBody().getPosition().y/32;

                            if(xe-xb != 0 && ye-yb == 0) dir = xe - xb; //bloque a la izq == 1 ||bloque derecha == -1
                            if(ye-yb != 0 && xe-xb == 0) dir = ye - yb; //bloque a la arriba == 1 || bloque abajo == -1
                            return dir;

                        }
                    }//forn
                }//forM
                */
            }
        }//forj
    }//fori
    return dir;
}

Juego* Juego::instance(){

    if(pinstance == 0){

        pinstance = new Juego();

    }

    return(pinstance);
}

int Juego::EnemigoBloqueColision(){

    int dir = 0;
    float xb =0, yb = 0, xe = 0, ye = 0;
    for(unsigned int i = 0; i< listaBloque.size();i++){
        for(unsigned int j = 0; j<listaBloque[i].size();j++){

            if(listaBloque[i][j]->getBody().getGlobalBounds().intersects(listaEnemigos[i][j]->getBody().getGlobalBounds())){
                    xb = (int) listaBloque[i][j]->getBody().getPosition().x/32;
                    yb = (int) listaBloque[i][j]->getBody().getPosition().y/32;

                    xe = (int) listaEnemigos[i][j]->getBody().getPosition().x/32;
                    ye = (int) listaEnemigos[i][j]->getBody().getPosition().y/32;

                    if(xe-xb != 0 && ye-yb == 0) dir = xe - xb; //bloque a la izq == 1 ||bloque derecha == -1
                    if(ye-yb != 0 && xe-xb == 0) dir = ye - yb; //bloque a la arriba == 1 || bloque abajo == -1
                return dir;
             }
        }
    }//fori

    return dir;
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
    rlistaBloque.clear();

     sf::Texture *text = new sf::Texture;
     std::vector<Bloque *> auxB;
      text->loadFromFile("resources/CuboDeHielo.png");
    int sad= rand()%8;
    for(int i = 1; i <= 13;i++){
        for(int j = 1; j<= 15;j++){
            if(i!= 7 || j != 8){ // PREGUNTAR A FIDEL QUE MIERDAS PASA, ESTO HACE QUE NO HAYA BLOQUE EN EL 1,1 SIN SENTIDO CON OPERADOR ||
            if(sad < 3){
                 // std::cout << i <<"," << j<< "rand -->"<< sad<<std::endl;
                auxB.push_back(new Bloque (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j),0));
            }else auxB.push_back(NULL);
            sad= rand()%8;
        }
        }
        listaBloque.push_back(auxB);
        rlistaBloque.push_back(auxB);
        auxB.clear();
    }
}
void Juego::DrawBloques(sf::RenderWindow &window){

     for(unsigned int i = 0; i < listaBloque.size();i++){
        for(unsigned int j = 0; j < listaBloque[i].size();j++){
        if(listaBloque[i][j]!= nullptr){
        listaBloque[i][j]->Draw(window);
        std::cout << listaBloque[i][j]->getBody().getPosition().x/32 <<" , " << listaBloque[i][j]->getBody().getPosition().y/32 << " BLOQUES" << std::endl;
        }
        }
    }
    
}
void Juego::crearEnemigos(){
    rlistaEnemigos.clear();
     sf::Texture *text = new sf::Texture;
     std::vector<Enemigo *> auxE;
      text->loadFromFile("resources/pengoybees.png");
      int ran=rand()%12;
    int contadro = 0;
    //while(contadro < 100)
    for(int i = 1; i <= 13;i++){
        for(int j = 1; j<= 15;j++){
            
            
                    if(ran == 0 ){
                         if((i != 1 || j != 1 ) && (i!= 7 || j != 8)){
                        
                        if(contadro < 4 && listaBloque[i-1][j-1] == NULL){
                            
                        auxE.push_back(new Enemigo (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j)));
                        
                        contadro++;

                        }else auxE.push_back(nullptr);
                    }

                }
            

             ran = rand()%12;
        }
        listaEnemigos.push_back(auxE);
        rlistaEnemigos.push_back(auxE);
        auxE.clear();
    }
}
void Juego::DrawEnemigos(sf::RenderWindow &window){
    int contador = 0;
    for(unsigned int i = 0; i < listaEnemigos.size();i++){
        for(unsigned int j = 0; j < listaEnemigos[i].size();j++){
            if(listaEnemigos[i][j]!= nullptr){
                listaEnemigos[i][j]->Draw(window);
                std::cout << listaEnemigos[i][j]->getBody().getPosition().x/32 <<" , " << listaEnemigos[i][j]->getBody().getPosition().y/32 << " ENEMIGOS ->" << contador<<std::endl;
        }}
    }
    
}
void Juego::Draw(sf::RenderWindow &window){
    Mapa * mundo = Mapa::instance(); 
    mundo->draw(window);

 }



void Juego::Borrar(){
     listaEnemigos.clear(); 
     listaBloque.clear();
       
}
void Juego::Reinicio(sf::RenderWindow &window){
    std::vector<Enemigo *> auxE;
    std::vector<Bloque *> auxB;

    Borrar();
    for(unsigned int i = 0; i< rlistaBloque.size();i++){
        for(unsigned int j = 0; j < rlistaBloque[i].size();j++){
            if(rlistaBloque[i][j] != nullptr){
                auxB.push_back(rlistaBloque[i][j]);
                
            }else{
                auxB.push_back(NULL);
            }
        }
        listaBloque.push_back(auxB);
        auxB.clear();
    }
     for(unsigned int i = 0; i< rlistaEnemigos.size();i++){
        for(unsigned int j = 0; j < rlistaEnemigos[i].size();j++){
            if(rlistaEnemigos[i][j] != nullptr){
                auxE.push_back(rlistaEnemigos[i][j]);
                
            }else{
                auxE.push_back(NULL);
            }
        }
        listaEnemigos.push_back(auxE);
        auxE.clear();
    }
    DrawBloques(window);
    DrawEnemigos(window);
}
void Juego::Next(sf::RenderWindow &window){
    Borrar();crearBloques();crearEnemigos();
    DrawBloques(window);
    DrawEnemigos(window);
}


