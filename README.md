# C CLI Blackjack Optimal Strategy Game
#### Video Demo:  <[https://www.youtube.com/watch?v=9Js7vSRZ5s8]>
#### Description:
My Blackjack Optimal Strategy Game is made in C and it is a CLI Game.It loads in the data from 3 CSV files that stores the data for the optimal strategy.
The user then chooses from a range of options from 1 to 8. The program then checks the user answer with the optimal strategy that has been previously loaded in.

I also created the card pixel art in the CLI game.Instead of programming the King, Jack , Queen into the game , i Just replaced it with the T which represents T as all of them represent the same value anyways.The user can play the game and infinte amount of time until the user chooses to quit by pressin option 8.

For imporvments in this project i could inplement a pause inbetween each answer for the user to see whether the answer they got is correct.In this version the progam immediately "deals" out the next hand; and if the user CLI is small he needs to scroll up to see whether he got it correct.I would also implement input checking on the users input as i have not implemented that in this version.

Here are some of the challenges I faced
- I was unsure of how to split a csv file line into each variable in c until i found out of the funciton `strok` which tokenises each line of the csv file
- I forgot that there was a \n in each line of fgets.This bug caused me 1-2 hours on why whne i compared two variables which look the same on the cli but was failing the `strcmp` function; and in order to fix it i have to use the `strcspn ` function to find the index of \n to replace it with \0
- You cant' just assign a string to a variable in C your have to use the `strcpy` function in order to do so
- I was racking my brains for an hour or two trying to figure out how to dynammically allocate space for a 2D array of strings.Turns out you have to create a `char***` pointer which in essence is a 3d pointer.This made me realises how easy we have it when we code in python

All in all it was alot of fun doing this project.At first i thought it was simple but doing it in c was a whole other ball game.I can confidently say i have learnt alot from this project by googling and using Gemini.

Why did i do this project?

After watching professional card counters on youtube. I was inspired and want to learn to count cards myself.THe professional card counters advice was to learn basic strategy first.But i always found it annoying when simulating a blackjack hand i had to lookback at a table to see if i was correct.This program helps to solve this problem by giving you immediate feedback right after you answer so that you can know **instantly** whether you are playing optimally.With this project i hope i can learn basic strategy more efficently now.
