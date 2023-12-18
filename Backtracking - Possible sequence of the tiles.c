/* 
Problem: You have n tiles, where each tile has one letter tiles[i] printed on it.
    Return the possible non-empty sequences of letters 
    you can make using the letters printed on those tiles
Constraints: 
    1 <= tiles.length <= 7
    tiles consist of uppercase English letters 
Example:
    tiles: AAB
    number of possible non-empty sequences: 8
    hint: the possible sequence are "A", "B", AA", "AB", "BA", "AAB", "ABA", "BAA".

    tiles: AAABBC
    number of possible non-empty sequences: 188

    tiles: V
    number of possible non-empty sequences: 1
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TILES 7

int countSeq(char* tiles, bool used[], int len, int pos)
{
    if(pos > len) return 0;

    int cnt = 0;

    bool visited[26] = {false};

    for(int i = 0; i < len; ++i)
    {
        if(!used[i] && !visited[tiles[i] - 'A'])
        {
            // Mark the letter as used and visited
            used[i] = true;
            visited[tiles[i] - 'A'] = true;

            // Include this sequence and continue generating longer sequeces
            cnt += 1 + countSeq(tiles, used, len, pos + 1);

            used[i] = false; // Backtrack
        }
    }

    return cnt;
}

int main()
{
    char tiles[MAX_TILES + 1];
    bool used[MAX_TILES] = {false};

    printf("Enter the tiles: ");
    scanf("%7s", tiles);

    int len  = strlen(tiles);

    int ans = countSeq(tiles, used, len, 0);
    printf("Number of possible non-empty sequences: %d\n", ans);

    return 0;
}

