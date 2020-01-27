
#ifndef _FILE_PARSER_
#define _FILE_PARSER_

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

#ifdef __NPAS_FILE_READING__

    struct Misdata
    {
        char
        *station,
        *aos,
        *los,
        **data;
        tm
        aostm,
        lostm;
        time_t aos_t, los_t;
        bool changed;
        int stanum;
        Misdata *next;
    };
    struct Misheader
    {
        char misname[20];
        int misnum;
        Misdata *data, *datahead;
        Misheader *next;
    };

#endif

class Parser
{

  public:



    Parser();
    Parser(char*);
    Parser(int, char, char*, char**);
    ~Parser();
    void dumpfile();
    void setDel(char );
    void setCommentDel(char);
    void setVarsPerLine(int* );
    bool setFileLocation(char* );
    void setPassedVar(char**);
    char **getline();
    char *getline_nodel();

    char *getdel();
    char **stripunalmemstr(char *, int *);
    char **stripmemstr(char *, int *);
    bool getfileopen();
    int getnumlines();
    int getnumdelcount();

    //rewind to top of file and clear any flags;
    void rewind_file();

    Misheader *readvis();
    Misheader *readsch();
    Misdata *Misdata_remove(Misheader *head, Misdata *delinput);
    void MisHeaderCleanup(Misheader *);
    bool debug ;

  private:
    //functions
    bool check_fileopen();

    //vars
    //bool debug;
    int numVars;
    bool fileOpen, commentflag;
    char delimiter;
    char commentDelimter;
    char *fileLocation;
    char **passedVar;
    std::ifstream file;
};

#endif
