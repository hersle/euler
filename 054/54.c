#include <stdio.h>

const char *HIGH_CARD_STR = "high card";
const char *ONE_PAIR_STR = "one pair";
const char *TWO_PAIRS_STR = "two pairs";
const char *THREE_OF_A_KIND_STR = "three of a kind";
const char *STRAIGHT_STR = "straight";
const char *FLUSH_STR = "flush";
const char *FULL_HOUSE_STR = "full house";
const char *FOUR_OF_A_KIND_STR = "four of a kind";
const char *STRAIGHT_FLUSH_STR = "straight flush";

void print_hand(int *ranks, int *suits)
{
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d:%d ", ranks[i], suits[i]);
    }
    printf("\n");
}

void print_hands(int *p1_ranks, int *p1_suits, int *p2_ranks, int *p2_suits)
{
    print_hand(p1_ranks, p1_suits);
    print_hand(p2_ranks, p2_suits);
}

int get_card_rank(char rank)
{
    if (rank == 'T')  // ten
        return 10;
    if (rank == 'J')  // jack
        return 11;
    if (rank == 'Q')  // queen
        return 12;
    if (rank == 'K')  // king
        return 13;
    if (rank == 'A')  // ace
        return 14;
    return rank - '0';  // return numeric value
}

int get_card_suit(char suit)
{
    if (suit == 'S')  // spades
        return 1;
    if (suit == 'D')  // diamonds
        return 2;
    if (suit == 'C')  // clubs
        return 3;
    return 4;  // hearts
}

// Functions return 1 if player 1 wins
// Functions return 2 if player 2 wins
// Functions return 0 if noone wins

int high_card(int *p1_ranks, int *p2_ranks)
{
    int i;
    int j;
    int *p1_highest;
    int *p2_highest;
    for (i = 0; i < 4; i++) {
        p1_highest = p1_ranks;
        p2_highest = p2_ranks;
        for (j = 1; j < 5; j++) {
            if (p1_ranks[j] > *p1_highest)
                p1_highest = &p1_ranks[j];
            if (p2_ranks[j] > *p2_highest)
                p2_highest = &p2_ranks[j];
        }

        if (*p1_highest > *p2_highest)
            return 1;
        if (*p2_highest > *p1_highest)
            return 2;

        // Do not compare these cards again
        *p1_highest = 0;
        *p2_highest = 0;
    }

    return 0;
}

int one_pair(int *p1_ranks, int *p2_ranks)
{
    int i;
    int j;
    int p1_rank = 0;
    int p2_rank = 0;

    // Find player 1 pair
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (p1_ranks[i] == p1_ranks[j])
                p1_rank = p1_ranks[i];
        }
    }

    // Find player 2 pair
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (p2_ranks[i] == p2_ranks[j])
                p2_rank = p2_ranks[i];
        }
    }

    if (p1_rank > p2_rank)
        return 1;
    if (p2_rank > p1_rank)
        return 2;
    return 0;
}

int two_pairs(int *p1_ranks, int *p2_ranks)
{
    int i;
    int j;
    int p1_rank1 = 0;
    int p1_rank2 = 0;
    int p2_rank1 = 0;
    int p2_rank2 = 0;

    // Player 1
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (p1_ranks[i] == p1_ranks[j])
                if (p1_rank1 == 0)
                    p1_rank1 = p1_ranks[i];
                else
                    p1_rank2 = p1_ranks[i];
        }
    }

    // Player 2
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (p2_ranks[i] == p2_ranks[j])
                if (p2_rank1 == 0)
                    p2_rank1 = p2_ranks[i];
                else
                    p2_rank2 = p2_ranks[i];
        }
    }

    if (p1_rank1 * p1_rank2 != 0 && p2_rank1 * p2_rank2 == 0)
        return 1;  // player 1 has two pairs, player 2 does not
    if (p2_rank1 * p2_rank2 != 0 && p1_rank1 * p1_rank2 == 0)
        return 2;  // player 2 has two pairs, player 1 does not
    if (p1_rank1 * p1_rank2 == 0 && p2_rank1 * p2_rank2 == 0)
        return 0;  // neither player has two pairs

    int p1_rank_max = p1_rank1 > p1_rank2 ? p1_rank1 : p1_rank2;
    int p1_rank_min = p1_rank1 < p1_rank2 ? p1_rank1 : p1_rank2;
    int p2_rank_max = p2_rank1 > p2_rank2 ? p2_rank1 : p2_rank2;
    int p2_rank_min = p2_rank1 < p2_rank2 ? p2_rank1 : p2_rank2;

    if (p1_rank_max > p2_rank_max)
        return 1;
    if (p2_rank_max > p1_rank_max)
        return 2; 
    if (p1_rank_min > p2_rank_min)
        return 1;
    if (p2_rank_min > p1_rank_min)
        return 2;
    return 0;
}

