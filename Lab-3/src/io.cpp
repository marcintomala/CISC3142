#include <iostream>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <unordered_set>
#include "college.h"

using namespace std;
namespace fs = experimental::filesystem;

vector<string> dir_filter () {
    // to filter out non-.csv files
    vector<string> csv_files;
    string extension = ".csv";
    for (const auto& file : fs::v1::directory_iterator("../data/")) {
        if (file.path().extension().string() == extension)
            csv_files.push_back(file.path());
    }
    return csv_files;
}


int read () {
    // reading all the .csv files in the /data directory
    ifstream in_stream;
    vector<string> files = dir_filter(); // paths to only the .csv files
    
    college c;

    for (string file : files) {
        in_stream.open(file);
        if (in_stream.good()) {
            
            string header;
            in_stream >> header;
            stringstream head (header);
            string column;
            int header_length = 0;
            while (getline(head, column, ',')) {
                header_length++;
            }

            if (header_length != 6) {
                throw runtime_error ("One or more of the .csv files is incorrectly formatted (missing columns).");
            }

            string lines; //where each page of the file will go to

            string emplid;
            string course_no;
            string ins_id;
            string term_id;
            string sect_code;
            string grade;

            while (in_stream >> lines) {
                stringstream line (lines);
                getline(line, emplid, ',');
                getline(line, course_no, ',');
                getline(line, ins_id, ',');
                getline(line, term_id, ',');
                getline(line, sect_code, ',');
                getline(line, grade);


                string class_id = term_id + '.' + course_no + '.' + sect_code;
                section* sect = c.get_section(class_id);

                if(!sect) {
                    sect = new section (class_id, sect_code, ins_id, term_id);
                    c.schedule_course(class_id, sect);
                }

                c.enroll_student(emplid, class_id, grade);
                c.assign_instructor(ins_id, class_id);
            }
        }
        in_stream.close();
    }

    for (const auto& s : c.get_students()) {
        cout << s.first << ": ";
        for (const auto& c : s.second->classes) {
            cout << c.first << ": " << c.second << "; "; 
        }
        cout << endl;
    }
    for (const auto& co : c.get_courses()) {
        cout << co.first << ": ";
        cout << co.second->course_num << ", " << co.second->instr_id << ", "
             << co.second->section_code << ", " << co.second->term << endl;
    }

    for (const auto& i : c.get_instructors()) {
        cout << i.first << ": ";
        for (const auto& c : i.second->classes) {
            cout << c << " "; 
        }
        cout << endl;
    }

    return 0;
}