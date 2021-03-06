
#include "Juego.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>



Juego* Juego::pinstance = 0;

Juego::Juego(){ //WIP FUNCION CARGARNIVEL
    Mapa * mundo = Mapa::instance(); 
    mundo->cargarmapa("mapaxml/MapaBaseF.tmx");
    mundo->hacerSprites();
    crearBordes();
    crearBloques();
    crearEnemigos();

    bcoord.x =-1;
    bcoord.y = -1;
    bcoordF.y = -1;
    bcoordF.x = -1;
    
    text = new sf::Texture;
    text->loadFromFile("resources/pengoybees.png");
   
   
}
void Juego::morir(Player * player, float deltatime, sf::RenderWindow &window){
                    player->setPerdVid(true);
                    if(player->PerderVida(window)){
                        player->setVidas(3);
                        player->setAccion(-1);
                        player->setVelx(false);player->setVely(false);
                        player->setPosDespues(7*32,8*32);
                        player->setPerdVid(true);
                       
                    }else {
                        player->setAccion(-1);
                        player->setVelx(false);player->setVely(false);
                        player->setPosDespues(7*32,8*32);
                        player->setPerdVid(true);
                       
                    } 
                    
}
void Juego::update(float deltatime, Player * player,sf::RenderWindow &window){
   
   
    timer += deltatime;
    timer2 += deltatime;
    for(unsigned int k = 0; k < listaEnemigos.size();k++) 
      for(unsigned int n = 0; n < listaEnemigos[k].size();n++) 
        if(listaEnemigos[k][n] != nullptr)
            if(timer >= 1.5 && !player->getDios()){
                if(player->getBody().getGlobalBounds().intersects(listaEnemigos[k][n]->getBody().getGlobalBounds())){
                    timer = 0;
                    morir(player,deltatime,window);
                    
                }else{
                     player->setPerdVid(false);
                     
                } 
                
            }
    player->Update(player->getAcciones(),deltatime);
    
    for(unsigned int k = 0; k < listaEnemigos.size();k++) {
      for(unsigned int n = 0; n < listaEnemigos[k].size();n++) {
        
        if(listaEnemigos[k][n] != nullptr){
            
            listaEnemigos[k][n]->Update(deltatime);
            
        }

   
    Enemigo * newEnemigo;
    timerEnemigos += deltatime;
    if(timerEnemigos > 3000) // entorno a 15s aprox para que reaparezcan los snoobees
    if(!listaBloque.empty() && !listaEnemigos.empty())
    for(unsigned int i = 1; i < listaBloque.size() && cantEnem < 4;i++){
        for(unsigned int j = 1; j < listaBloque[i].size() && cantEnem < 4;j++){
            std:: cout << listaEnemigos.size()<< ", " << listaEnemigos[i].size() << " dsadsa "<< listaBloque.size() << ", " << listaBloque[i].size() <<std::endl;;
            if(listaBloque[i-1][j-1] == NULL 
            && listaEnemigos[i-1][j-1] == NULL && 
            (int)player->getBody().getPosition().x/32 != i && (int)player->getBody().getPosition().y/32 != j){
                
                newEnemigo = new Enemigo (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j));
                if (newEnemigo != nullptr){
                    listaEnemigos[i-1][j-1] = newEnemigo;
                    timerEnemigos = 0;
                    cantEnem++;
                } 
            }

                
        }
    }
        

    if(cantEnem == 0) Next(window);    

       
    
      }
    }
    for(unsigned int k = 0; k < listaBloque.size();k++) {
      for(unsigned int n = 0; n < listaBloque[k].size();n++) {
       

        if(listaBloque[k][n] == nullptr) continue;
            listaBloque[k][n]->Update(deltatime,false, player);
    
      }
    }

    
    bcoord = BloqueBloqueColision(player);
        bcoord.x = (int)bcoord.x;
        bcoord.y = (int)bcoord.y;
        Bloque * aux = nullptr;
        /*if(bcoordF.x > -1 && bcoordF.y >-1 && bcoordF.x < 14 && bcoordF.y < 16 && bcoord.x > -1 && bcoord.y >-1 && bcoord.x < 14 && bcoord.y < 16){
            aux = listaBloque[bcoord.x][bcoord.y];
            listaBloque[bcoord.x][bcoord.y] = nullptr;
            listaBloque[bcoordF.x][bcoordF.y] = aux;
            
            if(bcoordF.x == bcoord.x && bcoordF.y == bcoord.y){
              
               if( listaBloque[bcoordF.x][bcoordF.y] != nullptr) {
                
                listaBloque[bcoordF.x][bcoordF.y]->setAccion(-1);
                
            }
        
            }
        }*/
    
    
    if(timer2 >= 0.5)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        timer2= 0;
        
        bcoordF = BloqueBloqueColisionF(player);
        
        
        bcoordF.x = (int)bcoordF.x;
        bcoordF.y = (int)bcoordF.y;
        
        }
    
    

 EnemigoBloqueColision();
}


