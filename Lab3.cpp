#include <iostream>
#include <string>
using namespace std;

class GuessingGame{
    private:
        string playerName;
        int secretNumber[3];
        int Score;

    public:
        GuessingGame():playerName{""},secretNumber{0,0,0},Score{0}{}

        GuessingGame(string name,int num1,int num2,int num3,int score){
            playerName=name;
            secretNumber[0]=num1;
            secretNumber[1]=num2;
            secretNumber[2]=num3;
            if(score>=0){
                Score=score;
            }
            else{
                Score=0;
            }
        }
        void setPlayerName(string name){ playerName=name;}
        string getPlayerName() const { return playerName;}

        void displayMenu(){
            cout  << "========== NUMBER GUESSING GAME ==========" <<endl;
            cout << "1. Easy" <<endl;
            cout << "2. Medium" <<endl;
            cout << "3. Hard" <<endl;
            cout << "4. Display Score" <<endl;
            cout << "5. Exit" <<endl;
            cout << "Enter your choice: ";
        }

        bool checkGuess(int index,int guess_num){
            if(index==1){
                if(guess_num==secretNumber[0]){
                    return true;
                }
                else if(guess_num>secretNumber[0]){
                    cout << "Too high!" <<endl;
                }
                else{
                    cout << "Too low!" <<endl;
                }
            }
            else if(index==2){
                if(guess_num==secretNumber[1]){
                    return true;
                }
                else if(guess_num>secretNumber[1]){
                    cout << "Too high!" <<endl;
                }
                else{
                    cout << "Too low!" <<endl;
                }
            }
            else if(index==3){
                if(guess_num==secretNumber[2]){
                    return true;
                }
                else if(guess_num>secretNumber[2]){
                    cout << "Too high!" <<endl;
                }
                else{
                    cout << "Too low!" <<endl;
                }
            }
            else{
                cout << "Invalid index!" <<endl;
            }
            return false;
        }

        int displayScore() const {
            return Score;
        }

        void startGame(){
            int choice,guess_num,attempts;
            do{
                displayMenu();
                cin >> choice;
                switch(choice){
                    case 1:{
                        cout << "You selected EASY level." <<endl;
                        for(int attempts=5;attempts>0;attempts--){
                            cout << "Guess the number between 1 and 10." <<endl;
                            cout << "You have " << attempts << " attempts." <<endl;
                            cout << "Enter your guess: ";
                            cin >> guess_num;
                            if(guess_num>=1 && guess_num<=10){
                                if(checkGuess(choice,guess_num)==true){
                                cout << "Congratulations!" <<endl;
                                cout << "You guessed the correct number!" <<endl;
                                Score+=10;
                                cout << "Score: " << displayScore() <<endl;
                                break;
                                }
                                else{
                                    if(attempts==1){
                                        cout << "Sorry, you have used all your attempts." <<endl;
                                    }
                                }
                            }
                            else{
                                cout << "Invalid input." <<endl;
                                attempts++;
                                continue;
                            }
                        }
                        break;
                    }
                    case 2:{
                        cout << "You selected MEDIUM level." <<endl;
                        for(int attempts=7;attempts>0;attempts--){
                            cout << "Guess the number between 1 and 50." <<endl;
                            cout << "You have " << attempts << " attempts." <<endl;
                            cout << "Enter your guess: ";
                            cin >> guess_num;
                            if(guess_num>=1 && guess_num<=50){
                                if(checkGuess(choice,guess_num)==true){
                                cout << "Congratulations!" <<endl;
                                cout << "You guessed the correct number!" <<endl;
                                Score+=20;
                                cout << "Score: " << displayScore() <<endl;
                                break;
                                }
                                else{
                                    if(attempts==1){
                                        cout << "Sorry, you have used all your attempts." <<endl;
                                    }
                                }
                            }
                            else{
                                cout << "Invalid input." <<endl;
                                attempts++;
                                continue;
                            }
                        }
                        break;
                    }
                    case 3:{
                        cout << "You selected HARD level." <<endl;
                        for(int attempts=10;attempts>0;attempts--){
                            cout << "Guess the number between 1 and 100." <<endl;
                            cout << "You have " << attempts << " attempts." <<endl;
                            cout << "Enter your guess: ";
                            cin >> guess_num;
                            if(guess_num>=1 && guess_num<=100){
                                if(checkGuess(choice,guess_num)==true){
                                cout << "Congratulations!" <<endl;
                                cout << "You guessed the correct number!" <<endl;
                                Score+=30;
                                cout << "Score: " << displayScore() <<endl;
                                break;
                                }
                                else{
                                    if(attempts==1){
                                        cout << "Sorry, you have used all your attempts." <<endl;
                                    }
                                }
                            }
                            else{
                                cout << "Invalid input." <<endl;
                                attempts++;
                                continue;
                            }
                        }
                        break;
                    }
                    case 4:{
                        cout << "Your current score is: " << displayScore() <<endl;
                        break;
                    }
                    case 5:{
                        cout << "Exiting the game. Thank you for playing!" <<endl;
                        break;
                    }
                    default:{
                        cout << "Invalid choice. Please try again." <<endl;
                        break;
                    }
                }
                        
            }while(choice!=5);

            
        }
};

int main(){
    GuessingGame game("",7,35,82,0);
    cout << "Enter your name: ";
    string name;
    getline(cin,name);
    game.setPlayerName(name);
    cout << "Welcome, " << game.getPlayerName() << "!" <<endl;
    game.startGame();
    return 0;
}