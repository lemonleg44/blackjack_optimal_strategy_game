#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func.h"

// #define MAX_LINE_LENGTH 1024
// #define HARD_HANDS = 11
// #define SOFT_HANDS = 8
// #define PAIR_HANDS = 10
// #define DEALER_UPCARD = 10
int main()
{
  srand(time(NULL)); // generates random seed everytime so that random numbers are not repeated when we rerun the program time(null) gets time from system clock
    char ***hard_total_arr = file_process("hard_total.csv", 10, 1);

    char ***soft_total_arr = file_process("soft_total.csv",8,2);

    char ***split_arr = file_process("split.csv",10,3);

    if (hard_total_arr == NULL)
    {
        printf(" hard total arr sumthg wrong");
        exit(-1);
    }

      if (soft_total_arr == NULL)
    {
        printf("soft_total arr sumthg wrong");
        exit(-1);
    }

      if (split_arr == NULL)
    {
        printf("split_arr sumthg wrong");
        exit(-1);
    }



    printf("hard total array :%s \n", hard_total_arr[0][0]);

    printf("soft total array :%s \n", soft_total_arr[2][0]);

    printf("split total array :%s \n", split_arr[5][0]);

    
    char card_arr[11 * sizeof(char)] = "23456789TA";

    while (1) // while true loop
    {
      /* code */
    
      
      //randomly genereate delaer upcard and player hand 
      int deal_card = rand_card(0,9);

      int player_card1 = rand_card(0,9);

      int player_card2 = rand_card(0,9);

      // print out cards

      printf("Dealer Card: %c\n",card_arr[deal_card]);

      print_card(card_arr[deal_card]);

      printf("Players Cards: %c%c\n", card_arr[player_card1], card_arr[player_card2]);

      print_2_cards(card_arr[player_card1], card_arr[player_card2]);
      // TODO :Check if blackjack

      if(player_card1 + player_card2 == 17){

        printf("Blackjack! No action needed for this turn");

        continue;
      }
      

      //get userinput on what is optimal action

      int option;

      printf("choose option(input number): 1.H, 2.S, 3.D, 4.Ds, 5.Y, 6.N, 7.Y/N , 8.QUIT\n");
      printf("Answer: \n");
      scanf("%d" , &option);

      char option_arr[8][5] = {"H","S","D","Ds","Y","N","Y/N","QUIT"};

      const char* player_ans = option_arr[option - 1];

      printf("%s\n",player_ans);

      //find correcte answer in the array 

      //if user choose option 8 , quit the program

      if (option == 8){
        break;
      }
      
      char correct_ans[5];
      // if player card is same
      if (player_card1 == player_card2)
      {
        strcpy(correct_ans , split_arr[(player_card1 - 9) * -1][deal_card]);

        if (strcmp(correct_ans,player_ans) == 0)
        {
          printf("You got it correct!!\n");
        }
        else{
          printf("You got it wrong:(\n");
        }
      }

      // if it is soft total

      else if (player_card1 == 9 || player_card2 == 9){

        if(player_card1 == 9){

          strcpy(correct_ans , soft_total_arr[(player_card2 -7) * -1][deal_card]);

        }
        else{

          strcpy(correct_ans , soft_total_arr[(player_card1 -7) * -1][deal_card]);

        }
        if (strcmp(correct_ans,player_ans) == 0)
          {

            printf("You got it correct!!\n");

          }
        else{

            printf("You got it wrong:(\n");
          }


      }

      // else is hard total
      else{
        int hard_total = player_card1 + player_card2 + 4; // the reason plus 4 is to 
                                                            //calcuate the actual hard total value
        if (hard_total >= 17){ 
          strcpy(correct_ans ,option_arr[option -1]);

          if(option == 2){

            printf("You got it correct!!\n");

          }
          else{

            printf("You got it wrong:(\n");
          }
        }

        else if (hard_total <= 8){
          strcpy(correct_ans ,option_arr[option -1]);
          if(option == 1){

            printf("You got it correct!!\n");

            

          }
          else{

            printf("You got it wrong:(\n");
          }

        }

        else{
          strcpy(correct_ans , hard_total_arr[(hard_total - 17) * -1][deal_card]);

          if (strcmp(correct_ans,player_ans) == 0)
          {

            printf("You got it correct!!\n");

          }
        else{

            printf("You got it wrong:(\n");

          }
        }

        
      }

      printf("Your Answer : %s\n", player_ans);

      printf("Correct Answer : %s\n", correct_ans);

      printf("-------------------------\n");
  }
    //output if delaer is correct

    free_dealer_arr(hard_total_arr, 10, DEALER_UPCARD);

    free_dealer_arr(soft_total_arr, 8, DEALER_UPCARD);

    free_dealer_arr(split_arr, 10, DEALER_UPCARD);

    printf("Program has terminated");

    return 0;

}