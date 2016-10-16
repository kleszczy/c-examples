/*
 * https://github.com/kleszczy/c-examples
 *
 * Example of C Linked List data structure.
 *
 * You are a football coach, who needs to arrange
 * a list of players entering the field.
 *
 * You can add a new player in the front or in the back
 * of the list.
 *
 * You can also view the current list of players.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_NAME 50

/* Player's data - name and number */
typedef struct PlayerData Data; 
struct PlayerData {
	char name[MAX_PLAYER_NAME];
	int number;
};

/* Player struct - single element of our list */
typedef struct FootballPlayer Player;
struct FootballPlayer {
	Data data;
	Player *next; 
};

/* Function definitions */
Player* create_new_player(void);
void add_new_player_front(Player **player);
void add_new_player_back(Player **player);
void show_all_players(Player **player);

/* Function for creating a new player */
Player* create_new_player(void)
{
	Player *player = (Player *)malloc(sizeof(Player));
	
	/* Get the player's name */
	printf("Player name: ");
	scanf("%s", &player->data.name);

	/* Get the player's number */
	printf("Player number: ");
	scanf("%d", &player->data.number);

	/* There is no next player for now */
	player->next = NULL;

	return player;
}

/* Function for adding player in the front */
void add_new_player_front(Player **player)
{
	printf("Add new player in the front\n");

	Player *tmp = create_new_player();

	/* Check if it's the first player */
	if (*player != NULL)
		tmp->next = *player;
	*player = tmp;
}

/* Function for adding player in the back */
void add_new_player_back(Player **player)
{
	printf("Add new player in the back\n");

	Player *tmp = create_new_player();
	Player *iter = *player;

	/* Find the last player */
	while (iter->next != NULL)
		iter = iter->next;

	iter->next = tmp;
	*player = iter;
}

/* Function for displaying all players */
void show_all_players(Player **player)
{
	printf("List of players\n");

	Player *tmp = *player;

	/* Iterate through all players */
	while (tmp != NULL) {
		printf("Player name: %s number: %d\n",
			tmp->data.name, tmp->data.number);
		tmp = tmp->next;
	}
}

int main() {
	Player *first = NULL;

	/* Add three players */
	add_new_player_front(&first);
	add_new_player_back(&first);
	add_new_player_front(&first);

	/* Show all added players */
	show_all_players(&first);

	return 0;
}