int three_of_a_kind(int *p1_ranks, int *p2_ranks)
{
    int p1_rank = 0;
    int p2_rank = 0;

    int i;
    int j;
    int count;

    // One of the first three cards has to occur three times

    // Player 1
    for (i = 0; i < 3; i++) {
        count = 0;
        for (j = 0; j < 5; j++) {
            if (p1_ranks[j] == p1_ranks[i])
                count++;
        }
        
        if (count == 3) {
            p1_rank = p1_ranks[i];
            break;
        }
    }

    // Player 2
    for (i = 0; i < 3; i++) {
        count = 0;
        for (j = 0; j < 5; j++) {
            if (p2_ranks[j] == p2_ranks[i])
                count++;
        }
        
        if (count == 3) {
            p2_rank = p2_ranks[i];
            break;
        }
    }

    if (p1_rank > p2_rank)
        return 1;
    if (p2_rank > p1_rank)
        return 2;
    return 0;
}

int straight(int *p1_ranks, int *p2_ranks)
{
    int i;

    // Find smallest rank and check if ace is present
    int p1_min = p1_ranks[0];
    int p1_has_ace = 0;
    for (i = 1; i < 5; i++) {
        if (p1_ranks[i] < p1_min)
            p1_min = p1_ranks[i];
        if (p1_has_ace == 0 && p1_ranks[i] == 14)
            p1_has_ace = 1;
    }

    int rank = p1_min + 1;
    while (rank <= p1_min + 4) {
        for (i = 0; i < 5 && p1_ranks[i] != rank; i++);
        if (i == 5)
            break;
        rank++;
    }

    int p1_straight = rank == p1_min + 5 || 
                             (rank == p1_min + 4 && p1_min == 2 && p1_has_ace);

    // Find smallest rank and check if ace is present
    int p2_min = p2_ranks[0];
    int p2_has_ace = 0;
    for (i = 1; i < 5; i++) {
        if (p2_ranks[i] < p2_min)
            p2_min = p2_ranks[i];
        if (p2_has_ace == 0 && p2_ranks[i] == 14)
            p2_has_ace = 1;
    }

    rank = p2_min + 1;
    while (rank <= p2_min + 4) {
        for (i = 0; i < 5 && p2_ranks[i] != rank; i++);
        if (i == 5)
            break;
        rank++;
    }

    int p2_straight = rank == p2_min + 5 || 
                             (rank == p2_min + 4 && p2_min == 2 && p2_has_ace);

    if (p1_straight && !p2_straight)
        return 1;
    if (p2_straight && !p1_straight)
        return 2;
    if (!p1_straight && !p2_straight)
        return 0;
    return high_card(p1_ranks, p2_ranks);
}

int flush(int *p1_ranks, int *p1_suits, int *p2_ranks, int *p2_suits)
{
    int i;

    // Player 1 flush
    for (i = 1; i < 5 && p1_suits[i] == p1_suits[0]; i++);
    int p1_flush = i == 5;

    // Player 2 flush
    for (i = 1; i < 5 && p2_suits[i] == p2_suits[0]; i++);
    int p2_flush = i == 5;

    if (!p1_flush && !p2_flush)
        return 0;
    if (p1_flush && !p2_flush)
        return 1;
    if (p2_flush && !p1_flush)
        return 2;
    return high_card(p1_ranks, p2_ranks);
}

