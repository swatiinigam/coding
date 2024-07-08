class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize a list of players
        vector<int> players;
        for (int i = 1; i <= n; ++i) {
            players.push_back(i);
        }

        int index = 0; // Start from the first player
        
        // Continue until one player remains
        while (players.size() > 1) {
            // Find the index of the player to be removed
            index = (index + k - 1) % players.size();
            // Remove the player
            players.erase(players.begin() + index);
        }

        // The last remaining player is the winner
        return players[0];
    }
};
