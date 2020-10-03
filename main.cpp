//Name-Tasfique Enam
//Student ID-5886429
//LabTask 10

#include <iostream>
#include<sstream>
#include <limits>

using namespace std;

struct Item
{
    int value;
    int weight;


};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 < r2;
}

void makeheap(struct Item[],int,int);
void sorting(struct Item arr [], int s)
{
    for (int i = (s/2 - 1); i >= 0; i--)
        makeheap(arr, s, i);

    for (int i=s-1; i>=0; i--)
    {

        swap(arr[0], arr[i]);


        makeheap(arr, i, 0);
    }
}

void makeheap(struct Item arr[], int s, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left < s &&cmp(arr[left],arr[largest]))
        largest = left;

    if(right<s &&cmp(arr[right],arr[largest]))
        largest=right;

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        makeheap(arr,s,largest);
    }

}
void makeheap2(struct Item[],int,int);
void sortWeight(struct Item arr [], int s)
{
    for (int i = (s/2 - 1); i >= 0; i--)
        makeheap2(arr, s, i);

    for (int i=s-1; i>=0; i--)
    {

        swap(arr[0], arr[i]);


        makeheap2(arr, i, 0);
    }
}

void makeheap2(struct Item arr[], int s, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left < s && arr[left].weight>arr[largest].weight)
        largest = left;

    if(right<s && arr[right].weight>arr[largest].weight)
        largest=right;

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        makeheap2(arr,s,largest);
    }

}

void makeheap3(struct Item[],int,int);
void sortValue(struct Item arr [], int s)
{
    for (int i = (s/2 - 1); i >= 0; i--)
        makeheap3(arr, s, i);

    for (int i=s-1; i>=0; i--)
    {

        swap(arr[0], arr[i]);


        makeheap3(arr, i, 0);
    }
}

void makeheap3(struct Item arr[], int s, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left < s && arr[left].value<arr[largest].value)
        largest = left;

    if(right<s && arr[right].value<arr[largest].value)
        largest=right;

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        makeheap3(arr,s,largest);
    }

}



double Calculate(int W, struct Item arr[], int n,int c,int o)
{

    if(c==1)
    {
        cout<<"\nThe Lightest Object."<<endl;
        sortWeight(arr,n);
    }
    else if(c==2)
    {
        cout<<"\nThe Most Valuable Object."<<endl;
        sortValue(arr,n);
    }
    else if(c==3)
    {
        sorting(arr,n);
    }

    double finalvalue = 0.0;
    if(o==1)
    {

        string objectweight="";
        string objectvalue;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i].value << "  " << arr[i].weight << " : "
                 << ((double)arr[i].value / arr[i].weight) <<" value per weight"<< endl;
        }


        int CurrentWeight = 0;
        finalvalue = 0.0;
        cout<<"\nTotal Weight of the Object: "<<W<<endl;
        cout<<endl;

        for (int i = 0; i < n; i++)
        {

            if (CurrentWeight + arr[i].weight <= W)
            {
                stringstream string1;
                stringstream string2;
                if(objectweight!="")
                {
                    objectweight=arr[1].weight;
                }

                else
                {
                    string1<<objectweight<<"+"<<arr[i].weight;
                }
                if(objectvalue!="")
                {
                    objectvalue=arr[i].value;
                }
                else
                {
                    string2<<objectvalue<<"+"<<arr[i].value;
                }
               objectvalue=string2.str();
                objectweight=string1.str();
                cout<<"Remaining weight: "<<W-CurrentWeight <<"-" <<arr[i].weight;
                CurrentWeight += arr[i].weight;
                cout<<"="<<W-CurrentWeight<<endl;
                cout<<"Value: "<<finalvalue;
                finalvalue += arr[i].value;
                cout<<"+"<<arr[i].value<<"="<<finalvalue<<endl;
                cout<<endl;
            }


            else
            {
                int remain = W - CurrentWeight;
                if(remain!=0)
                {
                    cout<<"Remaining weight: "<<W<<"-"<<CurrentWeight<<"="<<remain<<endl;
                    cout<<"Value: "<<finalvalue<<"+"<<arr[i].value<<"*"<<"("<<remain<<"/"<<arr[i].weight<<")\t=";
                    cout<<finalvalue<<"+"<<arr[i].value * ((double) remain / arr[i].weight);
                    finalvalue += arr[i].value * ((double) remain / arr[i].weight);
                    cout<<"="<<finalvalue<<endl;
                    cout<<endl;
                }
                break;
            }
        }
    }
    else if(o==2)
    {
        string objectweight="";
        string objectvalue;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i].value << "  " << arr[i].weight << " : "
                 << ((double)arr[i].value / arr[i].weight) <<" value per weight"<< endl;
        }


        int CurrentWeight = 0;
        finalvalue = 0.0;
        cout<<"\nTotal Weight of Objects: "<<W<<endl;
        cout<<endl;
        int remain=0;
        for (int i = 0; i < n; i++)
        {
            if (CurrentWeight + arr[i].weight <= W)
                {

                    stringstream string1;
                    stringstream string2;
                    if(objectweight!="")
                    {
                        objectweight=arr[1].weight;
                    }

                    else
                    {
                        string1<<objectweight<<"+"<<arr[i].weight;
                    }
                    if(objectvalue!="")
                    {
                        objectvalue=arr[i].value;
                    }
                    else
                    {
                        string2<<objectvalue<<"+"<<arr[i].value;
                    }
                    objectvalue=string2.str();
                   objectweight=string1.str();
                    cout<<"Remainder weight: "<<W-CurrentWeight <<"-" <<arr[i].weight;
                    CurrentWeight += arr[i].weight;
                    cout<<"="<<W-CurrentWeight<<endl;
                    cout<<"Value: "<<finalvalue;
                    finalvalue += arr[i].value;
                    cout<<"+"<<arr[i].value<<"="<<finalvalue<<endl;
                    cout<<endl;
                }
                remain=W-CurrentWeight;
        }
        if(remain!=0)
                {
                    cout<<"The Remainder weight= "<<remain<<endl;
                }
    }


    return finalvalue;
}


