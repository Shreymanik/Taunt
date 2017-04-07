#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()
#define alli(a, n, k) (a+k),(a+n+k)
#define REP(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)
#define REPI(i, a, b, k) for(__typeof(a) i = a;i > b;i -= k)
#define REPITER(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
 
#define eps 1e-6
#define pi 3.141592653589793
 
using namespace std;
 
template<class T> inline T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<class T> inline T mod(T x) { if(x < 0) return -x; else return x; }
 
typedef vector<ll> VLL;
typedef vector<int> VII;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<int, PII > PPII;
typedef vector< PII > VPII;
typedef vector< PPII > VPPI;
 
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 10;
const int M = 4;
const int ALPHA = -100000;
const int BETA = 100000;
const int MAXSCORE = 1000;
const int MINSCORE = -1000;
const int MINVALUE = -10000;
const int MAXVALUE = 10000;
const int BIGMAXDEPTH = 25;
int ID, CID, ansSx, ansSy, ansX, ansY, time1;
int MAXDEPTH = 0;
bool globalFlag = false; 
bool TIMEOUT = false;
 
bool isMovePossible(int grid[N][M], int player_id, PII p)
{
	int type = (grid[p.fi][p.se] / 10) % 10;
	int dir = (grid[p.fi][p.se] % 10);
	if(type == 1)
	{
		if(p.fi == 0)
		{
			if(p.se == 0)
			{
				if(grid[p.fi][p.se+1] / 100 != player_id) return true;
				if(grid[p.fi+1][p.se] / 100 != player_id) return true;
			}
			else if(p.se == 1 or p.se == 2)
			{
				if(grid[p.fi][p.se+1] / 100 != player_id) return true;
				if(grid[p.fi][p.se-1] / 100 != player_id) return true;
				if(grid[p.fi+1][p.se] / 100 != player_id) return true;
			}
			else
			{
				if(grid[p.fi][p.se-1] / 100 != player_id) return true;
				if(grid[p.fi+1][p.se] / 100 != player_id) return true;
			}
		}
		else if(p.fi == N-1)
		{
			if(p.se == 0)
			{
				if(grid[p.fi][p.se+1] / 100 != player_id) return true;
				if(grid[p.fi-1][p.se] / 100 != player_id) return true;
			}
			else if(p.se == 1 or p.se == 2)
			{
				if(grid[p.fi-1][p.se] / 100 != player_id) return true;
				if(grid[p.fi][p.se+1] / 100 != player_id) return true;
				if(grid[p.fi][p.se-1] / 100 != player_id) return true;
			}
			else
			{
				if(grid[p.fi-1][p.se] / 100 != player_id) return true;
				if(grid[p.fi][p.se-1] / 100 != player_id) return true;
			}
		}
		else
		{
			if(p.se == 0)
			{
				if(grid[p.fi+1][p.se] / 100 != player_id) return true;
				if(grid[p.fi][p.se+1] / 100 != player_id) return true;
				if(grid[p.fi-1][p.se] / 100 != player_id) return true;
			}
			else if(p.se == 1 or p.se == 2)
			{
				if(grid[p.fi-1][p.se] / 100 != player_id) return true;
				if(grid[p.fi][p.se+1] / 100 != player_id) return true;
				if(grid[p.fi][p.se-1] / 100 != player_id) return true;
				if(grid[p.fi+1][p.se] / 100 != player_id) return true;
			}
			else
			{
				if(grid[p.fi-1][p.se] / 100 != player_id) return true;
				if(grid[p.fi][p.se-1] / 100 != player_id) return true;
				if(grid[p.fi+1][p.se] / 100 != player_id) return true;
			}
		}
	}
	else if(type == 2)
	{
		if(dir == 0)
		{
			if(p.fi == 1)
			{
				return true;
			}
			else
			{
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+1] / 100 != player_id) return true;
					if(grid[p.fi-2][p.se] / 100 != player_id) return true;
				}
				else if(p.se == 1 or p.se == 2)
				{
					if(grid[p.fi-2][p.se] / 100 != player_id) return true;
					if(grid[p.fi][p.se+1] / 100 != player_id) return true;
					if(grid[p.fi][p.se-1] / 100 != player_id) return true;
				}
				else
				{
					if(grid[p.fi-2][p.se] / 100 != player_id) return true;
					if(grid[p.fi][p.se-1] / 100 != player_id) return true;
				}
			}
		}
		else
		{
			if(p.fi == N-2)
			{
				return true;
			}
			else
			{
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+1] / 100 != player_id) return true;
					if(grid[p.fi+2][p.se] / 100 != player_id) return true;
				}
				else if(p.se == 1 or p.se == 2)
				{
					if(grid[p.fi+2][p.se] / 100 != player_id) return true;
					if(grid[p.fi][p.se+1] / 100 != player_id) return true;
					if(grid[p.fi][p.se-1] / 100 != player_id) return true;
				}
				else
				{
					if(grid[p.fi+2][p.se] / 100 != player_id) return true;
					if(grid[p.fi][p.se-1] / 100 != player_id) return true;
				}
			}
		}
	}
	else
	{
		if(dir == 0)
		{
			if(p.fi == 1)
			{
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+2] / 100 != player_id) return true;
				}
				else if(p.se == 1 or p.se == 2)
				{
					return true;
				}
				else
				{
					if(grid[p.fi][p.se-2] / 100 != player_id) return true;	
				}
			}
			else
			{
				if(p.se == 0)
				{
					if(grid[p.fi-2][p.se+2] / 100 != player_id) return true;
				}
				else if(p.se == 1)
				{
					if(grid[p.fi-2][p.se] / 100 != player_id) return true;
					if(grid[p.fi-2][p.se+2] / 100 != player_id) return true;
				}
				else if(p.se == 2)
				{
					if(grid[p.fi-2][p.se] / 100 != player_id) return true;
					if(grid[p.fi-2][p.se-2] / 100 != player_id) return true;
				}
				else
				{
					if(grid[p.fi-2][p.se-2] / 100 != player_id) return true;
				}
			}
		}
		else
		{
			if(p.fi == N-2)
			{
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+2] / 100 != player_id) return true;
				}
				else if(p.se == 1 or p.se == 2)
				{
					return true;
				}
				else
				{
					if(grid[p.fi][p.se-2] / 100 != player_id) return true;	
				}
			}
			else
			{
				if(p.se == 0)
				{
					if(grid[p.fi+2][p.se+2] / 100 != player_id) return true;
				}
				else if(p.se == 1)
				{
					if(grid[p.fi+2][p.se] / 100 != player_id) return true;
					if(grid[p.fi+2][p.se+2] / 100 != player_id) return true;
				}
				else if(p.se == 2)
				{
					if(grid[p.fi+2][p.se] / 100 != player_id) return true;
					if(grid[p.fi+2][p.se-2] / 100 != player_id) return true;
				}
				else
				{
					if(grid[p.fi+2][p.se-2] / 100 != player_id) return true;
				}
			}
		}
	}
	return false;
}
 
