
#include <stdlib.h>
#include <stdio.h>
#ifndef PROJEKT_SAPITRELLO_H
#define PROJEKT_SAPITRELLO_H

enum status{TODO,DOING,DONE};
typedef struct
{
    int code;
    char name[20];
}User;
typedef struct
{
    char title[15];
    char description[50];
    enum status stat;
}Card;
typedef struct
{
    char name[20];
    User * users;
    Card * cards;
}Board;



#endif //PROJEKT_SAPITRELLO_H

