//Name: Denver S. Reyes
//Activity: FINAL
//Description: Hangman game with conditionals, looping statements, functions(void and with parameters), file stream, and array.
//Date: 12-10-2021

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

//Function Definition
void promptAndWait();
void play(string words[], string word, int& high_score,  bool& game_continue);
void checker(int& num_try, char guess, string word, string& hide_w, bool& correct_guess);
void write(int high_score, int category, string username);
void read();


int main(){

    int ch, category, high_score = 0;
	char username[50];
	bool game_continue = true, loop = true;

	cout << "Enter your username: ";
	cin.getline(username, 50);
	system("cls");

    do
    {	
		
		game_continue = true;
		
		//Main Menu
        system("cls"); 
        cout << "  << Hangman >>" << endl;
		cout <<"                " << endl;
		cout <<" _____________  " << endl;
		cout <<" |      }       " << endl;
		cout <<" |      O       " << endl;
		cout <<" |      |       " << endl;
		cout <<" |    / | \\    " << endl;
		cout <<" |   /  |  \\   " << endl;
		cout <<" |     / \\    " << endl;
		cout <<" |    /   \\   " << endl;
		cout <<" |              " << endl;
		cout <<" |______________" << endl;
        cout << "\n [1] Play " << endl;
        cout << " [2] Instructions " << endl;
        cout << " [3] View Previous Scores Attempts " << endl;
        cout << " [4] Exit " << endl;
        cout << " Select an option: ";
        cin >> ch;
		cout << endl;
        
        switch(ch)
        {
            case 1:{

				select:
				cout << "<< Choose a Category of Words >>" << endl;
				cout << "[1] Months " << endl;
				cout << "[2] Computer Hardware " << endl;
				cout << "[3] Programming Jargons " << endl;
				cin >> category;

				switch(category){
					case 1:{
						string words[]{"january", "february", "march", "june", "july", "august", "september", "october", "november", "december"}; // Months
						string word;
						system("cls");
						while(game_continue == true){
							play(words, word, high_score, game_continue);
						}
						write(high_score, category, username);
						promptAndWait();
						break;
					}

					case 2:{
						string words[]{"motherboard", "cpu", "videocard", "ram", "hdd", "ssd", "powersupply", "keyboard", "mouse", "monitor"}; // Computer hardware
						string word;
						system("cls"); 
						while(game_continue == true){
							play(words, word, high_score, game_continue);
						}
						write(high_score, category, username);
						promptAndWait();
						break;
					}

					case 3:{
						string words[]{"algorithm", "compiler", "ide", "runtime", "syntax", "ssd", "api", "build", "framework", "git"}; // programming jargons
						string word;
						system("cls"); 
						while(game_continue == true){
							play(words, word, high_score, game_continue);
						}
						write(high_score, category, username);
						promptAndWait();
						break;
					}

					default:{
						cout << "Invalid Input\n" << endl;
						goto select;
						promptAndWait();
						break;
					}
				}
                break;
            }

            case 2:{
				cout << "Hangman is a guessing game in which you must first select the category of words that you want, \nand then the game will ask you to guess the letters of a selected word. \nIf you guess incorrectly, a part of the stickman will be drawn, \nand you have six tries before your stickman is hanged.\n";
				promptAndWait();
                break;
            }

			case 3:{
				read();
				promptAndWait();
				break;
			}

			case 4:{
				cout << "Thank you for playing !!!" << endl;
				loop = false;
				break;
			}
            
            default:{
				cout << "Invalid Input" << endl;
				promptAndWait();
                break;
            }
        }
    } while (loop == true);
    
}


//Function Declaration
void promptAndWait(){

    cin.ignore();
    cout << "\nPress Enter or Return to Continue...";
    cin.get();
}

