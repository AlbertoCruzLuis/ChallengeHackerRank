//Autor: Alberto Cruz Luis
//Github: https://github.com/AlbertoCruzLuis
//Date: 29/12/2019
//Problema de HackerRank - Attending Workshops
/*A student signed up for  workshops and wants to attend the maximum number of workshops where no two workshops overlap. You must do the following:

Implement  structures:

struct Workshop having the following members:

The workshop's start time.
The workshop's duration.
The workshop's end time.
struct Available_Workshops having the following members:

An integer,  (the number of workshops the student signed up for).
An array of type Workshop array having size .
Implement  functions:

Available_Workshops* initialize (int start_time[], int duration[], int n) 
Creates an Available_Workshops object and initializes its elements using the elements in the  and parameters (both are of size ). Here,  and  are the respective start time and duration for the workshop. This function must return a pointer to an Available_Workshops object.

int CalculateMaxWorkshops(Available_Workshops* ptr) 
Returns the maximum number of workshops the student can attend—without overlap. The next workshop cannot be attended until the previous workshop ends.

Note: An array of unknown size () should be declared as follows:

DataType* arrayName = new DataType[n];
Input Format

Input from stdin is handled by the locked code in the editor; you simply need to write your functions to meet the specifications of the problem statement above.

Output Format

Output to stdout is handled for you.

Your initialize function must return a pointer to an Available_Workshops object. 
Your CalculateMaxWorkshops function must return maximum number of non-overlapping workshops the student can attend.

Sample Input

6
1 3 0 5 5 8
1 1 6 2 4 1
Sample Output

CalculateMaxWorkshops should return .

Explanation

The first line denotes , the number of workshops. 
The next line contains  space-separated integers where the  integer is the  workshop's start time. 
The next line contains  space-separated integers where the  integer is the  workshop's duration.

The student can attend the workshops  and  without overlap, so CalculateMaxWorkshops returns  to main (which then prints  to stdout).*/

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshops{
    int start_time;
    int duration;
    int end_time;
};

//Sobrecarga operador < | Uso en algoritmo(sort)
bool operator<(Workshops a, Workshops b){
    return a.end_time < b.end_time;
}

struct Available_Workshops{
    int n;
    Workshops* array_Workshops;
    Available_Workshops(int Tam)
    {
        n = Tam;
        array_Workshops = new Workshops[Tam];
    }
};

Available_Workshops* initialize(int start_time[], int duration[], int n){
    Available_Workshops* obj = new Available_Workshops(n);
    for(int i = 0; i < n; i++)
    {
        obj->array_Workshops[i].start_time = start_time[i];
        obj->array_Workshops[i].duration = duration[i];
        obj->array_Workshops[i].end_time = obj->array_Workshops[i].start_time 
        + obj->array_Workshops[i].duration;
    }
    return obj;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int Max_Workshops = 0;
    sort(ptr->array_Workshops, ptr->array_Workshops + ptr->n);
    int prev = 0;
    for(int i = 0; i < ptr->n; i++)
    {
        int cur = ptr->array_Workshops[i].start_time;
        if(cur >= prev)
        {
            Max_Workshops++;
            prev = ptr->array_Workshops[i].end_time;
        }
    }
    delete[] ptr;   //Liberar Memoria
    return Max_Workshops;
}

//-------Programa Principal--------

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
