// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <string>
#include "animal.h"
#include "player.h"
#include "item.h"
#include "store.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <fstream>
#include "player.cpp"
#include "store.cpp"
#include <ctime>
#include <string> 
#include "animal.cpp"

using namespace std;
void type_text(string text, int speed) {
    
    // function to give a cool vintage-game-type-out-text type feel
    for(int i = 0; i < text.size(); i ++) {
        cout << text[i] << flush;
        // speed is done in milliseconds, multiply by 1000
        usleep(speed*1000);
    }
}
int generateRandomNumberBetween(int lowerRange, int upperRange) {
    return (rand() % upperRange + lowerRange);
}
Animal animalEncountered() {
    Animal finalAnimal;
    int randNum = generateRandomNumberBetween(0,100);
    if(randNum <= 50) {
        finalAnimal.setType("rabbit");
        finalAnimal.setWeight(5);
        finalAnimal.setAmountOfBulletsNeeded(10);
    } else if(randNum > 50 && randNum <= 75) {
        finalAnimal.setType("fox");
        finalAnimal.setWeight(10);
        finalAnimal.setAmountOfBulletsNeeded(8);
    } else if(randNum > 75 && randNum <= 88) {
        finalAnimal.setType("deer");
        finalAnimal.setWeight(60);
        finalAnimal.setAmountOfBulletsNeeded(5);
    } else if(randNum > 88 && randNum <= 95) {
        finalAnimal.setType("bear");
        finalAnimal.setWeight(200);
        finalAnimal.setAmountOfBulletsNeeded(10);
    } else if(randNum > 95 && randNum <= 100) {
        finalAnimal.setType("moose");
        finalAnimal.setWeight(500);
        finalAnimal.setAmountOfBulletsNeeded(12);
    }
    return finalAnimal;
}
Player addDaysToTrip(Player p, int days) {
    if(((p.getCurrentDay()) + days) > 30) {
        p.setCurrentMonth(p.getCurrentMonth() + 1);
        p.setCurrentDay((p.getCurrentDay() + days) - 30);
    } else {
        p.setCurrentDay(p.getCurrentDay() + days);
    }
    return p;
}
void printMainScreen() {
    cout << endl;
    cout << endl;
    cout << "                            `./////////:...            `....-/////:` " << endl;
    cout << "                            -oo:/oooooooooo++/`:++++..+oooooooooooo/" << endl;
    cout << "                            /+``/ooooooooooo/.ooooo+.oooooooooooo+. " << endl;
    cout << "                            o/  `+ooooooooo/.ooooo+.oooooooooooo.  " << endl;
    cout << "                            .o-  -ooooooooo/.ooooo+.ooooooooooo: " << endl;
    cout << "   --.  -+.                    :o-  +oooooooo/.ooooo+.oooooooooo:  " << endl;
    cout << "   .+oooo::+oo/::::::::`      `+-  +oooooooo/.ooooo+.oooooooooo`  " << endl;
    cout << "   `/+oooooooooooooooooooo-     `:...::..-:::..-::::::-:-..:::-.-`" << endl;
    cout << "   ```-::/ooooooooooooooo/------:+oo.`:/./o:-/:/ooooo/`./-.o+://` " << endl;
    cout << "       -:ooooooo++oooo+.      `+o-  +---/o.`.:. /o+  -/.``o+----  " << endl;
    cout << "       `oooo/.. `:o+o+         ``  /:` :o-.:-` ...  ./:--o/ `:-  `:-  " << endl;
    cout << "       .++-`/o`  .:+:++              ./:/o//:`        `-/-oo+/.  " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "        _____                              _____         _ _ " << endl;
    cout << "       |  _  |                            |_   _|       (_) |" << endl;
    cout << "       | | | |_ __ ___  __ _  ___  _ __     | |_ __ __ _ _| | " << endl;
    cout << "       | | | | '__/ _ \\/ _` |/ _ \\| '_ \\    | | '__/ _` | | |" << endl;   
    cout << "       \\ \\_/ / | |  __/ (_| | (_) | | | |   | | | | (_| | | |" << endl;   
    cout << "        \\___/|_|  \\___|\\__, |\\___/|_| |_|   \\_/_|  \\__,_|_|_|" << endl;   
    cout << "                        __/ |                                " << endl; 
    cout << "                       |___/ " << endl;  
    cout << endl;  
    cout << "..........................................................................." << endl;
    cout << endl;
    type_text("Select an Option from the Following:\n", 20);
    type_text("1. Load Game\n", 20);
    type_text("2. New Game\n", 20);
    type_text("3. Controls/Info\n", 20);
    type_text("4. Quit Game\n", 20);
    cout << endl;
    // cout << "Enter the # of your selected option: ";
}
void printRandomGraphic() {

}
void updateGameFilesWithInfo(Player p) {
    // update info using Player p as input;
    ofstream gamefile;
    gamefile.open ("gamedata.txt");
    // write name and other data to file
    gamefile << p.getName() << "\n" << to_string(p.getMilesToGo()) << "\n" << to_string(2040 - p.getMilesToGo()) << "\n" << to_string(p.getAmountOfFood()) << "\n" << to_string(p.getBalance()) << "\n" << p.getCurrentMonth() << "\n" << p.getCurrentDay() << "\n" << p.getPersonAtIndex(0) << "\n" << p.getPersonAtIndex(1) << "\n" << p.getPersonAtIndex(2) << "\n" << p.getPersonAtIndex(3);
    gamefile.close();
}
void updateInventoryFilesWithInfo(int amountOfOxen, int amountOfFood, int amountOfBullets, int amountOfRepair, int amountOfMedKit) {
    
    // update info using Player p as input;
    ofstream gamefile;
    gamefile.open ("inventory.txt");
    // write name and other data to file
    gamefile << amountOfOxen << "\n" << amountOfFood << "\n" << amountOfBullets << "\n" << amountOfRepair << "\n" << amountOfMedKit;
    gamefile.close();
}
void Clear()
{
    // if device is on windows
#if defined _WIN32
    system("cls");
// if device on linux/unix (should include macos but added specific case below just to be safe)
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void promptForshop(int balance) {
    // type_text("You have the opportunity to purchase supplies from the shop. You have $"+to_string(balance)+" left to spend. You don't have to spend it all now, there will be opportunites later down the trail.", 30);
    type_text("YOU HAD SAVED $"+to_string(balance)+" TO SPEND FOR THE TRIP, AND YOU HAVE AWAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE\nFOLLOWING ITEMS:\n- OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU\nSPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS.\n- FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK.\n- AMMUNITION. YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD. \n- MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHERTHINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS.\nYOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU\nCAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO\nGO HUNTING ALONG THE WAY TO GET MORE FOOD.", 30);
}
int main() {
    //defaults
    string name = "john";
    //in miles
    int milesToGo = 2040;
    int milesTravelled = 0;
    // amount of food in numerical value of pounds
    int food = 500;
    //in $ USD
    int balance = 1600;
    int health = 100;
    int month = 3;
    int day = 28;
    int oxenCount = 2;
    int amountOfBullets = 20;
     int amountOfRepair = 0;
      int amountOfMedKit = 0;
    string currentDate = "03/28/1847";
    string startDate = "03/28/1847";
    // types of death
    string typesOfDeath[6] = {"typhoid", "exhaustion", "dysentery", "cholera", "snakebite", "measles"};
    // all rivers on the trail (in order)
    string rivers[3] = {"Snake River", "Columbia River", "Platte River"};

    Clear();
    printMainScreen();
    bool hasSelectedProperOption = false;
    bool shouldExit = false;
    while(hasSelectedProperOption == false) {
        type_text("\nEnter the # of your selected option: ", 30);
        int option;
        cin >> option;
        if(option == 1) {
            Clear();
            type_text("Attempting to load previous game\n", 30);
            string line;
            ifstream gamefile ("gamedata.txt");
            int lineNumber = 0;
            if (gamefile.is_open())
            {
                while ( getline (gamefile,line) )
                {
                    // cout << line << '\n';
                    if (lineNumber == 0) {
                        name = line;
                    } else if (lineNumber == 1) {
                        milesToGo = stoi(line);
                    } else if (lineNumber == 2) {
                        milesTravelled = stoi(line);
                    } else if (lineNumber == 3) {
                        food = stoi(line);
                    } else if (lineNumber == 4) {
                        balance = stoi(line);
                    } else if (lineNumber == 5) {
                        month = stoi(line);
                    } else if (lineNumber == 6) {
                        day = stoi(line);
                    } else {
                        //for some reason file length is longer then expected
                    }
                    lineNumber = lineNumber + 1;
                }
                ifstream invFile ("inventory.txt");
            lineNumber = 0;
            if (invFile.is_open())
            {
                while ( getline (invFile,line) )
                {
                    // cout << line << '\n';
                    if (lineNumber == 0) {
                        oxenCount = stoi(line);
                    } else if (lineNumber == 1) {
                        food = stoi(line);
                    } else if (lineNumber == 2) {
                        amountOfBullets = stoi(line);
                    } else if (lineNumber == 3) {
                        amountOfRepair = stoi(line);
                    } else if (lineNumber == 4) {
                        amountOfMedKit = stoi(line);
                    } else {
                        //for some reason file length is longer then expected
                    }
                    lineNumber = lineNumber + 1;
                }
            }
                type_text("Finished loading game files. Press enter to continue.", 30);
                invFile.close();
                gamefile.close();
            } else {
                type_text("Error loading game files. Resetting Information..\n", 30);
                type_text("Creating game files\n", 30);
                ofstream gamefile;
                gamefile.open ("gamedata.txt");
                // write name and other default data to file
                gamefile << name << "\n" << milesToGo << "\n" << milesTravelled << "\n" << food << "\n" << balance;
                gamefile.close();
                type_text("Finished preparing game files. Press enter to continue.", 30);
            }
            hasSelectedProperOption = true;
        } else if (option == 2) {
            type_text("\nWhat is your first name?  ", 30);
            // (everything here will override gamedata.txt if data already exists)
            string name = "";
            cin >> name;
            Clear();
            type_text("Enter the first names of the other four(4) members in your party. Press enter to move on to the next member.", 30);
            type_text("\n1. ", 60);
            string firstMember = "";
            cin >> firstMember;
            type_text("2. ", 60);
            string secondMember = "";
            cin >> secondMember;
            type_text("3. ", 60);
            string thirdMember = "";
            cin >> thirdMember;
            type_text("4. ", 60);
            string fourthMember = "";
            cin >> fourthMember;
            Clear();
            type_text("On what day would you like to start your quest? Default is 03/28/1847. To set a different date type it in the following format: mm/dd/yyy otherwise press enter. Custom date must be in between 03/01/1847 and 05/01/1847.", 30);
            type_text("\n\nAs a reminder these are the months for each season:\n", 30);
            type_text("...................................................\n\n", 10);
            type_text("Winter: November to January (10 to 01)\n", 30);
            type_text("Spring: Febuary to April (02 to 05)\n", 30);
            type_text("Summer: April to July (05 to 07)\n", 30);
            type_text("Fall: July to October (07 to 10)\n", 30);
            type_text("...................................................\n\n", 10);

            
            int mon = 3;
            // int day = 28;
            type_text("Would you like to enter a custom date? [y/N]: ", 30);
            string reply;
            cin.ignore();
            getline(cin, reply);
            if(reply == "y") {
                type_text("\nEnter a Custom month: ", 60);
                cin >> mon;
                type_text("Enter a Custom day: ", 60);
                cin >> day;
            }
            month = mon;
            day = day;
            do 
            {
            // cout << '\n' << "Press a key to continue...";
            } while (cin.get() != '\n');
            // startDate = dtae;
            // type_text("\nProcessing")
            type_text("\nCreating game files\n", 30);
            // ofstream gamefile;
            // gamefile.open("gamedata.txt");
            Player p;
            p.setPersonAtIndex(firstMember, 0);
            p.setPersonAtIndex(secondMember, 1);
            p.setPersonAtIndex(thirdMember, 2);
            p.setPersonAtIndex(fourthMember, 3);
            p.setAmountOfFood(food);
            p.setHealth(health);
            p.setMilesToGo(milesToGo);
            p.setName(name);
            p.setBalance(balance);
            // if(dtae != "" && dtae != "\n") {
            //     p.setDate(dtae);
            // } else {
            //     p.setDate("03/28/1847");
            // }
            updateGameFilesWithInfo(p);
            updateInventoryFilesWithInfo(2, 500, 20, 0, 0);
            // write name and other default data to file
            // gamefile << name << "\n" << milesToGo << "\n" << milesTravelled << "\n" << food << "\n" << balance << "\n" << health << "\n" << firstMember << "\n" << secondMember << "\n" << thirdMember << "\n" << fourthMember;
            // gamefile << name << "\n" << milesToGo << "\n" << milesTravelled << "\n" << food << "\n" << balance << "\n" << health << "\n" << oxen;
            Clear();
            promptForshop(balance);
            bool shouldLoopForShop = true;
            type_text("\n\nWould you like to enter a purchase items from the shop now? [y/N]: ", 30);
            reply = "";
            cin.ignore();
            getline(cin, reply);
            if(reply == "n") {
                shouldLoopForShop = false;
            }
            
            if(shouldLoopForShop) {
                while(shouldLoopForShop) {
                    Clear();
                    type_text("Ye Olde Shoppe   \n", 30);
                    type_text(" __________________________________________________________________________\n", 5);
                    type_text("|: : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : |\n", 5);
                    type_text("| : : : : : : : : : : : : : : : :_________________________: : : : : : : : :|\n", 5);
                    type_text("|: : : : : : : : : : : : : : : _)                         (_ : : : : : : : |\n", 5);
                    type_text("| : : : : : : : : : : : : : : )_ :  Ye Olde Shoppe 1847 :  _( : : : : : : :|\n", 5);
                    type_text("|: : Eoooooor  : : : :__________)_________________________(__________  : : |\n", 5);
                    type_text("| _____________ : _ :/ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\\: _ :|\n", 5);
                    type_text("||  _________  | /_\\ '.Z.'.Z.'.Z.'.Z.'.Z.'.Z.'.Z.'.Z.'.Z.'.Z.'.Z.'.Z.' /_\\ |\n", 5);
                    type_text("|| |    |    | |:=|=: |Flowers * Perfumes_________Lingerie * Candles| :=|=:|\n", 5);
                    type_text("|| |    |    | | : : :|   ______    _  .'         '.  _    ______   |: : : |\n", 5);
                    type_text("|| |    |    | |======| .' ,|,  '. /_\\ |           | /_\\ .'  ,|, '. |======|\n", 5);
                    type_text("|| |    |    |:|Lounge| | ;;;;;  | =|= |           | =|= |  ;;;;; | |Casino|\n", 5);
                    type_text("|| |    |    | |<---  | |_';;;'_n|     |  n______  |     |$_';;;'_| |  --->|\n", 5);
                    type_text("|| |    |    | |      | |_|-;-|__|     |-|_______|-|     |__|-;-|_| |      |\n", 5);
                    type_text("|| |    |    | |      | |________|     |           |     |________| |      |\n", 5);
                    type_text("|| |    |    | |      |                |           |                |      |\n", 5);
                    type_text("lc_|____|____|_|______|________________|           |________________|______|\n", 5);
                    type_text("\n\n#1 - Oxen - $200 for 2 ", 30);
                    type_text("\n#2 - Food - $2 for 4lbs ", 30);
                    type_text("\n#3 - Bullets - $2 for 20 ", 30);
                    type_text("\n#4 - Wagon Repair Parts - 20 per part ", 30);
                    type_text("\n#5 - Med Kit - $25 for 1 ", 30);
                    type_text("\n#6 - Exit and get on the trail ", 30);
                    type_text("\n\nEnter the # of your selected option: ", 30);
                    string line = "";
                    getline(cin, line);
                    // format for item file
                    if (line == "1") {
                        type_text("\nHow many sets of oxen would you like to purchase?[0 to "+to_string(p.getBalance() / 200)+"] ", 30);
                        int amountOfSets = 0;
                        cin >> amountOfSets;
                        type_text("\nPurchasing "+to_string(2*amountOfSets)+" oxen for $"+to_string(200*amountOfSets), 30);
                        oxenCount = oxenCount + (2*amountOfSets);
                        balance = balance - (200*amountOfSets);
                        p.setBalance(balance);
                        updateGameFilesWithInfo(p);
                        updateInventoryFilesWithInfo(oxenCount, food, amountOfBullets, amountOfRepair, amountOfMedKit);
                    } else if (line == "2") {
                        type_text("\nHow many sets of 4lbs of food would you like to purchase?[0 to "+to_string(p.getBalance() / 2)+"] ", 30);
                        int amountOfSets = 0;
                        cin >> amountOfSets;
                        type_text("\nPurchasing "+to_string(4*amountOfSets)+" lbs of food for $"+to_string(2*amountOfSets), 30);
                        food = food + (4*amountOfSets);
                        balance = balance - (2*amountOfSets);
                        p.setAmountOfFood(food);
                        updateGameFilesWithInfo(p);
                        updateInventoryFilesWithInfo(oxenCount, food, amountOfBullets, amountOfRepair, amountOfMedKit);
                    } else if (line == "3") {
                        type_text("\nHow many sets of 20 bullets would you like to purchase?[0 to "+to_string(p.getBalance() / 2)+"] ", 30);
                        int amountOfSets = 0;
                        cin >> amountOfSets;
                        type_text("\nPurchasing "+to_string(20*amountOfSets)+" bullets for $"+to_string(2*amountOfSets), 30);
                        amountOfBullets = amountOfBullets + (20*amountOfSets);
                        balance = balance - (20*amountOfSets);
                        p.setBalance(balance);
                        updateGameFilesWithInfo(p);
                        updateInventoryFilesWithInfo(oxenCount, food, amountOfBullets, amountOfRepair, amountOfMedKit);
                    } else if (line == "4") {
                        type_text("\nHow many replacement parts would you like to purchase?[0 to "+to_string(p.getBalance() / 20)+"] ", 30);
                        int amountOfSets = 0;
                        cin >> amountOfSets;
                        type_text("\nPurchasing "+to_string(amountOfSets)+" replacement parts for $"+to_string(20*amountOfSets), 30);
                        amountOfRepair = amountOfRepair + (amountOfSets);
                        updateInventoryFilesWithInfo(oxenCount, food, amountOfBullets, amountOfRepair, amountOfMedKit);
                    } else if (line == "5") {
                        type_text("\nHow many med kits would you like to purchase?[0 to "+to_string(p.getBalance() / 25)+"] ", 30);
                        int amountOfSets = 0;
                        cin >> amountOfSets;
                        type_text("\nPurchasing "+to_string(amountOfSets)+" oxen for $"+to_string(25*amountOfSets), 30);
                        amountOfMedKit = amountOfMedKit + (amountOfSets);
                        updateInventoryFilesWithInfo(oxenCount, food, amountOfBullets, amountOfRepair, amountOfMedKit);
                    } else if (line == "6") {
                        type_text("\nLeaving shop and getting on the trail...", 30);
                        shouldLoopForShop = false;
                        hasSelectedProperOption = true;
                        break;
                    }
                }
            }
            hasSelectedProperOption = true;
        } else if (option == 3) {
            Clear();
            type_text("Welcome to The Oregon Trail!\n\n", 60);
            type_text("In popular culture, the Oregon Trail is perhaps the most iconic subject in the larger history of Oregon. It adorns a recent Oregon highway license plate, is an obligatory reference in the resettlement of Oregon, and has long attracted study, commemoration, and celebration as a foundational event in the state’s past. The Oregon Trail was first written about by an American historian in 1849, while it was in active use by migrants, and it subsequently was the subject of thousands of books, articles, movies, plays, poems, and songs. The trail continues as the principal interest of a modern-day organization—the Oregon-California Trails Association—and of major museums in Oregon, Idaho, and Nebraska.\n\n", 30);
            type_text("The Oregon Trail has attracted such interest because it is the central feature of one of the largest mass migrations of people in American history. Between 1840 and 1860, from 300,000 to 400,000 travelers used the 2,000-mile overland route to reach Willamette Valley, Puget Sound, Utah, and California destinations. The journey took up to six months, with wagons making between ten and twenty miles per day of travel. The trail followed the Missouri and Platte Rivers west through present-day Nebraska to South Pass on the Continental Divide in Wyoming, then west along the Snake River to Fort Hall in eastern Idaho, where travelers typically chose to continue due west to Oregon or to head southwest to Utah and California. (Information provided by oregonencyclopedia.org)", 30);
            type_text("\n\nWhen Starting the game for the first time, the player is welcomed with a screen where they input their name along with the names of all of the members travelling with them. Following basic informaiton, the player is then given the option to set a different date to start their quest. This Oregon Trail game has seasons and will incorporate the current month and day into various events that happen to add to the realism. The start date could end up being the most important part in your journey so choose wisely. Finally, players are given the option to buy items from the shop to help them on their journey, including: oxe, food, clothes, and hunting tools. Good luck and try not to die too quick!\n", 30);
            //show menu again after user presses enter
        } else if (option == 4) {
             type_text("Goodbye!", 60);
             shouldExit = true;
             hasSelectedProperOption = true;
        } else {
            type_text("Invalid input. Try again.", 60);
        }
        
    }
    bool shouldContinue = true;
    Player p;
    p.setAmountOfFood(food);
    p.setHealth(health);
    p.setMilesToGo(milesToGo);
    p.setName(name);
    p.setBalance(balance);
    p.setCurrentMonth(month);
    p.setCurrentDay(day);
    if(shouldExit == false) {
        string line = "";
        // assuming last line was press enter to continue
        getline(cin, line);
        do 
        {
            // cout << '\n' << "Press a key to continue...";
        } while (cin.get() != '\n');
        Clear();
        if(p.getCurrentMonth() > 10) {
            type_text("Uh-oh! Looks like you've run out of time! The current date is "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1857\nStart a new game by pressing 2 on the main menu. Good Bye!", 30);
            shouldContinue = false;
        } else if (p.getAmountOfFood() <=0 || food <= 0) {
            type_text("Uh-oh! Looks like you've run out of food! The current date is "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1857\nStart a new game by pressing 2 on the main menu. Good Bye!", 30);
            shouldContinue = false;
        } else if (p.getHealth() <= 0) {
            type_text("Uh-oh! Looks like you've run out of health! The current date is "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1857\nStart a new game by pressing 2 on the main menu. Good Bye!", 30);
            shouldContinue = false;
        } else if (milesToGo <= 0) {
            type_text("\nCongrats! You made it to oregon before time ran out! The current date is "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1857\nStart a new game by pressing 2 on the main menu. Good Bye!", 30);
        } else {
            type_text("Welcome to The Oregon Trails, "+name+"!\nThe date is "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1857\n", 30);
            type_text("You currently have " + to_string(food) + " lbs of food, " + to_string(milesToGo) + " miles left to Oregon, your health is " + to_string(health) + ", and your remaining balance is $"+to_string(balance), 30);
        }
        
        while(shouldContinue) {
            int probOfFindingRaiders = ((((((p.getMilesToGo()/100)-4)^2) + 72) / ((((p.getMilesToGo()/100)-4)^2) + 12)) - 1) / (0.10);
            // type_text("prob of finding raiders: "+to_string(probOfFindingRaiders), 30);
            type_text("\n\nWhat would you like to do?\n#1 - Travel\n#2 - Hunt\n#3 - Rest\n#4 - Help\n#5 - Save & Quit", 30);
            type_text("\nEnter the # of your selected option: ", 30);
            string line = "";
            getline(cin, line);
            // do 
            // {
            // } while (cin.get() != '\n');
            if(line == "1" || line == "travel") {
                Clear();
                type_text(",                        '           .        '        ,  \n", 5);
                type_text("   .            .        '       .         ,         \n", 5);
                type_text("                                                   .       '     +\n", 5);
                type_text("       +          .-'''''-.     \n", 20);
                type_text("                .'         `.   +     .     ________||\n", 5);
                type_text("       ___     :             :     |       /        ||  .     '___\n", 5);
                type_text("  ____/   \\   :               :   ||.    _/      || ||\\_______/   \\\n", 5);
                type_text(" /         \\  :      _/|      :   `|| __/      ,.|| ||             \\\n", 5);
                type_text("/  ,   '  . \\  :   =/_/      :     |'_______     || ||  ||   .      \\\n", 5);
                type_text("    |        \\__`._/ |     .'   ___|        \\__   \\\\||  ||...    ,   \\\n", 5);
                type_text("   l|,   '   (   /  ,|...-'        \\   '   ,     __\\||_//___          \n", 5);
                type_text(" ___|____     \\_/^\\/||__    ,    .  ,__             ||//    \\    .  ,\n", 5);
                type_text("           _/~  `\"\"~`\"` \\_           ''(       ....,||/       '   \n", 5);
                type_text(" ..,...  __/  -'/  `-._ `\\_\\__        | \\           ||  _______   .\n", 5);
                type_text("   itz/jgs/ccm'`  `\\   \\  \\-.\\        /(_1_,..      || /\n", 5);
                type_text("                                            ______/\"\"\"\"\n", 5);
                int milesTravelledRn = generateRandomNumberBetween(10, 30) * oxenCount;
                milesToGo = milesToGo - milesTravelledRn;
                milesTravelled = milesTravelled + milesTravelledRn;
                int daysTakenToTravel = generateRandomNumberBetween(2, 7);
                // lbs of food eaten = days taken times 5
                int amountOfFoodEaten = daysTakenToTravel * 4 * oxenCount;
                food = food - amountOfFoodEaten;
                p.setMilesToGo(milesToGo);
                p.setAmountOfFood(food);
                // p.addDaysToTrip(daysTakenToTravel);
                p = addDaysToTrip(p, daysTakenToTravel);
                updateGameFilesWithInfo(p);
                updateInventoryFilesWithInfo(oxenCount, food, amountOfBullets, amountOfRepair, amountOfMedKit);
                type_text("\n\n"+to_string(milesToGo)+" miles left! You traveled "+to_string(milesTravelledRn)+" miles for "+to_string(daysTakenToTravel)+" days, which left you with "+to_string(food)+" lbs of food. The date is now: "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1847", 30);
                if(p.getCurrentMonth() > 10) {
                        Clear();
                        type_text("Uh-oh! Looks like you've run out of time! The current date is "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1857\nStart a new game by pressing 2 on the main menu. Good Bye!", 30);
                        shouldContinue = false;
                    }
            } else if(line == "2" || line == "hunt") {
                // generates random animal from percentage chance
                Animal animal = animalEncountered();
                type_text("You encountered a "+animal.getType()+" which requires "+to_string(animal.getAmountOfBulletsNeeded())+" bullets to kill but will yield "+to_string(animal.getWeight())+" lbs of food.\n\nWould you like to kill it? [Y/n] ", 30);
                // int foodGot = generateRandomNumberBetween(5, 10) * p.getHuntingAbility();
                string reply;
                cin.ignore();
                getline(cin, reply);
            if(reply == "y" && amountOfBullets > animal.getAmountOfBulletsNeeded()) {
                int daysTakenToRecover = 1;
                // lbs of food eaten = days taken times 5
                // int amountOfFoodEaten = daysTakenToRecover * 4 * oxenCount;
                food = food + animal.getWeight();
                amountOfBullets = amountOfBullets - animal.getAmountOfBulletsNeeded();
            
                // p.setAmountOfFood(food)
                p.setAmountOfFood(food);
                // p.addDaysToTrip(daysTakenToRecover);
                p = addDaysToTrip(p, daysTakenToRecover);
                updateInventoryFilesWithInfo(oxenCount, food, amountOfBullets, amountOfRepair, amountOfMedKit);
                updateGameFilesWithInfo(p);
                type_text("\n\n"+to_string(milesToGo)+" miles left! You got "+to_string(animal.getWeight())+" lbs of food over "+to_string(daysTakenToRecover)+" days, which left you with "+to_string(food)+" lbs of food. The date is now: "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1847", 30);
                if(p.getCurrentMonth() > 10) {
                        Clear();
                        type_text("Uh-oh! Looks like you've run out of time! The current date is "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1857\nStart a new game by pressing 2 on the main menu. Good Bye!", 30);
                        shouldContinue = false;
                    }
            } else {
                if(amountOfBullets < animal.getAmountOfBulletsNeeded()) {
                    type_text("Error: you don't have enough bullets to do that!", 30);
                }
            }
                
            } else if(line == "3" || line == "rest") {

                if(health == 100) {
                    type_text("It looks like your health is already at 100. No need to rest, charge on!", 60);
                } else {
                    Clear();
                    type_text("      ()___ ",5);
                    type_text("    ()//__/)_________________()",5);
                    type_text("    ||(___)//#/_/#/_/#/_/#()/||",5);
                    type_text("    ||----|#| |#|_|#|_|#|_|| ||",5);
                    type_text("    ||____|_|#|_|#|_|#|_|#||/||",5);
                    type_text("jgs ||    |#|_|#|_|#|_|#|_||\n",5);
                    int healthRecoveredRn = generateRandomNumberBetween(10, 30);
                    int daysTakenToRecover = generateRandomNumberBetween(1, 3);
                // lbs of food eaten = days taken times 5
                    int amountOfFoodEaten = daysTakenToRecover * 3 * oxenCount;
                    food = food - amountOfFoodEaten;
                    p.setHealth(p.getHealth() + healthRecoveredRn);
                    p.setAmountOfFood(food);
                    p = addDaysToTrip(p, daysTakenToRecover);
                    // p.addDaysToTrip(daysTakenToRecover);
                    updateGameFilesWithInfo(p);
                    type_text("\n\n"+to_string(milesToGo)+" miles left! You healed "+to_string(healthRecoveredRn)+"/100 over "+to_string(daysTakenToRecover)+" days, which left you with "+to_string(food)+" lbs of food. The date is now: "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1847", 30);
                    
                    if(p.getCurrentMonth() > 10) {
                        Clear();
                        type_text("Uh-oh! Looks like you've run out of time! The current date is "+to_string(p.getCurrentMonth())+"/"+to_string(p.getCurrentDay())+"/1857\nStart a new game by pressing 2 on the main menu. Good Bye!", 30);
                        shouldContinue = false;
                    }
                }
            } else if(line == "4" || line == "help") {
                type_text("travel - travel a random amount of miles that depends on the amount of oxen being used. This will also add a random amount of days to your journey. Keep in mind you MUST get to oregon by 10/30/1847!", 30);
                type_text("\nhunt - hunt for food, will take up a random amount of days and will increase food supplies by a random amount depending on tools in inventory.", 30);
                type_text("\nrest - rest for a random amount of time during which the players health will increase by a random amount during which food supplies will be used.", 30);
            } else if(line == "5" || line == "quit") {
                type_text("Goodbye!", 60);
                shouldContinue = false;
            } else {
                type_text("Invalid input. Try again.", 60);
            }
        }
    }
    

    // user has exited, save data to file for later use. each new piece of info saved line by line: milesToGo, food, balance in that order
    return 0;
}