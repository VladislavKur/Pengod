#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libClases PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Player.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Animacion.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Enemigo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Bloque.cpp"
    
)

#Y donde se encuentran los .h
target_include_directories(libClases PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}"
)

