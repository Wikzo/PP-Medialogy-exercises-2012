#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

/**
Prototype for struct movie (assignment 2
*/
struct Movie{
    string title;
    string director;
    int year;
    int play_time;
};

struct Pixel_gray{
    char value;
};

struct Pixel{
    char r_value;
    char g_value;
    char b_value;
};

/**
Declare an array of integers with room for 63 entries.
Use a for-loop to initialize the array with the numbers
from 1-63.
*/
void one(){
    const int size = 63;
    int int_array[size];

    for(int i=0;i<size;i++)
        int_array[i]=i+1;

    for(int i=0;i<size;i++)
        cout << int_array[i] << " ";
    cout << endl;
}

/**
Define a new struct type suitable for storing information
about a film. It can e.g. contain the film's title, director,
year of production, and playing time. Declare a new variable
of your new film struct type, and fill it in with appropriate
information about your favourite film.
*/
void two(){
    struct Movie m1, m2;
    m1.title = "Watchmen";
    m1.director = "Zack Snyder";
    m1.year = 2009;
    m1.play_time = 162;

    cout << "Movie data:\n" << "Title: " << m1.title << "\nDirector: " << m1.director << "\nYear: " << m1.year << "\nPlaying time: " << m1.play_time << endl;
}

/**
A little array practice: Read 10 numbers into an array. Find
the smallest and biggest number and let them swap places in
the array. Get the user to enter a string, then check if it
is a palindrome.
*/
void three(){
    const int size = 10;
    int int_array[size] = {};
    int min_index = 0;
    int max_index = 0;

    cout << "Please input 10 integers (end each entry with a return):\n";
    for (int i=0;i<10;i++)
        cin >> int_array[i];


    for (int i=0;i<10;i++)
    {
        if (int_array[i] <= int_array[min_index]) min_index = i;
        else if (int_array[i]>int_array[max_index]) max_index = i;
    }

    int tmp;
    tmp = int_array[min_index];
    int_array[min_index] = int_array[max_index];
    int_array[max_index] = tmp;

    for(int i=0;i<10;i++)
        cout << int_array[i] << " ";
    cout << endl;

    string input_string;
    bool palindrome = true;
    cout << "Please enter a string: ";
    cin >> input_string;
    for (string::size_type i = 0; i < input_string.length(); i++)
        if (input_string.length()-1-i < i) break;
        else if (input_string[i] != input_string[input_string.length()-1-i])
        {
            palindrome = false;
            break;
        }
    if (palindrome)
        cout << "String is a palindrome." << endl;
    else
        cout << "String is not a palindrome." << endl;
}


/**
Keeping secrets from others is often important. One particularly
simple way of making it hard for people to read a text is the ROT13
algorithm, http://en.wikipedia.org/wiki/Rot-13. Implement the ROT13
algorithm in the following way: Ask the user to enter a word, use
ROT13 on the word, and output the result. Stick to words that use
the 26 letters of the English alphabet. You should not try to make
it work with Danish letters, æ, ø, and å.
*/
void four(){
    string input_string;

    cout << "Please enter a string: ";
    cin >> input_string;

    for (string::size_type i = 0; i < input_string.length(); i++) {
        if ((input_string[i] >= 65 && input_string[i] <= 77)||(input_string[i]>=97 && input_string[i]<=109))
            input_string[i] = input_string[i]+13;
        else input_string[i] = input_string[i]-13;
    }

    cout << "ROT-13 code: " << input_string << endl;
}

/**
Images are often represented using arrays and structs. Design a
solution for storing a greyscale image (of fixed, known size)
using arrays and structs.
*/
void five(){
    const int imagesize_x = 200;
    const int imagesize_y = 100;
    struct Pixel_gray grayscale_image[imagesize_x][imagesize_y];

    for(int i=0; i<imagesize_x;i++)
        for(int j=0;j<imagesize_y;j++)
            grayscale_image[i][j].value = 0;
}

/**
Adapt your design to also accept RGB colour images. Implement
the image designs that you just made.
*/
void six(){
    const int imagesize_x = 200;
    const int imagesize_y = 100;
    struct Pixel image[imagesize_x][imagesize_y];

    for(int i=0; i<imagesize_x;i++)
        for(int j=0;j<imagesize_y;j++){
            image[i][j].r_value = 0;
            image[i][j].g_value = 0;
            image[i][j].b_value = 0;
        }
}

//Seven cannot be shown today, as it is too similar with one of the miniprojects

// Implement a party host agent that visits all his guests once in a while and has a little chat with them.
// Note: Store the guest IDs in an array and traverse the array to get the next guest to talk to.
void agent_1(){
    string greeting = "Hi, nice that you could come.";
    const int number_guests = 4;
    int guests[] = {1,2,3,4};

    for (int i = 0; i<number_guests; i++)
    {
       // send command in the client program
        cout << "goto #agent 0 #dest " << guests[i]<<endl;
        // send command in the client program
        cout << "act #agent 0 #anim 34 #tts " << greeting << endl;
    }
}


int getRandomNumber(int max){
     return rand()%(max);
}

//Extend the party host program by randomly visiting guests, i.e. create a function that gives you a
//random index from your array and let the party host agent visit the guest agent with the ID stored at
//that index.
void agent_2(){
    string greeting = "Hi, nice that you could come.";
    const int number_guests = 4;
    int guests[] = {1,2,3,4};

    for (int i = 0; i<10; i++)
    {
        // send command in the client program
        cout << "goto #agent 0 #dest " << guests[getRandomNumber(number_guests)]<<endl;
        //cout << "act #agent 1 #anim 34 #tts " << greeting << endl;
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
            case 5: five(); break;
            case 6: six(); break;
            case 7: agent_1();break;
            case 8: agent_2();break;
            case 9: break;
            default: cout << "Try again!" << endl;
            }
    }
    while (input!=9);

    return 0;
}
