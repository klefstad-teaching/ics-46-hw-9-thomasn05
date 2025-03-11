#include <gtest/gtest.h>

#include "../src/dijkstras.h"
#include "../src/ladder.h"

TEST(EditDistanceTest, BasicCases) {
    EXPECT_TRUE(edit_distance_within("cat", "bat", 1));
    EXPECT_FALSE(edit_distance_within("cat", "dog", 1));
    EXPECT_TRUE(edit_distance_within("hello", "helo", 1));
    EXPECT_FALSE(edit_distance_within("hello", "world", 2));
}

TEST(IsAdjacentTest, BasicCases) {
    EXPECT_TRUE(is_adjacent("cat", "bat"));
    EXPECT_FALSE(is_adjacent("cat", "dog"));
    EXPECT_TRUE(is_adjacent("hello", "hella"));
    EXPECT_FALSE(is_adjacent("hello", "world"));
}

TEST(GenerateWordLadderTest, ValidLadders) {
    set<string> word_list = {"cat", "bat", "bit", "big", "dog"};
    vector<string> ladder = generate_word_ladder("cat", "dog", word_list);
    EXPECT_EQ(ladder.size(), 4);
    EXPECT_EQ(ladder.front(), "cat");
    EXPECT_EQ(ladder.back(), "dog");
}

TEST(GenerateWordLadderTest, NoLadderExists) {
    set<string> word_list = {"apple", "orange", "banana"};
    vector<string> ladder = generate_word_ladder("apple", "banana", word_list);
    EXPECT_TRUE(ladder.empty());
}


TEST(DijkstraTest, BasicGraph) {
    Graph G(5);
    G.addEdge(0, 1, 10);
    G.addEdge(0, 2, 3);
    G.addEdge(1, 2, 1);
    G.addEdge(1, 3, 2);
    G.addEdge(2, 1, 4);
    G.addEdge(2, 3, 8);
    G.addEdge(2, 4, 2);
    G.addEdge(3, 4, 7);
    G.addEdge(4, 3, 9);

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);

    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 7);
    EXPECT_EQ(distances[2], 3);
    EXPECT_EQ(distances[3], 9);
    EXPECT_EQ(distances[4], 5);
}

TEST(DijkstraTest, NoPathExists) {
    Graph G(4);
    G.addEdge(0, 1, 5);
    G.addEdge(1, 2, 10);

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);

    EXPECT_EQ(distances[3], INF);
}

TEST(ExtractShortestPathTest, ValidPath) {
    vector<int> previous = {-1, 0, 1, 2, 2};
    vector<int> path = extract_shortest_path({}, previous, 4);
    
    vector<int> expected_path = {4, 2, 1, 0};
    EXPECT_EQ(path, expected_path);
}

TEST(ExtractShortestPathTest, NoPath) {
    vector<int> previous = {-1, -1, -1, -1, -1};
    vector<int> path = extract_shortest_path({}, previous, 4);
    EXPECT_TRUE(path.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}