#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifndef PROJEKT_SAPITRELLO_H
#define PROJEKT_SAPITRELLO_H

extern int count;
enum status{TODO,DOING,DONE};
typedef struct
{
    int code;
    char *name;
}User;
typedef struct
{
    char *title;
    char *description;
    enum status stat;
    User *cardUsers;
    int numcardUsers;
    User *pastUsers;
}Card;
typedef struct
{
    char *name;
    User * users;
    Card * cards;
    int countusers;
    int countcards;
}Board;
void createUser(User **, int *, const char *);
int idGenerate();
void createBoard(Board **boards);
void addBoard(Board **boards, int *countBoards, const char *name);
void addUser(Board **boards, int boardId, User user);
Card *createCard(char *title, char *description);
void addCard(Board **boards, int boardId, Card card);
void addNewUser(Card *card1, User *user);
User *getPastUsers(Card *card1);
void setStatus(Card *card1, int status);
void getstatus(Card card1);
void removeCard(Board **boards, int boardId, int cardId);


#endif //PROJEKT_SAPITRELLO_H
