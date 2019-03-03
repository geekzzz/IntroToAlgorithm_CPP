static bool cmp(int a, int b)
{
	string stra = to_string(a);
	string strb = to_string(b);

	return (stra + strb) < (strb + stra);
}

string PrintMinNumber(vector<int> numbers) {
	string str;
	if (numbers.empty()) return str;

	sort(numbers.begin(), numbers.end(), cmp);
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		str += to_string(*it);

	return str;
}
