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
vector<int> hidden_numb = {1, 2, 3, 4};
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


int main()
{   
    
    string user_input = "";
    // Store user input and output greeting,
    cout << "Welcome to the bulls and cows game!\n";
    cout << "Please input a set of (*NON-REPEATING*) four digits (0-9), for example 1234\n";
    cout << "Try to guess the mystery number! A match will output B for bull, non-match output C for cow";
    cout << "Example: look for BBBB to win";
    cout << "Good luck have fun!!!\n" << "_________________BULLS AND COWS 2022____________________________\n>>";

    while(cin >> user_input){
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
                        cout << "WHAAAAAAAAT YOU WON!!!!!!OMGDGEGWGEGW\n";
                        return 0;
                    }
                    // If you reach this point you didnt win.
                    // So output format and clear for next guess. 
                    cout << check_guess(user_guess) << "\n";
                    user_guess.clear();
                }

        }
    }
}