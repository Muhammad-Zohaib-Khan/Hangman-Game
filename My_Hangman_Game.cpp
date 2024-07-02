#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

#define max_attempt 6
#define word_list_size 8

const char* get_random_word(){
    static const char* word[word_list_size]={"orange","apple","banana", "cherry","grape","kiwi","peach","olive"};
    int index=rand() % word_list_size;
    return word[index];
}

class HangmanGame{
  private:
      const char* secret_word;  //char variable
      char* current_word;     //array
      int attempt_left;        //integer variable
      char* guessed_letter;    //array
      int guessed_count;       //integer variable
      
      void display_info(){
          cout<<"Word "<<current_word<<endl;
          cout<<"Attempt Left "<< attempt_left<<endl;
          for (int i=0;i<guessed_count;i++){
              cout<<guessed_letter[i]<<" ";
          }
          cout<<endl;
      }
      
      bool already_guessed(char guess){
          for(int i=0;i<guessed_count;i++){
              if (guessed_letter[i]==guess){
              return true;
          }
          }
          return false;
      }
      
      bool update_word(char guess){
          bool correct_guess=false;
          for (int i=0;i<strlen(secret_word);i++){
              if (secret_word[i]==guess){
                  current_word[i]=guess;
                  correct_guess=true;
              }
          }
          guessed_letter[guessed_count++]=guess;
          return correct_guess;
      }
      
        void Draw_Hangman(int attempt_left) {
              
        if (attempt_left == 5) {
            cout << " _____" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        } else if (attempt_left == 4) {
            cout << " _____" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |    |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        } else if (attempt_left == 3) {
            cout << " _____" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   /|" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        } else if (attempt_left == 2) {
            cout << " _____" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   /|\\" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        } else if (attempt_left == 1) {
            cout << " _____" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   /|\\" << endl;
            cout << " |   /" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        } else if (attempt_left == 0) {
            cout << " _____" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   /|\\" << endl;
            cout << " |   / \\" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        }
    }

  public:
       HangmanGame(){
           srand(static_cast<unsigned int>(time(nullptr)));
           secret_word= get_random_word();
           current_word= new char[strlen(secret_word)+1];
           for(int i=0;i<strlen(secret_word);i++){
               current_word[i]='_';
           };                                                
           current_word[strlen(secret_word)]='\0';
           attempt_left=max_attempt;
           guessed_letter=new char[26];
           guessed_count=0;
       }
       ~HangmanGame(){
           delete [] current_word;
           delete [] guessed_letter;
       }
       
       void play() {
           // Print welcome message
           cout << "Welcome to Hangman!" << endl;
           cout << "Category: Fruits" << endl;
           cout << "You have " << attempt_left << " attempts to guess the fruit name." << endl;
           while(attempt_left>0){
               display_info();
               char guess;
               cout<<"Guess a letter: ";
               cin>>guess;
               if (isalpha(guess)){
                   guess=tolower(guess);
                   if (already_guessed(guess)){
                       cout<<"The letter is Already Guessed";
                   }else{
                       bool correctguess=update_word(guess);
                       if (correctguess){
                           cout<<"Good Guess"<<endl;
                           if (strcmp(current_word,secret_word)==0){
                               display_info();
                               cout<<"Congratulation you guessed the word: "<<secret_word <<endl;
                               return;
                           }
                       }else{
                           cout<<"incorrect_guess"<<endl;
                           attempt_left--;
                           Draw_Hangman(attempt_left);
                       }
                   }
               }else{
               cout<<"You Must Enter a valid Letter"<<endl;
           }
           }
           if (attempt_left==0){
               cout<<"You have run out of attempts the word was"<<secret_word<<endl;
           }
       }
};

int main() {
    HangmanGame myGame;
    myGame.play();
    return 0;
}
