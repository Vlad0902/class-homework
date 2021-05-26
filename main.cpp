

#include "regular_string.h"
#include "regular_regex.h"


int main() {

    cout<<"task1 <string>:"<<endl;
    string file_link = "task1_string.txt";
    read_file_for_links(file_link);
    cout<<"task1 <string> OK"<<endl;

    cout<<"task2 <string>"<<endl;
    string file_data = "task2_string.txt";
    read_file_date(file_data);
    cout<<"result in task2_string.txt"<<endl;
    cout<<"task2 <string> OK"<<endl;

    cout<<"task3 <string>"<<endl;
    string file_number = "task3_string.txt";
    read_file_number(file_number);
    cout<<"result in task3_string.txt"<<endl;
    cout<<"task3 <string> OK"<<endl;

    cout<<"task4 <string>"<<endl;
    string file_data_time = "task4_string.txt";
    read_file_data_time(file_data_time);
    cout<<"result in task4_string.txt"<<endl;
    cout<<"task4 <string> OK\n"<<endl;


    cout<<"task1 <regex>:"<<endl;
    string file_link_r = "task1_regex.txt";
    read_file_for_links_regex(file_link_r);
    cout<<"task1 <regex> OK"<<endl;

    cout<<"task2 <regex>"<<endl;
    string file_data_r = "task2_regex.txt";
    read_file_date_regex(file_data_r);
    cout<<"result in task2_regex.txt"<<endl;
    cout<<"task2 <regex> OK"<<endl;

    cout<<"task3 <regex>"<<endl;
    string file_number_r = "task3_regex.txt";
    read_file_number_regex(file_number_r);
    cout<<"result in task3_regex.txt"<<endl;
    cout<<"task3 <regex> OK"<<endl;

    cout<<"task4 <regex>"<<endl;
    string file_data_time_r = "task4_regex.txt";
    read_file_data_time_regex(file_data_time_r);
    cout<<"result in task4_regex.txt"<<endl;
    cout<<"task4 <regex> OK"<<endl;
}
