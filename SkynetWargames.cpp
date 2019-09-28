//Skynet HK-Ariel Wargams
#include <iostream>
#include <cstdlib>

using std::cout; //So we dont have to type std::cout
using std::endl; //So we dont have to type std::endl
using std::rand; //So we dont have to type std::rand
using std::cin;

int readjust(int high, int low)
{//This function below is the meat and potatoes of the binary search
    return (((high - low) / 2) + low);
}


int main()
{
    int enemyLocation, humanAttempt, humanGuess, linearAttempt, linearGuess, binaryAttempt, randomAttempt, binaryGuess, binaryHigh, binaryLow, randomGuess;
    char endInput;
    
    enemyLocation = rand() % 65;    //This is where the enemy will be
    humanAttempt = 1;               //This is the number of attempts the human has done
    linearAttempt = 1;              //This is the number of attempt the linear guess has done
    binaryAttempt = 1;              //This is the number of attempts the binary has done
    randomAttempt = 1;              //This is the number of attempts the random has done.
    randomGuess = rand() % 65;      //This sets the first random Guess;
    endInput = 'N';                 //This sets the endInput (to restart);
    linearGuess = 1;                //This sets the linearGuess at the bottom;
    binaryHigh = 64;                //This sets the binaryGuess Max to 64;
    binaryLow = 1;                  //This sets the binaryGuess Low to 1;
    binaryGuess = 33;               //This is the first BinaryGuess;
    
    
    
    cout << "Please guess a Number between 1 and 64" << endl;
    cin >> humanGuess;
    while(humanGuess != enemyLocation)
    {
        if(humanGuess > enemyLocation)
        {//Guess is larger than the location
            cout << "Sorry, " << humanGuess << " is too high, guess lower" << endl;
            cin >> humanGuess;
        }
        else if(humanGuess < enemyLocation)
        {//If the guess was too low
            cout << "Sorry, " << humanGuess << " is too low, guess higher" << endl;
            cin >> humanGuess;
        }
        else
        {
            cout << "There seems to be an error cheif";
        }
        humanAttempt++; //Raise the human Attempt
    }
    cout << "AI is working it's magic..." << endl;
    cout << "Please be patient..." << endl;
    
    while(linearGuess != enemyLocation)
    {
        ++linearGuess; //Raise the Linear Guess
        ++linearAttempt; //Raise the linear attempt
    }
    while(binaryGuess != enemyLocation)
    {
        ++binaryAttempt;//Raise the BinaryAttempt;
        if(binaryGuess > enemyLocation)
        {//Guess was higher than target
            binaryHigh = binaryGuess;   //Set the high to current value
            binaryGuess = readjust(binaryHigh, binaryLow); //Run the readjust function
            //cout << binaryGuess << endl; This was used for testing to see if it was working
        }
        else
        {//Guess was lower than target
            binaryLow = binaryGuess;    //Set the low to the currentGuess;
            binaryGuess = readjust(binaryHigh, binaryLow); //Run the readjust function
            //cout << binaryGuess << endl; //This was used for testing to see if it was working
        }
    }
    while(randomGuess != enemyLocation)
    {
        randomGuess = rand() % 65;      //Generate a random number
        //cout << randomGuess << endl;    //This was for testing only
        ++randomAttempt;                //Raise the attempts
    }
    if(humanGuess == enemyLocation)
    {//This runs after the human has properly guessed the Enemy's Location
        cout << "Congradulations! You properly guessed the enemy Location." << endl;
        
        if(humanAttempt == 1)//If they guessed it correct on the first try, give a special one
            cout << "It only took: " << humanAttempt << " guess" << endl;
        else//Took more than one try to guess the enemy location
            cout << "It took: " << humanAttempt << " guesses" << endl;
        
        cout << "Here's how you stacked up to the AI's" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Linear took: " << linearAttempt << endl;
        cout << "Binary took: " << binaryAttempt << endl;
        cout << "Random took: " << randomAttempt << endl;
        cout << "Would You like to play again? (Y/N)" << endl;
        cin >> endInput;
        if(endInput == 'Y' || endInput == 'y')
            main();
    }
    return 0;
}