int main()
{
    int number;
    double Weight;

    cout<<"Please Enter the number of object: ";
    cin>>number;

          while(cin.fail())
    {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Error"<<endl;
           cout<<"Please Enter the number of object: ";
           cin>>number;

    }




    while(number<0)
    {
        cout<<"Error"<<endl;
        cout<<"Please Enter the number of object: ";
        cin>>number;
    }

    Item array[number];
    for(int i=0;i<number;i++)
    {
        cout<<"\n==========================="<<endl;
        cout<<"Object "<<i+1;
        cout<<"\n==========================="<<endl;

        cout<<"The Object Value "<<i+1<<": ";
        cin>>array[i].value;

            while(cin.fail())
    {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Error"<<endl;
         cout<<"The Object Value "<<i+1<<": ";
            cin>>array[i].value;

    }

          while(array[i].value<0)
    {
        cout<<"Error"<<endl;
        cout<<"The Object Value "<<i+1<<": ";
        cin>>array[i].value;

    }

        cout<< " The Object Weight "<<i+1<<": ";
        cin>>array[i].weight;

        while(cin.fail())
    {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Error"<<endl;
           cout<< " The Object Weight "<<i+1<<": ";
            cin>>array[i].weight;


    }



             while(array[i].weight<0)
    {
        cout<<"Error"<<endl;
       cout<< " The Object Weight "<<i+1<<": ";
        cin>>array[i].weight;

    }



    }
    cout<<"\nPlease Enter the Object weight limit: ";
    cin>>Weight;

    while(cin.fail())
    {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Error"<<endl;
           cout<<"\nPlease Enter the Object  weight limit: ";
           cin>>Weight;
    }

     while(Weight<0)
    {
        cout<<"Error"<<endl;
      cout<<"\nPlease Enter the Object weight limit: ";
    cin>>Weight;

    }



    int choice;
    int option;
    do
    {
        cout<<"================================="<<endl;
        cout<<"\n\tMENU"<<endl;
       cout<<"================================="<<endl;
        cout<<" 1. Sorting by Object Weight"<<endl;
        cout<<"\n 2. Sorting by Object Value"<<endl;
        cout<<"\n 3. Sorting by Object value per weight"<<endl;
        cout<<"\n 4.Exit"<<endl;
        cout<<"\nEnter choice: ";
        cin>>choice;

           while(cin.fail())
           {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Error"<<endl;
         cout<<"================================="<<endl;
        cout<<"\n\tMain MENU"<<endl;
       cout<<"================================="<<endl;
        cout<<" 1. Sorting by Object Weight"<<endl;
        cout<<"\n 2. Sorting by Object Value"<<endl;
        cout<<"\n 3. Sorting by Object value per weight"<<endl;
        cout<<"\n 4.Exit"<<endl;
        cout<<"\nEnter choice: ";
            cin>>choice;


              }


         while(choice<1)
         {
        cout<<"================================="<<endl;
        cout<<"\n\tMain MENU"<<endl;
       cout<<"================================="<<endl;
        cout<<" 1. Sorting by Object Weight"<<endl;
        cout<<"\n 2. Sorting by Object Value"<<endl;
        cout<<"\n 3. Sorting by Object value per weight"<<endl;
         cout<<"\n 4.Exit"<<endl;
         cout<<"\nEnter choice: ";
           cin>>choice;
         }

          while(choice>4)
         {
       cout<<"================================="<<endl;
        cout<<"\n\tMain MENU"<<endl;
       cout<<"================================="<<endl;
        cout<<" 1. Sorting by Object Weight"<<endl;
        cout<<"\n 2. Sorting by Object Value"<<endl;
        cout<<"\n 3. Sorting by Object value per weight"<<endl;
        cout<<"\n 4.Exit"<<endl;
        cout<<"\nEnter choice: ";
        cin>>choice;
         }



        if(choice!=4)
        {
            cout<<"| 1)fraction | 2)Discrete |: ";
            cin>>option;
            cout << "The Maximum Object value we can obtain = "
             << Calculate(Weight, array, number,choice,option)<<endl;
        }

        if(choice==4)
      {
        cout<<"Goodbye"<<endl;
      }
    }while(choice!=4);
    return 0;
}

