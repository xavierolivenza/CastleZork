#include "Item.h"

Item::Item(){
}

Item::Item(const char* s1, const char* s2, Room* s3, const int s4, const int s5, const int s6, const bool s7, const bool s8, const bool s9, const bool s10) : Entity(s1,s2), item_room(s3), attack(s4), defense(s5), uses(s6), inventory(s7), equipped(s8), equipable(s9), inside_cupboard(s10){
}

Item::~Item(){
}