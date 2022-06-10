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


    while(!quit){
        cout << "Welcome to rock, paper scissors\n";
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
                cout << "Thanks for selecting " << user_string << "\n";
                // Increment turn number.
                ++turn_number;
                // Computers selection is made through use of int and string.

                comp_int = return_selection_int(computers_choice[turn_number]);
                comp_string = return_selection(comp_int);
                // Computers choice is read out.
                cout << "Computer has selected " << comp_string << "\n";
            
                // Play game
                rock_paper_scissors(comp_int, user_int);
            }

        } else if(user_input == "q"){
            quit = true;

        } else {
            cout << "Error incorrect selection, please try again.\n";
        }
    }
    // End of while loop. 
        cout << "Goodbye";
        return 0;
}