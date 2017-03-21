

#include "stdafx.h"
#include <iostream>
#include <string>
#include "CList.h"
using namespace std;
class Automobile
{
	
	
	

public:
	
	
	//~Automobile();
	int RegNum;
	
	string DeveloperCompany;
	string Color;
	int DoorsCount;
	double Price;
	int YearOfIssue;

	Automobile() {
		

	};
private:
	
};

class AutomobileItem
{	
public:
	int Count;
	Automobile CurrentAuto;
	Automobile PrevAuto;
	Automobile NextAuto;

private:

};

class AutoList
{
public:
	int GetCount() {
		return Count;

	}
	void Add(Automobile AutomobileParam) {

		Count++;
		//creating temporary item
		AutomobileItem CurrentItem;
		CurrentItem.CurrentAuto = AutomobileParam;
		if (Count>1) {
			CurrentItem.PrevAuto = List[Count - 2].CurrentAuto;
			//adding this item as nextItem to neighbor

			List[Count - 2].NextAuto = List[Count - 1].CurrentAuto;
		};
		

		//adding temporary item to list
		List[Count-1] = CurrentItem;
		

		

	}
	void DisplayListToConsole() {
		//rows headers
		cout << "Developer company \t";
		cout << "Year Of Issue \t";
		cout << "Color \t";
		cout << "Price \t";
		cout << "Registration Number \t";
		cout << "Doors count \t\n";
		//rows with data
		for (int i = 0; i < Count;i++) {
			cout << List[i].CurrentAuto.DeveloperCompany <<"\t\t\t" ;
			cout << List[i].CurrentAuto.YearOfIssue << "\t\t";
			cout << List[i].CurrentAuto.Color << "\t";
			cout << List[i].CurrentAuto.Price << "\t";
			cout << List[i].CurrentAuto.RegNum << "\t\t\t";
			cout << List[i].CurrentAuto.DoorsCount << "\t";
			cout << "\n";
		}
	}
	void AddAsNext() {

	}
	void Remove() {
		for (int i = Pointer; i < Count - 2; i++) {
			List[i].CurrentAuto = List[i + 1].CurrentAuto;
			List[i].PrevAuto = List[i - 1].CurrentAuto;
			List[i].NextAuto = List[i + 2].CurrentAuto;

		}
		List[Count - 1].CurrentAuto = List[Count].CurrentAuto;
		List[Count - 1].PrevAuto = List[Count - 2].CurrentAuto;
		List[Count - 1].NextAuto = List[Count - 1].CurrentAuto;
		Count--;
	}
	void Remove(int index) {

		for (int i = index; i < Count-2; i++) {
			List[i].CurrentAuto = List[i + 1].CurrentAuto;
			List[i].PrevAuto = List[i - 1].CurrentAuto;
			List[i].NextAuto = List[i + 2].CurrentAuto;

		}
		List[Count - 1].CurrentAuto = List[Count].CurrentAuto;
		List[Count - 1].PrevAuto = List[Count-2].CurrentAuto;
		List[Count - 1].NextAuto = List[Count - 1].CurrentAuto;
		Count--;

	}

	Automobile Next() {
		if (Pointer<Count)
		{
			Pointer++;

			return List[Pointer].CurrentAuto;
		}
		else
		{
			return List[Pointer].CurrentAuto;
		}
	}
	Automobile Prev() {
		if (Pointer>0)
		{
			Pointer--;

			return List[Pointer].CurrentAuto;
		}
		else
		{
			return List[Pointer].CurrentAuto;
		}
	}


	AutoList()
	{
		Count = 0;
		Pointer = 0;
	}

	~AutoList()
	{
	}
private:
	int Count=0;
	int Pointer;
	AutomobileItem *List = new AutomobileItem[Count+1];
	
};


int main() {
	//Declare a list
	AutoList OurAlist = AutoList();
	//Declare a new automobile
	Automobile CurrentAuto;
	//Setting Properties
	CurrentAuto.Color = "Black";
	CurrentAuto.Price = 200;
	CurrentAuto.DeveloperCompany = "Honda";
	CurrentAuto.RegNum = 32132;
	CurrentAuto.DoorsCount=4;
	CurrentAuto.YearOfIssue = 2007;
	//adding auto to list
	OurAlist.Add(CurrentAuto);
	//display all autos in list
	OurAlist.DisplayListToConsole();

	getchar();
	return 0;

}
