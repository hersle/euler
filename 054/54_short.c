#include <stdio.h>

#define STRAIGHT_FLUSH 8
#define FOUR_OF_A_KIND 7
#define FULL_HOUSE 6
#define FLUSH 5
#define STRAIGHT 4
#define THREE_OF_A_KIND 3
#define TWO_PAIRS 2
#define ONE_PAIR 1

void print_hand(int *ranks, int *suits)
{
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d:%d ", ranks[i], suits[i]);
    }
    printf("\n");
}

void read_hand(FILE *file, int *ranks, int *suits)
{
    int i;
    char rank;
    char suit;
    for (i = 0; i < 5; i++) {
        fscanf(file, "%c%c ", &rank, &suit);

        if (rank == 'T')
            ranks[i] = 10;
        else if (rank == 'J')
            ranks[i] = 11;
        else if (rank == 'Q')
            ranks[i] = 12;
        else if (rank == 'K')
            ranks[i] = 13;
        else if (rank == 'A')
            ranks[i] = 14;
        else
            ranks[i] = rank - '0';
        suits[i] = (int)suit;
    }
}

int min2(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int min5(int a, int b, int c, int d, int e)
{
    return min2(a, min2(b, min2(c, min2(d, e))));
}

int is_flush(int *suits)
{
    return suits[1] == suits[0] && suits[2] == suits[0] && 
           suits[3] == suits[0] && suits[4] == suits[0];
}

int is_straight(int *ranks)
{
    int lowest = min5(ranks[0], ranks[1], ranks[2], ranks[3], ranks[4]);

    int i;
    int target = lowest + 1;
    while (target <= lowest + 4) {
        for (i = 0; i < 5; i++) {
            if (ranks[i] == target)
                break;
        }
        if (i == 5)
            break;
        target++;
    }

    if (target == lowest + 5) {
        return lowest;  // return lowest rank in straight
    } else if (target == lowest + 4 && lowest == 2) {
        // 2-3-4-5 + an ace is also a legal flush
        int has_ace = ranks[0] == 14 || ranks[1] == 14 || ranks[2] == 14 ||
                      ranks[3] == 14 || ranks[4] == 14;
        if (has_ace)
            return 1;  // return lowest value in straight
    }
    return 0;
}

int high_card(int *p1_ranks, int *p2_ranks)
{
    int i;
    int *p1_highest = &p1_ranks[0];
    int *p2_highest = &p2_ranks[0];
    for (i = 1; i < 5; i++) {
        if (p1_ranks[i] > *p1_highest)
            p1_highest = &p1_ranks[i];
        if (p2_ranks[i] > *p2_highest)
            p2_highest = &p2_ranks[i];
    }

    if (*p1_highest > *p2_highest)
        return 1;
    else if (*p2_highest > *p1_highest)
        return 2;

    // Ranks equal. Return the player with the highest remaining card
    *p1_highest = 0;
    *p2_highest = 0;
    return high_card(p1_ranks, p2_ranks);
}

/*
 * Stores the most frequent rank and its frequency in the variables pointed to
 * by rank_max and freq_max. If multiple ranks are found equally frequent, the 
 * greatest rank is counted. The rank whose value equals exclude is not counted.
 */
void most_freq_rank(int *ranks, int exclude, int *rank_max, int *freq_max)
{
    *freq_max = 0;
    *rank_max = 0;

    int i, j;
    int freq;
    for (i = 0; i < 5; i++) {
        if (ranks[i] != exclude) {
            freq = 1;
            for (j = i + 1; j < 5; j++) {
                if (ranks[j] == ranks[i])
                    freq++;
            }
            if (freq > *freq_max || (freq == *freq_max && ranks[i] > *rank_max)) {
                *freq_max = freq;
                *rank_max = ranks[i];
            }
        }
    }
}

/*
 * Stores a maximum of three values, in descending importance, representing
 * the hands score in the array pointed to by score.
 */
void *hand_score(int *ranks, int *suits, int *score)
{
    print_hand(ranks, suits);

    int flush = is_flush(suits);
    int straight = is_straight(ranks);

    // Straight flush
    if (straight && flush) {
        score[0] = STRAIGHT_FLUSH;
        score[1] = straight;
        puts("straight flush");
        return;
    }

    // Find most frequent rank in hand and its frequency
    int freq1_rank;
    int freq1_freq;
    most_freq_rank(ranks, 0, &freq1_rank, &freq1_freq);

    // Four of a kind
    if (freq1_freq == 4) {
        score[0] = FOUR_OF_A_KIND;
        score[1] = freq1_rank;
        puts("four of a kind");
        return;
    }

    // Find second most frequent rank in hand and its frequency
    int freq2_rank;
    int freq2_freq;
    most_freq_rank(ranks, freq1_rank, &freq2_rank, &freq2_freq);

    int three_of_a_kind = freq1_freq == 3;

    // Full house
    if (three_of_a_kind && freq2_freq == 2) {
        score[0] = FULL_HOUSE;
        score[1] = freq1_rank;
        score[2] = freq2_rank;
        puts("full house");
        return;
    }

    // Flush
    if (flush) {
        score[0] = FLUSH;
        puts("flush");
        return;
    }

    // Straight
    if (straight) {
        score[0] = STRAIGHT;
        score[1] = straight;
        puts("straight");
        return;
    }

    // Three of a kind
    if (three_of_a_kind) {
        score[0] = THREE_OF_A_KIND;
        score[1] = freq1_rank;
        puts("three of a kind");
        return;
    }

    // One or two pairs
    int one_pair = freq1_freq == 2;
    if (one_pair) {
        score[1] = freq1_rank;
        int two_pairs = one_pair && freq2_freq == 2;
        if (two_pairs) {
            score[0] = TWO_PAIRS;
            score[2] = freq2_rank;
            puts("two pairs");
        } else {
            score[0] = ONE_PAIR;
            puts("one pair");
        }
        return;
    }

    // Hand can only attempt to win with high card
    puts("high card");
}

int determine_winner(int *p1_ranks, int *p1_suits, int *p2_ranks, int *p2_suits)
{
    int p1_score[3] = {0};
    int p2_score[3] = {0};

    hand_score(p1_ranks, p1_suits, p1_score);
    hand_score(p2_ranks, p2_suits, p2_score);

    printf("p1 score %d %d %d\n", p1_score[0], p1_score[1], p1_score[2]);
    printf("p2 score %d %d %d\n", p2_score[0], p2_score[1], p2_score[2]);

    int i;
    for (i = 0; i < 3; i++) {
        if (p1_score[i] > p2_score[i])
            return 1;
        else if (p2_score[i] > p1_score[i])
            return 2;
    }

    return high_card(p1_ranks, p2_ranks);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        puts("specify a poker hand file");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    int winner;
    int p1_wins = 0;
    int p1_ranks[5];
    int p1_suits[5];
    int p2_ranks[5];
    int p2_suits[5];

    int n = 1;
    while (!feof(file)) {
        read_hand(file, p1_ranks, p1_suits);
        read_hand(file, p2_ranks, p2_suits);

        printf("hand %d\n", n);

        winner = determine_winner(p1_ranks, p1_suits, p2_ranks, p2_suits);
        if (winner == 1)
            p1_wins++;

        printf("winner %d\n\n", winner);
        n++;
    }

    fclose(file);
    printf("player 1 won %d times\n", p1_wins);
    return 0;
}
