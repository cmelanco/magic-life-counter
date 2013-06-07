#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
vector<int> player;
vector<string> name;
int pc;
void lifeDisplay();
bool die (const string & msg);
bool error=false;
int main(
){char agian;
	do{

	for (bool seen=false;seen==false;){
		cout << "How many players?";
		cin >> pc;
		if (!cin) die("Must enter a postive number of players, no words or letters");
		if (pc<1){ 
			cout << "You need at least one life to track"<<endl;
			error=true;
			break;
		}
		if (pc>=1){
			seen=true;
			name.resize (pc);
			player.resize (pc);
		}//sets player size and stops 
		for (int i=0;i<pc;i++){
			cout<<"Enter name of player"<<i+1<<":";
			cin>>name[i];
		}
		cout << "Enter starting life:";
		int life;
		cin>>life || die("well thats not very good now is it?");
		for (int i=0;i<pc;i++){player[i]=life;}
		lifeDisplay();
		cout<<"how to use:'1 -2'(player1 takes 2 damge)"<<endl<<"'3 +2' or '3 2'(player3 gains 3 life)."<<endl;
		cout<<"Type '0 0' to quit"<<endl<<endl;
		bool check=false;
		int playerNum=0;
		while (check==false){
			cout<<"Enter life change:";
			int dmg=0;
			cin>>playerNum || die("YOU BROKE IT!");
			cin>>dmg || die("YOU BROKE IT!");
			if(playerNum<0 || playerNum>pc){
				cout<<"invaild player try agian"<<endl;
				break;
			}
			if(playerNum==0){
				check=true;
				break;
			}
			player[playerNum-1]+=dmg;
			lifeDisplay();
			cin.clear();
			}
	}
	if (error==false){
		cout<<"Play agian?('y' or 'n'):";
		cin>>agian;}
	if (error=true){
		agian='y';
		error=false;}
	}while(agian=='y');
}


void lifeDisplay(){
		for(int i=0;i<pc;i++)cout<<name[i]<<":"<<player[i]<<endl;
		return;
}
	
bool die(const string & msg){
		cerr << endl << "Fatal error:" << msg << endl;
		exit (EXIT_FAILURE);
	}
	