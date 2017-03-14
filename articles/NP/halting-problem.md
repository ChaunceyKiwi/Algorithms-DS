# Halting Problem

## Motivation
It really confuses me to read the proof of halting problem. I think the reason why it dazzles me is that actually there are several ways to lead to the contradiction. Thus I decide to write down the proof of my version so that at least I have a stable comprehension.

## Proof
Assume Halting problem is solvable, then there exists such a function `H(P, input)`, which is defined as
	
	bool H(P) {
		if P will halt eventually {
			return true;
		} else {
			return false;
		}
	}
	
Then we can construct another function `K(P)`, which is defined as 

	void K(P) {
		if (H(P) == true) {
			loop forever;
		} else {
			halt;
		}
	}
	

Then, will K(K) halt or not? To answer that, we have two situations:

1. K(K) will halt eventually. Then we know from second definition that H(K) is false, which means K will not halt. Contradiction.
2. K(K) will not halt. Then we know from second definition that H(K) is true, which means K will halt. Contradiction.

Thus there do not exist such a function H(P) to tell if a problem will halt eventually or not.

## Discussion
There are some similar paradox like `Barber paradox` and `omnipotence paradox`.

### Barber paradox
	A = {a | a lives in the town}
	S_a = {x | a shaves x}
	
The barber s is the "one who shaves all those, and those only, who do not shave themselves." 
	
	S_s = {a | a not in S_a}

If s is not in S_s, it is in S_s. If s is in S_s, it is not in S_s, lol. 