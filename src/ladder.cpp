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

vector<string> generate_word_ladder(const string &begin_word, const string &end_word, const set<string> &word_list)
{
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty())
    {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (const auto &word : word_list)
        {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end())
            {
                visited.insert(word);
                auto new_ladder = ladder;
                new_ladder.push_back(word);
                if (word == end_word)
                    return new_ladder;
                ladder_queue.push(new_ladder);
            }
        }
    }

    return {};
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