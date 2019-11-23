#include <iostream>
#include <fstream>
using namespace std;

int main(){
    welcomeMenu(); //this is the menu 
    bool direction = true; //set direction
    int on; //0 = off 1 = On 
    int quit = 0; //this is in case the user wants to quit
    int counter = 0;
    int who = 1; //who is going to be who is the player 
    int lowestCards = 7; // this will be who has the lowest amount of cards
    while(quit == 0){
        setClockWise(direction); //this will set the direction to clockwise
        for(int i = 0; i < 7; i++){
            int num = drawCard();
            string card = drawSpecial(num);
            string color = drawColor(num);
            setDeck1(i, card, color); //this will set the starting 7 cards
        }
        for(int i = 0; i < 7; i++){
            int num = drawCard();
            string card = drawSpecial(num);
            string color = drawColor(num);
            setDeck2(i, card, color); //this will set the starting 7 cards
        }
        for(int i = 0; i < 7; i++){
            int num = drawCard();
            string card = drawSpecial(num);
            string color = drawColor(num);
            setDeck3(i, card, color); //this will set the starting 7 cards
        }
        for(int i = 0; i < 7; i++){
            int num = drawCard();
            string card = drawSpecial(num);
            string color = drawColor(num);
            setDeck4(i, card, color); //this will set the starting 7 cards
        }
        setDeck1Size(1); //this will make the size of the vector to be 7
        setDeck2Size(1); //this will make the size of the vector to be 7
        setDeck3Size(1); //this will make the size of the vector to be 7
        setDeck4Size(1); //this will make the size of the vector to be 7
        quit = quitMenu();
        while(lowestCard > 0){
            if(who == 1){
                cout << "You have: " << getDeck1Size( )<< " cards" << endl;
                cout << "Computer 1 has: " << getDeck2Size() << " cards" << endl;
                cout << "Computer 2 has: " << getDeck3Size() << " cards" << endl;
                cout << "Computer 3 has: " << getDeck4Size() << " cards" << endl;
                printDeck();
                lastCardNum = getLastCardNum();
                lastCardColor = getLastCardColor();
                int thing1 = 1;
                int thing2 = 1;
                int deck1Size = getDeck1Size();
                int card = 0;
                int counter = 0;
                deck1Size = deck1Size + 1;
                while(thing1 == 1){
                    cout << "Which card would you like to play? (1-" << deck1Size << ")" << endl;
                    cout << "If you dont have a card to play press 1 to draw a card" << endl;
                    cin >> card;
                    if(card == 1){
                        int num = drawCard();
                        string card = drawSpecial(num);
                        string color = drawColor(num);
                        setDeck1(deck1Size + 1, card, color);
                        card = deck1Size -1; //this will make it so it leaves the while loop
                    } //if
                    else if(card < 1 || card > deck1Size){
                        cout << "You must choose a number between 1 and " << deck1Size << endl;
                    } //else if
                    else{
                        thing1 == 0;
                    } //else
                } //while thing = 1
                string lastCardColor = getLastCardColor("lastCard.txt");
                string lastCardNum = getLastCardNum("lastCard.txt")
                while(thing2 == 1){
                    if(lastCardColor == "No Card"){
                        setLastCard(deck1Num[deck - 1], deck1Color[deck - 1]);
                        deck1Num[card -1].erase();
                        deck1Color[card -1].erase();
                        setDeck1Size(0); //this will subtract 1 from the deck size
                        thing2 = 0;
                    } //if
                    else{
                        if(deck1Color[card -1] == lastCardColor || deck1Num[card -1] == lastCardNum){
                            setLastCard(deck1Num[deck - 1], deck1Color[deck - 1]);
                            deck1Num[card -1].erase();
                            deck1Color[card -1].erase();
                            setDeck1Size(0); //this will subtract 1 from the deck size
                            thing2 = 0;
                        } //if
                        else{
                            cout << "You can only play a card with the same color as the last card" << endl;
                            cout << "Please pick a " << lastCardNum << "/" << lastCardColor << " card" << endl;
                            cout << "If you dont have a card to play press 1 to draw a card" << end;
                            cin >> draw;
                            if(draw == 1){
                                num = drawCard();
                                card = drawSpecial(num);
                                color = drawColor(num);
                                setDeck1(deck1Size + 1, card, color);
                                setDeck1Size(1); //this will increase the size by 1;
                                thing2 == 0
                            } //if
                        } //else
                    } //else
                } //while thing == 2
            } //if who = 1
            else if(who == 2){
                deck2Size = getDeck2Size();
                for(int i = 0; i < deck2Size; i++){
                    deck2Color = getDeck2Color(i);
                    deck2Num = getDeck2Num(i);
                    if(deck2Num == lastCardNum || deck2Color == lastCardColor){ //check this
                        setDeck2Size(0);
                        setLastCard(deck2Num, deck2Color);
                        deck2Num[i].erase();
                        deck2Color[i].erase();
                    } //if 
                    else if(deck2Num == "Plus 4" || deck2Num == "Color Changer"){
                        setDeck2Size(0);
                        setLastCard(deck2Num, deck2Cololr);
                        deck2Num[i].erase();
                        deck2Color[i].erase();
                    } // else if
                    else{
                        num = drawCard();
                        card = drawSpecial(num);
                        color = drawColor(num);
                        setDeck1(deck1Size + 1, card, color);
                    } //else
                } //for loop 
            } //who = 2
            else if(who == 3){
                deck3Size = getDeck3Size();
                for(int i = 0; i < deck3Size; i++){
                    deck3Color = getDeck3Color(i);
                    deck3Num = getDeck3Num(i);
                    if(deck3Num == lastCardNum || deck3Color == lastCardColor){ //check this
                        setDeck3Size(0);
                        setLastCard(deck3Num, deck3Color);
                        deck3Num[i].erase();
                        deck3Color[i].erase();
                    } //if 
                    else if(deck3Num == "Plus 4" || deck3Num == "Color Changer"){
                        setDeck3Size(0);
                        setLastCard(deck3Num, deck3Cololr);
                        deck3Num[i].erase();
                        deck3Color[i].erase();
                    } //else if
                    else{
                        num = drawCard();
                        card = drawSpecial(num);
                        color = drawColor(num);
                        setDeck1(deck1Size + 1, card, color);
                    } //else
                }// for loop 
                
            } //who = 3
            else if(who == 4){
                deck4Size = getDeck4Size();
                for(int i = 0; i < deck4Size; i++){
                    deck4Color = getDeck4Color(i);
                    deck4Num = getDeck4Num(i);
                    if(deck4Num == lastCardNum || deck4Color == lastCardColor){ //check this
                        setDeck4Size(0);
                        setLastCard(deck4Num, deck4Color);
                        deck4Num[i].erase();
                        deck4Color[i].erase();
                    } //if 
                    else if(deck4Num == "Plus 4" || deck4Num == "Color Changer"){
                        setDeck4Size(0);
                        setLastCard(deck4Num, deck4Cololr);
                        deck4Num[i].erase();
                        deck4Color[i].erase();
                    } //else if 
                    else{
                        num = drawCard();
                        card = drawSpecial(num);
                        color = drawColor(num);
                        setDeck1(deck1Size + 1, card, color);str
                    } //else
                }// for loop
               
            } //who = 4
            else{
                cout << "Error at playCard" << endl;
            } //else
            ifstream inFile("lastCard.txt"); 
            if(inFile.is_open()){
                while(getline(inFile, line)){
                    split(line, ',', word, size);
                    lastCardColor = getLastCardColor("lastCard.txt");
                    lastCardNum = getLastCardNum("lastCard.txt");
                    if(lastCardNum == "Reverse"){
                        reverse();
                        who = next(who);
                    }
                    else if(lastCardNum == "Skip"){
                        who = next(who);
                    }
                    else if(lastCardNum == "+2"){
                        who = next(who);
                        // plus2(who);
                        for(int i = 0; i < 2; i++){ //this will forloop twice since it is a plus 2 functions
                            int num = draw();   //this will draw a number
                            string color = drawColor(num); //this will take that number and give it a color
                            string card = drawSpecial(num); //this will check if the card should be a speical card or not and if it is it will return as a special card
                            if(who == 1){ //the user must draw 2
                                setDeck1Size(1); //this increases the deck size by 1, if 0 is put in the deck size would decrease by 1
                                setDeck1(card, color); //this places that card into the deck 
                            }
                            else if(who == 2){ //this is for computer 1
                                setDeck2Size(1);
                                setDeck2(card, color);
                            }
                            else if(who == 3){ //computer 2
                                setDeck3Size(1);
                                setDeck3(card, color);
                            }
                            else if(who == 4){ //computer 3
                                setDeck4Size(1);
                                setDeck4(card, color);
                            }
                            else{ //something is wrong because none of the players was the target so something with who is wrong
                                cout <<  "Error at Plus 2" << endl;;
                            }
                        }
                    }
                    else if(lastCardNum == "Plus 4"){
                        who = next(who);
                        // plus4(who);
                        int num;
                        string color;
                        string card;
                        for(int i = 0; i < 4; i++){ //this is all the same as plus 2 but it for loops 4 times now 
                            num = draw();   
                            color = drawColor(num);
                            card = drawSpecial(num);
                            if(who == 1){
                                setDeck1Size(1);
                                setDeck1(card, color);
                            }
                            else if(who == 2){
                                setDeck2Size(1);
                                setDeck2(card, color);
                            }
                            else if(who == 3){
                                setDeck3Size(1);
                                setDeck3(card, color);
                            }
                            else if(who == 4){
                                setDeck4Size(1);
                                setDeck4(card, color);
                            }
                            else{
                                cout <<  "Error at Plus 4" << endl;
                            }
                        }
                        int blah = 0;
                        while(blah == 0){
                            if(who != 1){
                                string temp;
                                int deck2Lar =0;
                                int deck3Lar =0;
                                int deck4Lar =0;
                                int green = 0;
                                int blue =0;
                                int red = 0;
                                int yellow = 0;
                                if(who == 2){
                                    for(int i = 0 ; i > getDeck2Size(); i++){
                                        temp = getDeck2Color(i);
                                        if(temp == "Green"){
                                            green++;
                                        }
                                        else if(temp == "Blue"){
                                            blue++;
                                        }
                                        else if(temp == "Red"){
                                            red++;
                                        }
                                        else{
                                            yellow++;
                                        }
                                    }
                                    if(green > red && green > blue && green > yellow){
                                        deck2Lar = "Green";
                                    }
                                    if(red > green && red > blue && red > yellow){
                                        deck2Lar = "Red";
                                    }    
                                    if(blue > green && blue > red && blue > yellow){
                                        deck2Lar = "Blue";
                                    } 
                                    if(yellow > green && yellow > blue && yellow > red){
                                        deck2Lar = "Yellow";
                                    } 
                                }
                                else if(who == 3){
                                    for(int i = 0 ; i > getDeck3Size(); i++){
                                        temp = getDeck3Color(i);
                                        if(temp == "Green"){
                                            green++;
                                        }
                                        else if(temp == "Blue"){
                                            blue++;
                                        }
                                        else if(temp == "Red"){
                                            red++;
                                        }
                                        else{
                                            yellow++;
                                        }
                                    }
                                    if(green > red && green > blue && green > yellow){
                                        deck3Lar = "Green";
                                    }
                                    if(red > green && red > blue && red > yellow){
                                        deck3Lar = "Red";
                                    }    
                                    if(blue > green && blue > red && blue > yellow){
                                        deck3Lar = "Blue";
                                    } 
                                    if(yellow > green && yellow > blue && yellow > red){
                                        deck3Lar = "Yellow";
                                    } 
                                }
                                else{
                                    for(int i = 0 ; i > getDeck4Size(); i++){
                                        temp = getDeck4Color(i);
                                        if(temp == "Green"){
                                            green++;
                                        }
                                        else if(temp == "Blue"){
                                            blue++;
                                        }
                                        else if(temp == "Red"){
                                            red++;
                                        }
                                        else{
                                            yellow++;
                                        }
                                    }
                                    if(green > red && green > blue && green > yellow){
                                        deck4Lar = "Green";
                                    }
                                    if(red > green && red > blue && red > yellow){
                                        deck4Lar = "Red";
                                    }    
                                    if(blue > green && blue > red && blue > yellow){
                                        deck4Lar = "Blue";
                                    } 
                                    if(yellow > green && yellow > blue && yellow > red){
                                        deck4Lar = "Yellow";
                                    } 
                                    
                                }
                            }
                            cout << "Which color would you like to change it to? (Green, Red, Blue, Yellow) (This is case sensitive)" << endl;
                            cin >> color;
                            if(who != 1){
                                if(who == 2){
                                    color  = deck2Lar;
                                }
                                else if(who == 3){
                                    color = deck3Lar;
                                }
                                else{
                                    color = deck4Lar;
                                }
                            }
                            else if(color == "Green" || color == "Red" || color == "Blue" || color == "Yellow"){
                                setLastCard(card, color);
                                blah = 1;
                            }
                        }
                    } //this is for plus
                    else if(lastCardNum == "Color Changer"){
                        int blah = 0;
                        while(blah == 0){
                            if(who != 1){
                                string temp;
                                int deck2Lar =0;
                                int deck3Lar =0;
                                int deck4Lar =0;
                                int green = 0;
                                int blue =0;
                                int red = 0;
                                int yellow = 0;
                                if(who == 2){
                                    for(int i = 0 ; i > getDeck2Size(); i++){
                                        temp = getDeck2Color(i);
                                        if(temp == "Green"){
                                            green++;
                                        }
                                        else if(temp == "Blue"){
                                            blue++;
                                        }
                                        else if(temp == "Red"){
                                            red++;
                                        }
                                        else{
                                            yellow++;
                                        }
                                    }
                                    if(green > red && green > blue && green > yellow){
                                        deck2Lar = "Green";
                                    }
                                    if(red > green && red > blue && red > yellow){
                                        deck2Lar = "Red";
                                    }    
                                    if(blue > green && blue > red && blue > yellow){
                                        deck2Lar = "Blue";
                                    } 
                                    if(yellow > green && yellow > blue && yellow > red){
                                        deck2Lar = "Yellow";
                                    } 
                                }
                                else if(who == 3){
                                    for(int i = 0 ; i > getDeck3Size(); i++){
                                        temp = getDeck3Color(i);
                                        if(temp == "Green"){
                                            green++;
                                        }
                                        else if(temp == "Blue"){
                                            blue++;
                                        }
                                        else if(temp == "Red"){
                                            red++;
                                        }
                                        else{
                                            yellow++;
                                        }
                                    }
                                    if(green > red && green > blue && green > yellow){
                                        deck3Lar = "Green";
                                    }
                                    if(red > green && red > blue && red > yellow){
                                        deck3Lar = "Red";
                                    }    
                                    if(blue > green && blue > red && blue > yellow){
                                        deck3Lar = "Blue";
                                    } 
                                    if(yellow > green && yellow > blue && yellow > red){
                                        deck3Lar = "Yellow";
                                    } 
                                }
                                else{
                                    for(int i = 0 ; i > getDeck4Size(); i++){
                                        temp = getDeck4Color(i);
                                        if(temp == "Green"){
                                            green++;
                                        }
                                        else if(temp == "Blue"){
                                            blue++;
                                        }
                                        else if(temp == "Red"){
                                            red++;
                                        }
                                        else{
                                            yellow++;
                                        }
                                    }
                                    if(green > red && green > blue && green > yellow){
                                        deck4Lar = "Green";
                                    }
                                    if(red > green && red > blue && red > yellow){
                                        deck4Lar = "Red";
                                    }    
                                    if(blue > green && blue > red && blue > yellow){
                                        deck4Lar = "Blue";
                                    } 
                                    if(yellow > green && yellow > blue && yellow > red){
                                        deck4Lar = "Yellow";
                                    } 
                                    
                                }
                            }
                            cout << "Which color would you like to change it to? (Green, Red, Blue, Yellow) (This is case sensitive)" << endl;
                            cin >> color;
                            if(who != 1){
                                if(who == 2){
                                    color  = deck2Lar;
                                }
                                else if(who == 3){
                                    color = deck3Lar;
                                }
                                else{
                                    color = deck4Lar;
                                }
                            }
                            else if(color == "Green" || color == "Red" || color == "Blue" || color == "Yellow"){
                                setLastCard(card, color);
                                blah = 1;
                            }
                        }
                    } //color changer 
                    else{
                        for(int i = 0; i < 2; i++){
                            on = rule[i];
                            counter++;
                            if(on == 1 && counter == 1){
                                who = next(who);
                                stack(who, lastCard);
                                for(int j = 0; j < 2; j++){
                                    who = next(who); //who should be 2 more than what it started as now
                                }
                                stack(who, lastCard);
                                for(int l = 0; l < 3; l++){
                                    who = next(who); //who should now be back to the start
                                }
                                who = next(who); //this is to make the next player play
                            } //if counter is 1 and rule 1 on
                            else if(on == 1 && counter == 2){
                                who = next(who);
                                jumpIn(who, lastCard);
                                for(int j = 0; j < 2; j++){
                                    who = next(who); //who should be 2 more than what it started as now
                                } //for loop
                                jumpIn(who, lastCard);
                                for(int l = 0; l < 3; l++){
                                    who = next(who); //who should now be back to the start
                                } //for loop 
                                who = next(who); //this is to make the next play
                            } //is rule 1 is on and counter = 2
                             //else
                        } //forloop for rules
                        who = next(who); //this means both rules are off and its the next players turn
                    } //else
            
                } //while loop inside if
            }//this is the bracket close for if line
            if(getDeck1Size() < getDeck2Size() && getDeck1Size() < getDeck3Size() && getDeck1Size() < getDeck4Size()){
                lowestCards = getDeck1Size();
            }
            if(getDeck2Size() < getDeck1Size() && getDeck2Size() < getDeck3Size() && getDeck2Size() < getDeck4Size()){
                lowestCards = getDeck2Size();
            }
            if(getDeck3Size() < getDeck2Size() && getDeck3Size() < getDeck1Size() && getDeck3Size() < getDeck4Size()){
                lowestCards = getDeck3Size();
            }
            if(getDeck4Size() < getDeck2Size() && getDeck4Size() < getDeck3Size() && getDeck4Size() < getDeck1Size()){
                lowestCards = getDeck4Size();
            }
        } //while lowest
    } //while quit
} //main