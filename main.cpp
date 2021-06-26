#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
/*The scoring details are as follows:

*Black heart, red heart, plum blossom and square are 4, 3, 2 and 1 respectively

*From 3 to big king, add 1 point in turn, from 3 to 17 points

*The score is the sum of the color score and the number of points

*/
using namespace std;

int GetRandonNumber1()//Set up two functions to get random numbers
{
    int RandomNumber;
    srand(time(nullptr));//Set time seed
    RandomNumber=rand()%9+0;//get random number
    return RandomNumber;
}

int GetRandonNumber2()
{
    int RandomNumber;
    srand(time(nullptr));
    RandomNumber=rand()%53+10;
    return RandomNumber;
}

class Card//Create a card class to store card features, decors and points
{
	public:
		string color;
		string point;
		Card(string color, string point);//Colors and points
		Card(string point);//Big and small kings only have points
};

Card::Card(string color, string point)//Initialize constructor
{
    this->color = std::move(color);
    this->point = std::move(point);
}

Card::Card(string point)
{
    this->color = "";
    this->point = std::move(point);
}

class Cards//Create a cards class to perform various card operations
{
    int sumpionts{};//Set the number of points and
public:
    vector<Card> card;//Use a container to store the object card
    Cards();
    void display_all();//Function of display card
    void shufflePoker();//Shuffling function
    void display_tencards();//show ten cards
    void compare();//A function of comparison score
    void change_one();//change one card
    void change_two();//change two cards
    void change_three();//change three cards
    void reset();//Reset scores
    void display_grade() const;//Show score
};

Cards::Cards()
{
    string colors[]={"黑心", "红心", "梅花", "方块"};//The initial card color is: "black heart, red heart, plum blossom, square"
    string numbers[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};//from A to K,set the point
    for(auto & color : colors)//Initialize each card
    {
        for(auto & number : numbers)
        {
            this->card.emplace_back(color, number);
        }
    }
    //big Wang and small Wang need to be initialized separately
    this->card.emplace_back("", "大王");
    this->card.emplace_back("", "小王");

}

void Cards::reset()//reset the scores
{
    sumpionts=0;
}

void Cards::compare()//give a mark
{
    for(int i=0;i<10;i++)
    {
        if(this->card[i].color=="黑心")
        {
            sumpionts=sumpionts+4;
        }
        if(this->card[i].color=="红心")
        {
            sumpionts=sumpionts+3;
        }
        if(this->card[i].color=="梅花")
        {
            sumpionts=sumpionts+2;
        }
        if(this->card[i].color=="方块")
        {
            sumpionts=sumpionts+1;
        }
        if(this->card[i].point=="3")
        {
            sumpionts=sumpionts+3;
        }
        if(this->card[i].point=="4")
        {
            sumpionts=sumpionts+4;
        }
        if(this->card[i].point=="5")
        {
            sumpionts=sumpionts+5;
        }
        if(this->card[i].point=="6")
        {
            sumpionts=sumpionts+6;
        }
        if(this->card[i].point=="7")
        {
            sumpionts=sumpionts+7;
        }
        if(this->card[i].point=="8")
        {
            sumpionts=sumpionts+8;
        }
        if(this->card[i].point=="9")
        {
            sumpionts=sumpionts+9;
        }
        if(this->card[i].point=="10")
        {
            sumpionts=sumpionts+10;
        }
        if(this->card[i].point=="J")
        {
            sumpionts=sumpionts+11;
        }
        if(this->card[i].point=="Q")
        {
            sumpionts=sumpionts+12;
        }
        if(this->card[i].point=="K")
        {
            sumpionts=sumpionts+13;
        }
        if(this->card[i].point=="A")
        {
            sumpionts=sumpionts+14;
        }
        if(this->card[i].point=="2")
        {
            sumpionts=sumpionts+15;
        }
        if(this->card[i].point=="小王")
        {
            sumpionts=sumpionts+16;
        }
        if(this->card[i].point=="大王") {
            sumpionts = sumpionts+17;
        }
    }
    /*
    map<string, int> p;
    map<string, int> c;
    p["A"] = 1;
    p["2"] = 2;
    p["3"] = 3;
    p["4"] = 4;
    p["5"] = 5;
    p["6"] = 6;
    p["7"] = 7;
    p["8"] = 8;
    p["9"] = 9;
    p["10"] = 10;
    p["J"] = 11;
    p["Q"] = 12;
    p["K"] = 13;
    p["小王"] = 14;
    p["大王"] = 15;

    c["黑心"] = 4;
    c["红心"] = 3;
    c["梅花"] = 2;
    c["方块"] = 1;
    c[""] = 0;
    if(p[card1.point] > p[this->point])
        cout<<card1.color + card1.point + "  大于  " + this->color + this->point<<endl;
    else if(p[card1.point] < p[this->point])
        cout<<card1.color + card1.point + "  小于  " + this->color + this->point<<endl;
    else if(p[card1.point] == p[this->point])
    {
        if(c[card1.color] > c[this->color])
            cout<<card1.color + card1.point + "  大于  " + this->color + this->point<<endl;
        else if(c[card1.color] < c[this->color])
            cout<<card1.color + card1.point + "  小于  " + this->color + this->point<<endl;
        else
            cout<<card1.color + card1.point + "  等于  " + this->color + this->point<<endl;
    }
*/
}

void Cards::change_one()//Change a card
{
    string temp;//Temporary storage card
    int numb1=0;
    cout<<"Please enter the card you want to change:"<<endl;
    cin>>numb1;
    int numb2=GetRandonNumber2();//Get cards in other cards
    card[numb1-1]=temp;//Save temporary variable
    cout<<"Please input which card you want to change:"<<numb1<<endl;
    card[numb1-1]=card[numb2];//assignment
    card[numb2]=temp;//Assign the value of the temporary variable to card numb2
    cout<<"The exchange card is:"<<numb2+1<<endl;
}