VPII selectPiece(int grid[N][M], int player_id)
{
	VPII piece;
	VPII t1, t2, t3;
	PII p;
	REP(i, 0, N, 1) REP(j, 0, M, 1) 
		if(grid[i][j] / 100 == player_id)
		{
			p.fi = i;
			p.se = j;
			if(isMovePossible(grid, player_id, p))
			{
				int type = (grid[p.fi][p.se] / 10) % 10;
				if(type == 1)
					t1.pb(p);
				else if(type == 2)
					t2.pb(p);
				else if(type == 3)
					t3.pb(p);
				//piece.pb(p);
			}
		}
	for(int i = t3.size() - 1; i >= 0; i--)
		piece.pb(t3[i]);
	for(int i = t2.size() - 1; i >= 0; i--)
		piece.pb(t2[i]);
	for(int i = t1.size() - 1; i >= 0; i--)
		piece.pb(t1[i]);	
	return piece;
 
}
 
VPII selectMove(int grid[N][M], int player_id, PII p)
{
	VPII moves;
	int type = (grid[p.fi][p.se] / 10) % 10;
	int dir = (grid[p.fi][p.se] % 10);
	if(type == 1)
	{
		if(p.fi == 0)
		{
			if(p.se == 0)
			{
				if(grid[p.fi+1][p.se] / 100 != player_id) moves.pb(mp(p.fi+1, p.se));
				if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
				
			}
			else if(p.se == 1 or p.se == 2)
			{
				if(grid[p.fi+1][p.se] / 100 != player_id) moves.pb(mp(p.fi+1, p.se));
				if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
				if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				
			}
			else
			{
				if(grid[p.fi+1][p.se] / 100 != player_id) moves.pb(mp(p.fi+1, p.se));
				if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				
			}
		}
		else if(p.fi == N-1)
		{
			if(p.se == 0)
			{
				if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
				if(grid[p.fi-1][p.se] / 100 != player_id) moves.pb(mp(p.fi-1, p.se));
			}
			else if(p.se == 1 or p.se == 2)
			{
				
				if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
				if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				if(grid[p.fi-1][p.se] / 100 != player_id) moves.pb(mp(p.fi-1, p.se));
			}
			else
			{
				if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				if(grid[p.fi-1][p.se] / 100 != player_id) moves.pb(mp(p.fi-1, p.se));
				
			}
		}
		else
		{
			if(p.se == 0)
			{
				if(grid[p.fi+1][p.se] / 100 != player_id) moves.pb(mp(p.fi+1, p.se));
				if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
				if(grid[p.fi-1][p.se] / 100 != player_id) moves.pb(mp(p.fi-1, p.se));
			}
			else if(p.se == 1 or p.se == 2)
			{
				if(grid[p.fi+1][p.se] / 100 != player_id) moves.pb(mp(p.fi+1, p.se));
				if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
				if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				if(grid[p.fi-1][p.se] / 100 != player_id) moves.pb(mp(p.fi-1, p.se));
				
			}
			else
			{
				if(grid[p.fi+1][p.se] / 100 != player_id) moves.pb(mp(p.fi+1, p.se));
				if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				if(grid[p.fi-1][p.se] / 100 != player_id) moves.pb(mp(p.fi-1, p.se));
				
			}
		}
	}
	else if(type == 2)
	{
		if(dir == 0)
		{
			if(p.fi == 1)
			{
				moves.pb(mp(p.fi, p.se));
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
				}
				else if(p.se == 1 or p.se == 2)
				{
					if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
					if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				}
				else
				{
					if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				}
			}
			else
			{
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
					if(grid[p.fi-2][p.se] / 100 != player_id) moves.pb(mp(p.fi-2, p.se));
				}
				else if(p.se == 1 or p.se == 2)
				{
					if(grid[p.fi-2][p.se] / 100 != player_id) moves.pb(mp(p.fi-2, p.se));
					if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
					if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				}
				else
				{
					if(grid[p.fi-2][p.se] / 100 != player_id) moves.pb(mp(p.fi-2, p.se));
					if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				}
			}
		}
		else
		{
			if(p.fi == N-2)
			{
				moves.pb(mp(p.fi, p.se));
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
				}
				else if(p.se == 1 or p.se == 2)
				{
					if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
					if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				}
				else
				{
					if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				}
			}
			else
			{
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
					if(grid[p.fi+2][p.se] / 100 != player_id) moves.pb(mp(p.fi+2, p.se));
				}
				else if(p.se == 1 or p.se == 2)
				{
					if(grid[p.fi+2][p.se] / 100 != player_id) moves.pb(mp(p.fi+2, p.se));
					if(grid[p.fi][p.se+1] / 100 != player_id) moves.pb(mp(p.fi, p.se+1));
					if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				}
				else
				{
					if(grid[p.fi+2][p.se] / 100 != player_id) moves.pb(mp(p.fi+2, p.se));
					if(grid[p.fi][p.se-1] / 100 != player_id) moves.pb(mp(p.fi, p.se-1));
				}
			}
		}
	}
	else
	{
		if(dir == 0)
		{
			if(p.fi == 1)
			{
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+2] / 100 != player_id) moves.pb(mp(p.fi, p.se+2));
				}
				else if(p.se == 1 or p.se == 2)
				{
					moves.pb(mp(p.fi, p.se));
					if(p.se == 1 and grid[p.fi][p.se+2] / 100 != player_id) moves.pb(mp(p.fi, p.se + 2));
					if(p.se == 2 and grid[p.fi][p.se-2] / 100 != player_id) moves.pb(mp(p.fi, p.se - 2));
				}
				else
				{
					if(grid[p.fi][p.se-2] / 100 != player_id) moves.pb(mp(p.fi, p.se-2));
				}
			}
			else
			{
				if(p.se == 0)
				{
					if(grid[p.fi-2][p.se+2] / 100 != player_id) moves.pb(mp(p.fi-2, p.se+2));
				}
				else if(p.se == 1)
				{
					if(grid[p.fi-2][p.se] / 100 != player_id) moves.pb(mp(p.fi-2, p.se));
					if(grid[p.fi-2][p.se+2] / 100 != player_id) moves.pb(mp(p.fi-2, p.se+2));
				}
				else if(p.se == 2)
				{
					if(grid[p.fi-2][p.se] / 100 != player_id) moves.pb(mp(p.fi-2, p.se));
					if(grid[p.fi-2][p.se-2] / 100 != player_id) moves.pb(mp(p.fi-2, p.se-2));
				}
				else
				{
					if(grid[p.fi-2][p.se-2] / 100 != player_id) moves.pb(mp(p.fi-2, p.se-2));
				}
			}
		}
		else
		{
			if(p.fi == N-2)
			{
				if(p.se == 0)
				{
					if(grid[p.fi][p.se+2] / 100 != player_id) moves.pb(mp(p.fi, p.se+2));
				}
				else if(p.se == 1 or p.se == 2)
				{
					moves.pb(mp(p.fi, p.se));
					if(p.se == 1 and grid[p.fi][p.se+2] / 100 != player_id) moves.pb(mp(p.fi, p.se+2));
					if(p.se == 2 and grid[p.fi][p.se-2] / 100 != player_id) moves.pb(mp(p.fi, p.se-2));
				}
				else
				{
					if(grid[p.fi][p.se-2] / 100 != player_id) moves.pb(mp(p.fi, p.se-2));
				}
			}
			else
			{
				if(p.se == 0)
				{
					if(grid[p.fi+2][p.se+2] / 100 != player_id) moves.pb(mp(p.fi+2, p.se+2));
				}
				else if(p.se == 1)
				{
					if(grid[p.fi+2][p.se] / 100 != player_id) moves.pb(mp(p.fi+2, p.se));
					if(grid[p.fi+2][p.se+2] / 100 != player_id) moves.pb(mp(p.fi+2, p.se+2));
				}
				else if(p.se == 2)
				{
					if(grid[p.fi+2][p.se] / 100 != player_id) moves.pb(mp(p.fi+2, p.se));
					if(grid[p.fi+2][p.se-2] / 100 != player_id) moves.pb(mp(p.fi+2, p.se-2));
				}
				else
				{
					if(grid[p.fi+2][p.se-2] / 100 != player_id) moves.pb(mp(p.fi+2, p.se-2));
				}
			}
		}
	}
	return moves;
}
 
