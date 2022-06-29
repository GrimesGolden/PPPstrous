#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() {char ch; cin>>ch; }

const int ASCII_ZERO = 48; // Represent the ascii form of zero, comes into play later. 

// This function just takes two strings and throws a runtime error. Baseclass of exception. 
void error(string s1, string s2)
{ 
    throw runtime_error(s1 + s2);
}

// Two vectors to to compare guesses against the mystery number.
vector<int> hidden_numb = {};
vector<int> user_guess = {}; 

string check_guess(vector<int> guess)
{   
    string answer = "";
    // Itirate through the hidden number and match with input string. 
    for(int i = 0; i < hidden_numb.size(); i++){
        // Print B for bull or C for cow if no match.
        if(guess[i] == hidden_numb[i]){
            answer += 'B';
        }
        else{
            answer += 'C';
        }
    }

    return answer; 
}

bool guess_repeats(vector<int> guess){
    // Checks if a vector of ints contains any repetition.
    // A grimes golden powered algorithm. 
    bool repeats = false;
    int temp_int = guess[0];
    vector<int> temp_ints = {temp_int};
    for(int i = 1; i < guess.size(); i++){
        for(int k = 0; k < temp_ints.size(); k++){
            if(guess[i] == temp_ints[k]){
                repeats = true;
                break;
            }
        }
        temp_ints.push_back(guess[i]);    
    }
    return repeats;
}

void load_numb(){
    // fills an int with random numbers;
   for(int i=0; i<4; i++)
    {   
        hidden_numb.push_back((rand() % 9) + 1);
    } 
}

void verify_numb(){
    // Verifies the hidden number vector is free from repetitive digits.
    if(guess_repeats(hidden_numb)){
        // Does the vector repeat?
        // It does. 
        bool repeats = true;
        while(repeats){
            // As long as this vector contains repeating numbers...
            // Empty it.
            hidden_numb.clear();

            // Refill it,
            for(int i=0; i<4; i++)
            {   
                hidden_numb.push_back((rand() % 9) + 1);
            }
            
            // If it still repeats, 
            if(guess_repeats(hidden_numb)){
                // Clear it and fill it again. 
                hidden_numb.clear();
                for(int i=0; i<4; i++)
                {   
                hidden_numb.push_back((rand() % 9) + 1);
                }
            }
            else{
                // If it doesnt repeat, then we are done.
                // Get out of here.
                repeats = false;
                break;
            }
        }
    }
}

void bug_detection(){
    cout << "BUG DETECTION: HIDDEN NUMB IS:";
    for(int num : hidden_numb)
    {
        cout << num;
    }
    cout << "\n";
}

void print_greeting(){
    cout << "Welcome to the bulls and cows game!\n";
    cout << "Please input a set of (*NON-REPEATING*) four digits (0-9), for example 1234\n";
    cout << "Try to guess the mystery number! A match will output B for bull, non-match output C for cow\n";
    cout << "Example: look for BBBB to win\n";
    cout << "At any time press E to erase hardrive.";
    cout << "Good luck have fun!!!\n" << "_________________BULLS AND COWS 2022____________________________\n>>";
}


int main()
{   
    
    string user_input = "";
    
    // *******FILLING THE VECTOR WITH 4 NON REPEATING PSUEDO-RANDOM DIGITS 0-9***********
    srand(time(0)); // SEED RANDOM.
    load_numb(); // FILL VECTOR.
    verify_numb(); // MAKE SURE IT CONTAINS NO REPEATS. 

    
    bug_detection();

    
    // Store user input and output greeting,
    print_greeting();
    cout << "Would you like to play?\n";
    cout << "Enter Y to play or any key to destroy system 32.";
    string start_game;
    cin >> start_game;
    if(start_game == "Y"){
        cout << "LOADING GAME..\n";
        cout << "ENTER GUESS>>";
    }else{
        cout << "SYSTEM 32 DELETED";
        return 0;
    }
    while(cin >> user_input){

        if (user_input == "E"){
            cout << "ERASING HARDRIVE";
            return 0;
        }
        // As long as there is constant input.
        // Verify that there is a length of 4.
        if(user_input.length() != 4){
            cout << "Guess must include 4 digits\n";
        }
        else{
            // If the length was 4 then itirate through the string.
            // Convert each char into a number and verify it is a digit 0-9.
            // We now confirm the user ented a proper format.
            for(int i = 0; i < user_input.length(); i++){
                // 48 is the ascii value of 0, minus that gets the actual number.
                // Counting up from zero at 48, 1 = 49, 2 = 50 etc. 
                int num = user_input.at(i) - ASCII_ZERO;
                if(num < 0 || num > 9){
                    cout << "Error, input must be all digits 0-9\n";
                    return 0;
                }
                else{
                    // If format was correct push to vector.
                    user_guess.push_back(num);
                }
            }

            if(guess_repeats(user_guess)){
                // If the vector repeats?
                // Clear out and try again. 
                cout << "NO REPEATING NUMBERS\n";
                user_guess.clear();
            }
                else{
                    // If all bulls then you won
                    // Otherwise print the standard format and clear the vector for a new guess.
                    if(check_guess(user_guess) == "BBBB"){
                        cout << "CONGRATULATIONS, YOU WON THE GAME.\n";
                        hidden_numb.clear();
                        load_numb();
                        verify_numb();
                        cout << "LOADING A NEW NUMBER.\n";
                        cout << ">>";
                        user_guess.clear();
                    }
                    else{
                        // If you reach this point you didnt win.
                        // So output format and clear for next guess. 
                        cout << check_guess(user_guess) << "\n" << ">>";
                        user_guess.clear();
                    }
                }

        }
    }
}