//8.0.5

#include <iostream>
using namespace std;

class Word{
private:
    string prefix;
    string prefix2;
    string root;
    string suffix;
    string end;
public:
    void set_Prefix(string pref) { prefix = pref; }
    void set_Prefix2(string pref2) { prefix2 = pref2; }
    void set_Root(string root1) { root = root1; }
    void set_Suffix(string suffix1) { suffix = suffix1; }
    void set_End(string end1) { end = end1; }
    string get_Prefix(){return prefix;}
    string get_Prefix2(){return prefix2;}
    string get_Root(){return root;}
    string get_Suffix(){return suffix;}
    string get_End(){return end;}
    void print(){
        cout<<get_Prefix()<<get_Prefix2()<<get_Root()<<get_Suffix()<<get_End()<<endl;
    }
};

class Verb: public Word{
public:
    string verb_prefix;
    string verb_prefix2;
    string verb_root;
    string verb_suffix;
    string verb_end;
    void input(){
        cout<<"Input verb ";
        cout<<"Input prefix prefix2 root suffix end";
        cin>>verb_prefix>>verb_prefix2>>verb_root>>verb_suffix>>verb_end;
        set_Prefix(verb_prefix);
        set_Prefix2(verb_prefix2);
        set_Root(verb_root);
        set_Suffix(verb_suffix);
        set_End(verb_end);
    }
    void main_program(){
        string time;
        string osoba;
        cout<<"Input time:";
        cin>>time;
        if (time=="past_perfect"||time=="past_simple"){
            set_End("ed");
        }
        if (time=="present_continue"||time=="past_continue"){
            set_End("ing");
        }
        cout<<"Input osoba:";
        cin>>osoba;
        if (time=="present_simple"){
        if (osoba=="he"||osoba=="she"||osoba=="it"){
            set_End("es");
        }
        if (osoba=="we"||osoba=="you"||osoba=="they"){
            set_End(verb_end);
        } else{}
        }
        print();
    }
};

class Nouns: public Word{
public:
    string nouns_prefix;
    string nouns_prefix2;
    string nouns_root;
    string nouns_suffix;
    string nouns_end;

    void input(){
        cout<<"Input nouns";
        cout<<"Input prefix prefix2 root suffix end";
        cin>>nouns_prefix>>nouns_prefix2>>nouns_root>>nouns_suffix>>nouns_end;
        set_Prefix(nouns_prefix);
        set_Prefix2(nouns_prefix2);
        set_Root(nouns_root);
        set_Suffix(nouns_suffix);
        set_End(nouns_end);
    }
    void main_program(){
        string numeric;
        cout<<"Input numeric:";
        cin>>numeric;
        if (numeric=="one"){
            set_End("");
        }
        if (numeric=="many"){
            set_End("s");
        }
        print();
    }
};

class Adjective: public Word{
public:
    string adjective_prefix;
    string adjective_prefix2;
    string adjective_root;
    string adjective_suffix;
    string adjective_end;

    void input(){
        cout<<"Input adjective ";
        cout<<"Input prefix prefix2 root suffix end";
        cin>>adjective_prefix>>adjective_prefix2>>adjective_root>>adjective_suffix>>adjective_end;
        set_Prefix(adjective_prefix);
        set_Prefix2(adjective_prefix2);
        set_Root(adjective_root);
        set_Suffix(adjective_suffix);
        set_End(adjective_end);
    }
    void main_program(){
        string comparison;
        cout<<"Input comparison:";
        cin>>comparison;
        if (comparison=="big"){
            set_Suffix("er");
        }
        if (comparison=="biggest"){
            set_Prefix("the ");
            set_Suffix("er");
        }
        if (comparison=="the_biggest"){
            set_Prefix("the ");
            set_Prefix2("most ");
        }

        print();
    }
};



int main(){
    Verb v;
    v.input();
    v.main_program();
    Nouns n;
    n.input();
    n.main_program();
    Adjective a;
    a.input();
    a.main_program();
}