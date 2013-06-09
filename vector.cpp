/**
 * THis code does something with magic.  I am not sreally sure.
 */

#include <cstdlib>

#include <assert.h>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>

using namespace std;

/**
 * Display remaining life for all platers
 *
 * player - Player health
 * name   - Player name 
 */
void lifeDisplay(vector<int> const &player, vector<string> const &name);

/**
 * Write message and then exit code
 *
 * msg - A user message to be displayed before exiting
 */
bool die(string const &msg);

int main() 
{

  // Loop forever
  while (true)
  {
    cout << "How many players?";
    int numPlayers;
    cin >> numPlayers;

    // Validate user input
    if (!cin || (numPlayers<1)) die("Must enter a postive number of players, no words or letters");

    vector<int> player(numPlayers);
    vector<string> name(numPlayers);

    for (int i=0;i<numPlayers;++i)
    {
      cout << "Enter name of player" << i+1 << ":";
      cin >> name[i];
      // Ignore any extra characters in input stream until hitting a carriage return
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Player" << i+1 << " is named " << name[i] << endl;
    }
    cout << "Enter starting life:";
    int life;

    // Validate user input
    if (!(cin>>life) || (life<1)) die("Must enter a postive number for health, no words or letters");

    for (int i=0; i<numPlayers; ++i)
    {
      player[i]=life;
    }
    lifeDisplay(player, name);

    cout << "How to use:'1 -2'(player1 takes 2 damge)" << endl;
    cout << "'3 +2' or '3 2'(player3 gains 3 life)." << endl;
    cout << "Type '0 0' to quit" << endl << endl;

    int numActivePlayers = numPlayers;
    while (numActivePlayers > 1)
    {
      cout<<"Enter player number:";
      int playerNum=0;
      
      // Keep prompting until valid response is given
      while ( !(cin>>playerNum) || (playerNum < 0) || (playerNum > numPlayers))
      {
        cout << "Invalid player number.";
        cout << "Please try again." << endl << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Enter player number:";
      }

      if(playerNum==0)
      {
        cout << "Exiting.  Have a nice day." << endl;
        exit(0);
      }

      cout<<"Enter damage:";
      int dmg=0;
      // Keep prompting until valid response is given
      while (!(cin>>dmg))
      {
        cout << "Invalid damage .";
        cout << "Please try again." << endl << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Enter damage:";
      }

      cout << name[playerNum-1] << " received " << abs(dmg);
      if (dmg > 0)
      {
        cout << " health" << endl;
      }
      else
      {
        cout << " damage" << endl;
      }

      player[playerNum-1]+=dmg;
      lifeDisplay(player, name);

      // Determine number of players with positive health
      numActivePlayers = 0;
      for (int i=0; i<numPlayers; ++i)
      {
        if (player[i] > 0)
        {
          numActivePlayers++;
        }
      }
    }

    cout << endl << "Final healths:" << endl;
    lifeDisplay(player, name);
    for (int i=0; i<numPlayers; ++i)
    {
      if (player[i] > 0)
      {
        cout << name[i] << " is the winner." << endl;
      }
    }

    cout << endl << "Play again?('y' or 'n'):";
    char again;
    if (!(cin>>again) || again!='y')
    {
      cout << "Exiting.  Have a nice day." << endl;
      exit(0);
    }
  }
}


void lifeDisplay(vector<int> const &player, vector<string> const &name)
{
  // Make sure we have the same number of players as names
  assert(player.size()==name.size());

  for(unsigned int i=0;i<player.size();i++)
  {
    cout<<name[i]<<":"<<player[i]<<endl;
  }
  return;
}
	
bool die(string const &msg)
{
  cerr << endl << "Fatal error:" << msg << endl;
  exit (-1);
}
	
