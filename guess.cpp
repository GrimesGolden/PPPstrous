#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() {char ch; cin>>ch; }

const vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
 
int get_number(string user_input){
    // Matches string to index of the vector to return the digit in numerical terms.
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == user_input){
            return i; 
        }
    }
    // Or returns -1 if no match
    return -1; 
}

int main()
{   
    int digit = 0;
    string number = "";
    bool quit = false; 

    // While the quit flag is not set
    while(!quit)
    {   
        // Request an entry
        cout << "Enter a digit (number between 0 and 9) or '|' to quit." << "\n>>";

        // If the user inputs any integer with cin.
        if(cin >> digit)
        {
            if(digit >= 10 || digit < 0) // Check if its between zero and 9.
            {
                cout << "\nEnter a DIGIT\n";
                cout << "\n Look, is " << digit << " between 1 and 10? Lets try this again.\n"; // If it's not request data re-entry and repeat loop. 
            } else
            {
                cout << "\nYou entered " << numbers[digit] << " \n"; // If it is print the digit and repeat loop. 
                cout << "Enter another\n>>";
            }

        }
        else
        {   
            // Clear the input and return to cin. 
            //cin.clear();
            cin >> number;
            
            if(number == "|"){ // If user enters this character, immedietely quit by setting flag. 
                quit = true;
            } else if(get_number(number) != -1){
                cout << "You entered " << get_number(number) << " \n";  // If the function does not send back -1, its a match for a digit.
            } else{
                cout << "Sorry that doesn't seem to be a digit.\n"; // But then it must have sent back -1. Request re-entry. 
            }

        }

        // If user ends input with ctrl-d just quit the loop. 
        if(cin.eof()){
            quit = true;
        }
    }
}