#include <iostream>

using namespace std;

int main()
{
    // A (char) = 0x465 (dec)
    // a (char) = 0x97; (dec)
    // http://www.cdrummond.qc.ca/cegep/informat/professeurs/alain/images/ASCII1.GIF

    // Chessboard
    // A-H (horizontal
    // 1-8 (vertical)
    // https://www.chesscentral.com/v/vspfiles/assets/images/assets/chess_board_blank.gif

    char letter = 'a';
    uint16_t number = 1;
    uint16_t offset = 97;

    // Get input
    cout << "Give me a letter (A-H): ";
    cin >> letter;
    cout << "\nGive me a number (1-8): ";
    cin >> number;
    cout << endl;

    // Check to see if combination is legal
    if (number > 8 || number < 1) // outside of number range
        cout << "ERROR! Number undefined" << endl;
    else if (letter < 65) // out of capital range (left)
        cout << "ERROR! Letter undefined" << endl;
    else if (letter > 72 && letter < 61) // outside of range between capital and lowercase (right)
        cout << "ERROR! Letter undefined" << endl;
    else if (letter > 104) // outside of lowercase (right right)
        cout << "ERROR! Letter undefined" << endl;
    else // LEGAL NUMBER AND LETTER
    {
        if ((letter + number) % 2 == 0) // even number
        cout << letter << number << " is a black square" << endl;
        else // uneven number
            cout << letter << number << " is a white square" << endl;

        /*if (letter % 2 == 0) // letter is even
        {
            if (number % 2 == 0) // number even
                cout << letter << number << " is a black square" << endl;
            else // number uneven
                cout << letter << number << " is a white square" << endl;
        }
        else
        {
            if (number % 2 == 0) // number even
                cout << letter << number << " is a white square" << endl;
            else // number uneven
                cout << letter << number << " is a black square" << endl;
        }*/
    }

    cout << "\n------------------------------------";



    return 0;
}
