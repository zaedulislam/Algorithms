#include <iostream>

using namespace std;
const int SIZE = 10;
int arr[SIZE];
int count = 0;

void print()
{
	cout << "Array: ";
	for(int i = 0; i < count; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void shift_left(int startindex)
{
	for(int i = startindex; i < count-1; i++)
	{
		arr[i] = arr[i+1];
	}
}

void shift_right(int startindex)
{
	for(int i = count; i > startindex; i--)
	{
		arr[i] = arr[i-1];
	}
}

void add(int value)
{
	if(count == SIZE)
	{
        cout << "Array Full!!" << endl;
	}
	else if(count == 0)
	{
		arr[count] = value;
        		count++;
	}
	else
         	{
        	for(int i = 0; i < count; i++)
        	{
            	if(value <= arr[i] )
            	{
                	              	shift_right(i);
                		arr[i] = value;
                		break;
            }
            else
            {
                arr[count] = value;
            }
        }
        count++;
    }
}

void remove(int value)
{
	if(count == 0)
	{
		cout << "Array Empty!!" << endl;
	}
	else
	{
		for(int i = 0; i < count; i++)
		{
			if(arr[i] == value)
			{
				shift_left(i);
				count--;
				break;
			}
		}
	}
}

int main()
{
    add(5);
	add(7);
	add(1);
	add(9);
	add(2);
	print();
	remove(7);
	print();
	remove(1);
	print();
	return 0;
}
