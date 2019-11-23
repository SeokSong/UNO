#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//////////////////////////////////////////////////////////////////////////////////
// -- Deck.h 
class Deck{
    private:
        int num;
        string card;
        string color;
    public:
        Deck();
        Deck(int, string, string);
        void setNum(int);
        int getNum();
        void setCard(string);
        string getCard();
        void setColor(string);
        string getColor();
        int drawCard();
        string drawColor(int);
        string drawSpecial(int);
        
};
//////////////////////////////////////////////////////////////////////////////////
// -- Deck.cpp
Deck :: Deck(){
    int num = 0;
    string card = "";
    string color = "";
}
Deck :: Deck(int num_, string card_, string color_){
    num = num_;
    card = card_;
    color = color_;
}
void Deck :: setNum(int Nnum){
    num = Nnum; //sets num
}
int Deck :: getNum(){
    return num; //gets num
}
void Deck :: setCard(string Card){
    card = Card; //sets card
}
string Deck :: getCard(){
    return card; //gets card
}
void Deck :: setColor(string Color){
    color = Color; //set color 
}
string Deck :: getColor(){
    return color; //get color
}
int Deck :: drawCard(){
    int deck[100] = {1, 0, 2, 3, 3, 3, 3, 2, 3, 3, 0, 3, 2, 3, 3, 3, 2, 3, 3, 2, 1, 3, 3, 3, 3, 3, 2, 3, 3, 3, 1, 1, 0, 1, 3, 3, 2, 2, 2, 3, 1, 2, 3, 3, 2, 3, 3, 2, 0, 3, 1, 3, 3, 2, 3, 3, 3, 3, 3, 3, 1, 3, 2, 3, 3, 3, 2, 3, 2, 3, 1, 3, 3, 3, 3, 3, 0, 3, 3, 3, 1, 3, 3, 2, 3, 3, 3, 3, 2, 3, 1, 3, 3, 3, 2, 3, 0, 3, 3, 2};
    // srand(13);
    int i = random() % 100; //gets a random indx for the deck array
    //5% for +4
    //10% for color changer 
    //20% for speical 
    //65% for normal num
    int num = deck[i];
    return num;
}
string Deck :: drawColor(int card){
    string error = "Error at drawCard";
    string color;
    // srand(6);
    int num = random() % 4; //random num
    //remeber card and num are different
    if(card == 0){ //0 == plus 4
        color = "Plus 4";
    } 
    else if(card == 1){
        color = "Color Changer";
    }
    else if(num == 0){ //num is used to generate a random color if it isnt color changer or plus 4
        color = "Green";
    }
    else if(num == 1){
        color = "Red";
    }
    else if(num == 2){
        color = "Blue";
    }
    else if(num == 3){
        color = "Yellow";
    }
    else{
        return error;
    }
    return color;
}
string Deck :: drawSpecial(int card){
    int num;
    string type;
    if(card == 2){
        num = random() % 3; //random num
        //33% chance for and of these
        if(num == 0){
            type = "Skip";
        }
        else if(num == 1){
            type = "Reverse";
        }
        else{
            type = "+2";
        }
        return type;
    }
    else{
        if(card == 0 || card == 1){ //checks if its a plus 4 or color changer
            if(card == 0){
                type = "Plus 4";
            }
            else{
                type = "Color Changer";
            }
        }
        else{
            type = to_string(random() & 10); //if its a 3 then we will get a random num and then convert it to string
        }
        return type;
    }
    return "Error at drawSpecial";
}
//////////////////////////////////////////////////////////////////////////////////
// -- PlayerClass.h
class player{
    private:
        vector<string> deck1Num;
        vector<string> deck1Color;
    public:
        player();
        player(vector<string>, vector<string>);
        void printDeck();
        void setDeck1Num(string);
        void setDeck1Color(string);
        string getDeck1Num(int);
        string getDeck1Color(int);
        int quitMenu();
        int deck1Size();
        void playedCard(int);
        
};
//////////////////////////////////////////////////////////////////////////////////
// -- PlayerClass.cpp
player :: player(){
    deck1Color = {};
    deck1Num = {};
}
player :: player(vector<string> deck1Num_, vector<string> deck1Color_){
    int size = deck1Num_.size();
    for(int i = 0; i < size; i++){
        deck1Num[i] = deck1Num_[i]; 
        deck1Color[i] = deck1Color_[i];
    }
}
void player :: printDeck(){
    int deckSize = deck1Size(); //deck size
    for(int i = 0; i < deckSize; i++){
        string color = getDeck1Color(i); //get color
        string card =getDeck1Num(i); //get card
        cout << i + 1 << " Color: " << color << ", Card: " << card <<  endl; //print
    }
}
string player :: getDeck1Num(int idx){
    int size = deck1Size(); //size
    if (idx < size && idx >= 0){
        return deck1Num[idx] ; //gets the value at that index
    }
}
string player :: getDeck1Color(int idx){
    int size = deck1Size();
    if (idx < size && idx >= 0){
        return deck1Color[idx] ; //gets the value at that index
    }
}
void player :: setDeck1Num(string card){
    deck1Num.push_back(card); //adds to vector
}
void player :: setDeck1Color(string color){
    deck1Color.push_back(color); //adds to vector
}
int player :: quitMenu(){
    int quit = 0;
    //this will always be a option when the user plays to quit the game
    cout << "Would you like to quit the game? 0 == Continue, 1 == Quit" << endl;
    cin >> quit;
    return quit;
}
int player :: deck1Size(){
    int deck1Size = deck1Num.size(); //get size
    return deck1Size;
}
void player :: playedCard(int idx){
    deck1Num.erase(deck1Num.begin()+idx); //erases the value at idx
    deck1Color.erase(deck1Color.begin()+idx); //erases the value at idx
}
//////////////////////////////////////////////////////////////////////////////////
// -- computer.h 
class computer{
    private:
        vector<string> deck2Num;
        vector<string> deck3Num;
        vector<string> deck4Num;
        vector<string> deck2Color;
        vector<string> deck3Color;
        vector<string> deck4Color;
    public:
        computer();
        computer(vector<string>, vector<string>, vector<string>, vector<string>, vector<string>, vector<string>);
        void setDeck2Num(string);
        void setDeck2Color(string);
        string getDeck2Num(int);
        string getDeck2Color(int);
        void setDeck3Num(string);
        void setDeck3Color(string);
        string getDeck3Num(int);
        string getDeck3Color(int);
        void setDeck4Num(string);
        void setDeck4Color(string);
        string getDeck4Num(int);
        string getDeck4Color(int);
        int deck2Size();
        int deck3Size();
        int deck4Size();
        void computer2PlayedCard(int);
        void computer3PlayedCard(int);
        void computer4PlayedCard(int);
};
//////////////////////////////////////////////////////////////////////////////////
// -- computer.cpp
computer :: computer(){
    vector<string> deck2Num = {};
    vector<string> deck3Num = {};
    vector<string> deck4Num = {};
    vector<string> deck2Color = {};
    vector<string> deck3Color = {};
    vector<string> deck4Color = {};
}
computer :: computer(vector<string> deck2Num_, vector<string> deck2Color_, vector<string> deck3Num_, vector<string> deck3Color_, vector<string> deck4Num_, vector<string> deck4Color_){
    int size2 = deck2Num_.size();
    for(int i = 0; i < size2; i++){
        deck2Num[i] = deck2Num_[i]; //sets every value in rating array to 0
        deck2Color[i] = deck2Color_[i]; //sets every value in rating array to 0
    }
    int size3 = deck3Num_.size();
    for(int i = 0; i < size3; i++){
        deck3Num[i] = deck3Num_[i]; //sets every value in rating array to 0
        deck3Color[i] = deck3Color_[i]; //sets every value in rating array to 0
    }
    int size4 = deck4Num_.size();
    for(int i = 0; i < size4; i++){
        deck4Num[i] = deck4Num_[i]; //sets every value in rating array to 0
        deck4Color[i] = deck4Color_[i]; //sets every value in rating array to 0
    }
}
int computer :: deck2Size(){
    int size = deck2Num.size(); //size
    return size;
}
int computer :: deck3Size(){
    int size = deck3Num.size(); //size
    return size;
}
int computer :: deck4Size(){
    int size = deck4Num.size(); //size
    return size;
}
string computer :: getDeck2Num(int idx){
    int size = deck2Size();
    if (idx < size && idx >= 0){
        return deck2Num[idx]; //gets the value at that index
    }
}
string computer :: getDeck2Color(int idx){
    int size = deck2Size();
    if (idx < size && idx >= 0){
        return deck2Color[idx]; //gets the value at that index
    }
}
void computer :: setDeck2Num(string card){
    deck2Num.push_back(card); //adds to vector
    
}
void computer :: setDeck2Color(string color){
    deck2Color.push_back(color); //adds to vector
}
string computer :: getDeck3Num(int idx){
    int size = deck3Size();
    if (idx < size && idx >= 0){
        return deck3Num[idx]; //gets the value at that index
    }
}
string computer :: getDeck3Color(int idx){
    int size = deck3Size();
    if (idx < size && idx >= 0){
        return deck3Color[idx]; //gets the value at that index
    }
}
void computer :: setDeck3Num(string card){
    deck3Num.push_back(card); //adds to vector
}
void computer :: setDeck3Color(string color){
    deck3Color.push_back(color); //adds to vector
}
string computer :: getDeck4Num(int idx){
    int size = deck4Size();
    if (idx < size && idx >= 0){
        return deck4Num[idx]; //gets the value at that index
    }
}
string computer :: getDeck4Color(int idx){
    int size = deck4Size();
    if (idx < size && idx >= 0){
        return deck4Color[idx]; //gets the value at that index
    }
}
void computer :: setDeck4Num(string card){
    deck4Num.push_back(card); //adds to vector
}
void computer :: setDeck4Color(string color){
    deck4Color.push_back(color); //adds to vector

}
void computer :: computer2PlayedCard(int idx){
    deck2Num.erase(deck2Num.begin()+idx); //erases the value at the index
    deck2Color.erase(deck2Color.begin()+idx);
    
}
void computer :: computer3PlayedCard(int idx){ //erases the value at the index
    deck3Num.erase(deck3Num.begin()+idx);
    deck3Color.erase(deck3Color.begin()+idx);
}
void computer :: computer4PlayedCard(int idx){ //erases the value at the index
    deck4Num.erase(deck4Num.begin()+idx);
    deck4Color.erase(deck4Color.begin()+idx);
}
//////////////////////////////////////////////////////////////////////////////////
// -- PlayedCards.h
class PlayedCards{
    private:
        string lastCardNum;
        string lastCardColor;
        bool clockWise;
    public:
        PlayedCards();
        PlayedCards(string, string, bool);
        int next(int);
        int reverse();
        void setLastCard(string, string, string);
        string getLastCardNum(string);
        string getLastCardColor(string);
        void setClockWise(bool);
        bool getClockWise();
        int split(string, char, string*, int);
};
//////////////////////////////////////////////////////////////////////////////////
// -- PlayedCards.cpp
PlayedCards :: PlayedCards(){
    lastCardNum;
    lastCardColor;
    clockWise = true; //the same will start off clockwise
}
PlayedCards :: PlayedCards(string lastCardNum_, string lastCardColor_, bool clockWise_){
    lastCardNum = lastCardNum_;
    lastCardColor = lastCardColor;
    clockWise = clockWise_;
}
int PlayedCards :: next(int who){
    bool clockWise = getClockWise(); // checks the direction
    if(clockWise == true){ //if the direction of the game is clockwise then who will up go 1
        if(who == 4){ //this is so who is bound between 1 and 4
            who = 1;
        }
        else{
            who++;          //normal function  
        }

    }
    else if(clockWise == false){ //the game is going counter clock wise so who will be minus 1
        if(who == 1){
            who = 4; //this is to bound who 
        }
        else{
            who--; //normal 
            cout << "Working";
        }
        
    }
    else{
        cout << "Error at next" << endl; //who is broken if this prints
    }
    return who;
}
int PlayedCards :: reverse(){
    bool clockWise = getClockWise(); //checks the direction 
    if (clockWise == true){
        clockWise = false; //if the direction is clockwise it will reverse it 
        setClockWise(clockWise);
    }
    else if(clockWise == false){ 
        clockWise = true; //if the direction is counterclockwise then the direction will be clockwise 
        setClockWise(clockWise);
    }
    else{
        cout << "Error at reverse" << endl; //something is broke at getClockWise()
    }
}
void PlayedCards :: setLastCard(string card, string color, string fileName){
    ofstream myfile (fileName);
    if (myfile.is_open()){ //opens file
        myfile << card << endl; //writes to file
        myfile << color << endl;
        myfile.close(); //close file
    }
}
string PlayedCards :: getLastCardNum(string fileName){
    string lastCardNum;
    string line;
    int counter = 0;
    ifstream inFile(fileName);
    if(inFile.is_open()){ //if the file is open
        while(getline(inFile, line)){
            if(line.empty()){ //checks for empty string
             
            }
            else{
                while(counter == 0){
                    string word[2]; 
                    split(line,',', word, 2);  //calls split
                    lastCardNum = word[0]; //look at the first index of the array it is also the only indx with things, on the first line
                    counter++;
                    return lastCardNum; //return 
                }
            }
            
        }
    }
}
string PlayedCards :: getLastCardColor(string fileName){
    string lastCardColor;
    string line;
    int counter = 0;
    ifstream inFile(fileName);
    if(inFile.is_open()){ //if the file is open
        while(getline(inFile, line)){
            if(line.empty()){ //checks for empty string
             
            }
            else{
                counter++;
                while(counter == 2){
                    string word[2]; 
                    split(line,',', word, 2);  //calls split
                    lastCardColor = word[0]; //looks at the first index on the second line
                    counter++;
                    return lastCardColor;
                }
            }
            
        }
    }
}
void PlayedCards :: setClockWise(bool clockWise_){
    clockWise = clockWise_; //this will set the direction of the game 
}
bool PlayedCards ::getClockWise(){
    return clockWise; //returns the direction for the the game 
}
int PlayedCards :: split(string sentence,char spliter, string word[], int wordSize){
    int counter, sentenceIndex;
    string adder;
    counter = 1;
    if (sentence == ""){ //checks to see if the 
        counter = 0;
        return counter;
    }
    for (int i = 0; i < sentence.length(); i++){
        sentenceIndex = sentence[i];
        if (sentence[0] == spliter){
            i = i + 1;
        }
        else if (sentence[i] == spliter){
            if (sentence[i - 1] == spliter){
                if(sentence[i] == sentence[sentence.length()- 1]){
                    i = i + 1;
                }
            }
            else{
            counter = counter + 1;
            }
        }
        else{
            adder = sentence.length() - i;
            word[counter - 1] = word[counter - 1] + sentence[(adder, i)];
    }

    }
    return counter;
    
}
//////////////////////////////////////////////////////////////////////////////////
// -- Any Helper Functions
int split(string sentence,char spliter, string word[], int wordSize){
    int counter, sentenceIndex;
    string adder;
    counter = 1;
    if (sentence == ""){ //checks to see if the 
        counter = 0;
        return counter;
    }
    for (int i = 0; i < sentence.length(); i++){
        sentenceIndex = sentence[i];
        if (sentence[0] == spliter){
            i = i + 1;
        }
        else if (sentence[i] == spliter){
            if (sentence[i - 1] == spliter){
                if(sentence[i] == sentence[sentence.length()- 1]){
                    i = i + 1;
                }
            }
            else{
            counter = counter + 1;
            }
        }
        else{
            adder = sentence.length() - i;
            word[counter - 1] = word[counter - 1] + sentence[(adder, i)];
    }

    }
    return counter;
    
}

