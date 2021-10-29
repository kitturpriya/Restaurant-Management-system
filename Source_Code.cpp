/*
    DSA Project: Restaurant Management System  
    
    Created BY: I-076 ~ Shrushti Mehta
                I-078 ~ Priyanka Kittur
                I-082 ~ Shreyas Dongre

*/



#include<iostream>
#include<string>

using namespace std;

//Defining 4 classes for 4 static menu linked lists and defining insert and delete functions for the same.
class starters
{
    public:
    int serial_no;
    int item_no;
    int key;
    string item_name;
    int cost;
    starters *next;
    void display(starters* n);
    void insert(starters** current );
    void del(starters** current );
};
//15 starters:
starters *head=new starters();
starters *first=new starters();
starters *second=new starters();
starters *third=new starters();
starters *fourth=new starters();
starters *fifth=new starters();
starters *sixth=new starters();
starters *seventh=new starters();
starters *eighth=new starters();
starters *ninth=new starters();
starters *tenth=new starters();
starters *eleventh=new starters();
starters *twelveth=new starters();
starters *thirteenth=new starters();
starters *fourteenth=new starters();

int oriental=8;  //initial ending index no for each section starting from 1.
int i_oriental=8;  //no.of items in that section
int tandoor=15;
int i_tandoor=7;
void starters::display(starters* n)
{
    cout<<"Starters:"<<endl;
    cout<<"Oriental and Continental Starters:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    int a=0;
    while(a<oriental)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Indian-Tandoor Starters:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(n!=NULL)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
    }
    cout<<endl;
}
void starters::insert(starters** current ) //specify end of section pos for node to inserted at the end always.
{
    int num;
    int s;
    cout<<"Select section:\n1. Oriental and Continental\n2. Tandoori\n";
    cin>>s;
    switch(s)
    {
        case 1:
        {
            oriental++;
            tandoor++;
            num=oriental;
            break;
            
        }
        case 2:
        {
            tandoor++;
            num=tandoor;
            break;
        }
        default:
        {
            cout<<"Invalid input."<<endl;
            break;
        }
    }
    int pos=num;
    string item;
    cin.ignore();                          //ignores the \n trailing from the prev input
    cout<<"Enter item name to be added:";
    getline(cin,item);                     //to input strings with white spaces.
    int item_cost;
    cout<<"Enter item cost :";
    cin>>item_cost;
    
    starters* start=head;
    while(start!=NULL)
    {
        if((start->item_no)>=pos)
        {
            start->item_no+=1;
        }
        start=start->next;
    }
    while(pos--)
    {
        if(pos==0)
        {
            starters* midnode= new starters();
            midnode->next=*current;    //inserting the new node at pos by shifting the earlier node at that pos ahead.
             if(num==oriental)
            {
                i_oriental++;
                midnode->serial_no=i_oriental;
            }
            else if(num==tandoor)
            {
                i_tandoor++;
                midnode->serial_no=i_tandoor;
            }
        
            midnode->key=1;
            midnode->item_name=item;
            midnode->cost=item_cost;
            midnode->item_no=num;
            *current=midnode;  //linking the previous node with newly inserted one.
        }
        else
        {
            current= &(*current)->next;
        }
    }

}
void starters::del(starters** current ) //delete node at any specified position.
{
    int pos;
    cout<<"Enter Item num to be deleted:";
    cin>>pos;
    int num=pos;
    starters* start=head;
   
    if(pos<=oriental)
    {
        for(int i=1;i<=oriental;i++)
        {
            if((start->serial_no)>num )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        oriental-=1;
        tandoor--;
        i_oriental--;

    }
    else
    {
        for(int i=1;i<=oriental;i++)
        {
            start=start->next;
        }


        for(int i=oriental+1;i<=tandoor;i++)
        {
            if((start->serial_no)>num-oriental )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        tandoor-=1;
        i_tandoor--;
    }

    starters* start2=head;
    while(start2!=NULL)
    {
        if((start2->item_no)>=pos)
        {
            start2->item_no-=1;
        }
        start2=start2->next;
    }
    starters* current2 = new starters();
    while(pos--) 
    {
        if(pos == 0) 
        {
        //This part skips the node to be deleted and continues the loop from the next node.
        current2 = *current;
        *current = current2->next;  //updated the current to the next of the node to be deleted.
        
        } 
        else
        {
            current= &(*current)->next;
        }
    }


}
class beverages
{
    public:
    int serial_no;
    int item_no;
    int key;
    string item_name;
    int cost;
    beverages *next;
    void display1(beverages* n);
    void insert1(beverages** current );
    void del1(beverages** current );
};
//15 beverages :
beverages  *head1=new beverages ();
beverages  *first1=new beverages ();
beverages  *second1=new beverages ();
beverages  *third1=new beverages ();
beverages  *fourth1=new beverages ();
beverages  *fifth1=new beverages ();
beverages  *sixth1=new beverages ();
beverages  *seventh1=new beverages ();
beverages  *eighth1=new beverages ();
beverages  *ninth1=new beverages ();
beverages  *tenth1=new beverages ();
beverages  *eleventh1=new beverages ();
beverages  *twelveth1=new beverages ();
beverages  *thirteenth1=new beverages ();
beverages  *fourteenth1=new beverages ();

int juice=3;   //initial ending index no for each section starting from 1.
int i_juice=3;  //no.of items in that section
int mix=6;
int i_mix=3;
int milk=12;
int i_milk=6;
int mock=15;
int i_mock=3;
void beverages::display1(beverages* n)
{
    cout<<"Beverages:"<<endl;
    cout<<"Fresh Juices:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    int a=0;
    while(a<juice)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Mixology:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(a<mix)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Milkshakes:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(a<milk)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Mocktails:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(n!=NULL)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
    }
    cout<<endl;
}
void beverages::insert1(beverages** current ) //insert new node.
{
   
    int num;
    int s;
    cout<<"Select section:\n1.Fresh Juices\n2. Mixology\n3. Milkshakes\n4. Mocktails\n";
    cin>>s;
    switch(s)
    {
        case 1:
        {
            juice++;
            mix++;
            milk++;
            mock++;
            num=juice;
            break;
            
        }
        case 2:
        {
            mix++;
            milk++;
            mock++;
            num=mix;
            break;
        }
        case 3:
        {
            milk++;
            mock++;
            num=milk;
            break;
        }
        case 4:
        {
            mock++;
            num=mock;
            break;
        }
        default:
        {
            cout<<"Invalid input."<<endl;
            break;
        }
    }

    int pos=num;
    string item;
    cin.ignore();                          //ignores the \n trailing from the prev input
    cout<<"Enter item name to be added:";
    getline(cin,item);                     //to input strings with white spaces.
    int item_cost;
    cout<<"Enter item cost :";
    cin>>item_cost;

    beverages* start=head1;
    while(start!=NULL)
    {
        if((start->item_no)>=pos)
        {
            start->item_no+=1;
        }
        start=start->next;
    }

    while(pos--)
    {
        if(pos==0)
        {
            beverages* midnode= new beverages();
            midnode->next=*current;    //inserting the new node at pos by shifting the earlier node at that pos ahead.

            if(num==juice)
            {
                i_juice+=1;
                midnode->serial_no=i_juice;
            }
            else if(num==mix)
            {
                i_mix+=1;
                midnode->serial_no=i_mix;
            }
            else if(num==milk)
            {
                i_milk+=1;
                midnode->serial_no=i_milk;
            }
            else if(num==mock)
            {
                i_mock+=1;
                midnode->serial_no=i_mock;
            }
            midnode->key=2;
            midnode->item_name=item;
            midnode->cost=item_cost;
            midnode->item_no=num;
            *current=midnode;  //linking the previous node with newly inserted one.
        }
        else
        {
            current= &(*current)->next;
        }
    }

}
void beverages::del1(beverages** current ) //delete node at any specified position.
{
    int pos;
    cout<<"Enter Item num to be deleted:";
    cin>>pos;
    int num=pos;
    beverages* start=head1;
    if(pos<=juice)
    {
        for(int i=1;i<=juice;i++)
        {
            if((start->serial_no)>num )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        juice-=1;
        mix--;
        milk--;
        mock--;
        i_juice--;

    }
    else if(pos<=mix && pos>juice)
    {
        for(int i=1;i<=juice;i++)
        {
            start=start->next;
        }


        for(int i=juice+1;i<=mix;i++)
        {
            if((start->serial_no)>num-juice )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        mix-=1;
        milk--;
        mock--;
        i_mix--;
    }
    else if(pos<=milk && pos>mix)
    {
        for(int i=1;i<=mix;i++)
        {
            start=start->next;
        }


        for(int i=mix+1;i<=milk;i++)
        {
            if((start->serial_no)>num-mix )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        milk-=1;
        mock--;
        i_milk--;
    }
    else
    {
        for(int i=1;i<=milk;i++)
        {
            start=start->next;
        }


        for(int i=milk+1;i<=mock;i++)
        {
            if((start->serial_no)>num-milk )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        mock-=1;
        i_mock--;
    }
    beverages* start2=head1;
    while(start2!=NULL)
    {
        if((start2->item_no)>=pos)
        {
            start2->item_no-=1;
        }
        start2=start2->next;
    }
    beverages* current2 = new beverages();
    while(pos--) 
    {
        if(pos == 0) 
        {
        //This part skips the node to be deleted and continues the loop from the next node.
        current2 = *current;
        *current = current2->next;  //updated the current to the next of the node to be deleted.
        
        } 
        else
        {
            current= &(*current)->next;
        }
    }


}
class main_course
{
    public:
    int serial_no;
    int item_no;
    int key;
    string item_name;
    int cost;
    main_course *next;
    void display2(main_course* n);
    void insert2(main_course** current );
    void del2(main_course** current );
};
//30 main course items:
main_course  *head2=new main_course ();
main_course *first2=new main_course();
main_course  *second2=new main_course ();
main_course *third2=new main_course ();
main_course  *fourth2=new main_course();
main_course  *fifth2=new main_course ();
main_course *sixth2=new main_course ();
main_course  *seventh2=new main_course ();
main_course  *eighth2=new main_course ();
main_course *ninth2=new main_course ();
main_course  *tenth2=new main_course ();
main_course  *eleventh2=new main_course();
main_course *twelveth2=new main_course ();
main_course  *thirteenth2=new main_course ();
main_course  *fourteenth2=new main_course ();
main_course  *fifteenth2=new main_course ();
main_course  *sixteenth2=new main_course ();
main_course  *seventeenth2=new main_course ();
main_course  *eighteenth2=new main_course ();
main_course  *nineteenth2=new main_course ();
main_course  *twenteeth2=new main_course ();
main_course  *twentyone2=new main_course ();
main_course  *twentytwo2=new main_course ();
main_course  *twentythree2=new main_course ();
main_course  *twentyfour2=new main_course ();
main_course  *twentyfive2=new main_course ();
main_course  *twentysix2=new main_course ();
main_course  *twentyseven2=new main_course ();
main_course  *twentyeight2=new main_course ();
main_course  *twentynine2=new main_course ();

int sabji=13;   //initial ending index no for each section starting from 1.
int roti=18;
int rice=22;
int dal=25;
int biryani=30;
int i_sabji=13;  //no.of items in that section
int i_roti=5;
int i_rice=4;
int i_dal=3;
int i_biryani=5;

void main_course::display2(main_course* n)
{
    cout<<"Main Course:"<<endl;
    cout<<"Sabji Tarkari:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    int a=0;
    while(a<sabji)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Roti:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(a<roti )
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Rice:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(a<rice )
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Dal:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(a<dal)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Biryani's:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(n!=NULL)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
    }
    cout<<endl;
}
void main_course::insert2(main_course** current ) //insert new node.
{
    
    int num;
    int s;
    cout<<"Select section:\n1.Sabji Tarkari\n2. Roti\n3. Rice\n4. Dal\n5. Biryani\n";
    cin>>s;
    switch(s)
    {
        case 1:
        {
            sabji++;
            roti++;
            rice++;
            dal++;
            biryani++;
            num=sabji;
            break;
            
        }
        case 2:
        {
            roti++;
            rice++;
            dal++;
            biryani++;
            num=roti;
            break;
        }
        case 3:
        {
            rice++;
            dal++;
            biryani++;
            num=rice;
            break;
        }
        case 4:
        {
            dal++;
            biryani++;
            num=dal;
            break;
        }
        case 5:
        {
            biryani++;
            num=biryani;
            break;
        }
        default:
        {
            cout<<"Invalid input."<<endl;
            break;
        }
    }
    int pos=num;
    string item;
    cin.ignore();                          //ignores the \n trailing from the prev input
    cout<<"Enter item name to be added:";
    getline(cin,item);                     //to input strings with white spaces.
    int item_cost;
    cout<<"Enter item cost :";
    cin>>item_cost;

    main_course* start=head2;
    while(start!=NULL)
    {
        if((start->item_no)>=pos)
        {
            start->item_no+=1;
        }
        start=start->next;
    }
    while(pos--)
    {
        if(pos==0)
        {
            main_course* midnode= new main_course();
            midnode->next=*current;    //inserting the new node at pos by shifting the earlier node at that pos ahead.
            if(num==sabji)
            {
                i_sabji+=1;
                midnode->serial_no=i_sabji;
            }
            else if(num==roti)
            {
                i_roti+=1;
                midnode->serial_no=i_roti;
            }
            else if(num==rice)
            {
                i_rice+=1;
                midnode->serial_no=i_rice;
            }
            else if(num==dal)
            {
                i_dal+=1;
                midnode->serial_no=i_dal;
            }
            else if(num==biryani)
            {
                i_biryani+=1;
                midnode->serial_no=i_biryani;
            }
        
            midnode->key=3;
            midnode->item_name=item;
            midnode->cost=item_cost;
            midnode->item_no=num;
            *current=midnode;  //linking the previous node with newly inserted one.
        }
        else
        {
            current= &(*current)->next;
        }
    }

}
void main_course::del2(main_course** current ) //delete node at any specified position.
{
    int pos;
    cout<<"Enter Item num to be deleted:";
    cin>>pos;
    int num=pos;
    main_course* start=head2;
    if(pos<=sabji)
    {
        for(int i=1;i<=sabji;i++)
        {
            if((start->serial_no)>num )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        sabji-=1;
        roti--;
        rice--;
        dal--;
        biryani--;
        i_sabji--;

    }
    else if(pos<=roti && pos>sabji)
    {
        for(int i=1;i<=sabji;i++)
        {
            start=start->next;
        }


        for(int i=sabji+1;i<=roti;i++)
        {
            if((start->serial_no)>num-sabji )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        roti-=1;
        rice--;
        dal--;
        biryani--;
        i_roti--;
    }
    else if(pos<=rice && pos>roti)
    {
        for(int i=1;i<=roti;i++)
        {
            start=start->next;
        }


        for(int i=roti+1;i<=rice;i++)
        {
            if((start->serial_no)>num-roti )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        rice-=1;
        dal--;
        biryani--;
        i_rice--;
    }
    else if(pos<=dal && pos>rice)
    {
        for(int i=1;i<=rice;i++)
        {
            start=start->next;
        }


        for(int i=rice+1;i<=dal;i++)
        {
            if((start->serial_no)>num-rice )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        dal-=1;
        biryani--;
        i_dal--;
    }
    else
    {
        for(int i=1;i<=dal;i++)
        {
            start=start->next;
        }


        for(int i=dal+1;i<=biryani;i++)
        {
            if((start->serial_no)>num-dal )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        biryani-=1;
        i_biryani--;
    }

    main_course* start2=head2;
    while(start2!=NULL)
    {
        if((start2->item_no)>=pos)
        {
            start2->item_no-=1;
        }
        start2=start2->next;
    }
    
    main_course* current2 = new main_course();
    while(pos--) 
    {
        if(pos == 0) 
        {
        //This part skips the node to be deleted and continues the loop from the next node.
        current2 = *current;
        *current = current2->next;  //updated the current to the next of the node to be deleted.
        
        } 
        else
        {
            current= &(*current)->next;
        }
    }


}
class deserts
{
    public:
    int serial_no;
    int item_no;
    int key;
    string item_name;
    int cost;
    deserts *next;
    void display3(deserts* n);
    void insert3(deserts** current );
    void del3(deserts** current );
};
//15 desserts :
deserts  *head3=new deserts ();
deserts  *first3=new deserts ();
deserts  *second3=new deserts ();
deserts  *third3=new deserts ();
deserts  *fourth3=new deserts ();
deserts  *fifth3=new deserts ();
deserts  *sixth3=new deserts ();
deserts  *seventh3=new deserts ();
deserts  *eighth3=new deserts ();
deserts  *ninth3=new deserts ();
deserts  *tenth3=new deserts ();
deserts  *eleventh3=new deserts ();
deserts  *twelveth3=new deserts ();
deserts  *thirteenth3=new deserts ();
deserts  *fourteenth3=new deserts ();

int ice=4;   //initial ending index no for each section starting from 1.
int fruit=7;
int falooda=11;
int freak=15;
int i_ice=4;   //no.of items in that section
int i_fruit=3;
int i_falooda=4;
int i_freak=4;
void deserts::display3(deserts* n)
{
    cout<<"Desserts:"<<endl;
    cout<<"Ice-creams:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    int a=0;
    while(a<ice)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Fruit with Ice-cream:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(a<fruit)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Falooda:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(a<falooda)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
        a++;
    }
    cout<<"Freakshakes:"<<endl;
    cout<<"Item no.\tSerial no.\t\tItem name\t\t\t\t\t\t\tCost"<<endl;
    while(n!=NULL)
    {
        cout<<n->item_no<<"\t\t"<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t\t\t\t\t\tRs."<<n->cost<<endl;
        n=n->next;
    }
    cout<<endl;
}
void deserts::insert3( deserts** current ) //insert new node.
{
    int num;
    int s;
    cout<<"Select section:\n1.Ice-cream\n2. Fruit with Ice-cream\n3.Falooda\n4. Freakshakes\n";
    cin>>s;
    switch(s)
    {
        case 1:
        {
            ice++;
            fruit++;
            falooda++;
            freak++;
            num=ice;
            break;
            
        }
        case 2:
        {
            fruit++;
            falooda++;
            freak++;
            num=fruit;
            break;
        }
        case 3:
        {
            falooda++;
            freak++;
            num=falooda;
            break;
        }
        case 4:
        {
            freak++;
            num=freak;
            break;
        }
        default:
        {
            cout<<"Invalid input."<<endl;
            break;
        }
    }
    int pos=num;
    string item;
    cin.ignore();                          //ignores the \n trailing from the prev input
    cout<<"Enter item name to be added:";
    getline(cin,item);                     //to input strings with white spaces.
    int item_cost;
    cout<<"Enter item cost :";
    cin>>item_cost;

    deserts* start=head3;
    while(start!=NULL)
    {
        if((start->item_no)>=pos)
        {
            start->item_no+=1;
        }
        start=start->next;
    }
    while(pos--)
    {
        if(pos==0)
        {
            deserts* midnode= new deserts();
            midnode->next=*current;    //inserting the new node at pos by shifting the earlier node at that pos ahead.
            if(num==ice)
            {
                i_ice+=1;
                midnode->serial_no=i_ice;
            }
            else if(num==fruit)
            {
                i_fruit++;
                midnode->serial_no=i_fruit;
            }
            else if(num==falooda)
            {
                i_falooda+=1;
                midnode->serial_no=i_falooda;
            }
            else if(num==freak)
            {
                i_freak+=1;
                midnode->serial_no=i_freak;
            }
            midnode->key=4;
            midnode->item_name=item;
            midnode->cost=item_cost;
            midnode->item_no=num;
            *current=midnode;  //linking the previous node with newly inserted one.
        }
        else
        {
            current= &(*current)->next;
        }
    }

}
void deserts::del3(deserts** current ) //delete node at any specified position.
{
    int pos;
    cout<<"Enter Item num to be deleted:";
    cin>>pos;
    int num=pos;
    deserts* start=head3;
    if(pos<=ice)
    {
        for(int i=1;i<=ice;i++)
        {
            if((start->serial_no)>num )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        ice-=1;
        fruit--;
        falooda--;
        freak--;
        i_ice--;

    }
    else if(pos<=fruit && pos>ice)
    {
        for(int i=1;i<=ice;i++)
        {
            start=start->next;
        }


        for(int i=ice+1;i<=fruit;i++)
        {
            if((start->serial_no)>num-ice )
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        fruit--;
        falooda--;
        freak--;
        i_fruit--;
    }
    else if(pos<=falooda && pos>fruit)
    {
        for(int i=1;i<=fruit;i++)
        {
            start=start->next;
        }


        for(int i=fruit+1;i<=falooda;i++)
        {
            if((start->serial_no)>num-fruit)
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        falooda--;
        freak--;
        i_falooda--;
    }
    else
    {
        for(int i=1;i<=falooda;i++)
        {
            start=start->next;
        }


        for(int i=falooda+1;i<=freak;i++)
        {
            if((start->serial_no)>num-falooda)
            {
                start->serial_no=start->serial_no-1;
            }
            start=start->next;
        }
        freak-=1;
        i_freak--;
    }

    deserts* start2=head3;
    while(start2!=NULL)
    {
        if((start2->item_no)>=pos)
        {
            start2->item_no-=1;
        }
        start2=start2->next;
    }
    
    deserts* current2 = new deserts();
    while(pos--) 
    {
        if(pos == 0) 
        {
        //This part skips the node to be deleted and continues the loop from the next node.
        current2 = *current;
        *current = current2->next;  //updated the current to the next of the node to be deleted.
        
        } 
        else
        {
            current= &(*current)->next;
        }
    }


}
//---------------------------------------------------------------------------Customer(Order) ~ Shrushti--------------------------------------------------------------
class Order
{
    public:
    int serial_no;
    int reals_no;
    int key;
    int quantity;
    string item_name;
    int cost;
    Order *next;
    void display4(Order* n);
    void display5(Order* n);
    void del(Order* current,int pos );
};
Order *list=new Order();

Order *start, *ptr, *head4,*node;
int bill=0;                        //keep track of the total bill of the current order.
void Order::display4(Order* n)    //display function to display the final order.
{
    cout<<"Order:"<<endl;
    cout<<"Serial no.\t\tItem name\t\t   Quantity\t\t\tCost"<<endl;
    while(n!=NULL)
    {
       cout<<n->serial_no<<".\t\t"<<n->item_name<<"\t\t"<<n->quantity<<"\t\t\tRs."<<n->cost<<endl;
       n=n->next; 
    }
    cout<<endl;
}
void Order::display5(Order* n)  //display function to display the final order.
{
    cout<<"Order:"<<endl;
    cout<<"Item name\t\t   Quantity\t\t\tCost"<<endl;
    while(n!=NULL)
    {
       cout<<n->item_name<<"\t\t"<<n->quantity<<"\t\t\tRs."<<n->cost<<endl;
       n=n->next; 
    }
    cout<<endl;
}
void tp() //creating the head of the dynamic linked list
{
    head4=new Order;
    node=new Order;
}

int newiter=0;
void Order::del(Order *head, int pos ) //delete node at any specified position from the order linked list.
{  
    int new_sno2=0;
    Order *n = head;
   if(pos==0)
    {
        if(head->next == NULL)
        {
            cout << "There is only one node." <<" The list can't be made empty ";
            return;
        }
         bill=bill - n->cost*n->quantity;
        
        head->serial_no = head->next->serial_no;
        head->key = head->next->key;
        head->quantity = head->next->quantity;
        head->item_name = head->next->item_name;
        head->cost = head->next->cost;
 
        
        
        n = head->next;
        
        head->next = head->next->next;
        start->serial_no=new_sno2;
        new_sno2++;
        
        free(n);
 
        return;
    }
      
 
    Order *prev = head;
    Order *prev1 = head;
    for(int i = 0; prev->next != NULL && i < pos - 1; i++)
    {
        prev = prev->next;
    }
        
 
   
    if(prev->next == NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
    for(int i = 0; prev1->next != NULL && i < pos - 1; i++)
    {
        prev1 = prev1->next;
        start->serial_no=new_sno2;
        
        
        if(i==pos-2)
        {
            
            start->serial_no=new_sno2;
            new_sno2++;
            
            
        }
    }
        
 
    
    if(prev1->next == NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
    prev1=prev1->next;
    bill=bill - prev1->cost*prev1->quantity;
    
    prev->next = prev->next->next;
    start->serial_no=new_sno2;
    new_sno2++;
 
    return;

}



starters obj;
beverages obj1;
main_course obj2;
deserts obj3;
Order obj4;
int iterateO=0;
int new_sno=1;
void esp()        //creating the head of the dynamic linked list
{
    start=new Order;
    ptr=start;
}

void takingorder(int sno, int key1, int q)  //Creating dynamic linked lists and searching the required  (item num) item with simultaneously fetching data for it from the 4 static menu linked lists.
{
    
    while (ptr!=NULL) //iterating and adding new nodes in LL until pointer not equals null.
    {
        iterateO++;
        starters* w;        //Defining pointers for each sub menu  and assigning them the respective head.
        w=head;
        beverages* x;
        x=head1;          
        main_course* y;
        y=head2;
        deserts* z;
        z=head3;
        int pos1;
        int exp1=1;
        if (key1==1)   //if the item is starter then fetch the required data from the starter link list and add it in order link list
        {
            if (iterateO>1) //if its the second iteration then make a new node point to the next node;
            {
                ptr->next=new Order;
                ptr=ptr->next;
            }
            pos1=sno;
            ptr->reals_no=sno;
            ptr->serial_no=new_sno;
            ptr->key=key1;
            ptr->quantity=q;
            while (exp1!=pos1)  //this loop is to match and fetch the exact item from the static ll through the serial number given by user 
            {
                if (exp1<pos1)
                {
                    w=w->next;
                    exp1++;
                }
            }            
            ptr->item_name=w->item_name;
            ptr->cost=w->cost;
            bill = bill+ (w->cost*q);
            w=w->next;
            new_sno++;
            key1=0;
            
            break;
        }
        else if (key1==2)//if the item is beverage then fetch the required data from the starter link list and add it in order link list
        {
            if (iterateO>1) //if its the second iteration then make a new node point to the next node;
            {
                ptr->next=new Order;
                ptr=ptr->next;
            }
            pos1=sno;
            ptr->reals_no=sno;
            ptr->serial_no=new_sno;
            ptr->key=key1;
            ptr->quantity=q;
            while (exp1!=pos1) //this loop is to match and fetch the exact item from the static ll through the serial number given by user
            {
                if (exp1<pos1)
                {
                    x=x->next;
                    exp1++;
                }
            }
            ptr->item_name=x->item_name;
            ptr->cost=x->cost;
            bill = bill+ (x->cost*q);
            x=x->next;
            new_sno++;
            key1=0;
            
            break;
        }
        else if (key1==3) //if the item is main course then fetch the required data from the starter link list and add it in order link list
        {
            if (iterateO>1) //if its the second iteration then make a new node point to the next node;
            {
                ptr->next=new Order;
                ptr=ptr->next;
            }
            pos1=sno;
            ptr->reals_no=sno;
            ptr->serial_no=new_sno;
            ptr->key=key1;
            ptr->quantity=q;
            while (exp1!=pos1) //this loop is to match and fetch the exact item from the static ll through the serial number given by user
            {
                if (exp1<pos1)
                {
                    y=y->next;
                    exp1++;
                }
            }
            ptr->item_name=y->item_name;
            ptr->cost=y->cost;
            bill = bill+ (y->cost*q);
            y=y->next;
            new_sno++;
            key1=0;
            
            break;
        }
        else if (key1==4) //if the item is desert then fetch the required data from the starter link list and add it in order link list
        {
            if (iterateO>1) //if its the second iteration then make a new node point to the next node;
            {
                ptr->next=new Order;
                ptr=ptr->next;
            }
            pos1=sno;
            ptr->reals_no=sno;
            ptr->serial_no=new_sno;
            ptr->key=key1;
            ptr->quantity=q;
            while (exp1!=pos1) //this loop is to match and fetch the exact item from the static ll through the serial number given by user
            {
                if (exp1<pos1)
                {
                    z=z->next;
                    exp1++;
                }
            }
            ptr->item_name=z->item_name;
            ptr->cost=z->cost;
            bill = bill+ (z->cost*q);
            z=z->next;
            new_sno++;
            key1=0;
            
            break;
        }
        else
        {
            
            ptr->next=NULL;
            ptr=NULL;
            q=0;
            break;
        }
      
    }
    
    
    
}
//----------------------------------------------------------Total sales admin ~ Priyanka---------------------------------------------------------
class TotalSales
{
    public:
    string item_name;
    int quantity;
    int cost;
    TotalSales *next;
    
};
TotalSales *start8, *ptr8;
int iteratorSalespassed=0;           //num of items in a particular order.
void tsp()
{
   start8=new TotalSales;
   ptr8=start8; 
}
int iteratesales=0;                  //flag variable to check no. of iterations in the dynamic LL.
void tsales1(Order* n,int check)     //to store all the items ordered and keep a track of it.
{
    
    while(ptr8!=NULL)
    {
        
        if(check!=0)
        {
            iteratesales++;
            while(iteratorSalespassed!=0)
            {
               
                if (iteratesales>1)
                {
                    
                    ptr8->next=new TotalSales;
                    ptr8=ptr8->next;
                }
                ptr8->item_name=n->item_name;
                ptr8->quantity=n->quantity;
                ptr8->cost=n->cost;
                n=n->next;
                iteratorSalespassed--;       //this variable is incremented for each item in the order(in customer panel)
                iteratesales++;
            }
            
            break;
        }
        else
        {
            ptr8->next=NULL;
            ptr8=NULL;
            
        }
        
    }
}

//Functiom for Total Sale of the day:
int amt=0;          //declared the variables globally so that even if more than one order is passed,
int serial_no=0;    //the bill will be cummulative of both
int amt1;
int cost;
int bill_no=0;
void tsales1disp(TotalSales* n)
{
     cout<<"Serial No.\t\t\tItem Name\t\t\tQuantity\t\t\tTotal Item Cost\n";
     while(n!=NULL)
     {
         cost=(n->quantity)*(n->cost);
         serial_no++;
         cout<<serial_no<<"\t\t\t"<<n->item_name<<"\t\t\t"<<n->quantity<<"\t\t\t\tRs."<<cost<<"\n";
         n=n->next;
     }
}
void TotalSale(Order* n)
{
    bill_no++;   
    amt1=0; //part bill amount
    cost=0;
    while(n!=NULL)
     {
         cost=(n->quantity)*(n->cost);
         amt+=cost;
         amt1+=cost;
         n=n->next;
     }
}
void TotalSale_display(Order* n)
{
     cout<<"Total Bill for (latest) Bill no. ["<<bill_no<<"]: Rs."<<amt1<<endl;
     
     cout<<"TOTAL Sales: Rs."<<amt<<endl;
}
//######################################################################### KITCHEN ~ Shreyas #####################################################
class kitchen                    //class kitchen for making a new linked list inorder to store sorted menu items.
{
    public:
    int reals_no;
    int serial_no;
    int quantity;
    int key;
    string item_name;
    kitchen *next;
    public:
    void displaykit(kitchen* n);
   
};

void kitchen::displaykit(kitchen* n) //display function for the sorted order linked list
{
    int kitsno = 0;
    cout << "\nYour Order will be served in following sequence!\n\n";
    cout<<"Serial No.\t\t\tItem Name\t\t\tQuantity\n";
    while(n!=NULL)
    {
        kitsno++;
        cout<<kitsno<<"\t\t\t"<<n->item_name<<"\t\t\t"<<n->quantity<< '\n';
        n=n->next;
    }
    cout<<endl;
}

kitchen objdisp;

int iterateSort=0;
void kitchen1(Order *headS) // Sorting: Iterating through Order linked list and the 4 menu link lists  and dynamically fetching nodes from the static linked lists & order linked lists according to keys and storing the fetched nodes into new linked lists dynamically.
{
                     //Key1=Starters; Key2=Beverages; Key3=Main Course; Key4=Deserts
   Order* n;  
   n=headS;
   Order* o;            //Defining 4 different pointers for the same order linked list so that for sorting we can iterate independently.
   o=headS;
   Order* p;
   p=headS;
   Order* q;
   q=headS;
   
   starters* w;
   w=head;
   beverages* x;        //Defining pointers for each sub menu  and assigning them the respective head.
   x=head1;
   main_course* y;
   y=head2;
   deserts* z;
   z=head3;
   
   kitchen *start6, *ptr6;
   start6 = new kitchen; //creating the head of the dynamic linked list
   ptr6 = start6;
    while(ptr6!=NULL) //iterating till pointer equals null and adding items from the order linked list 
    {
        
        
        while(n!=NULL)  //iterating through Order LL and fetch for all nodes with key value 1 i.e fetch for starters.
        {
            
            starters* w;
            w=head;
            int pos1;
            int exp1=1;
            if (n->key == 1)   
            {
                iterateSort++;
               if (iterateSort>1)
              {
                ptr6->next=new kitchen;
                ptr6=ptr6->next;
              }    
              pos1=n->reals_no;
              
              ptr6->reals_no = n->reals_no;
              ptr6->quantity = n->quantity;
              ptr6->key = n->key;
              while(exp1!=pos1)     //this loop is to match and fetch the exact item from the static ll through the serial number passed by Order LL
              {
             
                if (exp1<pos1)
                {
                    w=w->next;
                    exp1++;
                }
              }
              
              ptr6->item_name = w->item_name;
              n=n->next;
              w=w->next;
              
              
            }
            else  
            {
               
                n=n->next;
                
            }
            
            
            
        }
        
        while(o!=NULL) //iterating through Order LL and fetch for all nodes with key value 2 i.e fetch for beverages.
        {
            
            beverages* x;
            x=head1;
            int pos2;
            int exp2i=1;
            if (o->key == 2)
            {
                iterateSort++;
              if (iterateSort>1)
              {
                ptr6->next=new kitchen;
                ptr6=ptr6->next;
              }    
              pos2=o->reals_no;
             
              ptr6->reals_no = o->reals_no;
              ptr6->quantity = o->quantity;
              ptr6->key = o->key;
              while(exp2i!=pos2)      //this loop is to match and fetch the exact item from the static ll through the serial number passed by Order LL
              {
                
                if (exp2i<pos2)
                {
                    x=x->next;
                    exp2i++;
                }
              }
              
              ptr6->item_name = x->item_name;
              o=o->next;
              x=x->next;
             
              
            }
            else  
            {
               
                o=o->next;
                
            }
            
            
            
        }
        while(p!=NULL) //iterating through Order LL and fetch for all nodes with key value 3 i.e fetch for main course.
        {
            
            main_course* y;
            y=head2;
            int pos3;
            int exp3=1;
            if (p->key == 3)
            {
                iterateSort++;
              if (iterateSort>1)
              {
                ptr6->next=new kitchen;
                ptr6=ptr6->next;
              }    
              pos3=p->reals_no;
              
              cout<<p->key<<endl;
              ptr6->reals_no = p->reals_no;
              ptr6->quantity = p->quantity;
              ptr6->key = p->key;
              while(exp3!=pos3)    //this loop is to match and fetch the exact item from the static ll through the serial number passed by Order LL
              {
                
                if (exp3<pos3)
                {
                    y=y->next;
                    exp3++;
                }
              }
              
              ptr6->item_name = y->item_name;
              p=p->next;
              y=y->next;
              
              
            }
            else  
            {
              
                p=p->next;
                
            }
            
            
            
        }
        
        while(q!=NULL) //iterating through Order LL and fetch for all nodes with key value 4 i.e fetch for deserts.
        {
            
            deserts* z;
            z=head3;
            int pos4;
            int exp4=1;
            if (q->key == 4)
            {
                iterateSort++;
              if (iterateSort>1)
              {
                ptr6->next=new kitchen;
                ptr6=ptr6->next;
              }
              pos4=q->reals_no;   
             
              cout<<q->key<<endl;
              ptr6->reals_no = q->reals_no;
              ptr6->quantity = q->quantity;
              ptr6->key = q->key;
              while(exp4!=pos4)    //this loop is to match and fetch the exact item from the static ll through the serial number passed by Order LL
              {
                 
                if (exp4<pos4)
                {
                    z=z->next;
                    exp4++;
                }
              }
              ptr6->item_name = z->item_name;
              q=q->next;
              z=z->next;
              
              
            }
            else  
            {
               
                q=q->next;
                
            }
            
            
            
        }
        ptr6->next = NULL;
        
        ptr6 = NULL;
        break;
        
    }
    
    objdisp.displaykit(start6);  //displaying this newly created LL containing the sorted orders.

  
}

//------------------------------------------------------------Defining the Main panel,Customer and admin panels---------------------------------------------
int iteratorSales=0;

void customerpanel()  //All the frontend customer panel funtions is be called from here.
{
    char ask;
    bool r=true;
    int iterator=0;
   while (r == true)
    {
       int s,x,q,key;
       
       cout<<"Enter selection:\n1.Order the Starter\n2.Order the Beverages\n3.Order the Main course\n4.Order the Desert\n5.Display the Order Placed\n6.Display Final Bill\n7.Delete an item from the Order\n8.Confirm Order\n";
       cin>>s;
       switch(s)
        {
           case 1:
            {
               iteratorSalespassed++;
               iterator++;
               if (iterator == 1)
               {
                   obj.display(head);
                   cout<<"Enter the Item number of the starter you want to order: ";
                   cin>>x;
                   cout<<"Enter quantity: ";
                   cin>>q;
                   key=1;
                   esp();
                   takingorder(x,1,q);
                   break;
               }
               else
               {
                   obj.display(head);
                   cout<<"Enter the Item number of the starter you want to order: ";
                   cin>>x;
                   cout<<"Enter quantity: ";
                   cin>>q;
                   key=1;
                   
                   takingorder(x,1,q);
                   break;
               }
               
            }
           case 2:
            {
               iteratorSalespassed++;    
               iterator++;
               if (iterator == 1)
                {
                   obj1.display1(head1);
                   cout<<"Enter the Item number of the beverage you want to order: ";
                   cin>>x;
                   cout<<"Enter quantity: ";
                   cin>>q;
                   key=2;
                   esp();
                   takingorder(x,2,q);
                   break;
                }
                else
                {
                   obj1.display1(head1);
                   cout<<"Enter the Item number of the beverage you want to order: ";
                   cin>>x;
                   cout<<"Enter quantity: ";
                   cin>>q;
                   key=2;
                   takingorder(x,2,q);
                   break;
                }
               
            }
           case 3:
            {
               iteratorSalespassed++;    
               iterator++;
               if (iterator == 1)
                {
                   obj2.display2(head2);
                   cout<<"Enter the Item number of the main course you want to order: ";
                   cin>>x;
                   cout<<"Enter quantity: ";
                   cin>>q;
                   key=3;
                   esp();
                   takingorder(x,3,q);
                   break;
                }
                else
                {
                   obj2.display2(head2);
                   cout<<"Enter the Item number of the main course you want to order: ";
                   cin>>x;
                   cout<<"Enter quantity: ";
                   cin>>q;
                   key=3;
                   takingorder(x,3,q);
                   break;
                }
               
            }
           case 4:
            {
               iteratorSalespassed++;    
               iterator++;
               if (iterator == 1)
                {
                   obj3.display3(head3);
                   cout<<"Enter the Item number of the desert you want to order: ";
                   cin>>x;
                   cout<<"Enter quantity: ";
                   cin>>q;
                   key=4;
                   esp();
                   takingorder(x,4,q);
                   break; 
                }
                else
                {
                   obj3.display3(head3);
                   cout<<"Enter the Item number of the desert you want to order: ";
                   cin>>x;
                   cout<<"Enter quantity: ";
                   cin>>q;
                   key=4;
                   takingorder(x,4,q);
                   break; 
                }
                
            } 
            case 5:
            {
                obj4.display4(start);
                break;
            }
            case 6:
            {
                cout<<"Total Bill Payable:"<<bill<<"\n"<<endl;
                break;
            }
            case 7:
            {
                int pos;
                cout<<"Enter item num to be deleted: ";
                cin>>pos;
                tp();
                obj4.del(start,pos-1);//-------------------------------------------------------delpos-------------------------------------------------------------------
                obj4.display5(start);
                break;
            }
            case 8:
            {
                
                iteratorSales++;
                takingorder(99,99,99);
                TotalSale(start);
                if(iteratorSales==1)
                {
                    tsp();
                    tsales1(start,1);
                    iterateO=0;
                    iterator=0;
                    bill=0;
                    r=false;
                    iteratorSalespassed=0;
                    cout<<"Order Confirmed"<<endl;
                    cout<<"Do you want your order to be sorted? (y/n): ";
                    cin>>ask;
                    if(ask=='y')
                    {
                        kitchen1(start);
                        iterateSort=0;
                        break;
                    }
                    if (ask=='n')
                    {
                        obj4.display5(start);
                        break;
                    }
                    else
                    {
                        cout<<"Wrong Input"<<endl;
                        break;
                    }
                }
                else 
                {
                    tsales1(start,1);
                    iterateO=0;
                    iterator=0;
                    r=false;
                    iteratorSalespassed=0;
                    cout<<"Order Confirmed"<<endl;
                    cout<<"Do you want your order to be sorted? (y/n): ";
                    cin>>ask;
                    if(ask=='y')
                    {
                        kitchen1(start);
                        iterateSort=0;
                        break;
                    }
                    if (ask=='n')
                    {
                        obj4.display5(start);
                        break;
                    }
                    else
                    {
                        cout<<"Wrong Input"<<endl;
                        break;
                    }
                }
               
                
                
                
            }
           default:
           {
               cout<<"Invalid input."<<endl;
               break;
           }
        }
       
    }
}
    
void adminpanel() //All the backend admin panel funtions is be called from here.
{
   int s;
   cout<<"Enter selection:\n1.Display the menu\n2.Insert item in Starters\n3.Insert item in Beverages\n4.Insert item in Main Course\n5.Insert item in Desserts\n6.Delete item from Starters\n7.Delete item from Beverages\n8.Delete item from Main Course\n9.Delete item from Desserts\n10.View Total sales of the day\n11.Exit to Main Menu\n";
   cin>>s;
   switch(s)
   {
       case 1:
       {
           obj.display(head);
           obj1.display1(head1);
           obj2.display2(head2);
           obj3.display3(head3);
           adminpanel();
           break;
       }
       case 2:
       {
           obj.insert(&head);
           obj.display(head);
           adminpanel();
           break;
       }
       case 3:
       {
           obj1.insert1(&head1);
           obj1.display1(head1);
           adminpanel();
           break;
       }
       case 4:
       {
           obj2.insert2(&head2);
           obj2.display2(head2);
           adminpanel();
           break;
       }
       case 5:
       {
           obj3.insert3(&head3);
           obj3.display3(head3);
           adminpanel();
           break;
       }
       case 6:
       {
           obj.del(&head);  //can del any pos.
           obj.display(head);
           adminpanel();
           break;
       }
       case 7:
       {
           obj1.del1(&head1);
           obj1.display1(head1);
           adminpanel();
           break;
       }
       case 8:
       {
           obj2.del2(&head2);
           obj2.display2(head2);
           adminpanel();
           break;
       }
       case 9:
       {
           obj3.del3(&head3);
           obj3.display3(head3);
           adminpanel();
           break;
       }
       case 10:
       {
           tsales1disp(start8);
           TotalSale_display(start);
           break;
       }
       case 11:
       {
           break;
       }
       default:
       {
           cout<<"Invalid input."<<endl;
           break;
       }
       
   }
}

void MainMenu() // Displaying Main Program Menu
{
    cout<<"\n                                 **************************************************************************\n";
    cout<<"                                                     WELCOME TO RESTAURANT MANAGEMENT SYSTEM\n";
    cout<<"                                 **************************************************************************\n\n\n";
    cout<<"\t\t\t\t\t\t\t1. ADMIN SECTION--> \n";
    cout<<"\t\t\t\t\t\t\t2. CUSTOMER SECTION--> \n";
    cout<<"\t\t\t\t\t\t\t3. Exit--> \n\n";
    cout<<"\t\t\t\t\t\t\tEnter Your Choice --->";
} 

int main()
{
   //Restaurant Menu:

   //Starter linked list.
   //oriental and continental starters:
   head->serial_no=1;
   head->item_no=1;
   head->key=1;
   head->item_name="Mushroom Cheese Stuff";
   head->cost=360;
   head->next=first;
   first->serial_no=2;
   first->item_no=2;
   first->key=1;
   first->item_name="Paneer Pattaya";
   first->cost=350;
   first->next=second;
   second->serial_no=3;
   second->item_no=3;
   second->key=1;
   second->item_name="Paneer Chilly Dry";
   second->cost=350;
   second->next=third;
   third->serial_no=4;
   third->item_no=4;
   third->key=1;
   third->item_name="Veg Crispy";
   third->cost=320;
   third->next=fourth;
   fourth->serial_no=5;
   fourth->item_no=5;
   fourth->key=1;
   fourth->item_name="Manchurian Chilly Dry";
   fourth->cost=340;
   fourth->next=fifth;
   fifth->serial_no=6;
   fifth->item_no=6;
   fifth->key=1;
   fifth->item_name="Paneer Hot Dragon";
   fifth->cost=370;
   fifth->next=sixth;
   sixth->serial_no=7;
   sixth->item_no=7;
   sixth->key=1;
   sixth->item_name="Kung Pao (Paneer/Mushroom)";
   sixth->cost=380;
   sixth->next=seventh;
   seventh->serial_no=8;
   seventh->item_no=8;
   seventh->key=1;
   seventh->item_name="Chef's Spl Paneer(Mangolian/Shanghai sauces)";
   seventh->cost=390;
   seventh->next=eighth;
   //Indian-Tandoor Starters:
   eighth->serial_no=1;
   eighth->item_no=9;
   eighth->key=1;
   eighth->item_name="Bhutte Bhatti Wale";
   eighth->cost=290;
   eighth->next=ninth;
   ninth->serial_no=2;
   ninth->item_no=10;
   ninth->key=1;
   ninth->item_name="Veg Hariyali Kebab";
   ninth->cost=340;
   ninth->next=tenth;
   tenth->serial_no=3;
   tenth->item_no=11;
   tenth->key=1;
   tenth->item_name="Paneer Tikka";
   tenth->cost=320;
   tenth->next=eleventh;
   eleventh->serial_no=4;
   eleventh->item_no=12;
   eleventh->key=1;
   eleventh->item_name="Paneer Firangi";
   eleventh->cost=310;
   eleventh->next=twelveth;
   twelveth->serial_no=5;
   twelveth->item_no=13;
   twelveth->key=1;
   twelveth->item_name="Paneer Malai Tikka";
   twelveth->cost=330;
   twelveth->next=thirteenth;
   thirteenth->serial_no=6;
   thirteenth->item_no=14;
   thirteenth->key=1;
   thirteenth->item_name="Paneer Achari";
   thirteenth->cost=330;
   thirteenth->next=fourteenth;
   fourteenth->serial_no=7;
   fourteenth->item_no=15;
   fourteenth->key=1;
   fourteenth->item_name="Mushroom Tikka";
   fourteenth->cost=320;
   fourteenth->next=NULL;

   

   //Beverages Linked list.
   //Fresh juices:
   head1->serial_no=1;
   head1->item_no=1;
   head1->key=2;
   head1->item_name="Apple";
   head1->cost=210;
   head1->next=first1;
   first1->serial_no=2;
   first1->item_no=2;
   first1->key=2;
   first1->item_name="Pineapple";
   first1->cost=140;
   first1->next=second1;
   second1->serial_no=3;
   second1->item_no=3;
   second1->key=2;
   second1->item_name="Cocktail";
   second1->cost=180;
   second1->next=third1;
   //Mixology:
   third1->serial_no=1;
   third1->key=2;
   third1->item_name="Cindrella(Kiwi,Litchi,Apple)";
   third1->cost=230;
   third1->next=fourth1;
   fourth1->serial_no=2;
   fourth1->key=2;
   fourth1->item_name="Litchi Blast(Black Grapes,Litchi)";
   fourth1->cost=230;
   fourth1->next=fifth1;
   fifth1->serial_no=3;
   fifth1->key=2;
   fifth1->item_name="Milanberry(Watermelon,Strawberry)";
   fifth1->cost=220;
   fifth1->next=sixth1;
   //Milkshakes:
   sixth1->serial_no=1;
   sixth1->key=2;
   sixth1->item_name="Vanilla";
   sixth1->cost=180;
   sixth1->next=seventh1;
   seventh1->serial_no=2;
   seventh1->key=2;
   seventh1->item_name="Butterscotch";
   seventh1->cost=200;
   seventh1->next=eighth1;
   eighth1->serial_no=3;
   eighth1->key=2;
   eighth1->item_name="Dryfruit";
   eighth1->cost=270;
   eighth1->next=ninth1;
   ninth1->serial_no=4;
   ninth1->key=2;
   ninth1->item_name="Kit Kat";
   ninth1->cost=220;
   ninth1->next=tenth1;
   tenth1->serial_no=5;
   tenth1->key=2;
   tenth1->item_name="Choco Love";
   tenth1->cost=210;
   tenth1->next=eleventh1;
   eleventh1->serial_no=6;
   eleventh1->key=2;
   eleventh1->item_name="Strawberry Cheese ";
   eleventh1->cost=250;
   eleventh1->next=twelveth1;
   //Mocktails:
   twelveth1->serial_no=1;
   twelveth1->key=2;
   twelveth1->item_name="Urban Ferry(Khus,Litchy,Lemon,Mint)";
   twelveth1->cost=230;
   twelveth1->next=thirteenth1;
   thirteenth1->serial_no=2;
   thirteenth1->key=2;
   thirteenth1->item_name="Green Chiller(Cucumber,Greenapple)";
   thirteenth1->cost=200;
   thirteenth1->next=fourteenth1;
   fourteenth1->serial_no=3;
   fourteenth1->key=2;
   fourteenth1->item_name="Delight Punch(Peach,Guava)";
   fourteenth1->cost=210;
   fourteenth1->next=NULL;
   third1->item_no=4;
   fourth1->item_no=5;
   fifth1->item_no=6;
   sixth1->item_no=7;
   seventh1->item_no=8;
   eighth1->item_no=9;
   ninth1->item_no=10;
   tenth1->item_no=11;
   eleventh1->item_no=12;
   twelveth1->item_no=13;
   thirteenth1->item_no=14;
   fourteenth1->item_no=15;
  
  
  
   
   //Main Course linked list.
   //Sabji Tarkari:
   head2->serial_no=1;
   head2->key=3;
   head2->item_name="Paneer Tikka Masala";
   head2->cost=360;
   head2->next=first2;
   first2->serial_no=2;
   first2->key=3;
   first2->item_name="Paneer Makhmali";
   first2->cost=340;
   first2->next=second2;
   second2->serial_no=3;
   second2->key=3;
   second2->item_name="Palak Paneer";
   second2->cost=250;
   second2->next=third2;
   third2->serial_no=4;
   third2->key=3;
   third2->item_name="Paneer Mutter Masala";
   third2->cost=280;
   third2->next=fourth2;
   fourth2->serial_no=5;
   fourth2->key=3;
   fourth2->item_name="Paneer Butter Masala";
   fourth2->cost=330;
   fourth2->next=fifth2;
   fifth2->serial_no=6;
   fifth2->key=3;
   fifth2->item_name="Veg Kolhapuri";
   fifth2->cost=250;
   fifth2->next=sixth2;
   sixth2->serial_no=7;
   sixth2->key=3;
   sixth2->item_name="Exotic Bhuna Masala";
   sixth2->cost=280;
   sixth2->next=seventh2;
   seventh2->serial_no=8;
   seventh2->key=3;
   seventh2->item_name="Mushroom Tikka Masala";
   seventh2->cost=290;
   seventh2->next=eighth2;
   eighth2->serial_no=9;
   eighth2->key=3;
   eighth2->item_name="Veg Afghani";
   eighth2->cost=260;
   eighth2->next=ninth2;
   ninth2->serial_no=10;
   ninth2->key=3;
   ninth2->item_name=" Veg Cheese Seekh Masala";
   ninth2->cost=340;
   ninth2->next=tenth2;
   tenth2->serial_no=11;
   tenth2->key=3;
   tenth2->item_name="Nargisi Kofta";
   tenth2->cost=320;
   tenth2->next=eleventh2;
   eleventh2->serial_no=12;
   eleventh2->key=3;
   eleventh2->item_name="Methi Mutter Malai";
   eleventh2->cost=310;
   eleventh2->next=twelveth2;
   twelveth2->serial_no=13;
   twelveth2->key=3;
   twelveth2->item_name="Veg Kadai";
   twelveth2->cost=260;
   twelveth2->next=thirteenth2;
   //Roti:
   thirteenth2->serial_no=1;
   thirteenth2->key=3;
   thirteenth2->item_name="Tandoori Roti";
   thirteenth2->cost=35;
   thirteenth2->next=fourteenth2;
   fourteenth2->serial_no=2;
   fourteenth2->key=3;
   fourteenth2->item_name="Butter Naan";
   fourteenth2->cost=65;
   fourteenth2->next=fifteenth2;
   fifteenth2->serial_no=3;
   fifteenth2->key=3;
   fifteenth2->item_name="Garlic Cheese Naan";
   fifteenth2->cost=120;
   fifteenth2->next=sixteenth2;
   sixteenth2->serial_no=4;
   sixteenth2->key=3;
   sixteenth2->item_name="Bhatore";
   sixteenth2->cost=60;
   sixteenth2->next=seventeenth2;
   seventeenth2->serial_no=5;
   seventeenth2->key=3;
   seventeenth2->item_name="Roti ki Tokri(7 types of roti)";
   seventeenth2->cost=410;
   seventeenth2->next=eighteenth2;
   //Rice:
   eighteenth2->serial_no=1;
   eighteenth2->key=3;
   eighteenth2->item_name="Jeera Rice";
   eighteenth2->cost=210;
   eighteenth2->next=nineteenth2;
   nineteenth2->serial_no=2;
   nineteenth2->key=3;
   nineteenth2->item_name="Dal Kichdi Tadka";
   nineteenth2->cost=290;
   nineteenth2->next=twenteeth2;
   twenteeth2->serial_no=3;
   twenteeth2->key=3;
   twenteeth2->item_name="Veg Pulao";
   twenteeth2->cost=250;
   twenteeth2->next=twentyone2;
   twentyone2->serial_no=4;
   twentyone2->key=3;
   twentyone2->item_name="Kashmiri Pulao";
   twentyone2->cost=270;
   twentyone2->next=twentytwo2;
   //Dal:
   twentytwo2->serial_no=1;
   twentytwo2->key=3;
   twentytwo2->item_name="Dal Fry";
   twentytwo2->cost=275;
   twentytwo2->next=twentythree2;
   twentythree2->serial_no=2;
   twentythree2->key=3;
   twentythree2->item_name="Fusion Dal Makhani";
   twentythree2->cost=260;
   twentythree2->next=twentyfour2;
   twentyfour2->serial_no=3;
   twentyfour2->key=3;
   twentyfour2->item_name="Punjabi Kadi Pakodewali";
   twentyfour2->cost=250;
   twentyfour2->next=twentyfive2;
   //Biryani:
   twentyfive2->serial_no=1;
   twentyfive2->key=3;
   twentyfive2->item_name="Veg Biryani";
   twentyfive2->cost=280;
   twentyfive2->next=twentysix2;
   twentysix2->serial_no=2;
   twentysix2->key=3;
   twentysix2->item_name="Afghani Tikka Biryani";
   twentysix2->cost=290;
   twentysix2->next=twentyseven2;
   twentyseven2->serial_no=3;
   twentyseven2->key=3;
   twentyseven2->item_name="Hariyali Biryani";
   twentyseven2->cost=290;
   twentyseven2->next=twentyeight2;
   twentyeight2->serial_no=4;
   twentyeight2->key=3;
   twentyeight2->item_name="Veg Makhani Biryani";
   twentyeight2->cost=300;
   twentyeight2->next=twentynine2;
   twentynine2->serial_no=5;
   twentynine2->key=3;
   twentynine2->item_name="Kali Handi Dum Biryani";
   twentynine2->cost=380;
   twentynine2->next=NULL;
   head2->item_no=1;
   first2->item_no=2;
   second2->item_no=3;
   third2->item_no=4;
   fourth2->item_no=5;
   fifth2->item_no=6;
   sixth2->item_no=7;
   seventh2->item_no=8;
   eighth2->item_no=9;
   ninth2->item_no=10;
   tenth2->item_no=11;
   eleventh2->item_no=12;
   twelveth2->item_no=13;
   thirteenth2->item_no=14;
   fourteenth2->item_no=15;
   fifteenth2->item_no=16;
   sixteenth2->item_no=17;
   seventeenth2->item_no=18;
   eighteenth2->item_no=19;
   nineteenth2->item_no=20;
   twenteeth2->item_no=21;
   twentyone2->item_no=22;
   twentytwo2->item_no=23;
   twentythree2->item_no=24;
   twentyfour2->item_no=25;
   twentyfive2->item_no=26;
   twentysix2->item_no=27;
   twentyseven2->item_no=28;
   twentyeight2->item_no=29;
   twentynine2->item_no=30;
   
  
   

   //Desserts linked list.
   //Ice-Creams:
   head3->serial_no=1;
   head3->key=4;
   head3->item_name="Sizzling Brownie";
   head3->cost=260;
   head3->next=first3;
   first3->serial_no=2;
   first3->key=4;
   first3->item_name="3 Scoop Ice-cream(Chocolate or Strawberry)";
   first3->cost=250;
   first3->next=second3;
   second3->serial_no=3;
   second3->key=4;
   second3->item_name="Matka(Mango,Dry fruit)";
   second3->cost=290;
   second3->next=third3;
   third3->serial_no=4;
   third3->key=4;
   third3->item_name="Jelly Belly";
   third3->cost=240;
   third3->next=fourth3;
   //Fruit with Ice-cream:
   fourth3->serial_no=1;
   fourth3->key=4;
   fourth3->item_name="Choco Mocha(Vanilla,Chocolate,Dry fruit)";
   fourth3->cost=260;
   fourth3->next=fifth3;
   fifth3->serial_no=2;
   fifth3->key=4;
   fifth3->item_name="Mix Fruit Cream";
   fifth3->cost=240;
   fifth3->next=sixth3;
   sixth3->serial_no=3;
   sixth3->key=4;
   sixth3->item_name="Boston ream Parfait";
   sixth3->cost=260;
   sixth3->next=seventh3;
   //Falooda:
   seventh3->serial_no=1;
   seventh3->key=4;
   seventh3->item_name="Royal Falooda";
   seventh3->cost=210;
   seventh3->next=eighth3;
   eighth3->serial_no=2;
   eighth3->key=4;
   eighth3->item_name="Kesar Falooda";
   eighth3->cost=220;
   eighth3->next=ninth3;
   ninth3->serial_no=3;
   ninth3->key=4;
   ninth3->item_name="Dry Fruit Falooda";
   ninth3->cost=240;
   ninth3->next=tenth3;
   tenth3->serial_no=4;
   tenth3->key=4;
   tenth3->item_name="Kulfi Falooda";
   tenth3->cost=220;
   tenth3->next=eleventh3;
   //Freak Shakes:
   eleventh3->serial_no=1;
   eleventh3->key=4;
   eleventh3->item_name="Vanilla Freakshake";
   eleventh3->cost=320;
   eleventh3->next=twelveth3;
   twelveth3->serial_no=2;
   twelveth3->key=4;
   twelveth3->item_name="Nutella Freakshake";
   twelveth3->cost=350;
   twelveth3->next=thirteenth3;
   thirteenth3->serial_no=3;
   thirteenth3->key=4;
   thirteenth3->item_name="Oreo Freakshake";
   thirteenth3->cost=360;
   thirteenth3->next=fourteenth3;
   fourteenth3->serial_no=4;
   fourteenth3->key=4;
   fourteenth3->item_name="Ferrero Rocher Freakshake";
   fourteenth3->cost=365;
   fourteenth3->next=NULL;

   head3->item_no=1;
   first3->item_no=2;
   second3->item_no=3;
   third3->item_no=4;
   fourth3->item_no=5;
   fifth3->item_no=6;
   sixth3->item_no=7;
   seventh3->item_no=8;
   eighth3->item_no=9;
   ninth3->item_no=10;
   tenth3->item_no=11;
   eleventh3->item_no=12;
   twelveth3->item_no=13;
   thirteenth3->item_no=14;
   fourteenth3->item_no=15;

  //--------------------------------------------------------------------------------- Defining MAIN MENU--------------------------------------------------------------------------------------------------------------
  int choice;
   while(1)
    {
        MainMenu();
        
        cin>>choice;
        

        if(choice==3)
        {
            cout<<"\n\n\t\t\t\t\t\t\t**********Thank you!!**********\n";
            break;
        }

        switch (choice)
        {
            case 1:
                adminpanel();
                break;
            case 2:
                customerpanel();
                
                
                
            case 3:
                break;

            default:
                cout<<"\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n";
                break;
        }
    }
}









