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

    cout << "************************************************\n";
    cout << "Welcome to the name database.\n>>";
    cout << "Enter a name to search: \n>>";

    while(cin >> input){

        if(input == "|"){
            break;
        } else if(isdigit(input[0])){
            for (int score : scores){
                if(stoi(input) == score){
                    cout << "Matching score: " << score << "\n";
                    found_score = true;
                }
            }
            if(!found_score){
                cout << "Score not found.\n";
            }
            found_score = false;
        } else{
            for(string name : names){
                if(input == name){
                    cout << "Matching name: " << name << "\n";
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