int welcomeMenu(){
    string name;
    int quit;
    PlayedCards played;
    string answer;
    bool rules[1]; //rules array
    cout << "Hello welcome to Uno" << endl;
    cout << "Would you like to play UNO? (Y/N)" << endl;
    cin >> answer;
    if(answer == "Y" || answer == "y"){
        cout << "This verson of Uno will have a couple different optional rules" << endl;
        cout << "Would you like to see the optional rules? (Y/N)" << endl;
        cin >> answer;
        if(answer == "Y" || answer == "y"){
            int num = 3;
            cout << "The first optional rule is called 'Stack', what this allows is for you to stack any +2 or +4 " << endl;
            cout << "that have been played against you. You will only be given the option to stack if you have a +2 or +4 in your deck" << endl;
            cout << "Would you like this rule to be on? 1 = On , anything else will count as Off" << endl;
            cin >> num;
            if(num != 1){
                num = 0;
            }
            rules[0] = num;
            num =1;
            int nums = 3;
            cout << "The second optional rule is called 'Jump In', what this rule is if you happen to have the " << endl;
            cout << "exact same card as the last card played (Ex. Last Card Played = Green 2, and you have a Green 2 you can jump in)" << endl;
            cout << "the Jump In rule does not take in to accout if its your turn only if you have that specific card" << endl;
            cout << "Would you like this rule to be on? 1 = On , anything else will count as Off" << endl;
            cin >> nums;
            if(num != 1){
                num = 0;
            }
            rules[1] = nums;
            quit = 0;
        }
        else{
            quit = 0;
        }
    }
    else{
        quit = 1;
    }
    return quit;
}
//////////////////////////////////////////////////////////////////////////////////
// -- Uno Game
int main(){
    srand(time(NULL)); //make things random 
    PlayedCards played;
    Deck deck;
    player player;
    computer computer;
    int quit = welcomeMenu(); //this is the menu 
    // bool direction = true; //set direction
    int on; //0 = off 1 = On 
    int counter = 0;
    int who = 1; //who is going to be who is the player 
    for(int i = 0; i < 7; i++){
        int num = deck.drawCard(); //get num for probability
        string card = deck.drawSpecial(num); //find the card
        string color = deck.drawColor(num); //find the color
        player.setDeck1Num(card); //this will set the starting 7 cards
        player.setDeck1Color(color);
    }
    for(int i = 0; i < 7; i++){
        int num = deck.drawCard();
        string card = deck.drawSpecial(num);
        string color = deck.drawColor(num);
        computer.setDeck2Num(card); //this will set the starting 7 cards
        computer.setDeck2Color(color);
    }
    for(int i = 0; i < 7; i++){
        int num = deck.drawCard();
        string card = deck.drawSpecial(num);
        string color = deck.drawColor(num);
        computer.setDeck3Num(card); //this will set the starting 7 cards
        computer.setDeck3Color(color);
    }
    for(int i = 0; i < 7; i++){
        int num = deck.drawCard();
        string card = deck.drawSpecial(num);
        string color = deck.drawColor(num);
        computer.setDeck4Num(card); //this will set the starting 7 cards
        computer.setDeck4Color(color);        
    }
    int lowestCards = 7; // this will be who has the lowest amount of cards
    while(quit == 0){
        while(lowestCards > 0){
            if(who == 1){
                cout << "You have: " << player.deck1Size( )<< " cards" << endl; //num of your cards
                cout << "Computer 1 has: " << computer.deck2Size() << " cards" << endl; //num of all computer cards
                cout << "Computer 2 has: " << computer.deck3Size() << " cards" << endl;
                cout << "Computer 3 has: " << computer.deck4Size() << " cards" << endl;
                player.printDeck(); //this prints your deck
                string lastCardNum = played.getLastCardNum("lastCard.txt"); //gets the last card 
                string lastCardColor = played.getLastCardColor("lastCard.txt");
                cout << "Last Card " << lastCardColor << " " << lastCardNum << endl; //print last card
                int thing1 = 1;
                int thing2 = 1;
                int size = player.deck1Size();
                int cardNum = 0;
                int counter = 0;
                size = size + 1;
                while(thing1 == 1){
                    cout << "Which card would you like to play? (1-" << size -1 << ")" << endl; //find out which card they wanna play
                    cout << "If you dont have a card to play press 0 to draw a card" << endl; //draw card
                    cin >> cardNum;
                    if(cardNum == 0){ //draw card
                        int num = deck.drawCard();
                        string card = deck.drawSpecial(num);
                        string color = deck.drawColor(num);
                        player.setDeck1Num(card);
                        player.setDeck1Color(color);
                        break;
                    } //if
                    else if(cardNum < 1 || cardNum > size){ //invalid option
                        cout << "You must choose a number between 1 and " << size -1 << endl;
                    }
                    else{ //play card
                        break;
                    }//else if
                } //while thing = 1
                string card = player.getDeck1Num(cardNum -1); //get the card at the idx they wanted 
                string color = player.getDeck1Color(cardNum -1);
                lastCardColor = played.getLastCardColor("lastCard.txt"); //get last card
                lastCardNum = played.getLastCardNum("lastCard.txt");
                while(thing2 == 1){
                    if(lastCardNum == "No Card"){ //compare this only happens at the beginning of the game
                        played.setLastCard(card, color, "lastCard.txt"); //sets last card
                        player.playedCard(cardNum-1); //removes card the idx
                        break;
                    } //if
                    else{ 
                        if(color == lastCardColor || card == lastCardNum || card == "Color Changer" || card == "Plus 4"){ //this will happen the rest of the game makes sure either the color or card match the last card
                            played.setLastCard(card, color, "lastCard.txt"); //sets last card
                            player.playedCard(cardNum -1); //removes the card at the inx
                            break;
                        } //if
                        else if (cardNum != 0){ //draw unless you decided to draw already
                            int draw;
                            cout << "You can only play a card with the same color as the last card" << endl;
                            cout << "Please pick a " << lastCardColor << " card " << "or a " << lastCardNum << " card" << endl;
                            cout << "If you dont have a card to play press 0 to draw a card" << endl;
                            cin >> draw;
                            if(draw == 0){
                                int num = deck.drawCard();
                                string card = deck.drawSpecial(num);
                                string color = deck.drawColor(num);
                                player.setDeck1Num(card);
                                player.setDeck1Color(color);
                                thing2 == 0;
                            } //if
                        } 
                        else{
                            break;
                        }
                    } //else
                } //while thing == 2
                if(card == "Reverse"){
                    played.reverse();
                }
                else if(card == "Skip"){ //checks if the card was a skip
                    who = played.next(who);
                }
                else if(card == "+2"){
                    who = played.next(who);
                    for(int i = 0; i < 2; i++){
                        int num = deck.drawCard();   //this will draw a number
                        string color = deck.drawColor(num); //this will take that number and give it a color
                        string card = deck.drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                        if(who == 2){
                            computer.setDeck2Num(card);
                            computer.setDeck2Color(card);
                        }
                        else if (who == 4){
                            computer.setDeck4Num(card);
                            computer.setDeck4Color(color);
                        }
                    }
                    who = played.next(who);
                    who = played.next(who);
                    who = played.next(who);
                }
                else if(card == "Plus 4"){
                    who = played.next(who);
                    for(int i = 0; i < 4; i++){
                        int num = deck.drawCard();   //this will draw a number
                        string color = deck.drawColor(num); //this will take that number and give it a color
                        string card = deck.drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                        if(who == 2){
                            computer.setDeck2Num(card);
                            computer.setDeck2Color(card);
                        }
                        else if(who == 4){
                            computer.setDeck4Num(card);
                            computer.setDeck4Color(color);
                        }
                    }
                    who = played.next(who);
                    who = played.next(who);
                    who = played.next(who);
                    cout << "What color would you like to change it to?" << endl;
                    cin >> color;
                    played.setLastCard(card, color, "lastCard.txt");
                }
                else if(card == "Color Changer"){
                    cout << "What color would you like to change it to?" << endl;
                    cin >> color;
                    played.setLastCard(card, color, "lastCard.txt");
                }
                quit = player.quitMenu(); //gives the option to quit
                who = played.next(who);
                break;
            } //if who = 1
            else if(who == 2){
                cout << "Computer 1 is playing" << endl;
                string lastCardColor = played.getLastCardColor("lastCard.txt"); //get last card
                string lastCardNum = played.getLastCardNum("lastCard.txt");
                int size = computer.deck2Size();
                for(int i = 0; i < size; i++){
                    string deck2Color = computer.getDeck2Color(i); //color at the set indx
                    string deck2Num = computer.getDeck2Num(i); //card at the set indx
                    if(deck2Num == lastCardNum || deck2Color == lastCardColor){ //checks if color or card matches
                        cout << "Computer 1 played a " << deck2Color << " " << deck2Num << endl;
                        played.setLastCard(deck2Num, deck2Color,"lastCard.txt"); //update the last card
                        computer.computer2PlayedCard(i); // played card will remove the cards at the indx
                        break;
                    } //if 
                    else if(lastCardNum == "No Card"){
                        played.setLastCard(deck2Num, deck2Color, "lastCard.txt");
                        cout << "Computer 1 played a " << deck2Color << " " << deck2Num << endl;
                        computer.computer2PlayedCard(i);
                        break;
                    }
                    else if(deck2Num == "Plus 4" || deck2Num == "Color Changer"){
                        played.setLastCard(deck2Num, deck2Color, "lastCard.txt");
                        cout << "Computer 1 played a " << deck2Num << endl;
                        computer.computer2PlayedCard(i); //removes the card at idx
                        break;
                        
                    } // else if
                    else{
                        int num = deck.drawCard(); //draw card
                        string card = deck.drawSpecial(num);
                        string color = deck.drawColor(num);
                        computer.setDeck2Num(card); //adds the new card
                        computer.setDeck2Color(color); //adds the new color
                        cout << "Drawing Card" << endl;
                        break;
                    } //else
                } //for 
                string deck2Num = played.getLastCardNum("lastCard.txt");
                if(deck2Num == "Reverse"){
                    played.reverse();

                }
                else if(deck2Num == "Skip"){ //checks if the card was a skip
                    who = played.next(who);
                }
                else if(deck2Num == "+2"){
                    who = played.next(who);
                    for(int i = 0; i < 2; i++){
                        int num = deck.drawCard();   //this will draw a number
                        string color = deck.drawColor(num); //this will take that number and give it a color
                        string card = deck.drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                        if(who == 3){
                            computer.setDeck3Num(card);
                            computer.setDeck3Color(card);
                        }
                        else if (who == 1){
                            player.setDeck1Num(card);
                            player.setDeck1Color(color);
                        }
                    }
                    who = played.next(who);
                    who = played.next(who);
                    who = played.next(who);
                }
                else if(deck2Num == "Plus 4"){
                    who = played.next(who);
                    for(int i = 0; i < 4; i++){
                        int num = deck.drawCard();   //this will draw a number
                        string color = deck.drawColor(num); //this will take that number and give it a color
                        string card = deck.drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                        if(who == 3){
                            computer.setDeck3Num(card);
                            computer.setDeck3Color(card);
                        }
                        else if (who == 1){
                            player.setDeck1Num(card);
                            player.setDeck1Color(color);
                        }
                    }
                    who = played.next(who);
                    who = played.next(who);
                    who = played.next(who);
                    string color = deck.drawColor(3);
                    played.setLastCard(deck2Num, color, "lastCard.txt");
                }
                else if(deck2Num == "Color Changer"){
                    string color = deck.drawColor(3);
                    played.setLastCard(deck2Num, color, "lastCard.txt");
                }
                quit = player.quitMenu();//gives the user the option to quit
                who = played.next(who);
            } //who = 2
            else if(who == 3){
                cout << "Computer 2 is playing" << endl;
                string lastCardColor = played.getLastCardColor("lastCard.txt"); //gets last card
                string lastCardNum = played.getLastCardNum("lastCard.txt");
                int deck3Size = computer.deck3Size(); 
                for(int i = 0; i < deck3Size; i++){
                    string deck3Color = computer.getDeck3Color(i); //for loops through the deck to if any card works
                    string deck3Num = computer.getDeck3Num(i);
                    if(deck3Num == lastCardNum || deck3Color == lastCardColor){ //check if anything matchs
                        played.setLastCard(deck3Num, deck3Color, "lastCard.txt");
                        cout << "Computer 2 played a " << deck3Color << " " << deck3Num << endl;
                        computer.computer3PlayedCard(i); //removes the card at the idx
                        break;
                    } //if 
                    else if(deck3Num == "Plus 4" || deck3Num == "Color Changer"){ //checks if the computer has a plus 4 or color changer
                        played.setLastCard(deck3Num, deck3Color, "lastCard.txt");
                        cout << "Computer 2 played a " << deck3Num << endl;
                        computer.computer3PlayedCard(i); //removes the card at the idx

                        break;
                    } //else if
                    else{
                        int num = deck.drawCard(); //draw card
                        string card = deck.drawSpecial(num);
                        string color = deck.drawColor(num);
                        computer.setDeck3Num(card); //add card
                        computer.setDeck3Color(color); //add color
                        cout << "Drawing Card" << endl;
                        break;
                    } //else
                }// for loop 
                string deck3Num = played.getLastCardNum("lastCard.txt");
                if(deck3Num == "Reverse"){
                    played.reverse();
                }
                else if(deck3Num == "Skip"){ //checks if the card was a skip
                    who = played.next(who);
                }
                else if(deck3Num == "+2"){
                    who = played.next(who);
                    for(int i = 0; i < 2; i++){
                        int num = deck.drawCard();   //this will draw a number
                        string color = deck.drawColor(num); //this will take that number and give it a color
                        string card = deck.drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                        if(who == 4){
                            computer.setDeck4Num(card);
                            computer.setDeck4Color(card);
                        }
                        else if (who == 2){
                            computer.setDeck2Num(card);
                            computer.setDeck2Color(color);
                        }
                    }
                    who = played.next(who);
                    who = played.next(who);
                    who = played.next(who);
                }
                else if(deck3Num == "Plus 4"){
                    who = played.next(who);
                    for(int i = 0; i < 4; i++){
                        int num = deck.drawCard();   //this will draw a number
                        string color = deck.drawColor(num); //this will take that number and give it a color
                        string card = deck.drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                        if(who == 4){
                            computer.setDeck4Num(card);
                            computer.setDeck4Color(card);
                        }
                        else if (who == 2){
                            computer.setDeck2Num(card);
                            computer.setDeck2Color(color);
                        }
                    }
                    who = played.next(who);
                    who = played.next(who);
                    who = played.next(who);
                    string color = deck.drawColor(3);
                    played.setLastCard(deck3Num, color, "lastCard.txt");
                }
                else if(deck3Num == "Color Changer"){
                    string color = deck.drawColor(3);
                    played.setLastCard(deck3Num, color, "lastCard.txt");
                }
                quit = player.quitMenu(); //player can quit
                who = played.next(who);
                break;
                
            } //who = 3
            else if(who == 4){
                cout << "Computer 3 is playing" << endl;
                string lastCardColor = played.getLastCardColor("lastCard.txt"); //get last card
                string lastCardNum = played.getLastCardNum("lastCard.txt");
                int deck4Size = computer.deck4Size();
                for(int i = 0; i < deck4Size; i++){
                    string deck4Color = computer.getDeck4Color(i); //for loop to see if any card can be played
                    string deck4Num = computer.getDeck4Num(i);
                    if(deck4Num == lastCardNum || deck4Color == lastCardColor){ //check if any card matches
                        played.setLastCard(deck4Num, deck4Color, "lastCard.txt");
                        cout << "Computer 3 played a " << deck4Color << " " << deck4Num << endl;
                        computer.computer4PlayedCard(i); //removes the card
                        break;
                    } //if 
                    else if(deck4Num == "Plus 4" || deck4Num == "Color Changer"){ //checks if any of the cards is a plus 4 or color changer
                        played.setLastCard(deck4Num, deck4Color, "lastCard.txt");  //update last card 
                        cout << "Computer 3 played a " << deck4Num << endl;
                        computer.computer4PlayedCard(i); //removes card at idx
                        break;
                    } //else if 
                    else{
                        int num = deck.drawCard(); //draw card
                        string card = deck.drawSpecial(num);
                        string color = deck.drawColor(num);
                        computer.setDeck4Num(card);
                        computer.setDeck4Color(color);
                        cout << "Drawing Card" << endl;
                        break;
                    } //else
                }// for loop
                string deck4Num = played.getLastCardNum("lastCard.txt");
                if(deck4Num == "Reverse"){
                    played.reverse();
                }
                else if(deck4Num == "Skip"){ //checks if the card was a skip
                    who = played.next(who);
                }
                else if(deck4Num == "+2"){
                    who = played.next(who);
                    for(int i = 0; i < 2; i++){
                        int num = deck.drawCard();   //this will draw a number
                        string color = deck.drawColor(num); //this will take that number and give it a color
                        string card = deck.drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                        if(who == 3){
                            computer.setDeck3Num(card);
                            computer.setDeck3Color(card);
                        }
                        else if (who == 1){
                            player.setDeck1Num(card);
                            player.setDeck1Color(color);
                        }
                    }
                    who = played.next(who);
                    who = played.next(who);
                    who = played.next(who);
                }
                else if(deck4Num == "Plus 4"){
                    who = played.next(who);
                    for(int i = 0; i < 4; i++){
                        int num = deck.drawCard();   //this will draw a number
                        string color = deck.drawColor(num); //this will take that number and give it a color
                        string card = deck.drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                        if(who == 3){
                            computer.setDeck3Num(card);
                            computer.setDeck3Color(card);
                        }
                        else if (who == 1){
                            player.setDeck1Num(card);
                            player.setDeck1Color(color);
                        }
                    }
                    who = played.next(who);
                    who = played.next(who);
                    who = played.next(who);
                    string color = deck.drawColor(3);
                    played.setLastCard(deck4Num, color, "lastCard.txt");
                }
                else if(deck4Num == "Color Changer"){
                    string color = deck.drawColor(3);
                    played.setLastCard(deck4Num, color, "lastCard.txt");
                }
                quit = player.quitMenu(); //player can quit
                who = played.next(who);
                break;
            } //who = 4

            int rule[1];
            for(int i = 0; i < 2; i++){ //this for loops to check for both rules and if their on 
                on = rule[i];
                counter++;
                if(on == 1 && counter == 1){
                    string lastCardColor = played.getLastCardColor("lastCard.txt");
                    string lastCardNum = played.getLastCardNum("lastCard.txt"); //gets last card
                    bool direction  = played.getClockWise(); //gets direction
                    if(direction == true){
                        if(who == 1){
                            int stack = 0;
                            int size = player.deck1Size();
                            for(int i = 0; i < size; i++){ //check through user deck to see if they can stack a +2 or +4
                                string card = player.getDeck1Num(i);
                                string color = player.getDeck1Num(i);
                                if(lastCardNum == "+2" || lastCardNum == "Plus 4"){
                                    if(lastCardNum == card){
                                        cout << "Would you like to stack the card? Press 1 to stack." << endl;
                                        cin >> stack;
                                        if(stack == 1){
                                            player.getDeck1Num(i);
                                            player.getDeck1Color(i);
                                            played.setLastCard(card, color, "lastCard.txt");
                                        }
                                    }
                                }
                            }
                        }
                        else if(who == 2){ //same as user just no interface and computer will always jump in
                            int stack = 0;
                            int size = computer.deck2Size();
                            for(int i = 0; i < size; i++){
                                string card = computer.getDeck2Num(i);
                                string color = computer.getDeck2Num(i);
                                if(lastCardNum == "+2" || lastCardNum == "Plus 4"){
                                    if(lastCardNum == card){
                                        computer.getDeck2Num(i);
                                        computer.getDeck2Color(i);
                                        played.setLastCard(card, color, "lastCard.txt");
                                    }
                                }
                            }
                        }
                        else if(who == 3){
                            int stack = 0;
                            int size = computer.deck3Size();
                            for(int i = 0; i < size; i++){
                                string card = computer.getDeck3Num(i);
                                string color = computer.getDeck3Num(i);
                                if(lastCardNum == "+2" || lastCardNum == "Plus 4"){
                                    if(lastCardNum == card){
                                        computer.getDeck3Num(i);
                                        computer.getDeck3Color(i);
                                        played.setLastCard(card, color, "lastCard.txt");
                                    }
                                }
                            }
                        }
                        else if(who == 4){
                            int stack = 0;
                            int size = computer.deck4Size();
                            for(int i = 0; i < size; i++){
                                string card = computer.getDeck4Num(i);
                                string color = computer.getDeck4Num(i);
                                if(lastCardNum == "+2" || lastCardNum == "Plus 4"){
                                    if(lastCardNum == card){
                                        computer.getDeck4Num(i);
                                        computer.getDeck4Color(i);
                                        played.setLastCard(card, color, "lastCard.txt");
                                    }
                                }
                            }
                        }
                        who = played.next(who);
                        who = played.next(who);
                        who = played.next(who); //these whos will return the game back to the original player
                    }
                    who = played.next(who); //this is to make the next player play
                } //if counter is 1 and rule 1 on
                else if(on == 1 && counter == 2){
                    int jumpIn = 0;
                    for(int i = 0; i < 4; i++){
                        if(who == 1){
                            int size = player.deck1Size();
                            string lastCardColor = played.getLastCardColor("lastCard.txt");
                            string lastCardNum = played.getLastCardNum("lastCard.txt");
                            for(int i = 0; size; i++){
                                string card = player.getDeck1Num(i);
                                string color = player.getDeck1Color(i);
                                if(card == lastCardNum && color == lastCardColor){
                                    cout << "Would you like to jump in? Press 1 to Jump In." << endl;
                                    cin >> jumpIn;
                                    if(jumpIn == 1){
                                        player.getDeck1Num(i);
                                        player.getDeck1Color(i);
                                    }
                                }
                                
                            }
                        }
                        else if(who == 2){
                            int size = computer.deck2Size();
                            string lastCardColor = played.getLastCardColor("lastCard.txt");
                            string lastCardNum = played.getLastCardNum("lastCard.txt");
                            for(int i = 0; size; i++){
                                string card = computer.getDeck2Num(i);
                                string color = computer.getDeck2Color(i);
                                if(card == lastCardNum && color == lastCardColor){
                                    computer.getDeck2Num(i);
                                    computer.getDeck2Color(i);
                            
                                }
                                
                            }
                        }
                        else if(who == 3){
                            int size = computer.deck3Size();
                            string lastCardColor = played.getLastCardColor("lastCard.txt");
                            string lastCardNum = played.getLastCardNum("lastCard.txt");
                            for(int i = 0; size; i++){
                                string card = computer.getDeck3Num(i);
                                string color = computer.getDeck3Color(i);
                                if(card == lastCardNum && color == lastCardColor){
                                    computer.getDeck3Num(i);
                                    computer.getDeck3Color(i);
                            
                                }
                                
                            }
                        }
                        else if(who == 4){
                            int size = computer.deck4Size();
                            string lastCardColor = played.getLastCardColor("lastCard.txt");
                            string lastCardNum = played.getLastCardNum("lastCard.txt");
                            for(int i = 0; size; i++){
                                string card = computer.getDeck4Num(i);
                                string color = computer.getDeck4Color(i);
                                if(card == lastCardNum && color == lastCardColor){
                                    computer.getDeck4Num(i);
                                    computer.getDeck4Color(i);
                            
                                }
                                
                            }
                        }
                    }
                    // who = played.next(who);
                    // jumpIn(who, lastCard);
                } //is rule 1 is on and counter = 2
                 //else
            } //forloop for rules
            // who = played.next(who); //this means both rules are off and its the next players turn
        } //else
        if(player.deck1Size() < computer.deck2Size() && player.deck1Size() < computer.deck3Size() && player.deck1Size() < computer.deck4Size()){ //checks if user has the lowest amount of card
            lowestCards = player.deck1Size();
        }
        if(computer.deck2Size() < player.deck1Size() && computer.deck2Size() < computer.deck3Size() && computer.deck2Size() < computer.deck4Size()){ //checks id computer 1 has the lowest amount of card
            lowestCards = computer.deck2Size();
        }
        if(computer.deck3Size() < computer.deck2Size() && computer.deck3Size() < player.deck1Size() && computer.deck3Size() < computer.deck4Size()){ //checks if computer 2 has the lowest amount of card
            lowestCards = computer.deck3Size();
        }
        if(computer.deck4Size() < computer.deck2Size() && computer.deck4Size() < computer.deck3Size() && computer.deck4Size() < player.deck1Size()){ //checks if computer 3 has the lowest amount of cards
            lowestCards = computer.deck4Size();
        }
        if(quit == 1){
            lowestCards = 0; //if the user wants to quit then lowestest cards will be set to 0 so the game ends
        }
    } //while lowest
    cout << "I hope you had fun" << endl; //this is how you know you won or quit
    
} //main