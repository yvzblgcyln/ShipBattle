#include <iostream>
using namespace std;

int counter,counter_x,counter_y,ship_count;
bool is_create_situation;
int x,y;

class ship{
    public:
        string game_board[4][4] = {{ ".", ".", "." ,"." },{ ".", ".", ".", "." },{ ".", ".", "." ,"." },{ ".", ".", ".", "." }};
        int ship[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
        int shot[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
        int score,game_point;
        void get_coordinates();
        void print_board();
}player1,player2;

void player_1();
void player_2();


int main()
{
    cout << "how many ships do you want? : ";
    cin >> ship_count;

    player_1();
    player_2();

    if(player1.score < player2.score)
        cout << "player1 won\n";
    else if(player1.score > player2.score)
        cout << "player2 won\n";
    else
        cout << "tie game\n";
}

void ship::get_coordinates(){
    if(is_create_situation)
        cout << "\nship coordinates" ;
    else
        cout << "\nshot coordinates" ;
    cout << " \nx: ";
    cin >> x;
    cout << "y: " ;
    cin >> y;

    if(x<5 && x>0 && y<5 && y>0){
        if(is_create_situation){
            if(ship[x-1][y-1]==0)
                ship[x-1][y-1]=1;
            else{
                cout << "already taken coordinates\n" ;
                counter--;}}

        else if(shot[x-1][y-1]==1){
            cout << "already hitted coordinates\n" ;}

        else{
            if(ship[x-1][y-1]==1){
                cout << "shot !\n" ;
                game_board[x-1][y-1]='o';
                game_point++;
                    score++;}
            else{
                cout << "missed shot !\n" ;
                game_board[x-1][y-1]='x';
                    score++;}
            print_board();
            shot[x-1][y-1]=1;}}
    else
        cout << "invalid entrance, enter coordinates between 1-4 \n\n" ;
}

void ship::print_board(){
    for(counter_x=1;counter_x<5;counter_x++){
        for(counter_y=1;counter_y<5;counter_y++){
            cout << game_board[counter_x-1][counter_y-1] << ' ';
        }cout << '\n';}
}

 void player_1(){
     cout << "\nPlayer 1's turn\n";
    player1.game_point=0;

    is_create_situation=true;

    for(counter=0;counter<ship_count;counter++)
        player1.get_coordinates();

    is_create_situation=false;

    while(1){
        player1.get_coordinates();
        if(player1.game_point==ship_count){
            cout << "\nEND TURN\n" ;
            break;}}
 }

 void player_2(){
     cout << "\nPlayer 2's turn\n";
    player2.game_point=0;
    is_create_situation=true;

    for(counter_x=0 ; counter_x < ship_count ; counter_x++){
        for(counter_y=0;counter_y < ship_count ; counter_y++){
            player2.ship[counter_x][counter_y]=0;
            player2.shot[counter_x][counter_y]=0;
            player2.game_board[counter_x][counter_y]='.';}}

    for(counter=0;counter<ship_count;counter++)
        player2.get_coordinates();

    is_create_situation=false;

    while(1){
        player2.get_coordinates();
        if(player2.game_point==ship_count){
            cout << "\nGAME OVER: " ;
            break;}}
 }
