#include "utility.h"

using namespace std;

namespace utility
{
	int readInstance(
		std::string &name, 
		int &w, 
		int &n, 
		int &m, 
		int &MAXW, 
		int &MINW,
		int &NSLength2, 
		int &NSLength3,
		vector<char> &A,
		vector<int> &MAXS,
		vector<int> &MINS,
		vector< vector<int> > &R,
		vector< vector<char> > &C2		
	)
	{
		FILE* fi;
		fi = fopen(name.c_str(), "r");
		int sumRead;
		
		if (fi != NULL) {
			
			sumRead = fscanf(fi, "#w\n%i\n\n", &w);
			sumRead += fscanf(fi, "#n\n%i\n\n", &n);
			sumRead += fscanf(fi, "#m\n%i\n\n#A\n", &m);

			if (sumRead != 3) return 1;

			sumRead = 0;
			A.resize(m);
			for (int i=0;i<m;i++)
			{
				sumRead += fscanf(fi, "%c ", &(A[i]));
			}
			fscanf(fi, "\n\n#R\n");
			if (sumRead != m) return 1;

			sumRead = 0;
			R.resize(m-1);
			for (int i=0; i<m-1; i++)
			{
				R[i].resize(w);
				for (int j=0; j<w; j++)
				{
					sumRead += fscanf(fi, "%i", &(R[i][j]));
				}
				fscanf(fi, "\n");
			}
			if (sumRead != (m-1)*w) return 1;

			sumRead = 0;
			MAXS.resize(m);
			fscanf(fi, "\n#MAXS\n");
			for (int i=0;i<m; i++)
			{
				sumRead += fscanf(fi, "%i", &(MAXS[i]));
			}
			if (sumRead != m) return 1;

			sumRead = 0;
			MINS.resize(m);
			fscanf(fi, "\n\n#MINS\n");
			for (int i=0; i<m; i++)
			{
				sumRead += fscanf(fi, "%i", &(MINS[i]));
			}
			if (sumRead != m) return 1;

			sumRead = 0;
			sumRead += fscanf(fi, "\n\n#MAXW\n%i\n\n#MINW\n%i\n\n", &MAXW, &MINW);

			sumRead += fscanf(fi, "#NSLength2\n%i\n#NSLength3\n%i\n\n#C2\n", &NSLength2, &NSLength3);
			if (sumRead != 4) return 1;

			sumRead = 0;
			C2.resize(NSLength2+NSLength3);
			for (int i=0; i<NSLength2; i++)
			{
				C2[i].resize(2);
				sumRead += fscanf(fi, "%c %c\n", &(C2[i][0]), &(C2[i][1]));
			}

			for (int i=0; i<NSLength3; i++)
			{
				C2[NSLength2+i].resize(3);
				sumRead += fscanf(fi, "%c %c %c\n", &(C2[NSLength2+i][0]), &(C2[NSLength2+i][1]), &(C2[NSLength2+i][2]) );
			}
			if (sumRead != NSLength2*2+NSLength3*3 ) return 1;

			return 0;
		} else {
			cout << "Error" << endl;
			return -1;
		}
	}

	std::string moveToString(int i, int j, int k)
	{
		ostringstream os;
		os << i << "-" << j << "-" << k;
		return os.str();
	}

	int distance(int wb_size, int min, int max)
	{		
		if (wb_size < min)
		{
			return min - wb_size;
		} else if (wb_size > max) {
			return wb_size - max;
		}
		return 0;
	}

	
	/* int countMatchInRegex(std::string s, std::string re)
	{
		std::regex words_regex(re);
		auto words_begin = std::sregex_iterator(
			s.begin(), s.end(), words_regex);
		auto words_end = std::sregex_iterator();

		return std::distance(words_begin, words_end);
	} */
}