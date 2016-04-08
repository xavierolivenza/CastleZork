#include <stdio.h>
#include <string.h>
#include "Player.h"
#include "World.h"
#include "Exits.h"

Player::Player(){
}
Player::~Player(){
}

int Player::check_firstcommand(const String& firstcommand)const{
	if (firstcommand == "look"){
		return LOOK;
	}
	else if (firstcommand == "go"){
		return GO;
	}
	else if (firstcommand == "open"){
		return OPEN;
	}
	else if (firstcommand == "close"){
		return CLOSE;
	}
	else if ((firstcommand == "quit") || (firstcommand == "q")){
		return QUIT;
	}
	else if ((firstcommand == "help") || (firstcommand == "h")){
		return HELP;
	}
	// ---------------------------------------------------------------------------------------------------------------
	//Detection commands with 1 word
	else if ((firstcommand == "north") || (firstcommand == "n")){
		return NORTH;
	}
	else if ((firstcommand == "east") || (firstcommand == "e")){
		return EAST;
	}
	else if ((firstcommand == "south") || (firstcommand == "s")){
		return SOUTH;
	}
	else if ((firstcommand == "west") || (firstcommand == "w")){
		return WEST;
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (firstcommand == "pick"){
		return PICK;
	}
	else if (firstcommand == "drop"){
		return DROP;
	}
	else if ((firstcommand == "inventory") || (firstcommand == "inv") || (firstcommand == "i")){
		return INVENTORY;
	}
	else if (firstcommand == "equipped"){
		return EQUIPPED;
	}
	else if (firstcommand == "equip"){
		return EQUIP;
	}
	else if (firstcommand == "unequip"){
		return UNEQUIP;
	}
	else if (firstcommand == "put"){
		return PUT;
	}
	else if (firstcommand == "get"){
		return GET;
	}
	else if ((firstcommand == "stats") || (firstcommand == "s")){
		return STATS;
	}
}

int Player::check_secondcommand(const String& secondcommand)const{
	if ((secondcommand == "north") || (secondcommand == "n")){
		return NORTH;
	}
	else if ((secondcommand == "east") || (secondcommand == "e")){
		return EAST;
	}
	else if ((secondcommand == "south") || (secondcommand == "s")){
		return SOUTH;
	}
	else if ((secondcommand == "west") || (secondcommand == "w")){
		return WEST;
	}
	if (secondcommand == "katana"){
		return KATANA;
	}
	else if (secondcommand == "gas mask"){
		return GASMASK;
	}
	else if (secondcommand == "treasure"){
		return TREASURE;
	}
	else if (secondcommand == "venom gas grenade"){
		return GRANADE;
	}
	else if (secondcommand == "sword"){
		return SWORD;
	}
	else if (secondcommand == "shield"){
		return SHIELD;
	}
	else if (secondcommand == "explosive"){
		return EXPLOSIVE;
	}
}

int Player::check_thirdcommand(const String& firstcommand, const String& thirdcommand)const{
	if ((firstcommand == "put") && (thirdcommand == "into")){
		return INTO;
	}
	else if ((firstcommand == "get") && (thirdcommand == "from")){
		return FROM;
	}
}

int Player::check_fourthcommand(const String& fourthcommand)const{
	if (fourthcommand == "cupboard"){
		return CUPBOARD;
	}
}

int Player::check_numcommands(const String& firstcommand, const String& secondcommand, const String& thirdcommand, const String& fourthcommand)const{
	int command_words = 0;
	if (firstcommand.c_capacity() != 1){
		command_words++;
		if (secondcommand.c_capacity() != 1){
			command_words++;
			if (thirdcommand.c_capacity() != 1){
				command_words++;
				if (fourthcommand.c_capacity() != 1){
					command_words++;
				}
			}
		}
	}
	return command_words;
}