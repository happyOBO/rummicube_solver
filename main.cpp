#include <iostream>
#include <vector>
#include <utility> // pair
#include <bitset>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>


#define BLACK 0
#define BLUE 36
#define RED 31
#define YELLOW 33


using namespace std;
void error_msg();

int num_of_red_tiles,num_of_yellow_tiles,num_of_black_tiles,num_of_blue_tiles;
map<int,int> red_tiles;
map<int,int> blue_tiles;
map<int,int> yellow_tiles;
map<int,int> black_tiles;


void show_ascii_art(void)
{
    cout<<
    " ____                                _               _             ____          _                    \n"<<
    "|  _ \\  _   _  _ __ ___   _ __ ___  (_)  ___  _   _ | |__    ___  / ___|   ___  | |__   __  ___  _ __ \n"<<
    "| |_) || | | || '_ ` _ \\ | '_ ` _ \\ | | / __|| | | || '_ \\  / _ \\ \\___ \\  / _ \\ | |\\ \\ / / / _ \\| '__|\n"<<
    "|  _ < | |_| || | | | | || | | | | || || (__ | |_| || |_) ||  __/  ___) || (_) || | \\ V / |  __/| |   \n"<<
    "|_| \\_\\ \\__,_||_| |_| |_||_| |_| |_||_| \\___| \\__,_||_.__/  \\___| |____/  \\___/ |_|  \\_/   \\___||_|   "<<endl;
    cout<<
    "\n                         ____ ____ _  _ ____    ____ ___ ____ ____ ___ \n"<<
    "                         | __ |__| |\\/| |___    [__   |  |__| |__/  |  \n"<<
    "                         |__] |  | |  | |___    ___]  |  |  | |  \\  | \n"<<endl;
}

void init(void)
{
    try
    {
   
        for(int i = 1; i<= 13; i++)
        {
            red_tiles.insert(make_pair(i, 0));
            yellow_tiles.insert(make_pair(i, 0));
            black_tiles.insert(make_pair(i, 0));
            blue_tiles.insert(make_pair(i, 0));
        }

        cout<<"Write down the tiles you have.\n"<<endl;
        cout<<"# of Received Red Tiles (ex: 5): ";
        cin>>num_of_red_tiles;
        cout<<"Received Red Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_red_tiles; i++)
        {
            int tile;
            cin>>tile;
            red_tiles[tile]++;
        }

        cout<<"# of Received Blue Tiles (ex: 5): ";
        cin>>num_of_blue_tiles;
        cout<<"Received Blue Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_blue_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            blue_tiles[tile]++;
        }

        cout<<"# of Received Yellow Tiles (ex: 5): ";
        cin>>num_of_yellow_tiles;
        cout<<"Received Yellow Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_yellow_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            yellow_tiles[tile]++;
        }
        
        cout<<"# of Received Black Tiles (ex: 5): ";
        cin>>num_of_black_tiles;
        cout<<"Received Black Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_black_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            black_tiles[tile]++;
        }
    }
    catch(int err)
    {
        error_msg();
    }
 
}

void print_user_tiles()
{
    // char string_tiles[20][20] = {"NONE","|1 |","|2 |","|3 |","|4 |","|5 |","|6 |","|7 |","|8 |","|9 |", "|10|" ,"|11|","|12|","|13|"}; 
    try
    {
        for(int j = 1; j <= 14; j++)
        {
            printf(".___  ");
        }
        cout<<endl;
        for(int i = 1; i<= 13; i++)
        {
            if(red_tiles[i] != 0)
            {
                for(int j = 0; j < red_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",RED, i);
                    printf("|  ");
                }

            }
            
        }
        for(int i = 1; i<= 13; i++)
        {
            if(blue_tiles[i] != 0)
            {

                for(int j = 0; j < blue_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",BLUE, i);
                    printf("|  ");
                }
            }    
        }
        for(int i = 1; i<= 13; i++)
        {
            if(yellow_tiles[i] != 0)
            {
                for(int j = 0; j < yellow_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",YELLOW, i);
                    printf("|  ");
                }
            }
        }
        for(int i = 1; i<= 13; i++)
        {
            if(black_tiles[i] != 0)
            {
                for(int j = 0; j < black_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",BLACK, i);
                    printf("|  ");
                }
            }
        } 
        cout<<endl;
        for(int j = 1; j <= 14; j++)
        {
            printf("|__|  ");
        }
        cout<<endl;
    }
    catch(int err)
    {
        error_msg();
    }

}

void error_msg()
{
    cout<<
    "\n_   _ ____ _  _    ___ _   _ ___  ____ ___     _ ___    _ _ _ ____ ____ _  _ ____     ____ ____ ___ ____ _   _  \n"<<
    " \\_/  |  | |  |     |   \\_/  |__] |___ |  \\    |  |     | | | |__/ |  | |\\ | | __     |__/ |___  |  |__/  \\_/   \n"<<
    "  |   |__| |__|     |    |   |    |___ |__/    |  |     |_|_| |  \\ |__| | \\| |__] .   |  \\ |___  |  |  \\   |   .\n"<<endl;
}

// void cmb_same_value()
// {
//     for(int i = 1;i <= 13; i++)
//     {
//         int count = 0;
//         if(red_tiles[i] != 0) count++;
//         if(yellow_tiles[i] != 0) count++;
//         if(blue_tiles[i] != 0) count++;
//         if(black_tiles[i] != 0) count++;

//         if(3 <= count)
//         {

//         }
//     }
// }

int main(void)
{
    show_ascii_art();
    int button = -1;

    while(button != 0)
    {
        cout<<"Press the button to do what you want."<<endl;
        cout<<"1: Initialize my tiles."<<endl;
        cout<<"2: show my tiles."<<endl;
        cout<<"3: Show the tiles I can submit."<<endl;
        cout<<"4: Add one tile"<<endl;
        cout<<"5: Show tiles on the table"<<endl;
        cout<<"6: Write Laying My tiles on the table"<<endl;
        cout<<"7: Write Laying Other's tiles on the table"<<endl;
        cout<<"0: Exit the program"<<endl;
        cin>>button;
        if(button == 1)
        {
            cout<<"You pressed the button 1."<<endl;
            init();
            int num_of_total_tiles = num_of_red_tiles + num_of_yellow_tiles + num_of_blue_tiles + num_of_black_tiles;
            if (num_of_total_tiles == 14)
            {
                cout<<"Done."<<endl;
            }
            else
            {
                error_msg();
            }
            
        }
        else if(button == 2)
        {
            print_user_tiles();
        }
        else if(button == 3)
        {
            cout<<"It's not prepared. comming soon."<<endl;
        }
        else if(button == 4)
        {
            cout<<"It's not prepared. comming soon."<<endl;
        }
        else if(button == 5)
        {
            cout<<"It's not prepared. comming soon."<<endl;
        }
        else if(button == 6)
        {
            cout<<"It's not prepared. comming soon."<<endl;
        }
        else if(button == 0)
        {
            cout<<"You pressed the exit button."<<endl;
            cout<<"Bye!"<<endl;
            break;
        }
        else
        {
            cout<<"Sorry. Press the button again."<<endl;
        }
        
    }
    
}