# Take the gold

Welcome to Take the gold
This game is based on Zork for a class project in the degree in video game design and development of CITM Terrassa, Catalonia, Spain.

## Installation

Download the release zip, unzip it and execute the .exe file.

## Lore
You are a thief who must steal the treasure of the king in his castle.

## Instructions, how to play

You can move using:

n/s/e/w

north/east/south/west

go north/east/south/west

/s/e/w\n

Also you can use the commands:

look/l -> to see the description of the room where you are

look/l + north/east/south/west/n/s/e/w -> to see the description of the path

look/l + item name -> if you have it in the inventory you can see its lore

open/close + north/east/south/west/n/s/e/w -> to open/close door

pick + item name -> you can pick items from the ground

drop + item name -> you can drop items to the ground

equip + item name -> you can equip items

unequip + item name -> you can unequip items

put + item name + into + cupboard -> put item in the cupboard

get + item name + from + cupboard -> get the item from the cupboard

use + item name -> to use it

equipped -> to see the objects that the player has equipped

inventory/inv/i -> to see player inventory

backpacked -> to see what you had put inside the backpack if you had taken it

stats -> to see player stats

flee -> when you have the treasure you can go to Tower 1 and flee to finish the game

clear/c -> to clean the screen

help/h -> to open the help menu

quit/q -> to quit the game

## Changelog

16-03-2016 -> Take the gold first release with all rooms and movement, look, open, close, help and quit commands.

18-04-2016 -> Take the gold second release with all items and more commands(items look, pick, drop, equip, unequip, put, get, use, equipped, inventory, backpacked, stats, flee, clear).

##Comments

If the player tries to move in one direction and it prints again the room information where he is, means that there is a wall, this can "fix" with an if where you look if the source and destination of the exit is equal, prints "there is a wall", but I have left it to create confusion, if the player moves in one direction and information room is repeated, the player will wonder why it is happening, and if he makes a look + direction, he will know what there is there.
Notice that there are two blade weapons, you can only equip ne, if you equip the other, the first one will be unequipped.

## Credits

Xavier Olivenza Busquets, first year student in the degree in video game design and development of CITM Terrassa, Catalonia, Spain.

My github project web with links to the wiki with the GDD, to the release and to the github page: http://xavierolivenza.github.io/CastleZork/

My github project page: https://github.com/xavierolivenza/CastleZork

CITM Terrassa 2015-2016