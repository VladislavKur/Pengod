
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
void Juego::update(float deltatime, Player * player){

    for(unsigned int k = 0; k < listaEnemigos.size();k++) {
      for(unsigned int n = 0; n < listaEnemigos[k].size();n++) {
        
        if(listaEnemigos[k][n] == nullptr) continue;
            listaEnemigos[k][n]->Update(deltatime);

       
    
      }
    }
    for(unsigned int k = 0; k < listaBloque.size();k++) {
      for(unsigned int n = 0; n < listaBloque[k].size();n++) {
       

        if(listaBloque[k][n] == nullptr) continue;
            listaBloque[k][n]->Update(deltatime,false, player);
    
      }
    }

    sf::Vector2f coord(-1,-1);
    
    std::vector<std::vector<Bloque *>>lista = getListaBloque();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        Bloque* bloq;
        
        coord = BloqueBloqueColision(player);
        coord.x = (int)coord.x;
        coord.y = (int)coord.y;
       if(coord.x > -1 && coord.y >-1 && coord.x < 14 && coord.y < 16) 
       if(lista[coord.x][coord.y] != nullptr){
       //std::cout << cuerpo.getPosition().x << ", " << cuerpo.getPosition().y << std::endl;
       }
        }
    


}


sf::Vector2f Juego::BloqueBloqueColision(Player * player){
    
    int dirPlayer = player->getAcciones(); // 0 pengo arriba 1 pengo derecha 2 pengo abajo 3 pengo derecha (dir opuesta a la normal)
    sf::Vector2f res(-1,-1);
    
    int i = player->getBody().getPosition().x/32-1;
    int j = player->getBody().getPosition().y/32-1;
    //std::cout << i <<", " << j << std::endl;
    
            switch (dirPlayer)
            {
            case 0: if(listaBloque[i][j+1] != NULL && listaBloque[i][j+2] != NULL){ // bloque se mueve hacia abajo
                    //std::cout << listaBloque[i][j]->getBody().getPosition().x/32 << ", " << listaBloque[i][j]->getBody().getPosition().y/32 <<std::endl;
                    delete listaBloque[i][j+1]; listaBloque[i][j+1] =NULL;
                    }else{

                        if(listaBloque[i][j+1] != NULL){
                            for(unsigned int r = j+2; r < listaBloque[i].size();r++){
                                if(listaBloque[i][r] == NULL){
                                listaBloque[i][j+1]->setAccion(0);
                                res.x = listaBloque[i][j+1]->getBody().getPosition().x/32;
                                res.y = listaBloque[i][j+1]->getBody().getPosition().y/32;
                                }
                            }

                        }
                    }
                break;
            case 1: if(listaBloque[i-1][j] != NULL && listaBloque[i-2][j]!=NULL){ //bloque se mueve hacia izq
             //std::cout << listaBloque[i][j]->getBody().getPosition().x/32 << ", " << listaBloque[i][j]->getBody().getPosition().y/32 <<std::endl;
                    delete listaBloque[i-1][j]; listaBloque[i-1][j] =NULL;
                    }else{
                         if(listaBloque[i-1][j] != NULL){
                            for(int r = i-2; r >= 0;r--){
                                if(listaBloque[i][r] == NULL){
                                    listaBloque[i-1][j]->setAccion(1);
                                    res.x = listaBloque[i-1][j]->getBody().getPosition().x/32;
                                    res.y = listaBloque[i-1][j]->getBody().getPosition().y/32;
                                }
                                
                            }

                        }
                        
                    }
                break;
            case 2: if(listaBloque[i][j-1] != NULL && listaBloque[i][j-2] != NULL){ //bloque se mueve hacia arriba
             //std::cout << listaBloque[i][j]->getBody().getPosition().x/32 << ", " << listaBloque[i][j]->getBody().getPosition().y/32 <<std::endl;
                    delete listaBloque[i][j-1]; listaBloque[i][j-1] =NULL;
                    }else{
                         if(listaBloque[i][j-1] != NULL){
                            for(int r = j-2; r >= 0;r--){
                                if(listaBloque[i][r] == NULL){
                                    listaBloque[i][j-1]->setAccion(2);
                                    
                                    res.x = listaBloque[i][j-1]->getBody().getPosition().x/32;
                                    res.y = listaBloque[i][j-1]->getBody().getPosition().y/32;
                                }
                                
                            }

                        }
                        
                    }
                break;
            case 3: if(listaBloque[i+1][j] != NULL && listaBloque[i+2][j] != NULL){ //bloque se mueve hacia derecha
                    //std::cout << listaBloque[i][j]->getBody().getPosition().x/32 << ", " << listaBloque[i][j]->getBody().getPosition().y/32 <<std::endl;
                    delete listaBloque[i+1][j]; listaBloque[i+1][j] =NULL;
                    }else{
                         if(listaBloque[i+1][j] != NULL){
                            for(unsigned int r = i+2; r < listaBloque.size();r++){
                                if(listaBloque[i][r] == NULL){
                                    listaBloque[i+1][j]->setAccion(3);
                                    res.x = listaBloque[i+1][j]->getBody().getPosition().x/32;
                                    res.y = listaBloque[i+1][j]->getBody().getPosition().y/32;
                                }
                                
                            }

                        }
                        
                    }
                break;
            
            default:
                break;
            }


      
    return res;
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


