int minCostClimbingStairs(std::vector<int>& cost) {
	int n = cost.size();
	if (n <= 2)
		return std::min(cost[0], cost[1]);

	std::vector<int>minTable = cost;
	minTable.insert(minTable.begin(), 0);
	minTable.push_back(0);
	int res = 0;

	for (int i = n - 1; i >= 0; i--) {
		minTable[i] += std::min(minTable[i + 1], minTable[i + 2]);
	}

	return minTable[0];
}