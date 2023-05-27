cmake_minimum_required(VERSION 3.20)
project(pierreFeuilleCiseaux)

# give a name to the project
project(pierreFeuilleCiseaux)

# Ajouter le répertoire contenant les fichiers d'en-tête
include_directories(src)

# Ajouter tous les fichiers sources du répertoire "src"
file(GLOB SOURCES "src/*.cpp")

# Création de l'exécutable
add_executable(pierreFeuilleCiseaux ${SOURCES})
