#include "Exits.h"

Exit::Exit(){
}

Exit::Exit(const char* s1, const char* s2, Room* s3, Room* s4, bool s5, bool s6) : Entity(s1, s2), origin(s3), destination(s4), close(s5), door(s6){
}

Exit::~Exit(){
}