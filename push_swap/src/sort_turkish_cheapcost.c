#include "push_swap.h"


int	cost_ra_rb(int pos_a, int pos_b)
{
	int	cost;

	if (pos_a > pos_b)
		cost = pos_a;
	else
		cost = pos_b;
	return (cost);
}
int	cost_rra_rrb(int pos_a, int pos_b, int size_a, int size_b)
{
	int	cost;

	if (size_a - pos_a > size_b - pos_b)
		cost = size_a - pos_a;
	else
		cost = size_b - pos_b;
	return (cost);
}

int	cost_ra_rrb(int pos_a, int pos_b, int size_b)
{
	int cost;

	cost = pos_a + (size_b - pos_b);
	return (cost);
}

int	cost_rra_rb(int pos_a, int pos_b, int size_a)
{
	int cost;

	cost = (size_a - pos_a) + pos_b;
	return (cost);
}

int	cheapest_cost(int ra_rb, int rra_rrb, int ra_rrb, int rra_rb)
{
	int	cheapest;

	cheapest = ra_rb;
	if (cheapest > rra_rrb)
		cheapest = rra_rrb;
	if (cheapest > ra_rrb)
		cheapest = ra_rrb;
	if (cheapest > rra_rb)
		cheapest = rra_rb;
	return (cheapest);
}