

#include "regular_string_h.h"

int main(){

    printf("task1 <string.h>:\n");
    char file_link[] = "task1_string_h.txt";
    read_file_for_links(file_link);
    printf("task1 <string> OK\n");

    printf("task2 <string.h>:\n");
    char file_data[] = "task2_string_h.txt";
    read_file_date(file_data);
    printf("task2 <string> OK\n");

    printf("task3 <string.h>:\n");
    char file_number[] = "task3_string_h.txt";
    read_file_number(file_number);
    printf("task3 <string> OK\n");

    printf("task4 <string.h>:\n");
    char file_data_time[] = "task4_string_h.txt";
    read_file_date_time(file_data_time);
    printf("task4 <string> OK\n");


    /*char str[] = "l 5,2e+5 k 4.26 j OK";
    char  file[] = "number2.txt";
    char res[256];*/
    //check_links_in_line(str, 1);
    //write_file_about_links(str, 1);
    //read_file_for_links();
    //check_date_in_line(str, res);
    //read_file_date(file);
    //check_date_time_in_line(str, res);
    //printf("%s", res);
    //read_file_date_time(file);
    //check_number_in_line(str, res);
    //printf("%s", res);
    //read_file_number(file);
}