#include "Item.h"

Item::Item(){
}

Item::Item(const char* s1, const char* s2, Room* s3, const int s4, const int s5, const int s6, const bool s7, const bool s8, const bool s9, const bool s10){
	this->name = s1;
	this->description = s2;
	this->item_room = s3;
	this->attack = s4;
	this->defense = s5;
	this->uses = s6;
	this->inventory = s7;
	this->equipped = s8;
	this->equipable = s9;
	this->inside_cupboard = s10;
}

Item::~Item(){
}