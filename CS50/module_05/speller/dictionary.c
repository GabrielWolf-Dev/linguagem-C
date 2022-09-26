#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int counter = 0;

const unsigned int N = 26;

node *table[N];

bool check(const char *word)
{
    int index = hash(word);

    for (node *aux = table[index]; aux != NULL; aux = aux->next)
    {
        if (strcasecmp(aux->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

unsigned int hash(const char *word)
{
    unsigned long sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        sum += toupper(word[i]);
    }

    return sum % N;
}

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open dictionary\n");

        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *head = malloc(sizeof(node));
        if (head != NULL)
        {
            strcpy(head->word, word);

            int index = hash(word);

            head->next = table[index];

            table[index] = head;

            counter++;
        }

        else
        {
            return false;
        }
    }
    fclose(file);

    return true;
}

unsigned int size(void)
{
    return counter;
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *aux = table[i]->next;

            free(table[i]);

            table[i] = aux;
        }
    }

    return true;
}