#include "ladder.h"

bool edit_distance_within(const std::string &str1, const std::string &str2, int d)
{
    int size1 = str1.size();
    int size2 = str2.size();
    int diff = abs(size1 - size2);

    if (diff > d)
        return false;

    int min_size = min(size1, size2);
    int count = 0;
    for (int i = 0; i < min_size; i++)
    {
        if (str1[i] != str2[i])
            ++count;
    }

    return count + diff <= d;
}

bool is_adjacent(const string &word1, const string &word2)
{
    return edit_distance_within(word1, word2, 1);
}

void load_words(set<string> &word_list, const string &file_name)
{
    ifstream in(file_name);
    for (string s; in >> s;)
        word_list.insert(s);
    in.close();
}

void print_word_ladder(const vector<string> &ladder)
{
    for (const string &s : ladder)
        cout << s << "->";
    cout << endl;
}