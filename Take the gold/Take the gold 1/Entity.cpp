#include "Entity.h"

Entity::Entity(){
}

Entity::Entity(const char* name, const char *description, EntityType type) :name(name), description(description), type(type){
}

Entity::~Entity(){
}