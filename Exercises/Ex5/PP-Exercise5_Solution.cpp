#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

float average(float a, float b){
    return (a+b)/2;
}

/**
Implement a function that, given two floating point numbers,
computes the average of the two numbers and prints it to the
screen.
*/
void one(){
    float f1, f2;

    cout << "Please input two float number (e.g. 2.5): ";
    cin >> f1 >> f2;

    cout << "The average is: " << average(f1,f2) << endl;
}



int close_to_zero(int a, int b){
    if ((a*a)<=(b*b)) return a;
    else return b;
}

/**
Make a function that given two integers returns the one closest
to zero.
*/
void two(){
    int i1, i2;

    cout << "Please input two integers: ";
    cin >> i1 >> i2;

    cout << close_to_zero(i1, i2) << " is closer to zero." << endl;;
}


void billsAndCoins (int amount)
{
    int bAc[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 9; i>=0; i--){
        result[i] = amount/bAc[i];
        amount = amount - (result[i]*bAc[i]);
        if (result[i]>0) cout << result[i] << " " << bAc[i] << " bills/coins" << endl;
    }

}
/**
Make a function that given a payable amount of DKK, produces the
smallest number of bills and coins needed to pay that amount.
*/
void three(){
    int amount;

    cout << "Please input amount in DKK (no decimals): ";
    cin >> amount;

    billsAndCoins(amount);
}

int getRandomNumber(int max){
    int result;
    do {
        result = rand()%(max+1);
    } while (result == 0);

    return result;
}

string check_guess(int guess, int n2guess){
    if (guess<n2guess) return "larger";
    else return "smaller";
}

/**
Make a small game where the player has to guess a random number in
the range 0-100, by getting smaller than/greater than hints from
the computer after each guess. Use functions to structure your code.
*/
void four(){

    int guess;
    int number_to_guess = getRandomNumber(100);
    string help;

    cout << "Please guess a number between 1 and 100: ";
    cin >> guess;

    while (guess!=number_to_guess) {
        cout << "Try a " << check_guess(guess, number_to_guess) << " number: ";
        cin >> guess;
    }

    cout << "Congratulations! The number was " << number_to_guess << endl;
}

int ask_for_id(int agent_id){
    int destination = agent_id;
    do
    {
        cout << "Which other agent should agent number " << agent_id <<" visit next?" << endl;
        cin >> destination;
    } while (destination == agent_id);
    return destination;
}

// Implement a function that in each iteration of the main while loop asks the user for a new destination (in
// terms of an agent ID). Return this ID to the the main while loop and let the agent move to that destination.
void agent(){
    int agent_id = 0;
    int i = 10;
    while (i>0){
        int destination = ask_for_id(agent_id);
        cout << "goto #agent " << agent_id << " #dest " << destination << endl;
        i--;
    }
}

int main()
{
    int input = 0;

    srand((unsigned int)time(0));

    do {
        cout << "Input the number of the exercise you would like to see (exit with 9): ";
        cin >> input;
        switch (input){
            case 1: one();break;
            case 2: two();break;
            case 3: three();break;
            case 4: four(); break;
            case 5: agent(); break;
            case 9: break;
            default: cout << "Try again!" << endl;
            }
    }
    while (input!=9);

    return 0;
}
