#include<bits/stdc++.h>
//#include<ctime>
//#include<conio>
using namespace std;
class board
{  
    void add(int i)
    {
        int start,end;
        cout<<"\nAdd a ";
        if(i==1)    cout<<"ladder ";
        if(i==-1)   cout<<"snake ";
        cout<<"between which two places on the board?\n";
        cin>>start>>end;
        if(start>end)
        {
            int x=end;
            end=start;
            start=x;
            if(end>size){cout<<"\nError cannot excede size of board\n";return;}
        }
        if(i==1)    ladder.push_back(make_pair(start,end));
        if(i==-1)   snake.push_back(make_pair(start,end));
        return;
    }
    void del(int i)
    {
        vector<pair<int,int>>::iterator itr;
        int slno=1,choice;
        cout<<"\nChoose which one you want to delete from this list\nEnter only the Sl.no\n\n";
        if(i==1)
        {
            for(itr=ladder.begin();itr!=ladder.end();slno++,itr++)
                cout<<slno<<" "<<itr->first<<" to "<<itr->second<<"\n";
            cin>>choice;
            if(choice>slno)
            {
                cout<<"\nError sl no inncorrect\n";
                return;
            }
            itr=ladder.begin();
            itr+=choice-1;
            itr->first=0;
            itr->second=0;
        }
        if(i==-1)
        {
            for(itr=snake.begin();itr!=snake.end();slno++,itr++)
                cout<<slno<<" "<<itr->first<<" to "<<itr->second<<"\n";
            cin>>choice;
            if(choice>slno)
            {
                cout<<"\nError sl no inncorrect\n";
                return;
            }
            itr=snake.begin();
            itr+=choice-1;
            itr->first=0;
            itr->second=0;
        }
        return;
    }
    protected:
        int size=100;
        vector<int> p;
        vector<pair<int,int>> snake,ladder;
    public:
        void makeboard(int s)
        {
            int choice=0;
            for(int i=0;i<s;++i)  p.push_back(0);
            while(1)
            {   cout<<"\nMake your custom board using this menu/n1.Add snake/n 2.Delete snake/n3.Add ladder/n4.Delete ladder/n5.Go back\n\n";
                cin>>choice;
                switch(choice)
                {
                    case '1': add(-1);
                    case '2': del(-1);
                    case '3': add(1);
                    case '4': del(1);
                    case '5': return;
                }
            }
        }
    board()
    {
        int choice;
        cout<<"Do you want to make a custom board or do you want to play with a pre-set board?\nEnter 1 to make a board\nEnter anything else to play a pre-set board\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"\n Enter size of board\n";
            cin>>size;
            makeboard(size);
        }
        else 
        {
            for(int i=0;i<100;++i) p.push_back(0);
            snake.push_back(make_pair(79,98));
            snake.push_back(make_pair(75,95));
            snake.push_back(make_pair(73,93));
            snake.push_back(make_pair(36,87));
            snake.push_back(make_pair(60,64));
            snake.push_back(make_pair(19,62));
            snake.push_back(make_pair(34,54));
            snake.push_back(make_pair(7,17));
            ladder.push_back(make_pair(80,99));
            ladder.push_back(make_pair(72,91));
            ladder.push_back(make_pair(28,84));
            ladder.push_back(make_pair(51,67));
            ladder.push_back(make_pair(21,43));
            ladder.push_back(make_pair(2,38));
            ladder.push_back(make_pair(9,31));
            ladder.push_back(make_pair(4,14));
        }
    }
};
class game:public board
{
    vector<pair<int,int>> player;
    void match()
    {
        int t=2,k=turn(1);
        while(k==0)
        {
            k=turn(t);
            t++;
        }
        //clrscr();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\nThe winner is player "<<k<<"\nTotal turns played are "<<t;
        return;
    }
    int turn(int turnno)
    {
        int die;
        char dummy;
        //clrscr();
        cout<<"\n\n\n\n\nThis is turn number "<<turnno<<"\nPress any key to proceed";
        cin>>dummy;
        vector<pair<int,int>>::iterator itr_p,itr_s,itr_l;
        for(itr_p=player.begin();itr_p!=player.end();itr_p++)
        {
            //clrscr();
            cout<<"\n\n\n\n\n\nPlayer "<<itr_p->first<<"\'s turn\nPress any key to roll dice\n";
            cin>>dummy;
            die=rand();
            die=die%6+1;
            cout<<"\nInitial position: "<<itr_p->second<<" Dice roll: "<<die;//<<"New position: "<<(itr_p->second+die);
            cout<<"\nPress any key to continue\n";
            cin>>dummy;
            itr_p->second+=die;
            if(itr_p->second>=size)
                return itr_p->first;
            for(itr_s=snake.begin();itr_s!=snake.end();itr_s++)
            {    
                if(itr_p->second==itr_s->second)
                {
                    itr_p->second=itr_s->first;
                    cout<<"Oops a snake ate you :'/ your new location is: "<<itr_p->second;
                    break;
                }
            }
            for(itr_l=ladder.begin();itr_l!=ladder.end();itr_l++)
            {
                if(itr_p->second==itr_l->first)
                {
                    itr_p->second=itr_l->second;
                    cout<<"You reached a ladder yay! Youre new position is: "<<itr_p->second;
                    break;
                }
            }
            cout<<"\nYour final position after this round is: "<<itr_p->second<<"\n press any key to proceed\n";
            cin>>dummy;
        }
        return 0;
    }
    public:
    game()
    {  
        //clrscr();
        int noofplayers;
        cout<<"\n\n\n\n\n\nEnter number of players\n";
        cin>>noofplayers;
        for(int i=1;i<=noofplayers;++i) player.push_back(make_pair(i,0));
        match();
    }
};
int main()
{
    srand(59732893);
    int in=1;
    while(in)
    {
        game G;
        cout<<"Thank you for playing snakes and ladders\nTo start a new game enter 1\nTo exit press any other key\n\n\nGame developed by Aditya Subramanian\n\n\n\n";
        cin>>in;
    }
    return 0;
}