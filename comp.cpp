//*********************************COMPERATOR***********************************\\
struct srt
{
	bool operator() (pii a,pii b){
		return ((a.F - a.F/2)*a.S) > ((b.F - b.F/2)*b.S);
	}
};
set<pii,srt> s;