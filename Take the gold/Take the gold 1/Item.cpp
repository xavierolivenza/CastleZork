#include "Item.h"

Item::Item(){
}

Item::Item(const char* name, const char* description, Room* item_room, int attack, int defense, int uses, bool inventory, bool equipped, bool equipable, bool inside_cupboard, bool inside_backpack, EntityType type) : Entity(name, description, type), item_room(item_room), attack(attack), defense(defense), uses(uses), inventory(inventory), equipped(equipped), equipable(equipable), inside_cupboard(inside_cupboard), inside_backpack(inside_backpack){
}

Item::~Item(){
}