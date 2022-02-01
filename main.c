/*
** EPITECH PROJECT, 2022
** pendu game
** File description:
** main file
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

char *hidden_solution(char *solution)
{
    int len_solution = my_strlen(solution);
    char *hidden = malloc(sizeof(char) * (len_solution + 3));
    int i = 0;

    for (; solution[i]; i++)
        hidden[i] = '*';
    hidden[i] = '\0';
    return (hidden);
}

int verify_letter(char *solution, char letter)
{
    for (int i = 0; solution[i]; i++) {
        if (letter == solution[i]) {
            return (1);
        }
    }
    return (0);
}

char *change_the_letter(char *hidden, char letter, char *solution)
{
    for (int i = 0; solution[i]; i++) {
        if (letter == solution[i])
            hidden[i] = letter;
    }
    return (hidden);
}

int my_strcmp(char const *str1, char const *str2)
{
    for (int i = 0; str1[i]; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}

void check_if_same(char *hidden, char *solution)
{
    if (my_strcmp(hidden, solution)) {
        printf("Bravo vous avez gagné !");
        exit (0);
    }
}

int gameloop(int nb_coup, char *hidden, char *solution)
{
    int victory = 0;
    char letter = 0;

    for (; nb_coup != 0;) {
        check_if_same(hidden, solution);
        printf("Il vous reste %d coups à jouer\n", nb_coup);
        printf("Quel est le mot secret ? ");
        scanf(" %c", &letter);
        if (verify_letter(solution, letter)) {
            hidden = change_the_letter(hidden, letter, solution);
            printf("%s\n", hidden);
        } else {
            nb_coup--;
        }
    }
    printf("Vous avez perdu...");
    return (0);
}

int main(void)
{
    int nb_coup = 10;
    char *solution = "arbre";
    char *hidden = hidden_solution(solution);
    int return_value = 0;

    printf("Bienvenue dans le jeu du Pendu !\n");
    return_value = gameloop(nb_coup, hidden, solution);
    free(hidden);
    return (return_value);
}