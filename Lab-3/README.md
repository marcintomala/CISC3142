## Lab 3 - Objective

Perform data analysis on a set of `.csv` files using object-oriented programming in C++. 

## Run Instructions

### Due to the inclusion of a submodule, the repository should be cloned using `git clone --recurse-submodules <repo link>`.

Assuming `g++` and `make` are present on our machine, all that is required to run the included code is to execute the command `make lab3` 
from the root directory of the repository. The `Makefile` is designed such that it will cd into and compile the code inside the `Lab-3` directory,
then run the program from there. The `Makefile` will also automatically clean up the `.o` and `.gch` files from the `src` folder.

## Problem Statement

### Requirements
The provided CSV files require summarization. Each of the data files contains rosters showing students’ enrollment in courses and grades. Each file contains records for one course number of all sections across multiple terms. These are the main data files to use for generating a report that shows for each instructor (for each course and term).

The data that should be added as a git submodule is at: https://gist.github.com/d279545d975c1652689e8195e2426adf.git Please link the submodule as a sub directory named data

· Data CSV files fields: StudentId, CourseNumber*, InstructorId, TermId, Section_Id, Grade

\* CourseNumber is either 1115, 3115, 3130. There are 3 CSV files, one corresponding to each course number.

Another file shows enrollment count from a separate source that can be used to verify that you have the correct counts of certain semester

## Solution

#### Synopsis:

The program will read the `.csv` files, building a `college` object which includes data structures which store the instances of the four datatypes: `student`, `section`, `instructor`, `term`. The aggregation functions in `aggfunc.cpp` will use this organization to perform appropriate analysis. Output functions in `read.cpp` will produce file report outputs with timestamps in `output` directory.

#### In detail:
- The `main()` function in `main.cpp` will first build a `college` object using the `read()` function in `io.cpp`.
  - The `read()` function first builds a `vector` of filenames in `data` folder with the correct (`.csv`) extension (`read()` also throws an exception if any of the files is incorrectly formatted - the specified 6 columns are required). 
  - The `read()` function iterates over that vector, reading each file and extracting information needed to instantiate each of the four structs and add their respective pointers to the `college` object's storage data structures.
  - Of note is the construction of a unique class id which is a concatenation of termid, course number, and section id. This triple allows to uniquely identify and store each class section in the storage without overwriting any data (e.g. when a student attempts a course multiple times, or when the section ids happen to be the same).
- Once the `college` object is built, aggregation functions aggregate its contents appropriately, building a `map<string, vector<double>>` for each type of aggregation. These data structures store a mapping of the respective id (depending on aggregation - by course number, instructor, or term) to a `vector` of 3 values: count of students who match the criterion (passing or withdrawing), count of all students who were considered, as well as their ratio. This organization allows the output functions to quickly output to files the requisite information.
- After these sorted `map`s are built, all that's left is to call the output functions which use the C file output (`fprintf()`) to nicely format the output in each file. Moreover, a timestamp is formulated using the `ctime` library, to appropriately label each file, as requested.


## Expected Output:

Using Python with Pandas, I did some quick analysis to ensure that the numbers produced by my C++ program are indeed correct. The code used along with its output is available in the below Google Collab notebook:

[Google Collab with Pandas analysis to verify the results](https://colab.research.google.com/drive/1lvZg55RNVdSvv3300y2QjlS2Q7zh7QoO?usp=sharing)
