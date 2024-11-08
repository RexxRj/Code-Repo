// A class should have only single responsibility and reason to change

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string &title) : title(title) {}

    void add_entry(const string &entry)
    {
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + ": " + entry);
    }

    /*Having save function along with add_entry function here breaks single responsibility principle.
    Any modification to save have to be modified everywhere.
    So separating the responsibilty should be done.*/
    void save(const string &filename)
    {
        ofstream ofs(filename);
        for (auto &e : entries)
            ofs << e << endl;
    }
};

/*Having separate persistence manager will help in separation of saving functionality.(separation of concerns)
Any modification in saving functionality such as having to save in database instead of file,
can be modified here instead of changing the existing journal class.
*/
struct PersistenceManager
{

    static void save(const Journal &j, const string &filename)
    {
        ofstream ofs(filename);
        for (auto &e : j.entries)
            ofs << e << endl;
    }
};

int main()
{
    Journal journal{"Dear Diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");

    // journal.save("journal");
    // Instead use ->

    PersistenceManager pm;
    pm.save(journal, "journal");

    getchar();
    return 0;
}
