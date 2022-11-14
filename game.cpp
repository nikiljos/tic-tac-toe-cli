#include<iostream>
using namespace std;
void print_grid(int *data){
    int print_combi[][3]={{0,1,2},{3,4,5},{6,7,8}};
    cout<<"\n+---+---+---+\n";
    for(int *combi:print_combi){
        cout<<"| ";
        for(int i=0;i<3;i++){
            int current=data[combi[i]];
            if(current<=9){
                cout<<current<<" | ";
            }
            else if(current==10){
                cout<<"O | ";
            }
            else if(current==11){
                cout<<"X | ";
            }
            
        }
        cout<<"\n+---+---+---+\n";
    }
}
char check_winner(int *data){
    int win_combi[][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(int *combi:win_combi){
        if(data[combi[0]]==data[combi[1]]&&data[combi[1]]==data[combi[2]]){
            if(data[combi[0]]==10){
                return 'O';
            }
            else if(data[combi[0]]==11){
                return 'X';
            }
        }
    }
    return 'N';
}
int main(){
    int res[]={1,2,3,4,5,6,7,8,9};

    bool x=true;
    int counter=0;
    
    while(counter<9){
        print_grid(res);
        int input;
        char player='X';
        int val=11;
        if(!x){
            player='O';
            val=10;
        }
        cout<<"Player "<<player<<",Enter the postition you want to choose: ";
        cin>>input;
        if(input<1||input>9){
            cout<<"\nInvalid Postition!\n";
        }
        else if(res[input-1]!=input){
            cout<<"\nAlready Selected!\n";
        }
        else{
            res[input-1]=val;
            char status=check_winner(res);
            if(status=='N'){
                x=!x;
                counter++;
            }
            else{
                cout<<"\n"<<status<<" is the winner!\n";
                return 0;
            }
        }
    }
    cout<<"\nThe game is draw!\n";
}