#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getLongestCommonString(string s1, string s2) {
	int size1 = s1.length();
	int size2 = s2.length();
	int maxlen = 0;
	int maxStart = 0;
	for (int start = 0; start < size2; ++start) {
		for (int len = 1; len < size2 - start + 1; ++len) {
			if (len > maxlen) {
				string tmp = s2.substr(start, len);
				int pos = s1.find(tmp);
				if (string::npos != pos) {
					maxStart = pos;
					maxlen = len;
				}
			}
		}
	}
	return s1.substr(maxStart, maxlen);
}

string getLongestCommonStringdp(string s1, string s2) {
	int size1 = s1.length();
	int size2 = s2.length();
	int maxlen = 0;
	int maxEnd = 0;
	vector<vector<int> > dp(size1 + 1, vector<int>(size2 + 1, 0));
	for (int i = 1; i < size1 + 1; ++i) {
		for (int j = 1; j < size2 + 1; ++j) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				if (dp[i][j] > maxlen) {
					maxlen = dp[i][j];
					maxEnd = i - 1;
				}
			}
			else {
				//dp[i][j] = max(dp[i][j-1], dp[i-1][j]); for longest sub sequence
				dp[i][j] = 0;// for longest sub string
			}
		}
	}
	return s1.substr(maxEnd-maxlen+1, maxlen);
}

void getNext(string s, vector<int>&next) {
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == s[next[i - 1]]) next[i] = next[i-1] + 1;
	}
}

string getLongestCommonStringKPM(string s1, string s2) {
	vector<int>next(s2.length(), 0);
	getNext(s2, next);

	int i = 0, j = 0;
	int len = 0, maxlen = 0;
	int start = 0, maxStart = 0;
	while (i < s1.length() && j < s2.length()) {
		if (s1[i] == s2[j]) {
			++i;
			++j;
			++len;
			if (len > maxlen) {
				maxlen = len;
				maxStart = start;
			}
		}
		else {
			if (j == 0) {
				++j;
				++i;
				++start;
				len = 0;
			}
			else {
				start = i - next[j - 1];
				len = next[j - 1];
				j = next[j - 1];
			}
		}
	}
	return s1.substr(maxStart, maxlen);
}


int main() 
{
	string s1("abfabcacb"), s2("abfabdcf");
	//cout << "Enter s1, s2: " << endl;
	//cin >> s1 >> s2;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "Longest Common String = " << getLongestCommonString(s1, s2) << endl;
	cout << "Longest Common String[dp] = " << getLongestCommonStringdp(s1, s2) << endl;
	cout << "Longest Common String[kpm] = " << getLongestCommonStringKPM(s1, s2) << endl;
}