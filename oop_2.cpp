#include<iostream>
#include<string>
#include<ctime>
#include<math.h>
#include<numeric>
#include<stdlib.h>
using namespace std;

class hero{
	private:
		int attackmax;
		int blockmax;
	public:
		string name;
		int health;
		hero(string name,int health, int attackmax, 
		int blockmax ){
			this->name = name;
			this->health = health;
			this->attackmax = attackmax;
			this->blockmax= blockmax;
		}
		int attack(){
			return rand() %this ->attackmax;
		}
		int block(){
			return rand() % this->blockmax;
		}
			
};

class Battle{
	public:
		static void startfight(hero& hero1,
		hero& hero2){
			while(true){
				if(Battle::Getattackresult(hero1, hero2).compare("game over")== 0){
					cout<<"game over \n";
					break;
				}
				if(Battle::Getattackresult(hero2, hero1).compare("game over")== 0){
					cout<<"game over \n";
					break;
				}
			}
		}
		static string Getattackresult(hero& heroA, hero& heroB){
			int heroAattackamt = heroA.attack();
			int heroBblockamt = heroB.block();
			int damage2heroB = ceil(heroAattackamt- heroBblockamt);
			damage2heroB = (damage2heroB <= 0)? 0 :
				damage2heroB;
			heroB.health = heroB.health - damage2heroB;
			
            printf("%s and %s return the battle\n", 
			heroA.name.c_str(),
			heroB.name.c_str());
			printf("%s attacks %s and deals %d damage \n", 
			heroA.name.c_str(),
			heroB.name.c_str(),
			damage2heroB);
			printf("%s and is down to  %d health  \n",
			heroB.name.c_str(),
			heroB.health);
			
			if (heroB.health <= 0 ){
				printf("%s has died and %s is champion\n",
				heroB.name.c_str(),
				heroA.name.c_str());
				return "game over";
			}else {
				return"fight again";
			}
			
	}
			
};

int main()
{
	srand(time(NULL));
    cout<<"start fight \n";
	hero zilong("zilong", 200, 230, 125);
	hero alucard("alucard", 325, 220, 122);
	Battle::startfight(zilong,alucard);
	
}
