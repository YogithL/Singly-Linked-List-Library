#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"
#include "slist.cpp"
using namespace std;

void simpleSortTotal(LinkedList &list, Airport* referenceAirport, int length);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    LinkedList list;			// Replace array with Linked List
    
    int airportCount=0;
    
    infile.open ("USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int c=0;
        while (infile.good())
        {
            Airport *t = new Airport();
            infile.getline(t->code, 256, ',');
            infile.getline(cNum, 256, ',');
            t->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            t->latitude = atof(cNum);
            
            list.add(t);
            i++ ;
            c++;
        }
        
        airportCount = c-1;
        infile.close();
         
         Airport* austin= new Airport();
        
         for(int i=0; i<airportCount; i++)
         {
          if(list.get(i)->data.code=="AUS")
          {
              *austin= list.get(i)->data;
          }
         }

        //  for (int c=0; c < airportCount; c++)
        //     if (!(c % 1000))
        //     {
        //         cout << list.get(c)->data.code << " long: " << list.get(c)->data.longitude << " lat: " << list.get(c)->data.latitude <<  endl;
        //         cout << list.get(c+1)->data.code << " long: " << list.get(c+1)->data.longitude << " lat: " << list.get(c)->data.latitude <<  endl;
        //         cout <<"Distance between " << list.get(c)->data.code << " and " << list.get(c+1)->data.code << " is "
        //           << distanceEarth( list.get(c)->data.longitude, list.get(c)->data.latitude , list.get(c+1)->data.longitude, list.get(c+1)->data.latitude) << endl;
        //     }
         
         simpleSortTotal(list, austin, airportCount);
        
         cout<<"Farthest Airport From Austin!" << endl;
         cout<< list.get(airportCount-2)->data.code << ": " << distanceEarth(austin-> latitude, austin-> longitude, list.get(airportCount-1)->data.latitude, list.get(airportCount-1)->data.longitude) << endl;
         
         cout<<"\nAirports 100 miles within Austin!" << endl;
         for(int i=1; i<airportCount; i++)
         {
            double distance=distanceEarth(austin-> latitude, austin-> longitude, list.get(i)->data.latitude, list.get(i)->data.longitude);
            
            if(distance <= 160.934)
            {
               cout<< list.get(i)->data.code << ": " << distanceEarth(austin-> latitude, austin-> longitude, list.get(i)->data.latitude, list.get(i)->data.longitude) << endl;
            } 
         }
    }
    else
    {
        cout << "Error opening file";
    } 
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

void simpleSortTotal(LinkedList &list, Airport* referenceAirport, int length)
{
  Airport temp;
  cout<< length<< endl;  
  
  for(int i=0; i<length-1; i++)
  {
    for(int j=0; j<length; j++)
    {
      
      node*nodeI= list.get(i);
      node*nodeJ= list.get(j);
      
      double distanceI= distanceEarth(referenceAirport-> latitude, referenceAirport-> longitude, nodeI->data.latitude, nodeI->data.longitude);
      double distanceJ= distanceEarth(referenceAirport-> latitude, referenceAirport-> longitude, nodeJ->data.latitude, nodeJ->data.longitude);

      if(distanceI > distanceJ)
      {
        temp= nodeI->data;
        nodeI->data= nodeJ->data;
        nodeJ->data= temp;
      }
    }
  }
}