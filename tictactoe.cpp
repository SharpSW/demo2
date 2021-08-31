// To do:Remove Exit, Make so one player cant play the same spot as the other
#include<iostream>
using namespace std;
struct Board{
	char g[3][3];

};

ostream& operator<<(ostream& o,Board b){
	o<<"This is a Board";
	o<<b.g<<"\n";
	return o;
}
void boardprint(Board board){
	for(int i=0; i < 3;i++){
		for(int n=0; n < 3;n++){
			cout<<board.g[i][n];
			cout<<" ";
		}
		cout<<"|"<<"\n";
	}
}
void plexit(){
	cout<<"Please type the correct coordinates\n";
	exit(0);
}
void twywtg(){
	cout<<"Type where you want to go, Example: 0,0"<<"\n";
}
using Location=pair<int,int>;
Location gcoords(){
	// To be more friendly add loop
	twywtg();
	string player1;
	getline(cin,player1);
	int x;
	int y;
	if(player1.size() <3 or player1.size() >3){
		plexit();
	}
	
	// To be more friendly add loop
	x=player1[0]-'0';
	y=player1[2]-'0';
	if(x <0 or x >2){
		plexit();
	}
	if(y <0 or y >2){
		plexit();
	}
	pair<int,int> c;
	c.first=x;
	c.second=y;
	return c;
}
Location check(Board bazooka){ 
	Location monkey;
	monkey=gcoords();
	char u;
	u=bazooka.g[monkey.second][monkey.first];
	if( u == '~'){
		return monkey;
	}
	if( u == 'x' or u == 'o'){
		cout<<"Someone's already gone there, please pick somewhere else.\n";
		boardprint(bazooka);
		return check(bazooka);
	}
	Location dolphin;
	return dolphin;	
}
void wincheck(Board elephant){
	if(elephant.g[0][0]== 'x' && elephant.g[0][1]== 'x' && elephant.g[0][2]== 'x'){
		cout<<"Player 1 Wins!\n";
		exit(0);
	}
}
int main(){ // This makes the board blank 
	Board paint;
	/*
	cout<<paint.z<<"\n"; */
	/* 
	cout<<paint<<"\n"; */
	Board board;
	for(int i=0;  i < 3;i++){
		for(int n=0; n < 3;n++){
			board.g[i][n]='~';
		}
	}
	boardprint(board);
	// To be more friendly add loop
	while(1){
		Location e=check(board);
		// This puts the x at where the player attempted it to be at
		board.g[e.second][e.first]='x'; 
		boardprint(board);
		wincheck(board);
		Location f=check(board);
		// This puts the x at where the player attempted it to be at
		board.g[f.second][f.first]='o'; 
		boardprint(board);
	}
}	