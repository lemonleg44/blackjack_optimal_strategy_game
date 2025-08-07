#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE_LENGTH 1024
#define HARD_HANDS 11
#define SOFT_HANDS  8
#define PAIR_HANDS  10
#define DEALER_UPCARD 10
char ***allocate_dealer_arr(int n_rows, int size_of_data);

void free_dealer_arr( char*** array, int n_rows, int n_cols);

int rand_card(int min, int max);

void print_card(char value);

void print_2_cards(char value1 , char value2);

char*** file_process( char* file_name, int n_rows, int size_of_data)

{
    

    FILE *file;
    file = fopen(file_name,"r");
    
    if (file == NULL){
        printf("File cant be open");

        //TODO : find out how to return error
        exit(0);
    }

    char*** file_store;

    file_store = allocate_dealer_arr(n_rows, size_of_data);// creates memory for the array

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file); // skips the header file
    // for loop to get each line
    for(int i = 0; i < n_rows; i++)
    {
        // store the line in  a buffer 
        fgets(line, MAX_LINE_LENGTH, file);

        // split the string by comma
        char *split = strtok(line, ",");



        // nested for loop , skip first eleement as it is not in data
        for (int j =0; j< DEALER_UPCARD;j ++)
        {
            split = strtok(NULL,",");
            
            // store data in table
            file_store[i][j] = strdup(split);

            //printf(file_store[i][j]);
        }
        
    }

    // close the file
    
    if (fclose(file) == 0)
    {
        printf("file is closed\n");
    
    }
    else{
        printf("error closing file\n");

        exit(1);
    }
   // return pointer array
   
   return file_store;

  
}



char ***allocate_dealer_arr(int n_rows, int size_of_data)
{
    char ***dealer_arr = malloc(n_rows * sizeof(char **));

    if (dealer_arr == NULL)
    {
        printf("Failed to allocate mem for dealer_arr");
        exit(EXIT_FAILURE);//TODO : find out what exit failure does
    }

    for (int i = 0; i < n_rows; i++)
    {
        dealer_arr[i] = malloc(DEALER_UPCARD * sizeof(char*));

        if (dealer_arr[i] == NULL)
        {
            printf("Failed to allocate mem for dealer_arr[i]");
            exit(EXIT_FAILURE) ;
        }

        for(int j = 0; j < DEALER_UPCARD; j++)
        {
            dealer_arr[i][j] = malloc((size_of_data  + 1) * sizeof(char));

            if (dealer_arr[i][j] == NULL)
            {
                printf("Failed to allocate mem for dealer_arr[i][j]");
                exit(EXIT_FAILURE) ;
            }
        }
    }
    return dealer_arr;
}

void free_dealer_arr( char*** array, int n_rows, int n_cols)
{
    for(int i = 0; i < n_rows; i ++ )
    {
        for (int j = 0; j < n_cols; j++)
        {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

int rand_card(int min, int max)
{
    return rand() % (max - min + 1) + min ;
}


void print_card(char value)
{
// prints 7 x 5 card
printf(" ___ \n");
printf("|%c  |\n",value);
printf("|   |\n");
printf("| %c |\n",value);
printf("|   |\n");
printf("|__%c|\n",value);


}

void print_2_cards(char value1 , char value2) // althogh for loop is not need i tried to not hardcode as much as possible
{
    int no_cards = 2;
    char cards[2] = {value1,value2};
    if (no_cards > 1) // prints the card side by side
    {
        for (int i = 0; i <  no_cards -1; i++) // uses the tab to create spacing sideways for each card
        {
            printf(" ___ \t");
        }
        printf(" ___ \n");

        for (int i = 0; i <  no_cards -1; i++)
        {
            printf("|%c  |\t",cards[i]);
        }
        printf("|%c  |\n",cards[no_cards -1]);

        for (int i = 0; i <  no_cards -1; i++)
        {
            printf("|   |\t");
        }
        printf("|   |\n");

        for (int i = 0; i <  no_cards -1; i++)
        {
            printf("| %c |\t",cards[i]);
        }
        printf("| %c |\n",cards[no_cards -1]); 
        
        for (int i = 0; i <  no_cards -1; i++)
        {
            printf("|   |\t");
        }
        printf("|   |\n");

        for (int i = 0; i <  no_cards -1; i++)
        {
            printf("|__%c|\t",cards[i]);
        }
        printf("|__%c|\n",cards[no_cards -1]); 
    }

}