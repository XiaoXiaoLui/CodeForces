#include <vector>
#include <iostream>
#include <algorithm>

struct Vehicle
{
	int seqNum;
	unsigned int size;
	unsigned int capacity;
	
	bool selected;
	
	bool operator < (const Vehicle &other)
	{
		double capPerSize = ((double)capacity) / ((double)size);
		double capPerSizeOther = ((double)other.capacity) / ((double)other.size);
		
		/*
		if (capPerSize > capPerSizeOther)
		{
			return true;
		}
		else if (capPerSize == capPerSizeOther && size > other.size)
		{
			return true;
		}
		else 
		{
			return false;
		}*/
		return capPerSize > capPerSizeOther;
	}
};


using namespace std;

int main()
{
	unsigned int num = 0;
	unsigned int volumn = 0;
	unsigned int maxCapacity = 0;
	
	vector<Vehicle> lstVehicle;
	
	cin >> num >> volumn;
	
	Vehicle item;
	for (int i = 1; i <= num; i++)
	{
		cin >> item.size >> item.capacity;
		item.seqNum = i;
		item.selected = false;
		
		lstVehicle.push_back(item);
	}
	
	sort(lstVehicle.begin(), lstVehicle.end());
	
	vector<Vehicle>::iterator iter;
	unsigned int volumnRemain = volumn;
	
	/*
	cout << "test------" << endl;
	for (iter = lstVehicle.begin(); iter != lstVehicle.end(); ++iter)
	{
		cout << (*iter).seqNum << " " << (*iter).size << " " << (*iter).capacity << endl;
		
	}
	cout << "--------test" << endl;*/
	
	
	for (iter = lstVehicle.begin(); iter != lstVehicle.end() && volumnRemain > 0; ++iter)
	{
		if ((*iter).size <= volumnRemain)
		{
			volumnRemain -= (*iter).size;
			maxCapacity += (*iter).capacity;
			
			(*iter).selected = true;
		}
	}
	
	vector<Vehicle>::reverse_iterator rIter;
	
	// special case, maybe change the last 2 size1 to 1 size2
	if (volumnRemain == 0)
	{
		vector<Vehicle>::iterator last1;
		vector<Vehicle>::iterator secondLast1;
		vector<Vehicle>::iterator first2;
		
		bool bGetLast1 = false;
		
		for (rIter = lstVehicle.rbegin(); rIter != lstVehicle.rend(); ++rIter)
		{
			// find the first size 1
			if ((*rIter).selected && (*rIter).size == 1)
			{
				if (bGetLast1)
				{
					secondLast1 = rIter.base();
					break;
				}
				else
				{
					last1 = rIter.base();
					bGetLast1 = true;
				}
			} 
		}
		
		// has 2 selected size1
		if (rIter != lstVehicle.rend())
		{
			first2 = secondLast1;
			
			// try to find the first unselected size2
			for (; first2 != last1; first2++)
			{
				if (!(*first2).selected && (*first2).size == 2)
				{
					break;
				}
			}
			
			// need to change 2 size1 to 1 size2
			if (!(*first2).selected && ((*first2).capacity > (*last1).capacity + (*secondLast1).capacity))
			{
				(*last1).selected = false;
				(*secondLast1).selected = false;
				(*first2).selected = true;
				maxCapacity = maxCapacity - (*last1).capacity - (*secondLast1).capacity + (*first2).capacity;
			}
		}
	}
	
	
	
	
	// this is another special case, maybe need to change a size1 to size2
	if (volumnRemain == 1 && !lstVehicle.empty())
	{
		for (rIter = lstVehicle.rbegin(); rIter != lstVehicle.rend(); ++rIter)
		{
			// find the first size 1
			if ((*rIter).selected && (*rIter).size == 1)
			{
				break;
			}
		}
		
		if (rIter != lstVehicle.rend())
		{
			for (iter = rIter.base(); iter != lstVehicle.end(); ++iter)
			{
				// find the first unselected size 2
				if (!(*iter).selected && (*iter).size == 2)
				{
					break;
				}
			}
			
			// need to change
			if (iter != lstVehicle.end() && (*iter).capacity > (*rIter).capacity)
			{
				(*rIter).selected = false;
				(*iter).selected = true;
				
				maxCapacity = maxCapacity - (*rIter).capacity + (*iter).capacity;
			}
		}
	}
	
	cout << maxCapacity << endl;
	
	for (iter = lstVehicle.begin(); iter != lstVehicle.end(); ++iter)
	{
		if ((*iter).selected)
		{
			cout << (*iter).seqNum << " ";
		}
	}
	
	return 0;
}