sf::Vector2f Juego::BloqueBloqueColisionF(Player * player){
    
    int dirPlayer = player->getAcciones(); // 0 pengo arriba 1 pengo derecha 2 pengo abajo 3 pengo derecha (dir opuesta a la normal)
    sf::Vector2f res(-1,-1);
    
    int i = player->getBody().getPosition().x/32-1;
    int j = player->getBody().getPosition().y/32-1;
    //std::cout << i <<", " << j << std::endl;
    
            switch (dirPlayer)
            {
            case 0:if(i> 0 && j+1>0 && i < 14 && j+1<15 && j+2 < 14 && j+2 > 0)
                    if(listaBloque[i][j+1] != NULL && listaBloque[i][j+2] != NULL){ // bloque se mueve hacia abajo
                    //std::cout << listaBloque[i][j]->getBody().getPosition().x/32 << ", " << listaBloque[i][j]->getBody().getPosition().y/32 <<std::endl;
                    delete listaBloque[i][j+1]; listaBloque[i][j+1] =NULL;
                    }else{
                        if(i> 0 && j+1>0 && i < 14 && j+1<14)
                        if(listaBloque[i][j+1] != NULL ){
                            for(unsigned int r = j+2; r < listaBloque[i].size();r++){
                                 if(r > 0 && r< 16)
                                if(listaBloque[i][r] != NULL){
                                listaBloque[i][j+1]->setAccion(0);
                                listaBloque[i][j+1]->setMov(true);
                                res.x = listaBloque[i][r]->getBody().getPosition().x/32;
                                res.y = listaBloque[i][r]->getBody().getPosition().y/32-1;
                                
                                }
                            }

                        }
                    }
                break;
            case 1:  if(i-1> 0 && j>0 && i-1 < 15 && j<15 && i-2 < 16)
                    if(listaBloque[i-1][j] != NULL && listaBloque[i-2][j]!=NULL){ //bloque se mueve hacia izq
             //std::cout << listaBloque[i][j]->getBody().getPosition().x/32 << ", " << listaBloque[i][j]->getBody().getPosition().y/32 <<std::endl;
                    delete listaBloque[i-1][j]; listaBloque[i-1][j] =NULL;
                    }else{
                         if(i-1> 0 && j>0 && i-1 < 15 && j<15)
                         if(listaBloque[i-1][j] != NULL ){
                            for(int r = i-2; r >= 0;r--){
                                 if(r > 0 && r< 16)
                                if(listaBloque[r][j] != NULL){
                                    listaBloque[i-1][j]->setAccion(1);
                                    listaBloque[i-1][j]->setMov(true);
                                    res.x = listaBloque[r][j]->getBody().getPosition().x/32+1;
                                    res.y = listaBloque[r][j]->getBody().getPosition().y/32;
                                   
                                }
                                
                            }

                        }
                        
                    }
                break;
            case 2: if(i> 0 && j-1>0 && i < 14 && j-1<16 && j-2 < 17)
                    if(listaBloque[i][j-1] != NULL && listaBloque[i][j-2] != NULL){ //bloque se mueve hacia arriba
             //std::cout << listaBloque[i][j]->getBody().getPosition().x/32 << ", " << listaBloque[i][j]->getBody().getPosition().y/32 <<std::endl;
                    delete listaBloque[i][j-1]; listaBloque[i][j-1] =NULL;
                    }else{
                        if(i> 0 && j-1>0 && i < 14 && j-1<16)
                         if(listaBloque[i][j-1] != NULL ){
                            for(int r = j-2; r >= 0;r--){
                                 if(r > 0 && r< 16)
                                if(listaBloque[i][r] != NULL){
                                    listaBloque[i][j-1]->setAccion(2);
                                    listaBloque[i][j-1]->setMov(true);
                                     res.x = listaBloque[i][r]->getBody().getPosition().x/32;
                                    res.y = listaBloque[i][r]->getBody().getPosition().y/32+1;
                                   
                                }
                                
                            }

                        }
                        
                    }
                break;
            case 3: if(i+1> 0 && j>0 && i+1 < 13 && j<15 && i+2 < 12)
                    if(listaBloque[i+1][j] != NULL && listaBloque[i+2][j] != NULL){ //bloque se mueve hacia derecha
                    //std::cout << listaBloque[i][j]->getBody().getPosition().x/32 << ", " << listaBloque[i][j]->getBody().getPosition().y/32 <<std::endl;
                    delete listaBloque[i+1][j]; listaBloque[i+1][j] =NULL;
                    }else{
                        if(i+1> 0 && j>0 && i+1 < 13 && j<15)
                         if(listaBloque[i+1][j] != NULL){
                            for(unsigned int r = i+2; r < listaBloque.size();r++){
                                 if(r > 0 && r< 16)
                                if(listaBloque[r][j] != NULL){
                                    listaBloque[i+1][j]->setAccion(3);
                                    listaBloque[i+1][j]->setMov(true);
                                    res.x = listaBloque[r][j]->getBody().getPosition().x/32-1;
                                    res.y = listaBloque[r][j]->getBody().getPosition().y/32;
                                    
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
sf::Vector2f Juego::BloqueBloqueColision(Player * player){
    
    int dirPlayer = player->getAcciones(); // 0 pengo arriba 1 pengo derecha 2 pengo abajo 3 pengo derecha (dir opuesta a la normal)
    sf::Vector2f res(-1,-1);
    
    int i = player->getBody().getPosition().x/32-1;
    int j = player->getBody().getPosition().y/32-1;
    //std::cout << i <<", " << j << std::endl;
    
            switch (dirPlayer)
            {
            case 0: 
                         if(i> 0 && j+1>0 && i < 14 && j+1<14){
                            if(listaBloque[i][j+1] != NULL){
                            for(unsigned int r = j+2; r < listaBloque[i].size();r++){
                                if(r > 0 && r< 16)
                                if(listaBloque[i][r] == NULL){
                                
                                res.x = listaBloque[i][j+1]->getBody().getPosition().x/32;
                                res.y = listaBloque[i][j+1]->getBody().getPosition().y/32;
                                 
                                break;
                                }
                            }

                        }else break;
                         }else break;
                        
                    
                break;
            case 1:     if(i-1> 0 && j>0 && i-1 < 15 && j<15){
                            if(listaBloque[i-1][j] != NULL){
                            for(int r = i-2; r >= 0;r--){
                                if(r > 0 && r< 16)
                                if(listaBloque[i][r] == NULL){
                                   
                                    res.x = listaBloque[i-1][j]->getBody().getPosition().x/32;
                                    res.y = listaBloque[i-1][j]->getBody().getPosition().y/32;
                                    
                                    break;
                                }
                                
                            }

                        }else break;
                        
            }else break;
                        
                    
                break;
            case 2:      if(i> 0 && j-1>0 && i < 14 && j-1<16){
                            if(listaBloque[i][j-1] != NULL){
                            for(int r = j-2; r >= 0;r--){
                                if(r > 0 && r< 16)
                                if(listaBloque[i][r] == NULL){
                               
                                    
                                    res.x = listaBloque[i][j-1]->getBody().getPosition().x/32;
                                    res.y = listaBloque[i][j-1]->getBody().getPosition().y/32;
                                   
                                   
                                    break;
                                }
                                
                            }

                        }else break;
                        
            }else break;
                         
                    
                break;
            case 3:  if(i+1> 0 && j>0 && i+1 < 13 && j<15){
                    if(listaBloque[i+1][j] != NULL){
                            for(unsigned int r = i+2; r < listaBloque.size();r++){
                                if(r > 0 && r< 16)
                                if(listaBloque[i][r] == NULL){
                                    
                                    res.x = listaBloque[i+1][j]->getBody().getPosition().x/32;
                                    res.y = listaBloque[i+1][j]->getBody().getPosition().y/32;
                                    
                                    break;
                                }
                                
                            }

                        }else break;
                    }else break;
                         
                        
                    
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

bool Juego::EnemigoBloqueColision(){
    Bloque*  pBloque;
    Enemigo * pEnemigo;
 
    
     for(unsigned int n = 0; n < listaEnemigos.size();n++){
            for(unsigned int m = 0; m <listaEnemigos[n].size();m++){
                if(listaEnemigos[n][m] != nullptr ){
                    pEnemigo = listaEnemigos[n][m];
                    
                } 



        for(unsigned int i = 0; i < listaBloque.size();i++){
            for(unsigned int j = 0; j <listaBloque[i].size();j++){
                if(listaBloque[i][j] != nullptr ){
                    pBloque = listaBloque[i][j];
           
                } 

            
       

                
            
                if(pBloque != nullptr && pEnemigo != nullptr && listaEnemigos[n][m] != nullptr){
                    if(pBloque->getMov() == true && pBloque->getBody().getGlobalBounds().intersects(pEnemigo->getBody().getGlobalBounds())){
                        delete pEnemigo; pEnemigo = nullptr; listaEnemigos[n][m] = pEnemigo;
                        cantEnem--;
                        timerEnemigos = 0;
                    }
                }
                if(pBloque != nullptr && pEnemigo != nullptr && listaEnemigos[n][m] != nullptr){    
                    if(!pBloque->getMov()){
                        if(pBloque->getBody().getGlobalBounds().intersects(pEnemigo->getBody().getGlobalBounds())){// si salta este error, recargar, no se porque 
                                                                 //pBloque me sale null cuando lo compruebo antes  2 veces
                        }
                    }
                }
            
            }

        }
       

    
        }
    }//fin f
    return false;
}
bool Juego::PlayerBordeColision(Player * jugador, int dir){
     sf:: Vector2f posBloque;
    sf::Vector2f posant;
    
   // 0 abajo 1 izq 2 up 3 der
    
    
    for(unsigned int i = 0; i < listaBorde.size();i++){
        for(unsigned int j = 0; j <listaBorde[i].size();j++){

       if(listaBorde[i][j] != nullptr){
           posBloque = listaBorde[i][j]->getBody().getPosition();

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
bool Juego::PlayerBloqueColision(Player * jugador, int dir){
    sf:: Vector2f posBloque;
    sf::Vector2f posant;
    
   // 0 abajo 1 izq 2 up 3 der
    
    
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

void Juego::crearBordes(){
     
    
     sf::Texture *text = new sf::Texture;
     std::vector<Bloque *> auxB;
      text->loadFromFile("resources/CuboDeDiamante.png");
    
    for(int i = 0; i <= 14;i++){
        for(int j = 0; j<= 16;j++){
            if( i == 0 || j == 0 || i == 14 || j == 16){
            
                 // std::cout << i <<"," << j<< "rand -->"<< sad<<std::endl;
                auxB.push_back(new Bloque (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j),1));
            
            
        }
        }
        listaBorde.push_back(auxB);
        
        auxB.clear();
    }
}
void Juego::DrawBordes(sf::RenderWindow &window){

     for(unsigned int i = 0; i < listaBorde.size();i++){
        for(unsigned int j = 0; j < listaBorde[i].size();j++){
        if(listaBorde[i][j]!= nullptr){
        listaBorde[i][j]->Draw(window);
       
        }
        }
    }
    
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
                auxB.push_back(new Bloque (nullptr, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j),0));
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
void Juego::DrawrBloques(sf::RenderWindow &window){

     for(unsigned int i = 0; i < rlistaBloque.size();i++){
        for(unsigned int j = 0; j < rlistaBloque[i].size();j++){
        if(rlistaBloque[i][j]!= nullptr){
            rlistaBloque[i][j]->Draw(window);
       
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
    
    //while(contadro < 100)
    for(int i = 1; i <= 13;i++){
        for(int j = 1; j<= 15;j++){
            
                 if((i != 1 || j != 1 ) && (i!= 7 || j != 8)){
                    if(ran == 0 ){
                        
                        
                        if(cantEnem < 4 && listaBloque[i-1][j-1] == NULL){
                            
                        auxE.push_back(new Enemigo (text, sf::Vector2u(40,18),0.25f, sf::Vector2f(i,j)));
                        
                        
                        cantEnem++;

                        }else auxE.push_back(nullptr);
                    }else auxE.push_back(NULL);

                }
            

             ran = rand()%12;
        }
        listaEnemigos.push_back(auxE);
        rlistaEnemigos.push_back(auxE);
        auxE.clear();
    }
}
void Juego::DrawEnemigos(sf::RenderWindow &window){
    
    for(unsigned int i = 0; i < listaEnemigos.size();i++){
        for(unsigned int j = 0; j < listaEnemigos[i].size();j++){
            if(listaEnemigos[i][j]!= nullptr){
                listaEnemigos[i][j]->Draw(window);
                
        }}
    }
    
}
void Juego::DrawrEnemigos(sf::RenderWindow &window){
    
    for(unsigned int i = 0; i < rlistaEnemigos.size();i++){
        for(unsigned int j = 0; j < rlistaEnemigos[i].size();j++){
            if(rlistaEnemigos[i][j]!= nullptr){
                rlistaEnemigos[i][j]->Draw(window);
                
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
bool Juego::Reinicio(Player * player,sf::RenderWindow &window){
     std::cout << "REINICIO" << std::endl;
    Bloque *BloqueAux;
    Enemigo * EnemigoAux;

    sf::Vector2f pos;
    
    std::vector<Enemigo *> auxE;
    std::vector<Bloque *> auxB;
    player->getBody().setPosition(7*32,8*32);
    Borrar();
    DrawrBloques(window);
    DrawrEnemigos(window);
    player->Draw(window);
    
   
    listaBloque.clear();
    listaEnemigos.clear();
    
    return true;
  
}
bool Juego::Next(sf::RenderWindow &window){
    Borrar();
    cantEnem = 0;
    crearBloques();
    
    crearEnemigos();
    DrawBloques(window);
    DrawEnemigos(window);
    return true;
}


