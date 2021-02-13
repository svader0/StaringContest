#ifndef SCORE_STRUCT
#define SCORE_STRUCT

// a simple struct to hold our min and sec values
struct Score
{
	int min{ 0 }, sec{ 0 };
	Score(int m, int s)
	{
		min = m;
		sec = s;
	}
	Score(int s)
	{
		min = s / 60;
		s = s % 60;
		sec = s;
	}
	Score() = default;
};

#endif