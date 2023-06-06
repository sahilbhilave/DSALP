#include<iostream>
#include<cstring>

#define SIZE 5

class Telephone
{
    struct Data
    {
        char name[50] = "";
        long telephone = 0;
    }data[SIZE];

    public:
    int hash(char key[50])
    {
        return (key[0]%SIZE);
    }

    int probe(char key[50])
    {
        int index = hash(key);
        int i=0;
        while(strcmp(data[(index+i)%SIZE].name,"") != 0 )
        {
            i++;
            if(i == SIZE)
            {
                return -1;
            }
        }

        return (index+i)%SIZE;
    }

    void insert()
    {
        char name[50];
        long telephone;
        std::cout<<"Enter Name : ";
        std::cin>>name;

        std::cout<<"Enter Telephone : ";
        std::cin>>telephone;

        int index = hash(name);
        std::cout<<"\nPlacing at index "<<index<<"\n";
         if(strcmp(data[index].name, "") == 0 )
        {
            strcpy(data[index].name, name);
            data[index].telephone = telephone;
        }
        else
        {
            index = probe(name);
            if(index != -1){
            strcpy(data[index].name,name);
            data[index].telephone = telephone;
            }
            else
            {
                std::cout<<"Array is FULL";
            }
        }
    }

    void display()
    {
        for(int i=0;i<SIZE;i++)
        {
            std::cout<<data[i].name<<"  "<<data[i].telephone<<"\n";
        }
    }

    void search()
    {
        char name[50];
        std::cout<<"Enter Name To Search : ";
        std::cin>>name;

        int index = hash(name);
        int i=0;
        while(strcmp(data[index+i].name,name) != 0)
        {
            i++;
            if(i==SIZE)
            {
                std::cout<<"Element Not Found";
                return;
            }
        }

        std::cout<<"Data Found with Name : "<<data[index+i].name<<" Telephone : "<<data[index].telephone<<"\n";


    }

};

int main()
{
    Telephone n;

    int c=-1;
    while(c!=0)
    {
        std::cout<<"0.Exit";
        std::cout<<"\n1.Insert";
        std::cout<<"\n2.Display";
        std::cout<<"\n3.Search";
        std::cout<<"\nEnter choice : ";
        std::cin>>c;

        switch(c)
        {
            case 1:
                n.insert();
                break;
            case 2:
                n.display();
                break;
            case 3:
                n.search();
                break;
        }
    }
}
