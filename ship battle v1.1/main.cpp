#include <iostream>
using namespace std;

class ship{
    public:
        int score,game_point;
}player1,player2;

int counter,counter_x,counter_y,ship_count;
bool is_create_situation;
int x,y;
int width,heigh;
int map[10][10];
bool is_player_1;

void get_coordinates(int map[][10]);
void game_time(int map[][10]);
void reset_map(int n[][10]);
void game_config();
void print_board();

int main()
{
    game_config();

    reset_map(map);
    player1.game_point=0;
    player1.score=0;
    is_player_1=true;
    cout << "\nPlayer 1's turn\n";
    game_time(map);

    reset_map(map);
    player2.game_point=0;
    player2.score=0;
    is_player_1=false;
    cout << "\nPlayer 2's turn\n";
    game_time(map);

    cout << "\nSTATISTICS:\nPlayer 1:\n"<<ship_count <<"/" << player1.score ;
    cout << "\nPlayer 2:\n"<<ship_count <<"/" << player2.score;

    if(player1.score < player2.score)
        cout << "\n\nPlayer1 won\n";
    else if(player1.score > player2.score)
        cout << "\n\nPlayer2 won\n";
    else
        cout << "\nTie game\n";

    return 0;
}
void game_config(){
    while(1){
    cout << "enter width of the map: ";
    cin >> width;
    if(width<=10)
        break;
    else
        cout << "max value is 10\n\n";}

    while(1){
    cout << "enter heigh of the map: ";
    cin >> heigh;
    if(heigh<=10)
        break;
    else
        cout << "max value is 10\n\n";}

    while(1){
    cout << "how many ships do you want? : ";
    cin >> ship_count;
    if(ship_count<=heigh*width && ship_count>0)
        break;
    else
        cout << "enter valid number, max value is " << heigh * width << "\n\n";}

    cout << "\nGame is starting with " << heigh << "x" << width << " map with " << ship_count;

    if (ship_count==1)
        cout << " ship... \n";
    else
        cout << " ships... \n";

}
void reset_map(int map[][10]){
    for(counter_x=0; counter_x<10; counter_x++)
        for(counter_y=0; counter_y<10; counter_y++)
            map[counter_x][counter_y]=0;
}
void game_time(int map[][10]){

    is_create_situation=true;

    for(counter=0;counter<ship_count;counter++)
        get_coordinates(map);

    is_create_situation=false;

    while(1){
        get_coordinates(map);
        if(is_player_1 && player1.game_point==ship_count){
            cout << "\nEND TURN\n" ;
            break;}
        else if(!is_player_1 && player2.game_point==ship_count){
            cout << "\nGAME OVER\n" ;
            break;}}
 }

void get_coordinates(int map[][10]){
    if(is_create_situation)
        cout << "\nship coordinates" ;
    else
        cout << "\nshot coordinates" ;
    cout << " \nx: ";
    cin >> x;
    cout << "y: " ;
    cin >> y;

    if(x<width+1 && x>0 && y<heigh+1 && y>0){
        if(is_create_situation){
            if(map[x-1][y-1]==0)
                map[x-1][y-1]=1;
            else{
                cout << "already taken coordinates\n" ;
                counter--;}}

        else if(map[x-1][y-1]==2 && map[x-1][y-1]==3)
            cout << "already hitted coordinates\n" ;

        else{
            if(map[x-1][y-1]==1){
                cout << "shot !\n" ;
                map[x-1][y-1]=2;
                if(is_player_1){
                    player1.score++;cout << player1.score <<" score\n\n" ;
                    player1.game_point++;}
                else{
                    player2.score++;cout << player1.score <<" score\n\n" ;
                    player2.game_point++;}}
            else{
                cout << "missed shot !\n" ;
                map[x-1][y-1]=3;
                if(is_player_1)
                    player1.score++;
                else
                    player2.score++;
            }
            print_board();}}
    else{
        cout << "invalid entrance, enter coordinates between 1-4 \n\n" ;
        counter--;}
}
void print_board(){
    cout << "  ";
    for(counter_x=1;counter_x<heigh+1;counter_x++)
        cout << counter_x<< " ";
    cout << "\n";

    for(counter_x=1;counter_x<width+1;counter_x++){
        cout << counter_x<< " ";
        for(counter_y=1;counter_y<heigh+1;counter_y++){
            if(map[counter_x-1][counter_y-1]==2)
                cout << "o " ;
            else if(map[counter_x-1][counter_y-1]==3)
                cout << "x " ;
            else
                cout << ". " ;
        }cout << '\n';}
}
