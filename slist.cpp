#include "slist.h"
#include <string>

// Constructor
LinkedList::LinkedList()
{
    head=nullptr;
}

// Destructor
LinkedList:: ~LinkedList()
{
    node*current=head;
    node*previous;

    while(current != nullptr)
    {
        previous=current;
        current=current -> link;
        delete previous;
    }
}

// add(value)				//Adds a new value to the end of this list.
void LinkedList::add(Airport* x)
{
    node* insertion= new node();
    insertion->data= *x;
    insertion -> link= nullptr;

    if(head==nullptr)
    {
        head=insertion;
    }
    else
    {
        node* current= head;
        node* previous= nullptr;

        while(current!=nullptr)
        {
            previous=current;
            current=current->link;
        }

        previous->link=insertion;
    }
}

// clear()					//Removes all elements from this list.
void LinkedList::clear()
{
    node*current=head;
    node*previous= nullptr;

    while(current->link != nullptr)
    {
        previous=current;
        current=current -> link;
        delete previous;
    }

    head=nullptr;
}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool LinkedList::equals(LinkedList& x)
{
    node*current=head;
    node*currentX=x.head;

    while(current!=nullptr && currentX!=nullptr)
    {
        std::string code= current->data.code;
        std::string codeX= currentX->data.code;
        double longitude= current->data.longitude;
        double longitudeX= currentX->data.longitude;
        double latitude= current->data.latitude;
        double latitudeX= currentX->data.latitude;

        if(code!=codeX || longitude!=longitudeX || latitude!=latitudeX)
        {
            return false;
        }

        current=current->link;
        currentX=currentX->link;
    }
    
    return current==nullptr && currentX==nullptr;
}

//get(index)				//Returns the element at the specified index in this list.
node* LinkedList:: get(int index)
{
    int count=0;
    node*current=head;
 
    while(current!=nullptr)
    {
        if(count==index)
        {
            return current; 
        }
        
        if(current->link==nullptr)
        return nullptr;

        current=current->link;
        
        count++;
    }

    return nullptr;    
}

//insert(index, value)		//Inserts the element into this list before the specified index.
void LinkedList::insert(int index, Airport x)
{
    node* insertion= new node();
    insertion->data= x;
    insertion->link= 0;

    if(index==0)
    {
        insertion->link=head;
        head=insertion;
    }
    else
    {
    node*current=head;
    node*previous=nullptr;
    int count=0;

    while(current!=nullptr && count<index)
    {
        previous=current;
        current=current->link;
        count++;
    }

    previous->link=insertion;
    insertion->link=current;
    }
}


//exchg(index1, index2)		//Switches the payload data of specified indexex.
void LinkedList::exchg(int index1, int index2)
{
    node*current= head;
    node*one= nullptr;
    node*two= nullptr;
    int count=0;

    while(current!= nullptr)
    {
        if(index1==count)
        {
            one=current;
        }
        if(index2==count)
        {
            two=current;
        }

        current= current->link;
        count++;
    }

    Airport temp= one->data;
    one->data = two->data;
    two->data= temp; 
}

//swap(index1,index2)		//Swaps node located at index1 with node at index2
void LinkedList::swap(int index1, int index2)
{
    node*current= head;
    node*one= nullptr;
    node*two= nullptr;
    
    node*previous=nullptr;
    node*previousOne= nullptr;
    node*previousTwo= nullptr;

    int count=0;

    while(current!= nullptr)
    {
        if(index1==count)
        {
            one= current;
            previousOne= previous;
        }
        if(index2==count)
        {
            two=current;
            previousTwo= previous;
        }    

        previous= current;
        current= current->link;
        count++;
    }

    node*temp= one->link;
    one->link= two->link;
    two->link= temp;

    if(previousOne != nullptr)
    {
        previousOne->link=two;
    }
    else
    {
        head=two;
    }
    
    if(previousTwo != nullptr)
    {
        previousTwo->link=one;
    }
    else
    {
        head=one;
    }
}

// isEmpty()				//Returns true if this list contains no elements.
bool LinkedList::isEmpty()
{
    return head == nullptr;
}

// remove(index)			//Removes the element at the specified index from this list.
void LinkedList::remove(int index)
{
    node*current= head;
    node*previous= nullptr;
    int count=0;

    if(index==0)
    {
        head=head->link;
        delete current;
        return;
    }

    while(current!=nullptr)
    {
        if(count==index)
        {
            previous->link= current->link;
            delete current;
            break;
        }   

        count++;
        previous= current;
        current= current->link;
    }
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void LinkedList::set(int index, Airport value)
{
    node*current= head;
    int count=0;

    while(current!=nullptr)
    {
        if(count==index)
        {
            current->data= value;
        }   

        count++;
        current= current->link;
    }
}

// size()					//Returns the number of elements in this list.
int LinkedList::size()
{
    node*current= head;
    int count=0;

    while(current!=nullptr)
    {
        count++;
        current=current->link;
    }

    return count;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
LinkedList LinkedList::subList( int start, int length)
{
    node*current= head;
    int count=0;
    LinkedList x;

    while(current!=nullptr && count< start)
    {    
        count++;
        current= current->link;
    }

    while(current!=nullptr && count< (start + length))
    {
        Airport* copy = new Airport(current->data);
        x.add(copy);
        count++;
        current= current->link;
    }

    return x;

}

// toString()				//Converts the list to a printable string representation.
std:: string LinkedList:: toString()
{
    node*current=head;
    std:: string str="";
    while(current!=nullptr)
    {
        std::string code= current->data.code;
        double longitude= current->data.longitude;
        double latitude= current->data.latitude;
        
        str+= "Code: " + code + "Longitude: " + std::to_string(longitude) + "Latitude: " + std::to_string(latitude) + "\n";
        
        current=current->link;
    }

    return str;
}