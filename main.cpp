#include <iostream>
#include <string.h>
using namespace std;
// Name- Souroit Goswami
// ID- 210158764
// Email- sgoswami1@sheffield.ac.uk
class Robot
{
    public:
    string name;
    int x_axis_posn;
    int y_axis_posn;
    /*
    left - [L] {-x axis}, right - [R] {x axis},
    up - [U] {y axis}, down - [D] {-y axis}
    */
    char orient;

    Robot(int x_axis_posn,int y_axis_posn) //Constructor 1 initialisation-> Position
    {

        x_axis_posn=0;
        y_axis_posn=0;

    }
    Robot() //Constructor 2 initialisation-> Details
    {
        name="";
        orient=0;
    }

    ~Robot() //Destructor
    {
        cout<<"Destructor in use"<<endl;
        //delete name;
    }

    void display()
    {
        cout<<"Name="<<name<<endl;
        cout<<"Position=("<<x_axis_posn<<","<<y_axis_posn<<")"<<endl;
        cout<<"Orientation="<<orient<<endl;
        cout<<endl;
    }

    int steps(int k)
    {
        if(orient=='U')
        {
            y_axis_posn+=k;     //for Up & Down steps would be in y-axis
        }
        else if(orient=='D')
        {
            y_axis_posn-=k;     //for Up & Down steps would be in y-axis
        }
        else if(orient=='L')
        {
            x_axis_posn-=k;     //for Left & right steps would be in y-axis
        }
        else if(orient=='R')
        {
            x_axis_posn+=k;     //for Left & right steps would be in y-axis
        }
        return 1;
    }

    void clockwise()    //U->R, R->D, D->L, L->U
    {
        if(orient=='U')         //U->R
        {
            orient='R';
        }
        else if(orient=='R')    //R->D
        {
            orient='D';
        }
        else if(orient=='D')    //D->L
        {
            orient='L';
        }
        else if(orient=='L')    //L->U
        {
            orient='U';
        }
    }

    void anticlockwise()    //U->L, L->D, D->R, R->U
    {
        if(orient=='U')         //U->L
        {
            orient='L';
        }
        else if(orient=='L')    //L->D
        {
            orient='D';
        }
        else if(orient=='D')    //D->R
        {
            orient='R';
        }
        else if(orient=='R')    //R->U
        {
            orient='U';
        }
    }
};

int main()
{

    //Automated part to have any 'n' no. of robots
    //For our example follow the comment lines

    int i,n,k;
    char rotation;

    cout<<"Enter no. of robots"<<endl;
    cin>>n;//n=2
    Robot robo_obj[n];

    for(i=0;i<n;i++)
    {
        cout<<"Enter robot "<<i<<" details --> name, x_axis_posn, y_axis_posn, orientation"<<endl;
        cin>>robo_obj[i].name;// Alice , Bob
        cin>>robo_obj[i].x_axis_posn;// 2 , 4
        cin>>robo_obj[i].y_axis_posn;// 4 , 1
        cin>>robo_obj[i].orient;// U , R

        cout<<"Robot "<<robo_obj[i].name<<" displayed o/p :-"<<endl;
        robo_obj[i].display();

        //moving steps
        cout<<"Enter the no. of steps to move by Robot "<<robo_obj[i].name<<endl;
        cin>>k;// k= 2 , 1
        robo_obj[i].steps(k);

        //display after movement
        cout<<"Robot "<<robo_obj[i].name<<" status :-"<<endl;
        robo_obj[i].display();

        //Get the input about which direction to rotate
        cout<<"Enter C->clockwise rotation, A->Anticlockwise rotation"<<endl;// A , A
        cin>>rotation;
        switch(rotation)
        {
            case 'C':   //rotation clockwise
                        robo_obj[i].clockwise();
                        break;
            case 'A':   //rotation anticlockwise
                        robo_obj[i].anticlockwise();
                        break;
            default:    cout<<"Invalid choice"<<endl;
        }

        //display after movement
        cout<<"Robot "<<robo_obj[i].name<<" status :-"<<endl;
        robo_obj[i].display();

        //Again moving steps
        cout<<"Enter the no. of steps to move by Robot "<<robo_obj[i].name<<" again"<<endl;
        cin>>k;// k= 3, 4
        robo_obj[i].steps(k);

        //display after movement
        cout<<"Robot "<<robo_obj[i].name<<" status :-"<<endl;
        robo_obj[i].display();
    }

    return 0;
}