void play(string words[], string word, int& high_score, bool& game_continue){

	int num_try = 6;
	int n=rand()% 12;
	char guess;
	bool correct_guess = false;
	char previous_guess[7];
	previous_guess[0] = '\0';
	previous_guess[6] = '\0';


	srand(time(NULL)); //pick a random word from the array
    word=words[n];
	string hide_w(word.length(), '*'); //hide the characters of the selected word
	
	for(int i = 1; i < 6; i++){
		previous_guess[i] = '-';
	}
	
	while (num_try !=0 ){

		correct_guess = false;

		cout << "\nThe word you have to guess is: " << hide_w << endl;
		cout << "\nThe word have " << word.length() << " letters" << endl;
		cout << "\nYou have " << num_try <<" more guesses " << endl;
		if(previous_guess[0] == '\0'){
			cout << endl;
		}

		else{ 
			cout << "\nYou have guessed : " << previous_guess << endl;
		}

		cout << "\nGuess a letter : ";
		cin >> guess;

		checker(num_try, guess, word, hide_w, correct_guess);

		if(word == hide_w){
			cout << "\nCongratulations, you have correctly identified all of the letters in the word " << word << endl;\
			high_score++;
			break;
   		}
	   
		switch(num_try){

			case 6:{
				cout <<"                " << endl;
				cout <<" _____________  " << endl;
				cout <<" |      }       " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |______________" << endl;
				break;
			}

			case 5:{
				cout <<"                " << endl;
				cout <<" _____________  " << endl;
				cout <<" |      }       " << endl;
				cout <<" |      O       " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |______________" << endl;
				if(correct_guess == false){
					previous_guess[0] = guess;
				}
				break;
			}

			case 4:{
				cout <<"                " << endl;
				cout <<" _____________  " << endl;
				cout <<" |      }       " << endl;
				cout <<" |      O       " << endl;
				cout <<" |      |       " << endl;
				cout <<" |      |       " << endl;
				cout <<" |      |       " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |______________" << endl;
				if(correct_guess == false){
					previous_guess[1] = guess;
				}
				break;
			}

			case 3:{
				cout <<"                " << endl;
				cout <<" _____________  " << endl;
				cout <<" |      }       " << endl;
				cout <<" |      O       " << endl;
				cout <<" |      |       " << endl;
				cout <<" |    / |       " << endl;
				cout <<" |   /  |       " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |______________" << endl;
				if(correct_guess == false){
					previous_guess[2] = guess;
				}
				break;
			}

			case 2:{
				cout <<"                " << endl;
				cout <<" _____________  " << endl;
				cout <<" |      }       " << endl;
				cout <<" |      O       " << endl;
				cout <<" |      |       " << endl;
				cout <<" |    / | \\    " << endl;
				cout <<" |   /  |  \\   " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |              " << endl;
				cout <<" |______________" << endl;
				if(correct_guess == false){
					previous_guess[3] = guess;
				}
				break;
			}

			case 1:{
				cout <<"                " << endl;
				cout <<" _____________  " << endl;
				cout <<" |      }       " << endl;
				cout <<" |      O       " << endl;
				cout <<" |      |       " << endl;
				cout <<" |    / | \\    " << endl;
				cout <<" |   /  |  \\   " << endl;
				cout <<" |     /        " << endl;
				cout <<" |    /         " << endl;
				cout <<" |              " << endl;
				cout <<" |______________" << endl;
				if(correct_guess == false){
					previous_guess[4] = guess;
				}
				break;
			}

			case 0:{
				cout <<"                " << endl;
				cout <<" _____________  " << endl;
				cout <<" |      }       " << endl;
				cout <<" |      O       " << endl;
				cout <<" |      |       " << endl;
				cout <<" |    / | \\    " << endl;
				cout <<" |   /  |  \\   " << endl;
				cout <<" |     / \\    " << endl;
				cout <<" |    /   \\   " << endl;
				cout <<" |              " << endl;
				cout <<" |______________" << endl;
				cout <<"NOOOOOOO!...you've been hanged." << endl;
				game_continue = false;
				break;
			}

			default:{
				break;
			}
		}
	}

}

void checker(int& num_try, char guess, string word, string& hide_w, bool& correct_guess){
	
   
   for(int i = 0; i < hide_w.length(); i++){
	   
	   if(word[i] == guess){
			hide_w[i] = guess;
			cout << guess << " is a correct letter " << endl;
			correct_guess = true;
	   }
   }

   if(correct_guess == false){
		num_try --;
		cout << "Incorrect Guess " << guess << " is not present in the word" << endl;
	}

}
	
void write(int high_score, int category, string username){
	//File

    ofstream outfile;
    outfile.open("High_score.txt", ios:: app);

	string type;

	if(category == 1){
		type = "Month";
	}

	else if (category == 2){
		type = "Computer Hardware";
	}

	else if (category == 3){
		type = "Programming Jargons";
	}

	outfile << "---------------------------------------" << endl;
	outfile << "Username : " << username << endl;
	outfile << "Category : " << type << endl;
	outfile << "High Score : " << high_score << endl;
	outfile << "---------------------------------------" << endl;
	outfile.close();

}

void read(){

    //Variable

    string data;

    //File

    ifstream MyReadFile("High_score.txt");

    //Display the data in the file

    while (getline (MyReadFile, data)) {
        
        
        cout << data << endl;
        
    }

    MyReadFile.close();

}	