void Cards::change_two()//Change two cards
{
    int numb1;
    int numb3;
    string temp[3];//Temporary storage card
    cout<<"Which two cards do you want to change："<<endl;
    cin>>numb1;
    cin>>numb3;
    int numb4=GetRandonNumber2();
    int numb2=GetRandonNumber2();
    for (int i = 0; i < 1; i--)//Check the rationality of changing license plate
    {
        if(numb3==numb1)
        {
            cout<<"Please re-enter"<<endl;
            cin>>numb1;
            cin>>numb3;
        }
        else
            break;

    }
    for (int i = 0; i < 1; i--)//Check the reasonableness of the card
    {
        if(numb4==numb2)
            numb2=GetRandonNumber2();
        else
            break;
    }

    card[numb1-1]=temp[1];//Start the exchange
    card[numb3-1]=temp[2];
    cout<<"The one who was chosen was ："<<numb1<<"and"<<numb3<<endl;
    card[numb1-1]=card[numb2];
    card[numb3-1]=card[numb4];
    card[numb2]=temp[1];
    card[numb4]=temp[2];
    cout<<"What are the cards in exchange for："<<numb2+1<<"and"<<numb4+1<<endl;
}

void Cards::change_three()
{
    int numb1;
    int numb3;
    int numb5;
    string temp[4];// temporary storage card
    cout<<"Which three cards do you want to exchange："<<endl;

    cin>>numb1;
    cin>>numb3;
    cin>>numb5;
/*
    while (true)
    {
        if(numb1==numb3)
        {
            cout << "nput error, please input again：" << endl;
            cin>>numb1;
            cin>>numb3;
            cin>>numb5;
        }
        else if (numb1==numb5)
        {
            cout << "nput error, please input again：" << endl;
            cin>>numb1;
            cin>>numb3;
            cin>>numb5;
        }
        else if(numb3==numb5)
        {
            cout << "nput error, please input again：" << endl;
            cin>>numb1;
            cin>>numb3;
            cin>>numb5;
        }
        else
            break;
    }
*/
    int numb2;
    int numb4;
    int numb6;

    for (int i = 0; i < 1; i--)//Check exchange rationality
    {
        numb2=GetRandonNumber2();
        if(numb2!=numb1)
            break;
    }
    for (int i = 0; i < 1; i--)
    {
        numb4=GetRandonNumber2();
        if(numb4!=numb2)
            break;
    }
    for (int i = 0; i < 1; i--)
    {
        numb6=GetRandonNumber2();
        if(numb6!=numb2&&numb6!=numb4)
            break;
    }
    for (int i = 0; i < 1; i--)
    {
        if(numb5!=numb1&&numb5!=numb3)
            break;
        else
            numb5=GetRandonNumber1();
    }

    card[numb1-1]=temp[1];//start exchange
    card[numb3-1]=temp[2];
    card[numb5-1]=temp[3];
    cout<<"Who was chosen are "<<numb1<<"and"<<numb3<<"and"<<numb5<<endl;
    card[numb1-1]=card[numb2];
    card[numb3-1]=card[numb4];
    card[numb5-1]=card[numb6];

    card[numb2]=temp[1];
    card[numb4]=temp[2];
    card[numb6]=temp[3];
    cout<<"What are the cards in exchange for："<<numb2+1<<"and"<<numb4+1<<"and"<<numb6+1<<endl;
}

void Cards::shufflePoker()
{
    srand((unsigned int)time(nullptr));//Set time seed
	shuffle(this->card.begin(), this->card.end(), std::mt19937(std::random_device()()));//Call shuffle function to shuffle
}

void Cards::display_all()
{
	for(int i=0;i<card.size();i++)
    {
        cout<<this->card[i].color;//show the color
		cout<<this->card[i].point + "\t";//show the point
    }
    cout<<endl;
}

void Cards::display_grade() const
{
    cout<<"The quality of the evaluation card is："<<sumpionts<<endl;//show  the scores
}

void Cards::display_tencards()
{
    for(int i=0;i<10;i++)
    {
        cout<<this->card[i].color;//show the color
        cout<<this->card[i].point + "\t";//show the point
    }
    cout<<endl;

}

int main()
{
    while(true)
    {
        int num = 0;
        cout << "Initializes the playing card sequence：" << endl;
        Cards cards;//set a object and initializes the playing card sequence
        //cards.display_all();
        cout << "Start shuffling：" << endl;
        cards.shufflePoker();
        cards.display_all();
        cout << "Show 10 cards for the first time:" << endl;
        cards.display_tencards();
        cards.compare();
        cards.display_grade();
        cout << "select a card exchange mode:" << endl;
        cout << "input 1, enter mode 1 (exchange a card)" << endl;
        cout << "input 2, enter mode 2 (exchange two cards)）" << endl;
        cout << "input 3, enter mode 3 (exchange three cards)" << endl;
        cin >> num;
        if (num == 1) {
            cards.change_one();
        }
        if (num == 2) {
            cards.change_two();
        }
        if (num == 3) {
            cards.change_three();
        }
        cout << "Show 10 cards for the second time:" << endl;
        cards.display_tencards();
        cards.reset();
        cards.compare();
        cards.display_grade();
        cout << "The game is over" << endl;
        cout<<"This round of the game, please enter whether to continue the game, enter 1 to continue, 0, end"<<endl;
        int flag=1;
        cin>>flag;
        if(flag==0)
            break;
    }
    return 0;
}