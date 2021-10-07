#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n=5,a,m=5;
    //1D vector

    {
        vector<int> x;   //declare empty vector

        x.push_back(5);//insert element in empty vector (at the end of vector)

        for(i=0;i<n;i++) {cin>>a; x.push_back(a);}   //insert an array into empty vector
    }




    {
        vector<int> x(n);   //declare vector of size=5;(with all values as 0)

        vector<int> x(n,a);   //declare vector of size=5;(with all values as a)

        vector<int> x {1,2,3};   //declare vector of size=3;(with values as 1,2,3)

        vector<int> x(arr,arr+n);   //Initializing vector from an array

        vector<int> x(vec.begin(),vec.end());    //Initializing vector from an array
        vector<int> x(vec);         //Initializing vector from an array

        x=vec;      //copy elements of vec to x

        x.swap(vec)  //swap elements

        for(i=0;i<n;i++) cin>>x[i];  //insert an array

        for(int/*(auto)*/ &i:x) cin>>i;      //insert an array

        for(i=0;i<n;i++) cout<<x[i]<<" "; //print an array//slower

        for(vector<int>::iterator i=x.begin();i!=x.end();i++) cout<<*i<<" ";  //print an array//faster

        for(auto i=x.rbegin();i!=x.rend();i++) cout<<*i<<" ";     //print reversed array

        for(int i:x) cout<<i<<" ";      //print an array

        cout<<x[2]; //no range check
        cout<<x.at(2);//throw range_error exception of out of range

    }





    //2D vector

    vector<vector<int>> x;      //empty vector

    vector<vector<int>> x(n);      //vector with n rows

    vector<vector<int>> x(n,vector<int>(m));    //vector with n rows and m coloumns(all values 0)

    vector<vector<int>> x(n,vector<int>(m,5));     //vector with n rows and m coloumns(all values a)

    //sort row

    for(i=0;i<x.size();i++)
        sort(x[i].begin(),x[i].end());

    //sort by 1st coloumn

    sort(x.begin(),x.end());

    //sort by any coloumn(2nd)

    sort(x.begin(),x.end(),compare);

    /*bool compare(vector<int> &a,vector<int> &b)
    {
      return a[2]>b[2];   //descending
      return a[2]<b[2];   //ascending
    }*/














}
