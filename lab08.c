// EE231000 Lab08 Poker Hands
// 109061138, 張育瑋
// Date: 2020/11/20

#include <stdio.h>		// compiler directive
#include <stdlib.h>		// compiler directive

void deal(int dealt[52]);
void show_cards_in_hand(const int dealt[52]);
void check(int dealt[52]);
int StraightFlush_or_Flush(int d_rank[5]);
int FullHouse_or_ThreeofaKind(int d_rank[5], m_rank);

int main(void)						// main function begins
{
	int dealt[52] = {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, k;
	
//	deal(dealt);
	show_cards_in_hand(dealt);
	check(dealt);
	
	return 0;						// main function ends
}

void deal(int dealt[52])
{
	int cards = 5, d_card, suit, rank;

	printf("in hand:\n");
	while (cards) {
		d_card = rand() / 1000 % 52;
		if (!dealt[d_card]) {
			dealt[d_card]++;
			cards--;
			rank = d_card % 13 + 1;
			suit = d_card / 13;

			switch (rank) {
				case 1: printf("Ace");		break;
				case 11: printf("Jack");	break;
				case 12: printf("Queen");	break;
				case 13: printf("King");	break;
				default: printf("%d", rank);
			}
			switch (suit) {
				case 0: printf(" of clubs\n");		break;
				case 1: printf(" of diamonds\n");	break;
				case 2: printf(" of hearts\n");		break;
				case 3: printf(" of spades\n");
			}
			
		}
	}
	
	return;
}

void check(int dealt[52])
{
	printf("check starts\n");
	
	int d_suit[5], d_rank[5];				
		// suits and ranks of the 5 dealt cards
	int r_suit[4] = {0}, r_rank[13] = {0};	
		// repeated suits and ranks
	int m_suit = 0, m_rank = 0;
		// most appearing suit and rank in actual number,
		// 0 means all are different
	int tm_suit = 1, tm_rank = 1;			
		// times that m_suit and m_rank appears
		// 1 means all are different
	int i, j, k;	// loop indices
		
	for(i = 0, j = 0, k = 0; i < 52 && j < 5; i++)
		if(dealt[i]) {
			d_suit[j] = i / 13;
			d_rank[j] = i % 13;
			r_suit[d_suit[j]]++;
			r_rank[d_rank[j]]++;
			j++;
		}
	printf("tm_suit0 = %d\n", tm_suit);
	
	for(i = 0; i < 4; i++) {		// find the most repeated suit
		if (r_suit[i] > tm_suit) {
			tm_suit = r_suit[i];
			m_suit = i + 1;			// actual rank number
		}
	}
	
	printf("tm_suit' = %d\n", tm_suit);
	
	if (tm_suit == 5) 
		if (StraightFlush_or_Flush(d_rank))	// if 5 same ranks
			printf("Straight flush!!!\n");
		else printf("Flush!!!\n");
	else {
		for (i = 0; i < 13; i++) {
			if (r_rank[i] > tm_rank) {
				tm_rank = r_rank[i];
				m_rank = i + 1;			// actual rank number
			}
		}
	}
	
	switch (tm_rank) {
		case 4: printf("Four of a kind!!!\n");				break;
		case 3: FullHouse_or_ThreeofaKind(d_rank, m_rank);	break;
		case 2;
	}
	
	return;						// main function ends
}

int StraightFlush_or_Flush(int d_rank[5])
{
	printf("StraightFlush_or_Flush starts\n");
	
	int i;
	
//	printf("d_rank[5] = ");
//	for(i = 0; i < 5; i++) printf(" %d", d_rank[i]);
//	putchar('\n');
	
	if(d_rank[0] > 0) {
		for (i = 0; i < 5; i++) 
			if (d_rank[i] + 1 !=  d_rank[i + 1]) return 0;
		return 1;
	}
	else {
		if (d_rank[1] == 9) return 1;
		if (d_rank[4] == 4) return 1;
		return 0;
	}
}

int FullHouse_or_ThreeofaKind(int d_rank[5], int m_rank)
{
	
}

void show_cards_in_hand(const int dealt[52])
{
	int i;
	
	for(i = 0; i < 52; i++) {
		if (i % 13 == 12) printf(" %d\n", dealt[i]);
		else printf(" %d", dealt[i]);
	}
	
	return;
}