int full_house(int *p1_ranks, int *p2_ranks)
{
    // Check if the player has only two different ranks in his hand
    int i;
    int rank1 = p1_ranks[0];
    int rank2 = 0;
    int rank1_count = 1;
    int rank2_count = 0;
    for (i = 1; i < 5; i++) {
        if (p1_ranks[i] == rank1) {
            rank1_count++;
        } else if (p1_ranks[i] == rank2) {
            rank2_count++;
        } else {
            if (rank2 == 0) {
                rank2 = p1_ranks[i];
                rank2_count = 1;
            } else {
                break;
            }
        }
    }

    int p1_house = i == 5 && rank1_count + rank2_count == 5;
    int p1_rank_primary = rank1_count == 3 ? rank1 : rank2;
    int p1_rank_secondary = rank1_count == 2 ? rank1 : rank2;

    // Check if the player has only two different ranks in his hand
    rank1 = p2_ranks[0];
    rank2 = 0;
    rank1_count = 1;
    rank2_count = 0;
    for (i = 1; i < 5; i++) {
        if (p2_ranks[i] == rank1) {
            rank1_count++;
        } else if (p2_ranks[i] == rank2) {
            rank2_count++;
        } else {
            if (rank2 == 0) {
                rank2 = p2_ranks[i];
                rank2_count = 1;
            } else {
                break;
            }
        }
    }

    int p2_house = i == 5 && rank1_count + rank2_count == 5;
    int p2_rank_primary = rank1_count == 3 ? rank1 : rank2;
    int p2_rank_secondary = rank1_count == 2 ? rank1 : rank2;

    if (p1_house && !p2_house)
        return 1;
    if (p2_house && !p1_house)
        return 2;
    if (!p1_house && !p2_house)
        return 0;
    if (p1_rank_primary > p2_rank_primary)
        return 1;
    if (p2_rank_primary > p1_rank_primary)
        return 2;
    if (p1_rank_secondary > p2_rank_secondary)
        return 1;
    if (p2_rank_secondary > p1_rank_secondary)
        return 2;
    return 0;
}

int four_of_a_kind(int *p1_ranks, int *p2_ranks)
{
    int p1_rank = 0;
    int p2_rank = 0;

    int i;
    int j;
    int count;

    // One of the first two cards has to occur four times

    // Player 1
    for (i = 0; i < 2; i++) {
        count = 0;
        for (j = 0; j < 5; j++) {
            if (p1_ranks[j] == p1_ranks[i])
                count++;
        }
        
        if (count == 4) {
            p1_rank = p1_ranks[i];
            break;
        }
    }

    // Player 2
    for (i = 0; i < 2; i++) {
        count = 0;
        for (j = 0; j < 5; j++) {
            if (p2_ranks[j] == p2_ranks[i])
                count++;
        }
        
        if (count == 4) {
            p2_rank = p2_ranks[i];
            break;
        }
    }

    if (p1_rank > p2_rank)
        return 1;
    if (p2_rank > p1_rank)
        return 2;
    return 0;
}

