#include "sapiTrello.h"

void createUser(User **users, int *size, const char *name) {
    *users = (User *) realloc(*users, *size * sizeof(User));
    users[*size]->code = idGenerate();
    users[*size]->name = (char *) malloc(strlen(name) * sizeof(char));
    strcpy(users[*size]->name, name);
    (*size)++;
}
int count=0;
int idGenerate() {
    count++;
    return count;
}
void createBoard(Board **boards) {
    *boards = (Board *) malloc(0 * sizeof(Board));
}

void addBoard(Board **boards, int *countBoards, const char *name) {
    *boards = (Board *) realloc(*boards, *countBoards * sizeof(Board));
    boards[*countBoards]->name = (char *) malloc((strlen(name) + 1) * sizeof(char));
    strcpy(boards[*countBoards]->name, name);
    boards[*countBoards]->countusers = 0;
    boards[*countBoards]->users = (User *) malloc(0 * sizeof(User));
    boards[*countBoards]->countcards = 0;
    boards[*countBoards]->cards = (Card *) malloc(0 * sizeof(Card));
    (*countBoards)++;

}
void addUser(Board **boards, int boardId, User user) {
    boards[boardId]->users = (User *) realloc((*boards)[boardId].users, boards[boardId]->countusers * sizeof(User));
    boards[boardId]->users[boards[boardId]->countusers] = user;
    boards[boardId]->countusers++;
}

Card *createCard(char *title, char *description) {
    Card *card1;
    card1 = (Card *) malloc(sizeof(Card));
    card1->title = (char *) malloc((strlen(title)) * sizeof(char));
    card1->description = (char *) malloc((strlen(description)) * sizeof(char));
    strcpy(card1->title, title);
    strcpy(card1->description, description);
    card1->stat = TODO;
    card1->numcardUsers = 0;
    card1->pastUsers = (User *) malloc((*card1).numcardUsers* sizeof(User));
    return card1;
}
void addCard(Board **boards, int boardId, Card card) {

    boards[boardId]->cards = (Card *) realloc(boards[boardId]->cards,boards[boardId]->countcards * sizeof(Card));
    boards[boardId]->cards[boards[boardId]->countcards] = card;
    boards[boardId]->countcards++;
}
void addNewUser(Card *card1, User *user) {
    card1->cardUsers = user;
    card1->numcardUsers++;
    card1->pastUsers = (User *) realloc(card1->pastUsers, (card1->numcardUsers + 1) * sizeof(User));
    card1->pastUsers[card1->numcardUsers - 1] = *user;
}
User *getPastUsers(Card *card1)
{
    return card1->pastUsers;
}
void setStatus(Card *card1, int status) {
    card1->stat = status;
}
void getstatus(Card card1) {
    printf("A kartya statusza: ");
    if (card1.stat == 1) {
        printf("TODO\n");
    }
    if (card1.stat == 2)
    {
        printf("DOING\n");
    }
    else printf("DONE\n");
}
void removeCard(Board **boards, int boardId, int cardId) {
    for (int i = cardId - 1; i < boards[boardId]->countcards - 1; i++) {
        boards[boardId]->cards[i] = boards[boardId]->cards[i + 1];
    }
    boards[boardId]->countcards--;
    boards[boardId]->cards = (Card *) realloc(boards[boardId]->cards,boards[boardId]->countcards * sizeof(Card));
}
