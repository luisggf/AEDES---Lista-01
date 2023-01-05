#include <stdio.h>
#define MAX 151
#define PRIZES 6
#include <stdlib.h>
#include <time.h>

typedef struct Book_
{
    char title[MAX];
    char author[MAX];
    float prize[PRIZES];

} book;

void getBookInfo(book *book, int lenght)
{
    srand(time(NULL));
    for (int i = 0; i < lenght; i++)
    { // fill books info
        printf("\nPlease input the book name %d: ", i + 1);
        fgets(book[i].title, MAX, stdin);
        fflush(stdin);

        printf("\nPlease input the authors name %d: ", i + 1);
        fgets(book[i].author, MAX, stdin);
        fflush(stdin);

        for (int j = 0; j < PRIZES; j++)
        { // fill prize history from all books
            book[i].prize[j] = ((float)rand() / (float)(RAND_MAX)) * (100);
        }
    }
}

float *prizeAvg(book *book, int lenght)
{ // returns each book avg prize, each index represents avg from each book
    float *aux = calloc(lenght, sizeof(float));

    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < PRIZES; j++)
        {
            aux[i] += book[i].prize[j]; // sum each month prize
        }
        aux[i] = aux[i] / PRIZES; // provide book x average
    }
    return aux;
}

void rbook(book book[], int lenght)
{
    int max = 0;
    int min = 0;
    int max_index = 0, min_index = 0;
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < PRIZES; j++)
        {
            max = book[i].prize[j];
            min = book[i].prize[j];
            if (book[i].prize[j] >= max)
            {
                max = book[i].prize[j];
                max_index = i;
            }
            else if (book[i].prize[j] <= max)
            {
                min = book[i].prize[j];
                min_index = i;
            }
        }
    }
    printf("The cheaper book is the book named: %s", book[min].title);
    printf("The most expensive book is the book named: %s", book[max].title);
    return;
}

void book_info(book *book, int lenght)
{
    float *book_avg;
    for (int i = 0; i < lenght; i++)
    {
        book_avg = prizeAvg(book, lenght);
        printf("\nBook: %sAuthor: %sNumber: %d\nAverage prize: %.2f\n", book[i].title, book[i].author, i + 1, book_avg[i]);
    }
}

void book_prize_historic(book *book, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < PRIZES; j++)
        {
            printf("\nBook %d Month %d had a prize of: %.2f", i + 1, j + 1, book[i].prize[j]);
        }
    }
}

int main()
{
    book *b = malloc(2 * sizeof(book));
    float *book_avg;

    getBookInfo(b, 2);

    book_info(b, 2);

    book_prize_historic(b, 2);

    rbook(b, 2);

    free(b);

    return 0;
}