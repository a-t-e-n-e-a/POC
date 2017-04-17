#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 class Ship{
    public: 
	//int id; 
    int owner;
    int x;
    int y;
    int rhum;
    Ship(int own, int x, int y, int r);
    Ship(const Ship &s);
    Ship();
    
};
Ship::Ship(int own, int vx, int vy, int r){
    	owner=own;
    	x=vx;
    	y=vy;
    	rhum=r;
    }
Ship::Ship(const Ship &s){
	owner=s.owner;
	x=s.x;
	y=s.y;
	rhum=s.rhum;
}
Ship::Ship(){
    owner=-1;
	x=-1;
	y=-1;
	rhum=-1;
    }

class Barrel{
public:
	int x;
	int y;
	int cont;
	Barrel(int vx, int vy, int c);
	Barrel(const Barrel &b);
	Barrel();
};
Barrel::Barrel(int vx, int vy, int c){
    	x=vx;
    	y=vy;
    	content=c;
    }
Barrel::Barrel(const Barrel &b){
	x=b.x;
	y=b.y;
	content=s.content;
}
Barrel::Barrel(){
	x=-1;
	y=-1;
	content=-1;
}
Barrel & find_rhum_fats(&ship, list<Barrel> &barrels){
	Ship result;
	int min=100;
	int dist;
	barrel t;
	for (Barrel &b : barrels){
	    dist=abs(b.x-ship.x)+abs(b.y-ship.y);
	    if(dist<min){
	        t=b;
	        min=dist;
	        }
	    } 
	return &t; 
}
int main()
{

    // game loop
    while (1) {
        int myShipCount; // the number of remaining ships
        cin >> myShipCount; cin.ignore();
        int entityCount; // the number of entities (e.g. ships, mines or cannonballs)
        cin >> entityCount; cin.ignore();
        list<Ship> ships;
        list<Barrel> barrels;
        int x;
        int y;
        int entityId;
        string entityType;
        int arg1;
        int arg2;
        int arg3;
        int arg4;
        for (int i = 0; i < entityCount; i++) {
            cin >> entityId >> entityType >> x >> y >> arg1 >> arg2 >> arg3 >> arg4; cin.ignore();
            if(entityType=="SHIP" && arg1==1){
                ships.add(Ship(arg1,x,y,arg3));    //1 equals my ship
            }
            else if(entityType=="BARREL"){
                barrels.add(Barrel(x,y,arg1));   
            }
        }
        Ship mine=ships.front;
        Barrel target=find_rhum_fast(mine, barrels);
        for (int i = 0; i < myShipCount; i++) {

            // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;

            cout << "MOVE " << target.x << " " << target.y << endl; // Any valid action, such as "WAIT" or "MOVE x y"
        }
    }
}