int straight_flush(int *p1_ranks, int *p1_suits, int *p2_ranks, int *p2_suits)
{
    int i;

    // Find smallest rank and check if ace is present
    int p1_min = p1_ranks[0];
    int p1_has_ace = 0;
    for (i = 1; i < 5; i++) {
        if (p1_ranks[i] < p1_min)
            p1_min = p1_ranks[i];
        if (p1_has_ace == 0 && p1_ranks[i] == 14)
            p1_has_ace = 1;
    }

    int rank = p1_min + 1;
    while (rank <= p1_min + 4) {
        for (i = 0; i < 5 && p1_ranks[i] != rank; i++);
        if (i == 5)
            break;
        rank++;
    }

    int p1_straight = rank == p1_min + 5 || 
                             (rank == p1_min + 4 && p1_min == 2 && p1_has_ace);

    // Find smallest rank and check if ace is present
    int p2_min = p2_ranks[0];
    int p2_has_ace = 0;
    for (i = 1; i < 5; i++) {
        if (p2_ranks[i] < p2_min)
            p2_min = p2_ranks[i];
        if (p2_has_ace == 0 && p2_ranks[i] == 14)
            p2_has_ace = 1;
    }

    rank = p2_min + 1;
    while (rank <= p2_min + 4) {
        for (i = 0; i < 5 && p2_ranks[i] != rank; i++);
        if (i == 5)
            break;
        rank++;
    }

    int p2_straight = rank == p2_min + 5 || 
                             (rank == p2_min + 4 && p2_min == 2 && p2_has_ace);

    if (!p1_straight && !p2_straight)
        return 0;

    // Player 1 flush
    for (i = 1; i < 5 && p1_suits[i] == p1_suits[0]; i++);
    int p1_flush = i == 5;

    // Player 2 flush
    for (i = 1; i < 5 && p2_suits[i] == p2_suits[0]; i++);
    int p2_flush = i == 5;

    int p1_straight_flush = p1_straight && p1_flush;
    int p2_straight_flush = p2_straight && p2_flush;


    if (!p1_straight_flush && !p2_straight_flush)
        return 0;
    if (p1_straight_flush && !p2_straight_flush)
        return 1;
    if (p2_straight_flush && !p1_straight_flush)
        return 2;
    return high_card(p1_ranks, p2_ranks);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        puts("specify a file containing poker hands");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    int p1_wins = 0;
    int p1_ranks[5];
    int p1_suits[5];
    int p2_ranks[5];
    int p2_suits[5];

    int i;
    char rank;
    char suit;
    int winner;
    const char *reason;
    while (!feof(file)) {
        // Read 5 cards for player 1
        for (i = 0; i < 5; i++) {
            fscanf(file, "%c%c ", &rank, &suit);
            p1_ranks[i] = get_card_rank(rank);
            p1_suits[i] = get_card_suit(suit);
        }

        // Read 5 cards for player 2
        for (i = 0; i < 5; i++) {
            fscanf(file, "%c%c ", &rank, &suit);
            p2_ranks[i] = get_card_rank(rank);
            p2_suits[i] = get_card_suit(suit);
        }

        //print_hands(p1_ranks, p1_suits, p2_ranks, p2_suits);

        // Determine winner
        reason = NULL;
        // Royal flush function not present, since the winner of a royal flush
        // would be determined by the following straight flush function
        if (winner = straight_flush(p1_ranks, p1_suits, p2_ranks, p2_suits)) {
            reason = STRAIGHT_FLUSH_STR;
        } else if (winner = four_of_a_kind(p1_ranks, p2_ranks)) {
            reason = FOUR_OF_A_KIND_STR;
        } else if (winner = full_house(p1_ranks, p2_ranks)) {
            reason = FULL_HOUSE_STR;
        } else if (winner = flush(p1_ranks, p1_suits, p2_ranks, p2_suits)) {
            reason = FLUSH_STR;
        } else if (winner = straight(p1_ranks, p2_ranks)) {
            reason = STRAIGHT_STR;
        } else if (winner = three_of_a_kind(p1_ranks, p2_ranks)) {
            reason = THREE_OF_A_KIND_STR;
        } else if (winner = two_pairs(p1_ranks, p2_ranks)) {
            reason = TWO_PAIRS_STR;
        } else if (winner = one_pair(p1_ranks, p2_ranks)) {
            reason = ONE_PAIR_STR;
        } else if (winner = high_card(p1_ranks, p2_ranks)) {
            reason = HIGH_CARD_STR;
        }
            
        printf("%d\n", winner);
        //printf("winner: %d\n", winner);
        //printf("reason: %s\n\n", reason);

        if (winner == 1)
            p1_wins++;
    }

    fclose(file);

    //printf("player 1 won %d times\n", p1_wins);

    return 0;
}
