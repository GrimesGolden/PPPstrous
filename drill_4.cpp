#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() {char ch; cin>>ch; }

// Chapter 4 drill, PPP Bjarne Stroustrop Second Edition.


// Vectors
vector<double> measurements; // Vector and int variables to store doubles.
const vector<string> legal_units = {"m", "cm", "in", "ft"};

// Variables
// Conv Factors
const int CM_CONV = 100; // One meter = 100 cm
const int FT_CONV = 12; // One ft == 12 in
const double IN_CONV = 2.54; // One in = 2.54 cm
// This will track user input for unit and measurement.
double user_num;
string user_unit;
// Track total meters, total values entered, smallest value, largest value, and whether it is first itiration of loop.
double user_meters = 0;
double smallest_num = 0;
double largest_num = 0;
bool first_run = true;
double total_sum = 0;
int total_values = 0;

// Functions
bool unit_verified(string unit)
{
    // Searches vector to verify if user input is accepted unit.
    bool unit_verified = false;

    for(string legal_unit:legal_units){
        if(unit == legal_unit){
            unit_verified = true;
        }
    }

    // Returns true if unit is accepted
    return unit_verified;
}

void init_run(){
    // Initializes starting variables and sets init counter to false.
    if(first_run){
        smallest_num = user_num;
        largest_num = user_num;
        first_run = false;
    }
}

void set_min_max(double number){
    // Sets min and max variables from stored user data. 
    if(number < smallest_num){
            smallest_num = user_num;
        }

        if(number > largest_num){
            largest_num = user_num;
        }
}

void inc_sum(double sum){
    // Increments total sum. 
    total_sum += sum;
}

void inc_values(){
    total_values += 1;
}

void read_to_console(){
    // Reads info to console and asks user for further input. 
    cout << "The smallest number entered so far is " << smallest_num << "\n";
    cout << "The largest number entered so far is " << largest_num << "\n";
    cout << "\n";
    cout << "You entered '" << user_unit << "' as your units.";
    cout << "Thats " << user_meters << " meters!\n";
    cout << " You have entered " << total_sum << " meters, so far!\n";
    cout << " And " << total_values << " measurements!\n";
    cout << "Enter another number!\n";
}

void sort_and_print(){
    // Sorts vector of measurements and prints them to console.
    sort(measurements.begin(), measurements.end());

    for(double measurement: measurements){
        cout << measurement << ", ";
    }

    cout << "\n";
}

double in_to_meters(double num){
    num *= IN_CONV;
    num = num/CM_CONV;
    return num;
}

double ft_to_meters(double num){
    num *= FT_CONV;
    num = in_to_meters(num);
    return num;
}

double convert_to_meters(string unit, double num){
    // Takes a string representing the unit, along with a double for the actual measurement.
    // Converts according to standard conversion factors.
    if(unit == "cm"){
        num = num/CM_CONV;
        return num;
    }
    if (unit == "in"){
        num = in_to_meters(num);
        return num;
    }
    if (unit == "ft"){
        num = ft_to_meters(num);
        return num;
    }
    if (unit == "m"){
        return num;
    }
}

void exit_protocol(){
    // Prints all final data and an exit message. 
    cout << "Terminating data entry...\n" << " Congratulations, ";
    cout << "You entered " << total_values << " measurements. For a total of " << total_sum << " meters. "; 
    cout << "The smallest number entered was " << smallest_num << "\n";
    cout << "The largest number entered was " << largest_num << "\n";
    cout << "God bless you for your efforts, here are the measurements in ascending order.\n";
    sort_and_print();
    cout << "Goodbye\n";
}


// Main
int main()
{   
    cout << "Welcome please enter a number, followed by a space and the units, cm, m, in or ft. Example: 32 ft\n";
    cout << "Enter data below\n>>";

    // Recieve input as long as it is an double followed by a unit string. 

    while(cin >> user_num >> user_unit){

        if(unit_verified(user_unit)){
            // If the unit is correct then.
            // Initialize variables.
            init_run();
            // Set min_max.
            set_min_max(user_num);
            // Convert to meters and push to vector.
            user_meters = convert_to_meters(user_unit, user_num);
            measurements.push_back(user_meters);
            // Now increment trackers.
            inc_sum(user_meters);
            inc_values();
            // Read data to console.
            read_to_console();
        }
        // If unit is incorrect then print a little message, and attempt to re-enter data. 
        if(!unit_verified(user_unit)){
            cout << "Sorry, but '" << user_unit << "' is not a valid unit. Please re-enter data.\n>>";
        }


    }

    // After breaking out of loop, read out all data.
    exit_protocol();

    return 0;
}