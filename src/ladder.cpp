#include "ladder.h"

bool edit_distance_within(const std::string &str1, const std::string &str2, int d)
{
    int size1 = str1.size(), size2 = str2.size();

    if (abs(size1 - size2) > d)
        return false;

    int count = 0, i = 0, j = 0;

    while (i < size1 && j < size2)
    {
        if (str1[i] != str2[j])
        {
            if (++count > d)
                return false;

            if (size1 > size2)
                ++i;
            else if (size1 < size2)
                ++j;
            else
            {
                ++i;
                ++j;
            }
        }
        else
        {
            ++i;
            ++j;
        }
    }

    if (i < size1 || j < size2)
        ++count;

    return count <= d;
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
    {
        word_list.insert(s);
    }
    in.close();
}

void print_word_ladder(const vector<string> &ladder)
{
    for (size_t i = 0; i < ladder.size(); i++)
        cout << ladder[i];
    cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}
