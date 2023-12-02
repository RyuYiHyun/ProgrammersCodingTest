#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    regex re(R"([0-1]{3}-\d{4}-\d{4})");

	auto strList = { "notmatch.txt", "010-1111-2232", "123-1-4444" };
	for (auto str : strList) 
	{
		cout << str << ": ?" << endl;
		//if (regex_search(str, re))
		if (regex_match(str, re))
		{
			cout << "true" << endl;
		}
		else 
		{
			cout << "false" << endl;
			string replaced_str = "010-7255-0832";
			replaced_str = regex_replace(replaced_str, re, std::string("_someExtension"));
			cout << replaced_str << endl;
		}
	}

    return 0;
}