#include <iostream>
#include "queue.h"
#include <string>


class HwSales                      //class hardware sales
{
	private:                        //id, price, and amount variables
		int id, price, amount;       //name variable
		string name;
	public:
		HwSales(){price = amount = 0;}   //default const
		int returnPrice(){return price;}  //returns price
		int returnAmount(){return amount;}//returns amount
		int returnId(){return id;}        //returns id
      string returnName(){return name;} //returns name
		void sdm(int a, int b, int c, string d){id = a;price = b;amount = c;name = d;} //sets the data members
      friend ostream& operator << (ostream &, HwSales&);    //overloaded << op
};

ostream& operator << (ostream &stream, HwSales & ch)    //overloaded << op
{
	stream << "id:" <<ch.id<< " name:" <<ch.name << " price:" <<ch.price<< " amount:" <<ch.amount;
	return stream;
}



main()                   //main() func
{
	Queue <HwSales> hw;
	HwSales one, two;
	char choice;
	int prc, amnt, i;
	string nm;
	do
   {
		cout << "Choose:\n\tA:  Add Order\n\tC:  Cancel Order\n\tS:  Send item\n\tI:  Find order info\n\tQ:  Quit\nChoice: " ;
		cin >> choice;
      
		switch(choice)          //control
		{
			case 'A':            //add
         case 'a':
				cout << "Enter name, price, amount: ";
				cin >> nm >> prc >> amnt;

				srand(time(0));
				i = rand() % 1000;

				one.sdm(i, prc, amnt, nm);
				hw.insert(one);

				cout << nm <<" is added to the queue." << endl;
				break;
			case 'S':             //send
         case 's':
				if(!hw.isEmpty())
				{
					two = hw.deleteElement();
               cout << two.returnName() << " is delivered with " << two.returnPrice() * two.returnAmount() << endl;
				}
				else
					cout << "Empty queue" << endl;
				break;
			case 'C':             //cancel
      	case 'c':
			{
				if(!hw.isEmpty())
				{
            	Queue <HwSales> search;    //variables
               int item;
  					HwSales obj;

					cout << "Enter id: ";    //id taken
					cin >> item;

					while(!hw.isEmpty())      //if not empty
               {
						obj = hw.deleteElement();
                  if(obj.returnId() == item)
						{
							cout << "Name: " << obj.returnName() << " price: " <<obj.returnPrice() << " amount: " << obj.returnAmount() << "is removed." << endl;
						}
						else
							search.insert(obj);
               }
					while (!search.isEmpty())
               {
						obj = search.deleteElement();
						hw.insert(obj);
					}
				}
				else
					cout<<"Empty queue" << endl;
					break;
		}
		case 'I':         //find
      case 'i':
			if(!hw.isEmpty())        //if not empty
			{
				Queue <HwSales> other;
				HwSales v1;
				string v2;

				cout << "Enter name: ";
				cin >> v2;
                                     //if not empty
				while(!hw.isEmpty())
				{
					v1 = hw.deleteElement();
					if(v1.returnName() == v2)
					{
						cout<<" id: "<< v1.returnId() << " name: " <<v1.returnName() << " price: " << v1.returnPrice() << " amount: " << v1.returnAmount() << endl;
					}
					else
						cout<<"Wrong name" << endl;

					other.insert(v1);
				}
         	while (!other.isEmpty())    //if not empty
				{
					v1 = other.deleteElement();
					hw.insert(v1);
				}
			}
			else
				cout << "Empty queue" << endl;
			break;
		}
	}while((choice != 'Q') && (choice != 'q'));
	HwSales v3;

	cout << "Items left in queue: " << endl;

	while(!hw.isEmpty())
	{
		v3 = hw.deleteElement();
		cout << v3 << endl;
	}

   cout << "Bye.";

	int dmm;
   cin >> dmm;
}