#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() {char ch; cin>>ch; }

// It's a rock paper scissors game, but it doesn't use random, It uses vectors.

// To make it even more 'random' add a new vector of 11 ints to the set list and increase the size of data_sets. 

// These vectors store all the computers selections. 
vector<string> random_set_0 = {"0", "1", "0", "2", "0", "1", "2", "2", "0", "2", "1"};
vector<string> set_1 = {"1", "1", "1", "1", "2", "2", "2", "0", "0", "0", "0"};
vector<string> set_2 = {"1", "0", "2", "2", "2", "1", "0", "1", "0", "1", "0"};
vector<string> set_3 = {"1", "1", "2", "2", "1", "1", "2", "2", "1", "1", "2"};
vector<string> set_4 = {"2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "0"};
vector<string> set_5 = {"1", "0", "0", "1", "2", "0", "1", "1", "0", "1", "2"};

// This vector stores all the sets of selections. 
vector<vector<string>> data_sets = {random_set_0, set_1, set_2, set_3, set_4, set_5}; 

// These global variables store values from entire playthroughs. (While loop)
int win = 0;
int loss = 0;
int t = 0; // Tie is actually a key word. So I just use the letter t. 
int rock_selected = 0;
int paper_selected = 0;
int scissors_selected = 0;

int total_rounds = 0;
double total_playthroughs = 0;

bool verify_choice(string user_choice){
// Verifies if the user selected 0, 1 or 2 as a string.
// Because I took input as a string, this is my way of validating that.
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
// This prints the outcome of the game, did the user win, lose or tie.
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
    // Takes the input that was a string input from the user, or a string variable taken from the computers choice vectors.
    // Turns it into an integer. It's purpose is simply to turn the string into an index. Could I have just converted string to int?
    // Probly.....
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
    // Now takes an int, and returns string specifying which object.
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

void increment_scores(int user_choice){
// From the input of the users choice, increments the selections accordingly.
// This allows us to track how many times the user picked rock, paper or scissors.
    switch (user_choice)
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

    total_rounds++;
}

void store_outcome(int outcome){
// We store the outcome, win, lose or tie, into global variables.
    switch(outcome)
    {
    case 0:
        ++win;
        break;
    case 1:
        ++loss;
        break;
    case 2:
        ++t;
        break;
    default:
        break;
    }
}

int rock_paper_scissors(int comp_choice, int user_choice){
    // This is the most important function.
    // It provides the actual functionality of the game itself.
    // Using two nested switch statements, we calculate the outcome of the user v computer round.
    switch (user_choice)
    // 0 = win, 1 = lose 2 = tie
    {
    case 0: // User picked rock:
        switch (comp_choice)
        {
        case 0: // And comp picked rock
            return 2; //tie
            break;
        case 1:
            return 1; // User loses because comp 'picked' paper. Paper beats rock.... etc.
            break;
        case 2:
            return 0; // win
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

void exit_protocol(){

    total_playthroughs = (double(total_rounds) / 10.0);
    
    // Just prints some messages and the global variables. 
    cout << "Thanks for playing\n";
    if(total_rounds == 1){
        cout << "You played " << total_rounds << " round.\n";
        cout << "Across " << total_playthroughs << " Playthroughs\n";
    }
    if(total_playthroughs == 1){
        cout << "You played " << total_rounds << " rounds.\n";
        cout << "Across " << total_playthroughs << " Playthrough\n";
    }
    else if (total_rounds != 1 && total_playthroughs != 1){
        cout << "You played " << total_rounds << " rounds.\n";
        cout << "Across " << total_playthroughs << " Playthroughs\n";
    }

    cout << "Total wins: " << win << "\nTotal losses: " << loss << "\nTotal ties: " << t << "\n";
    cout << "You picked rock: " << rock_selected << " times!\n";
    cout << "You picked paper: " << paper_selected << " times!\n";
    cout << "You picked scissors: " << scissors_selected << " times!\n";
    cout << "Goodbye!\n";
}

int main()
{   
    // Exercise 10, play rock paper scissors, using a vector to simulate random. 
    // Use a switch statement to solve.

    bool quit = false;
    string user_input;
    int turn_number = 0;
    int play_through = 0; // CHANGE BUG DETECTION should be zero

    // Strings to hold selection.
    string comp_string; 
    string user_string;
    // Integers to hold selection. 
    int comp_int;
    int user_int;
    // Int to hold scoring variables.
    int outcome;

    // load in the random data sets. 
    // A vector of strings representing "user choices"; 
    vector<string> choices;

    



    while(!quit){


        if(turn_number == 0){
            choices = data_sets[play_through];
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
            if(turn_number >= (choices.size() - 1)){
                // We have selected every string option in the first vector of computer choices.
                // So we have ran out of data points.
                // Load in a new vector. 
                cout << "You have exhausted the computers choices...\n";
                cout << "Loading new data set.\n";

                if(play_through < (data_sets.size() - 1)){
                    //the number of data sets we have (size - 1))
                    // If we have looped through this while loop, less times than there are data sets in the entire set of all vectors.
                    // Increment the playthroughs.
                    ++play_through; 
                }else{
                    // Set them back to zero.
                    play_through = 0;
                }
                // Set the rounds back to zero. This is the end of a round.
                turn_number = 0;

                // re-load in the random data sets. 
                // A vector of strings representing "computer choices"; 
                // Basically load in a new "computer", a new set of computer selections. 
                choices = data_sets[play_through];


            // If the the input is correct, and we havent used up all the computers turns. 
            } else{

                // User string (users selection choice) is printed
                cout << "\n\n*********************\n";
                cout << "You selected " << user_string << "\n";
                // Increment turn number.
                ++turn_number;
                // Computers selection is made through use of int and string.

                comp_int = return_selection_int(choices[turn_number]);
                comp_string = return_selection(comp_int);
                // Computers choice is read out.
                cout << "Computer has selected " << comp_string << "\n";
            
                // Play game
                outcome = rock_paper_scissors(comp_int, user_int);
                store_outcome(outcome);
                cout << print_outcome(outcome);
                cout << "End of round: " << turn_number << "\n";

               increment_scores(user_int);
            }
    
        } else if(user_input == "q"){
            quit = true;

        } else {
            cout << "Error incorrect selection, please try again.\n";
        }
    }
    
    // End of while loop. 
        exit_protocol();
        return 0;
}