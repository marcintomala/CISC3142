// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code!

/* Homework Objective: fix this program to match the requirements listed:
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.

All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

vector< vector<string> > read_data() {

  vector< vector<string> > data(5);

  // define variables
  string sku, brand, category, year, price;

  ifstream in_stream;
  in_stream.open("data.csv"); //opening the file.

  if (!in_stream.fail()) { //if the file is open

    string lines;
    getline(in_stream, lines); // skip the header line

    while (getline(in_stream, lines)) { //while the end of file is NOT reached

     // Fields: sku,brand,category,year,price
     stringstream line (lines);

     getline(line, sku, ',');
     data[0].push_back(sku);

     getline(line, brand, ',');
     data[1].push_back(brand);

     getline(line, category, ',');
     data[2].push_back(category);

     getline(line, year, ',');
     data[3].push_back(year);

     getline(line, price, '\n');
     data[4].push_back(price);

    }

    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;

   } else {
    cout << "Unable to open file";
   }

  return data;
}

map<string, float> compute_average(vector< vector<string> > data, int col) {
  map< string, int > count;
  map< string, float > price_total;
  map< string, float > price_average;

  for (int i = 0; i < data[col].size(); i++) {

    float t;
    t = atof(data[4][i].c_str());

    if (count.count(data[col][i])) {
      count[data[col][i]]++;
      price_total[data[col][i]] += t;
    } else {
      count[data[col][i]] = 1;
      price_total[data[col][i]] = t;
    }
  }

  for (map<string, int>::iterator iter = count.begin(); iter != count.end(); ++iter) {
    string k = iter -> first;
    price_average[k] = price_total[k] / count[k];
  }

  return price_average;
}



int main() {

  //output values
  cout << "SKU" << "\t" << "Brand" << "\t" << "Category" << "\t" << "Year" << "\t" << "Price\n";
  vector< vector<string> > data = read_data();

  for (int i = 0; i < data[0].size(); i++) {
    cout << data[0][i] << "\t" << data[1][i] << "\t" << data[2][i] << "\t" << data[3][i] << "\t" << data[4][i] + "\n"; 
  }

  map<string, float> brand_prices = compute_average(data, 1); // column 1 = brand

  cout << "\n" <<  "Brand" << "\t" << "Average Price" << "\n"; 
  for (map<string, float>::iterator iter = brand_prices.begin(); iter != brand_prices.end(); ++iter) {
    string k = iter -> first;
    float v = iter -> second;
    cout << k << "\t" << v << "\n";
  }

  map<string, float> category_prices = compute_average(data, 2); // column 2 = category

  cout << "\n" <<  "Category" << "\t" << "Average Price" << "\n"; 
  for (map<string, float>::iterator iter = category_prices.begin(); iter != category_prices.end(); ++iter) {
    string k = iter -> first;
    float v = iter -> second;
    cout << k << "\t" << v << "\n";
  }

  cout << endl;

}