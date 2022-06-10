#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() {char ch; cin>>ch; }

vector<string> computers_choice = {"0", "1", "0", "2", "0", "1", "2", "2", "0", "2", "1"};

bool verify_choice(string user_choice){
    // Verify if the user selected 0,1,2.
    // Returns false otherwise. 
    if(user_choice == "0"){
        return true;
    }
    if(user_choice == "1"){
        return true;
    }
    if(user_choice == "2"){
        return true;
    }
    else{
        return false;
    }
}

string print_outcome(int outcome){
    switch (outcome)
    {
    case 0:
        return "You win!\n";
        break;
    case 1:
        return "You lose!\n";
        break;
    case 2:
        return "It's a tie!\n";
        break;
    default:
        return "It's an error!\n";
        break;
    }
}
int return_selection_int(string input_string){
    // Returns an integer to represent the selection.
    if(input_string == "0"){
        return 0;
    }
    if(input_string == "1"){
        return 1;
    }
    if(input_string == "2"){
        return 2;
    }
    else{
        return -1;
    }
}

string return_selection(int selection){
    switch (selection)
    {
    case 0:
        return "rock";
        break;
    case 1:
        return "paper";
        break;
    case 2:
        return "scissors";
        break;   
    default:
        return "error";
        break;
    }
}

int rock_paper_scissors(int comp_choice, int user_choice){
    switch (user_choice)
    // 0 = win, 1 = lose 2 = tie
    {
    case 0: // its a rock:
        switch (comp_choice)
        {
        case 0:
            return 2; //tie
            break;
        case 1:
            return 1; // lose 
            break;
        case 2:
            return 0; // wim
            break;
        default:
            return -1;
        }
    case 1:
        switch (comp_choice)
        {
        case 0:
            return 0; //win
            break;
        case 1:
            return 2; // tie
            break;
        case 2:
            return 1; // lose
            break;
        default:
            return -1; // error
        }
        break;
    case 2:
        switch (comp_choice)
        {
        case 0:
            return 1; //lose
            break;
        case 1:
            return 0; // win 
            break;
        case 2:
            return 2; // tie
            break;
        default:
            return -1;
        }
        break;
    default:
        return -1;
        break;
    }
}

int main()
{   
    // Exercise 10, play rock paper scissors, using a vector to simulate random. 
    // Use a switch statement to solve.

    bool quit = false;
    string user_input;
    int turn_number = 0;

    // Strings to hold selection.
    string comp_string; 
    string user_string;
    // Integers to hold selection. 
    int comp_int;
    int user_int;
    // Int to hold scoring variables.
    int outcome;
    int win = 0;
    int loss = 0;
    int tie = 0;
    int rock_selected = 0;
    int paper_selected = 0;
    int scissors_selected = 0;
    


    while(!quit){
        if(turn_number == 0){
            cout << "Welcome to rock, paper scissors\n";
        }

        cout << "For rock press 0, for paper press 1, for scissors press 2 or q to quit\n>>";
        cin >> user_input;

        // If input is verified correct, then...
        if(verify_choice(user_input)){
            // User int is stored.
            user_int = return_selection_int(user_input);
            // User string is stored
            user_string = return_selection(user_int);
    
            // Is the turn number beyond the amount of choices?
            if(turn_number >= (computers_choice.size() - 1)){
                // We can't play anymore so quit.
                cout << "You have exhausted the computers choices...\n";
                quit = true;

            // If the the input is correct, and we havent used up all the computers turns. 
            } else{
                // User string (users selection choice) is printed
                cout << "\n\n*********************\n";
                cout << "You selected " << user_string << "\n";
                // Increment turn number.
                ++turn_number;
                // Computers selection is made through use of int and string.

                comp_int = return_selection_int(computers_choice[turn_number]);
                comp_string = return_selection(comp_int);
                // Computers choice is read out.
                cout << "Computer has selected " << comp_string << "\n";
            
                // Play game
                outcome = rock_paper_scissors(comp_int, user_int);
                cout << print_outcome(outcome);
                cout << "End of round: " << turn_number << "\n";

                // Store scores
                switch (user_int)
                {
                case 0:
                    rock_selected++;
                    break;
                case 1:
                    paper_selected++;
                    break;
                case 2:
                    scissors_selected++;
                    break;
                default:
                    break;
                }

                switch(outcome){
                    case 0:
                        win++;
                        break;
                    case 1:
                        loss++;
                        break;
                    case 2:
                        tie++;
                        break;
                    default:
                        break;
                }
            }

        } else if(user_input == "q"){
            quit = true;

        } else {
            cout << "Error incorrect selection, please try again.\n";
        }
    }
    // End of while loop. 
        cout << "Thanks for playing\n";
        cout << "You played " << (turn_number) << " turns.\n";
        cout << "Total wins: " << win << "\nTotal losses: " << loss << "\nTotal ties: " << tie << "\n";
        cout << "You picked rock: " << rock_selected << " times!\n";
        cout << "You picked paper: " << paper_selected << " times!\n";
        cout << "You picked scissors: " << scissors_selected << " times!\n";
        cout << "Goodbye!\n";
        return 0;
}