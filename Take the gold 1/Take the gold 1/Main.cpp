#include <stdio.h>
#include <stdlib.h>
#include "World.h"

int main(){
	String fullcommand("\0"), firstcommand("\0"), secondcommand("\0"), thirdcommand("\0"), fourthcommand("\0");
	int command1 = 0, command2 = 0, command3 = 0, command4 = 0;
	int command_words = 0, i = 0, j = 0;
	int actual_position = 0;

	World world;
	Player commandinput;

	world.CreateWorld();
	printf("Welcome to Take the gold\nThis game is based on Zork for a class project.\nXavier Olivenza\nCITM Terrassa 2015-2016\n\n//------------------------------------------------------------------------//\n// Lore:                                                                  //\n// You are a thief who must steal the treasure of the king in his castle. //\n//------------------------------------------------------------------------//\n\nYou can move using:\n\tn/s/e/w\n\tnorth/east/south/west\n\tgo north/east/south/west/n/s/e/w\nAlso you can use the commands:\n\tlook/l -> to see the description of the room where you are\n\tlook/l + north/east/south/west/n/s/e/w -> to see the description of the\n\tpath\n\topen/close + north/east/south/west/n/s/e/w -> to open/close door\n\tpick + item name -> you can pick items from the ground\n\tdrop + item name -> you can drop items to the ground\n\tequip + item name -> you can equip items\n\tunequip + item name -> you can unequip items\n\tput + item name + into + cupboard -> put item in the cupboard\n\tget + item name + from + cupboard -> get the item from the cupboard\n\tequipped -> to see the objects that the player has equipped\n\tinventory/inv/i -> to see player inventory\n\tstats -> to see player stats\n\thelp/h -> to open the help menu\n\tquit/q -> to quit the game\nLet's start!\n\n");
	do{
		printf("//------------------------------------------------------------//\n");
		
		printf("You are in %s.\n%s\n", world.player->current_room->name.c_str(), world.player->current_room->description.c_str());
		world.dropeditemslook();
		
		fullcommand.getcommand();
		fullcommand.trim();
		fullcommand.tokenize(firstcommand, secondcommand, thirdcommand, fourthcommand);
		command_words = commandinput.check_numcommands(firstcommand, secondcommand, thirdcommand, fourthcommand);
		
		command1 = commandinput.check_firstcommand(firstcommand);
		command2 = commandinput.check_secondcommand(secondcommand);
		command3 = commandinput.check_thirdcommand(firstcommand, thirdcommand);
		command4 = commandinput.check_fourthcommand(fourthcommand);

		switch (command_words){
		case 1:
			world.executecommand1word(command1, actual_position);
			break;
		case 2:
			world.executecommand2words(command1, command2, actual_position);
			break;
		case 4:
			world.executecommand4words(command1, command2, command3, command4, actual_position);
			break;
		default:
			printf("That's not a valid command.\n");
			break;
		}
		/*
		//TEST Prints
		printf("Capacity: %i, %i, %i, %i\n", firstcommand.c_capacity(), secondcommand.c_capacity(), thirdcommand.c_capacity(), fourthcommand.c_capacity());
		printf("Inside main.\n");
		printf("firstcommand: '%s'\n", firstcommand.c_str());
		printf("secondcommand: '%s'\n", secondcommand.c_str());
		printf("thirdcommand: '%s'\n", thirdcommand.c_str());
		printf("fouthcommand: '%s'\n", fourthcommand.c_str());
		printf("words = %i\n", command_words);
		*/
	} while (command1 != 4);//Cheks if command is 'quit'
	system("pause");
	return 0;
}