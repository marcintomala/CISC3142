#include <iostream>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <unordered_set>
#include "college.h"

using namespace std;
namespace fs = experimental::filesystem::v1;

vector<string> dir_filter () {
    // to filter out non-.csv files
    vector<string> csv_files;
    string extension = ".csv";
    for (const auto& file : fs::directory_iterator("../data/")) {
        if (file.path().extension().string() == extension)
            csv_files.push_back(file.path());
    }
    return csv_files;
}


college read () {
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
                //each line's delimited contents are streamed to appropriate var
                stringstream line (lines);
                getline(line, emplid, ',');
                getline(line, course_no, ',');
                getline(line, ins_id, ',');
                getline(line, term_id, ',');
                getline(line, sect_code, ',');
                getline(line, grade);

                //each course section instance is labeled with a unique code
                //(concatenation of course_no, term_id, and section code)
                string class_id = term_id + '.' + course_no + '.' + sect_code;
                //we attempt to retrieve the section from the college
                section* sect = c.get_section(class_id);
                //if section is not already in college, we register it now:
                if(!sect) {
                    sect = new section (class_id, sect_code, ins_id, term_id);
                    c.schedule_course(class_id, sect);
                }

                //student from the current line gets added to the section
                sect->add_student(emplid);
                //student and instructor from current line are added to the college
                c.enroll_student(emplid, class_id, grade);
                c.assign_instructor(ins_id, class_id);
            }
        }
        in_stream.close();
    }

    return c;
}