int score(int grid[N][M], int available_moves) {
	int ansID, ansCID, ctID, ctCID;
	ansID = ansCID = ctID = ctCID = 0;
	REP(i, 0, N, 1) {
		REP(j, 0, M, 1) {
			int player_id = grid[i][j]/100;
			int type = (grid[i][j]/10)%10;
			if(player_id == ID) {
				if(type == 1)ansID++;
				if(type == 2)ansID+=2;
				if(type == 3)ansID+=3;
				ctID++;
			}
			else if(player_id == CID){
				if(type == 1)ansCID--;
				if(type == 2)ansCID-=2;
				if(type == 3)ansCID-=3;
				ctCID++;
			}
		}
	}
	if(ctCID == 0) {
		return MAXSCORE;
	}
	if(ctID == 0) {
		return MINSCORE;
	}
	if(available_moves >= 100) {
		if(ctID > ctCID) {
			return MAXSCORE;
		}
		else if(ctID < ctCID)
			return MINSCORE;
	}
	//return ctCID;
	return (10*(ctID - ctCID) + (ansID + ansCID));
	//return (ctID - ctCID);
}
				 
bool isAllowed(int x, int y) {
	if(x >= N || y >= M || x < 0 || y < 0)
		return false;
	return true;
}
 
int minimax(int grid[N][M], int player_id, int depth, int alpha, int beta, int available_moves) {
	
	int time3 = clock();
	 if((float)(time3 - time1) / CLOCKS_PER_SEC >= 0.95) {
		TIMEOUT = true;
		return -100000;
	 }
	
	if(depth == 0 || available_moves >= 100) {
		return score(grid, available_moves);
	} 
	//cout<<score(grid, available_moves);
	VPII piece = selectPiece(grid, player_id);
	VPII moves;
	int ans = MINVALUE, lowAns = MAXVALUE;
	bool valid_move = false;
	int temp[N][M];
	REP(i, 0, N, 1) REP(j, 0, M, 1) temp[i][j] = grid[i][j];
	for(int i = 0; i < (int)piece.size(); ++i) {
		moves.clear();
		moves = selectMove(grid, player_id, piece[i]);
		
		int x = piece[i].fi;
		int y = piece[i].se;
		int type = (grid[x][y] / 10) % 10;
		int dir = (grid[x][y] % 10);
		for(int j = 0; j < (int)moves.size(); ++j) {
			/*
			 * change grid
			 */
			 int p = moves[j].fi;
			 int q = moves[j].se;
			 if(!isAllowed(p, q))
				continue;
			 valid_move = true;
 
			 /*
			  * testing
			  
			  
			  
		 
			 if(depth <=2) {
				 cout<<x<<","<<y<<" "<<p<<","<<q<<endl;
			 } 
			 */
			 if(globalFlag == 0 && depth == MAXDEPTH) {
				 ansSx = x;
				 ansSy = y;
				 ansX = p;
				 ansY = q;
				 globalFlag = 1;
			 }
			 int save_pos = grid[x][y];
			 grid[x][y] = 0;
			 if(type == 1) {
				 grid[p][q] = save_pos;
			 }
			 else if(type == 2) {
				 if(p == x && q != y) {
					 grid[p][q] = save_pos;
				 }
				 else {
					if(dir == 1) {
						if(!isAllowed(x+1, y))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
						if(grid[x+1][y] / 100 != player_id) grid[x+1][y] = 0;
					}
					else {
						if(!isAllowed(x-1, y))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
						if(grid[x-1][y] / 100 != player_id) grid[x-1][y] = 0;
					}
					if(p != x) {
						if(p == 0 || p == N - 1){
							grid[p][q] = (save_pos/10)*10 + dir^1;
						}
						else grid[p][q] = save_pos;
					}
					else grid[p][q] = (save_pos/10)*10 + dir^1; 
				}
			}
			else {
					
				if(p != x && q!= y) {
					if(dir == 1) {
						if(q < y) {
							if(!isAllowed(x+1, y-1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x+1][y-1] / 100 != player_id) grid[x+1][y-1] = 0;
						}
						else {
							if(!isAllowed(x+1, y+1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x+1][y+1] / 100 != player_id) grid[x+1][y+1] = 0;
						}
					}
					else {
						if(q < y) {
							if(!isAllowed(x-1, y-1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x-1][y-1] / 100 != player_id) grid[x-1][y-1] = 0;
						}
						else {
							if(!isAllowed(x-1, y+1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x-1][y+1] / 100 != player_id) grid[x-1][y+1] = 0;
						}
					}
					if(p == 0 || p == N - 1){
						grid[p][q] = (save_pos/10)*10 + dir^1;
					}
					else {
						grid[p][q] = save_pos;
					}
				}
				else if(p == x && q == y) {
					if(dir == 1) {
						if(y == 1) {
							if(!isAllowed(x+1, y-1))
							cout<<"bcvbskldg7";
							if(grid[x+1][y-1] / 100 != player_id) grid[x+1][y-1] = 0;
						}
						else if(y == 2) {
							if(!isAllowed(x+1, y+1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x+1][y+1] / 100 != player_id) grid[x+1][y+1] = 0;
						}
					}
					else {
						if(y == 1) {
							if(!isAllowed(x-1, y-1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x-1][y-1] / 100 != player_id) grid[x-1][y-1] = 0;
						}
						else if(y == 2) {
							if(!isAllowed(x-1, y+1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x-1][y+1] / 100 != player_id) grid[x-1][y+1] = 0;
						}
					}
					grid[p][q] = (save_pos/10)*10 + dir^1;
				} 
				else if(q == y) {
					if(dir == 1) {
						if(y == 1) {
							if(!isAllowed(x+1, y-1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x+1][y-1] / 100 != player_id) grid[x+1][y-1] = 0;
						}
						else if(y == 2) {
							if(!isAllowed(x+1, y+1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x+1][y+1] / 100 != player_id) grid[x+1][y+1] = 0;
						}
					}
					else {
						if(y == 1) {
							if(!isAllowed(x-1, y-1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x-1][y-1] / 100 != player_id) grid[x-1][y-1] = 0;
						}
						else if(y == 2) {
							if(!isAllowed(x-1, y+1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x-1][y+1] / 100 != player_id) grid[x-1][y+1] = 0;
						}
					}
						if(p == 0 || p == N - 1){
							grid[p][q] = (save_pos/10)*10 + dir^1;
						}
						else grid[p][q] = save_pos;
				}
				else if(p == x) {
					if(dir == 1) {
						if(q < y) {
							if(!isAllowed(x+1, y-1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x+1][y-1] / 100 != player_id) grid[x+1][y-1] = 0;
						}
						else {
							if(!isAllowed(x+1, y+1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x+1][y+1] / 100 != player_id) grid[x+1][y+1] = 0;
						}
					}
					else {
						if(q < y) {
							if(!isAllowed(x-1, y-1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x-1][y-1] / 100 != player_id) grid[x-1][y-1] = 0;
						}
						else {
							if(!isAllowed(x-1, y+1))
							cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<"type: "<<type<<" "<<"dir: "<<dir<<endl;
							if(grid[x-1][y+1] / 100 != player_id) grid[x-1][y+1] = 0;
						}
					}
					grid[p][q] = (save_pos/10)*10 + dir^1;
				}
			}
			/*Testing
			
			if(type == 3 && depth <= 2){
			
			REP(ii, 0, N, 1) {
			REP(jj, 0, M, 1) {
			cout<<grid[ii][jj]<<" ";
			}cout<<endl;
			}
			cout<<endl; 
			}
			*/
			 int val = minimax(grid, player_id%2 + 1, depth - 1, alpha, beta, available_moves + 1);
			 if(val > ans) {
				ans = val;
				if(depth == MAXDEPTH) {
					ansSx = piece[i].fi;
					ansSy = piece[i].se;
					ansX = moves[j].fi;
					ansY = moves[j].se;
				}
			 }
			 lowAns = min(lowAns, val);
			 if(TIMEOUT == true) {
				return -100000;
			 }
			 /*
			  * restore grid
			  */
			  REP(ii, 0, N, 1) REP(jj, 0, M, 1) grid[ii][jj] = temp[ii][jj];
				  
			 if(player_id == ID) {
				alpha = max(alpha, ans);
				if(alpha >= beta) {	
					return ans;
				}
			 }
			 else {
				beta = min(beta, lowAns);
				if(alpha >= beta) {
					return lowAns;
				}
		   	 }	 
		 }
	 }
	if(!valid_move)
		return score(grid, available_moves);
	if(player_id == ID) {
		return ans;
	}
	else {
		return lowAns;
	}
		
 }
 
 void iterativeDeepening(int grid[N][M], int player_id, int number_of_moves) {
	//cout<<ID<<" "<<CID<<" ";
	int time2,startDepth;
	float tx;
	int val, sx, sy, dx, dy,answer = -1000000;
	if(number_of_moves >= 95){
		startDepth = 1;
	}
	else startDepth = 3;
	for(int i = startDepth; i <= BIGMAXDEPTH; ++i) {
		if(i + number_of_moves > 100)
			return;
		MAXDEPTH = i;
	//	cout<<i<<endl;
		time2 = clock();
		tx = (float)(time2 - time1) / CLOCKS_PER_SEC;
		//trace1(tx);
		//if(tx < 2.00f)
		val = minimax(grid, player_id, i, ALPHA, BETA, number_of_moves);
	//	cout<<val<<endl;
		//else break;
		//cout<<ansSx<<" "<<ansSy<<" "<<ansX<<" "<<ansY<<endl;
		if(val == MAXSCORE){
			//cout<<"sdg";
			return;
		}
		
		if(TIMEOUT == true) {
			if(answer >= val) {
				ansSx = sx;
				ansSy = sy;
				ansX = dx;
				ansY = dy;
			}
			//cout<<"dsgsdg";
			return;
		}
		else {
			answer = val;
			sx = ansSx;
			sy = ansSy;
			dx = ansX;
			dy = ansY;
			
		}			
 
	}
}
 
 
int main()
{
	int grid[N][M], player_id, number_of_moves;
	REP(i, 0, N, 1) REP(j, 0, M, 1) cin >> grid[i][j];
	cin >> number_of_moves >> player_id;
	ID = player_id;
	CID = player_id%2 + 1;
	if(ID == 1 && number_of_moves == 0) {
		cout<<"2 0"<<endl;
		cout<<"3 0"<<endl;
		return 0;
	}
	time1 = clock();
	iterativeDeepening(grid, player_id, number_of_moves);
	//minimax(grid, player_id, MAXDEPTH, ALPHA, BETA, number_of_moves);
	/*
	piece = selectPiece(grid, player_id);
	piece_move = selectMove(grid, player_id, piece);
 
	cout << piece.fi << ' ' << piece.se << endl;
	cout << piece_move.fi << ' ' << piece_move.se << endl;
	*/
	cout << ansSx << " " << ansSy << endl;
	cout << ansX << " " << ansY << endl;
	//cout<<(float)(clock() - time1) / CLOCKS_PER_SEC;
	return 0;
}
 
 
 
/*Testing
 
000 000 000 000
000 000 000 000
000 000 000 111
000 000 000 000
000 000 121 111
220 000 000 000
000 000 000 000
000 221 000 210
210 210 230 000
000 000 000 000
75
2
*/

