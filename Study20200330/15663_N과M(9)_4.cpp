#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

set<vector<int>> MakeCombination(int M, int index, vector<int> combination, vector<int> numbers) {
	set<vector<int>> result;
	if (M == combination.size()) {
		result.insert(combination);
		return result;
	}

	for (int i = index; i < numbers.size(); ++i) {
		swap(numbers[index], numbers[i]);
		combination.push_back(numbers[index]);
		set<vector<int>> makedCombi = MakeCombination(M, index + 1, combination, numbers);
		result.insert(makedCombi.begin(), makedCombi.end());

		combination.erase(combination.end() - 1);
	}

	return result;
}

int solution(int N, int M, vector<int> numbers) {
	vector<int> combination;
	set<vector<int>> result = MakeCombination(M, 0, combination, numbers);

	for (vector<int> vi : result) {
		for (int i : vi)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}

vector<int> DistributeNumbers(string s) {
	int index = 0;
	vector<int> result;
	while (index < s.length()) {
		result.push_back(s[index] - '0');
		index += 2;
	}

	return result;
}

int main() {
	int M, N;
	string inputNumbers;
	vector<int> numbers;
	cin >> N >> M;
	cin.ignore(1, '\n');
	getline(cin, inputNumbers);

	numbers = DistributeNumbers(inputNumbers);
	solution(N, M, numbers);
}