#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "interface.h"



void MSG_MENU()
{

    int option;
    int sub_option;
    srand(time(NULL));
    circle *c_1;
    circle *c_2;
    do
    {
        printf("\n\n>>> Menu options <<<");
        printf("\n1. Create new circles");
        printf("\n2. Calculate area from circle");
        printf("\n3. Calculate if circles are concentric");
        printf("\n4. Calculate which circle has greater radius");
        printf("\n5. Free memory of a given circle");
        printf("\n6. Exit from application");

        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            c_1 = create_circ(gen_float(), gen_float(), gen_float());
            printf("\nCircle 1 has X position: %.2f\nY position: %.2f\nRadius: %.2f", c_1->x, c_1->y, c_1->r);
            c_2 = create_circ(gen_float(), gen_float(), gen_float());
            printf("\nCircle 2 has X position: %.2f\nY position: %.2f\nRadius: %.2f", c_2->x, c_2->y, c_2->r);
            break;

        case 2:
            printf("\nWhich circle do you wish to know the area of? ");
            scanf("%d", &sub_option);
            do
            {
                if(sub_option == 1)
                {
                    printf("\nArea from circle 1: %.2f", calc_area(c_1));
                    break;
                }
                else if(sub_option == 2){
                    printf("\nArea from circle 2: %.2f", calc_area(c_2));
                    break;
                }
                else
                    printf("\nPlease input 1 or 2!");
            }
            while(sub_option != 1 || sub_option != 2);

            break;

        case 3:
            if (circ_concentric(c_1, c_2) == 1)
                printf("\n\nCircles are concentric! Both has coordinates: %.2f , %.2f", c_1->x, c_1->y);
            else
                printf("\n\nCircles aren't concentric! Circle 1 has coordinate: %.2f , %.2f\n Circle 2 has coordinates: %.2f , %.2f", c_1->x, c_1->y, c_2->x, c_2->y);
            break;

        case 4:
            if (greater_radius(c_1, c_2) == 1)
                printf("\n\nFirst circle has greater radius!\n\n");
            else
                printf("\n\nSecond circle has greater radius!\n\n");
            break;

        case 5:

            printf("\nWhich circle do you wish to delete? ");
            scanf("%d", &sub_option);
            do
            {
                if(sub_option == 1)
                {
                    free(c_1);
                    break;
                }
                else if(sub_option == 2){
                    //free(c_2);
                    free_circ(c_2);
                    break;
                }
                else
                    printf("\nPlease input 1 or 2!");
            }
            while(sub_option != 1 || sub_option != 2);
            break;

        case 6:
            printf("\nExiting application!");
            if(c_2 != NULL || c_1 != NULL){
                free(c_2);
                free(c_1);
            }
            break;

        default:
            printf("\nPlease input a valid value!");
        }
    }
    while(option != 6);
}

float gen_float(){
    return ((float)rand()/(float)(RAND_MAX)) * 10;
}


