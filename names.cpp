#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() {char ch; cin>>ch; }
int main()
{
    vector<string> names;
    vector<int> scores;
    string name;
    int score; 
    string input;

    int i = 0; //Used for itiration.
    int track_score = 0; 

    bool found_score = false;
    bool found_name = false;

    cout << "Input your scores to be stored.\n";
    cout << "Please use the following format 'Name Score', for example: Jordan 23.\n";
    cout << "Or enter 'NoName 0' to terminate program.\n";
    cout << ">>";

    while(true){

        // Input a name
        cin >> name;

        // Verify name is not repeated by traversing names list.
        for(string element : names){
            // If it is repeated, then end the program.
            if(element == name){
                cout << "Error: repeated name: " << name << "\n";
                return 0; 
            }
        }

        // Otherwise, add it to names.
        names.push_back(name);

        // Now add the integer portion to score
        cin >> score;
        scores.push_back(score);

        // If NoName 0 is entered, terminate program.
        if(name == "NoName" && score == 0){
            cout << "Exiting with termination code: NoName Zero\n"; 
            break;
        }

        // Else output confirmation message.
        cout << "Added name: " << name << " succesfully.\n";
        cout << "Added score: " << score << " succesfully\n";

        // Clear the buffer so superflous input isnt allowed through. 
        // This way if we dont type an iteger but hit enter and type another name, it will get cleared.
        // A bug existed before where names would get added on top and checked, for example joey would get repeated for jordan. Because buffer was full.
        cin.clear();

    }
    
    // Output each name and score in a line using itiration. 
    for(string name : names){
        cout << name << " ";
        cout << scores[i];
        cout << "\n";
        i++;
    }

    // Print a lil message
    cout << "************************************************\n";
    cout << "Welcome to the database.\n>>";
    cout << "Enter a name or score to search, or '|' to exit. >>\n";

    // While we recieve input...
    while(cin >> input){

        if(input == "|"){
            //If the input is | then end program.
            break;
        } else if(isdigit(input[0])){
            // If the input is a number. (starts with one at least..)
            for (int score : scores){
                // Then output the scores that match, along with their index within the name vector (thus the name they are paired with).
                if(stoi(input) == score){
                    cout << "Score : " << score << "\n";
                    cout << "Paired with name: " << names[track_score] << "\n>>";
                    found_score = true;
                }
                //Increment the itiration variable.
            track_score++;
            }
            // Zero out the itiration variable here.
            track_score = 0;
            // If we dont find the score output a message.
            if(!found_score){
                cout << "Score not found.\n>>";
            }
            // Now set score to false because we are about to loop again, thus we have found no scores at the beginning of the loop. 
            found_score = false;
        } else{
            // Else the input MUST be text. Because its not an int, so....
            for(string name : names){
                // If the input matches a name
                if(input == name){
                    // Similar operation as above
                    cout << "Matching name: " << name << "\n>>";
                    found_name = true;
                }
            }
            if(!found_name){
                cout << "Name not found.\n";
            }
            found_name = false;
        } // end else
    } // end while
} // End main.
