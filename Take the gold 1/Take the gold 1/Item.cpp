#include "Item.h"

Item::Item(){
}

Item::Item(const char* s1, const char* s2, Room* s3, int s4, int s5, int s6, bool s7, bool s8, bool s9, bool s10, bool s11) : Entity(s1,s2), item_room(s3), attack(s4), defense(s5), uses(s6), inventory(s7), equipped(s8), equipable(s9), inside_cupboard(s10), inside_backpack(s11){
}

Item::~Item(){
}